#include <Windows.h>										// Header File for Windows
#include <gl\GL.h>											// Header File for OpenGL32 Library
#include <gl\GLU.h>											// Header File for GLu32 Library

HGLRC hRC = NULL;											// Permanent Redering Context
HDC hDC = NULL;												// Private GDI Device Context
HWND hWnd = NULL;											// Holds our Window Handle
HINSTANCE hInstance;										// Holds the Instance of the Application

bool Keys[256];												// Array Used for the Keyboard Routine
bool Active = TRUE;											// Window Active Flag Set to TRUE by Default
bool FullScreen = TRUE;										// FullScreen Flag Set to FullScreen Mode by Default

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);		// Declaration for WndProc

GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height) {		// Resize and Initialize the GL Window
	if(Height == 0) {										// Prevent a Divide by Zero Error
		Height = 1;											// Set Height Equal to 1
	}
	glViewport(0,0,Width,Height);							// Reset the Current Viewport
	glMatrixMode(GL_PROJECTION);							// Select the Projection Matrix
	glLoadIdentity();										// Reset the Projection Matrix
	// Calculate the Aspect Ratio of the Window
	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);								// Select the ModelView Matrix
	glLoadIdentity();										// Reset the ModelView Matrix
}

int InitGL(GLvoid) {										// All Setup of OpenGL Goes Here
	glShadeModel(GL_SMOOTH);								// Enables Smooth Shading
	glClearColor(0.0f,0.0f,0.0f,0.0f);						// The Color of the Window (Red,Green,Blue,Alpha)
	glClearDepth(1.0f);										// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);								// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);									// The type of Depth Test to do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);		// Really Nice Perspective Calculations
	return TRUE;											// Initialization Went OK
}

int DrawGLScreen(GLvoid) {									// Draws Everything on Screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clears the Screen and the Depth Buffer
	glLoadIdentity();										// Reset the Current ModelView Matrix
	return TRUE;											// Everything Went OK
}

GLvoid KillGLWindow(GLvoid) {								// Properly Kill the Window
	if(FullScreen) {										// Is the Window FullScreen?
		ChangeDisplaySettings(NULL,0);						// If so, Switch it Back to Desktop
		ShowCursor(TRUE);									// Show Mouse Pointer
	}
	if(hRC) {												// Do we have a Rendering Context?
		if(!wglMakeCurrent(NULL,NULL)) {					// Are we able to Release DC and RC Contexts?
			MessageBox(NULL,L"Release of DC And RC Failed.",L"SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
			hRC = NULL;										// Set RC to NULL
		}
	}
	if(hDC && !ReleaseDC(hWnd,hDC)) {						// Are we able to Release the DC?
		MessageBox(NULL,L"Release Device Context Failed.",L"SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC = NULL;											// Set DC to NULL
	}
	if(hWnd && !DestroyWindow(hWnd)) {						// Are we able to Destroy the Window?
		MessageBox(NULL,L"Could Not Release hWnd.",L"SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd to NULL
	}
	if(!UnregisterClass(L"OpenGL",hInstance)) {		// Are we able to Unregister Class?
		MessageBox(NULL,L"Could Not Unregister Class.", L"SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance to NULL
	}
}

BOOL CreateGLWindow(char* Title, int Width, int Height, int Bits, bool FullScreenFlag) {
	GLuint PixelFormat;										// Holds the Result after Searching for a Match
	WNDCLASS wc;											// Windows Class Structure
	DWORD dwExStyle;										// Window Extended Style
	DWORD dwStyle;											// Window Style
	RECT WindowRect;										// Grabs Rectangle UpperLeft & LowerRight Values
	WindowRect.left = (long)0;								// Set Left Value to 0
	WindowRect.right = (long)Width;							// Set Right Value to Requested Width
	WindowRect.top = (long)0;								// Set Top Value to 0
	WindowRect.bottom = (long)Height;						// Set Bottom Value to Requested Height
	FullScreen = FullScreenFlag;							// Set the Global FullScreen Flag
	hInstance = GetModuleHandle(NULL);						// Grab an Instance for our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;			// Redraw on Move, and own DC for Window
	wc.lpfnWndProc = (WNDPROC)WndProc;						// WndProc Handles Messages
	wc.cbClsExtra = 0;										// No Extra Window Data
	wc.cbWndExtra = 0;										// No Extra Window Data
	wc.hInstance = hInstance;								// Set the Instance
	wc.hIcon = LoadIcon(NULL,IDI_WINLOGO);					// Load the Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// Load the Arrow Pointer
	wc.hbrBackground = NULL;								// No Background Required for GL
	wc.lpszMenuName = NULL;									// We don't want a Menu
	wc.lpszClassName = L"OpenGL";					// Set the Class Name
	if(!RegisterClass(&wc)) {								// Attempt to Register the Window Class
		MessageBox(NULL,L"Failed to Register the Window Class.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Exit and Return FALSE
	}
	if(FullScreen) {										// Attempt FullScreen Mode
		DEVMODE dmScreenSettings;							// Device Mode
		// Make Sure Memory is Cleared
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings); // Size of the DevMode Structure
		dmScreenSettings.dmPelsWidth = Width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = Height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = Bits;				// Selected Bits per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		// Try to Set Selected Mode and Get Results. NOTE: CDS_FULLSCREEN gets rid of Start Bar
		if(ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) {
			// If the Mode Fails, Offer 2 Options. Quit or Run in a Window
			if(MessageBox(NULL,L"The Requested FullScreen Mode is not Supported By\nYour Video Card. Use Windowed Mode Instead?",L"OpenGL",MB_YESNO | MB_ICONEXCLAMATION) == IDYES) {
				FullScreen = FALSE;							// Select Window Mode (FullScreen = FALSE)
			}
			else {
				// Pops up a Message Box Letting User Know the Program is Closing.
				MessageBox(NULL,L"Program will Now Close.",L"ERROR",MB_OK | MB_ICONSTOP);
				return FALSE;								// Exit and Return FALSE
			}
		}
	}
	if(FullScreen) {										// Are we still in FullScreen Mode?
		dwExStyle = WS_EX_APPWINDOW;						// Window Extended Style
		dwStyle = WS_POPUP;									// Window Style
		ShowCursor(FALSE);									// Hide Mouse Pointer
	}
	else {
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;		// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;						// Window Style
	}
	AdjustWindowRectEx(&WindowRect,dwStyle,FALSE,dwExStyle);// Adjust Window to True Requested Size
	if(!(hWnd = CreateWindowEx( dwExStyle,					// Extended Style for the Window
		L"OpenGL",									// Class Name
		L"Title",										// Window Title
		WS_CLIPSIBLINGS |									// Required Window Style
		WS_CLIPCHILDREN |									// Required Window Style
		dwStyle,											// Selected Window Style
		0, 0,												// Window Position
		WindowRect.right - WindowRect.left,					// Calculated Adjusted Window Width
		WindowRect.bottom - WindowRect.top,					// Calculated Adjusted Window Height
		NULL,												// No Parent Window
		NULL,												// No Menu
		hInstance,											// Instance
		NULL)))	{											// Don't Pass Anything to WM_CREATE
			KillGLWindow();									// Reset the Display
			MessageBox(NULL,L"Window Creation Error.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
			return FALSE;									// Return FALSE
	}
	static PIXELFORMATDESCRIPTOR pfd= {						// The pdf tells Windows how we want Things to be
		sizeof(PIXELFORMATDESCRIPTOR),						// Size of this Pixel Format Descriptor
		1,													// Version Number
		PFD_DRAW_TO_WINDOW |								// Format Must Support Window
		PFD_SUPPORT_OPENGL |								// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,									// Must Support Double Buffering
		PFD_TYPE_RGBA,										// Request an RGBA Format
		Bits,												// Select our Color Depth
		0, 0, 0, 0, 0, 0,									// First 6 Bits are Ignored
		0,													// No Alpha Buffer
		0,													// Shift Bit Ignored
		0,													// No Accumulation Buffer
		0, 0, 0, 0,											// Accumulation Bits Ignored
		16,													// 16-Bit Z-Buffer (Depth Buffer)
		0,													// No Stencil Buffer
		0,													// No Auxilliary Buffer
		PFD_MAIN_PLANE,										// Main Drawing Layer
		0,													// Reserved
		0, 0, 0												// Layer Masks Ignored
	};
	if(!(hDC = GetDC(hWnd))) {								// Did we get a Device Context?
		KillGLWindow();										// Reset the Display
		MessageBox(NULL,L"Can't Create a GL Device Context.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Return FALSE
	}
	if(!(PixelFormat = ChoosePixelFormat(hDC,&pfd))) {		// Did Windows find a Matching Pixel?
		KillGLWindow();										// Reset the Window
		MessageBox(NULL,L"Can't find a suitable PixelFormat.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Return FALSE
	}
	if(!SetPixelFormat(hDC,PixelFormat,&pfd)) {				// Are we able to set the Pixel Format?
		KillGLWindow();										// Reset the Window
		MessageBox(NULL,L"Can't set the Pixel Format.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Return FALSE
	}
	if(!(hRC = wglCreateContext(hDC))) {					// Are we able to get a Rendering Context?
		KillGLWindow();										// Reset the Window
		MessageBox(NULL,L"Can't Create a GL Rendering Context.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Return FALSE
	}
	if(!wglMakeCurrent(hDC,hRC)) {							// Try to Activate the Rendering Context
		KillGLWindow();										// Reset the Window
		MessageBox(NULL,L"Can't Activate the GL Rendering Context.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Return FALSE
	}
	ShowWindow(hWnd,SW_SHOW);								// Show the Window
	SetForegroundWindow(hWnd);								// Slightly Higher Priority
	SetFocus(hWnd);											// Sets Keyboard Focus to the Window
	ReSizeGLScene(Width,Height);							// Set Up your Perspective GL Screen
	if(!InitGL()) {											// Initialize our Newly Created GL Window
		KillGLWindow();										// Reset the Window
		MessageBox(NULL,L"Initialization Failed.",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// Return FALSE
	}
	return TRUE;											// Success
}

LRESULT CALLBACK WndProc( HWND hWnd,						// Handle for this Window
	UINT uMsg,												// Message for this Window
	WPARAM wParam,											// Additional Message Information
	LPARAM lParam) {										// Additional Message Information
		switch(uMsg) {										// Check for Windows Messages
			case WM_ACTIVATE: {								// Watch for Window Activate Message
				if(!HIWORD(wParam))	{						// Check Minimization State
					Active = TRUE;							// Program is Active
				}
				else {
					Active = FALSE;							// Program is No Longer Active
				}
				return 0;									// Return to the Message Loop
			}
			case WM_SYSCOMMAND: {							// Intercept System Commands
				switch(wParam) {							// Check System Calls
					case SC_SCREENSAVE:						// Screensaver Trying to Start?
					case SC_MONITORPOWER:					// Monitor Trying to Enter Powersave?
						return 0;							// Prevent from Happening
				}
				break;										// Exit
			}
			case WM_CLOSE: {								// Did we Receive a Close Message?
				PostQuitMessage(0);							// Send a Quit Message
				return 0;									// Jump Back
			}
			case WM_KEYDOWN: {								// Is a Key being held Down?
				Keys[wParam] = TRUE;						// If so, Mark it as TRUE
				return 0;									// Jump Back
			}
			case WM_KEYUP: {								// Has a Key being Released?
				Keys[wParam] = FALSE;						// If so, Mark is as FALSE
				return 0;									// Jump Back
			}
			case WM_SIZE: {									// Resize the OpenGL Window
				ReSizeGLScene(LOWORD(lParam),HIWORD(wParam)); // LoWord = Width  -  HiWord = Height
				return 0;									// Jump Back
			}
		}
		return DefWindowProc(hWnd,uMsg,wParam,lParam);		// Pass all Unhandled Messages to DefWindowProc
}

int WINAPI WinMain( HINSTANCE hInstance,					// Instance
	HINSTANCE hPrevInstance,								// Previous Instance
	LPSTR lpCmdLine,										// Command Line Parameters
	int nCmdShow) {											// Window Show State
		MSG msg;											// Windows Message Structure
		bool DONE = FALSE;									// Bool Variable to Exit Loop
		// Ask the User which ScreenMode they Prefer
		if(MessageBox(NULL,L"Would you Like to Run in FullScreen Mode?",L"Start FullScreen",MB_YESNO | MB_ICONQUESTION)==IDNO) {
			FullScreen = FALSE;								// Windowed Mode
		}
		// Create our OpenGL Window
		if(!CreateGLWindow("Lateralus.T_T",640,480,16,FullScreen)) {
			return 0;										// Quit if Window was not Created
		}
		while(!DONE) {										// Loop that Runs until DONE = TRUE
			if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {		// Is there a Message Waiting?
				if(msg.message==WM_QUIT) {					// Have we Received a Quit Message?
					DONE = TRUE;							// If so, DONE = TRUE
				}
				else {										// If not, Deal with Window Messages
					TranslateMessage(&msg);					// Translate the Message
					DispatchMessage(&msg);					// Dispatch the Message
				}
			}
			else {											// If there are no Messages
				// Draw the Scene. Watch for ESC Key and Quit Messages from DrawGLScreen()
				if(Active) {								// Program Active?
					if(Keys[VK_ESCAPE]) {					// Was ESC Pressed?
						DONE = TRUE;						// ESC Signalled a Quit
					}
					else {									// Not time to Quit? Update Screen
						DrawGLScreen();						// Draw the Scren
						SwapBuffers(hDC);					// Swap Buffers (Double Buffering)
					}
					if(Keys[VK_F1]) {						// If F1 being Pressed?
						Keys[VK_F1] = FALSE;				// If so, Make Key False
						KillGLWindow();						// Kill out Current Window
						FullScreen = !FullScreen;			// Toggle FullScreen / Windowed Mode
						// Re-Create our new OpenGL Window
						if(!CreateGLWindow("Lateralus.T_T",640,480,16,FullScreen)) {
							return 0;						// Quit if Window was not Created
						}
					}
				}
			}
		}
		// Shutdown
		KillGLWindow();										// Kill the Window
		return(msg.wParam);									// Exit the Program
}

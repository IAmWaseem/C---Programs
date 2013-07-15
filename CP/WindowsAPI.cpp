#include <Windows.h>
#include <CommDlg.h>

// -------------------------------------------------------------------------
// When tested - the printout cuts off the right side of the screen.
// It is not much, but still I cannot find the explanation for it.
// All values for printer are retrieved using API - all done by the book,
// but looks like the assumption that left margin for printer is
// the same as right margin is incorrect. I assumed that they are the same and
// the expression for horizontal printable area is:
//	int printedWidth = xPrnPixelsPerPage - xPrnPixelsMargin * 2;
// Easy fix will be to use 3 margins(!) instead of 2:
//	int printedWidth = xPrnPixelsPerPage - xPrnPixelsMargin * 3;
// Or play with the 'xPrnPixelsMargin' value itself (decrease it a little).
// Still, no explanation bothers me, but function works fine otherwise.
// -------------------------------------------------------------------------
void PrintScreen ()
	{
	HDC hScreenDC;

	if ((hScreenDC = GetDC (NULL)) != NULL) {
		HDC hMemDC;

		if ((hMemDC = CreateCompatibleDC (hScreenDC)) != NULL) {
			HBITMAP hFullScreenBitmap;
			int iScreenWidth = GetSystemMetrics (SM_CXSCREEN);
			int iScreenHeight = GetSystemMetrics (SM_CYSCREEN);
			
			if ((hFullScreenBitmap = CreateCompatibleBitmap (hScreenDC, iScreenWidth, iScreenHeight)) != NULL) {
				HBITMAP hDefaultBitmap = (HBITMAP) SelectObject (hMemDC, hFullScreenBitmap);

				// From screen to memory:
				BitBlt (hMemDC, 0, 0, iScreenWidth, iScreenHeight, hScreenDC, 0, 0, SRCCOPY);
				SelectObject (hMemDC, hDefaultBitmap);
				SelectObject (hMemDC, hFullScreenBitmap);

				// Printing:
				PRINTDLG pd = {0}; // Reset on declare

				pd.lStructSize = sizeof (pd);
				pd.Flags = PD_RETURNDEFAULT | PD_ALLPAGES | PD_RETURNDC;
				pd.nFromPage = 1;
				pd.nToPage = 1;
				pd.nCopies = 1;

				if (PrintDlg (&pd)) {
					if (pd.hDC) {
						// Scaling to fit on a printer page:
						double dblScreenRatio = (double) iScreenWidth / (double) iScreenHeight;
						int xPrnPixelsPerPage = GetDeviceCaps (pd.hDC, PHYSICALWIDTH);
						int xPrnPixelsMargin = GetDeviceCaps (pd.hDC, PHYSICALOFFSETX);
						int yPrnPixelsMargin = GetDeviceCaps (pd.hDC, PHYSICALOFFSETY);
						int printedWidth = xPrnPixelsPerPage - xPrnPixelsMargin * 2;
						int printedHeight = (int) ((double) printedWidth / dblScreenRatio);

						DOCINFO di = {0};

						di.cbSize = sizeof (di);
						di.lpszDocName = LPCWSTR("Print Full Screen");

						StartDoc (pd.hDC, &di);
						StartPage (pd.hDC);

						// FINALLY!
						StretchBlt (pd.hDC,
							xPrnPixelsMargin, yPrnPixelsMargin, printedWidth, printedHeight,
							hMemDC, 0, 0, iScreenWidth, iScreenHeight, SRCCOPY);

						EndPage (pd.hDC);
						EndDoc (pd.hDC);
						DeleteDC (pd.hDC);
						}
					// Clean up after print dlg:
					if (pd.hDevMode) {
						GlobalFree (pd.hDevMode);
						}
					if (pd.hDevNames) {
						GlobalFree (pd.hDevNames);
						}
					}
				SelectObject (hMemDC, hDefaultBitmap);
				DeleteObject (hFullScreenBitmap);
				}
			DeleteDC (hMemDC);
			}
		ReleaseDC (NULL, hScreenDC);
		}
	}

int main() {
	PrintScreen();
}
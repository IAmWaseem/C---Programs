/*    #include <windows.h>
    #include <iostream>
using namespace std;
int main()
{
	system("color 17");
	cout << "hello" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); //replace the 0 with a number for the color you want
    cout << "Your text here" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	cout << "Blue Color" << endl;
    return 0;
}*/

    #include<iostream>
    #include<Windows.h>
    using namespace std;
    int main()
    {
    for(int i=0; i<255; i++)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
    cout << "supppppppppppp " << i << endl;
     system("pause");
	}
    }
#include <iostream>

using namespace std;

int main()
{
    cout<<"Grading Program"<<endl<<endl;
    char x;
    cout<<"Enter Grade"<<endl;
    cin>>x;
    if ((x=='A')||(x=='a'))
    cout<<"The marks are 10"<<endl;
    if ((x=='B')||(x=='c'))
    cout<<"The marks are 8"<<endl;
    if ((x=='C')||(x=='b'))
    cout<<"The marks are 6"<<endl;
    if ((x=='D')||(x=='d'))
    cout<<"The marks are 5"<<endl;
    if ((x=='F')||(x=='f'))
    cout<<"The marks are 0"<<endl;
    if ((x!= 'A')||(x=! 'B')||(x=! 'C')||(x=! 'D')||(x=! 'F')||(x=! 'a')||(x=! 'b')||(x=! 'c')||(x=! 'd')||(x=! 'f'))
    cout<<"Wrong grade Entered"<<endl;
    
    system("PAUSE");
    
    return 0;
}

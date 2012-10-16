#include <iostream>

using namespace std;

int main()
{
    cout<<"Grading Program"<<endl<<endl;
    float x;
    cout<<"Enter marks"<<endl;
    cin>>x;
    if (x==10)
    cout<<"The grade is A"<<endl;
    if ((x>=8)&&(x<10))
    cout<<"The grade is B"<<endl;
    if ((x>=6)&&(x<8))
    cout<<"The grade is C"<<endl;
    if ((x>=5)&&(x<6))
    cout<<"The grade is D"<<endl;
    if ((x>=0)&&(x<5))
    cout<<"The grade is F"<<endl;
    if ((x<0)||(x>10))
    cout<<"Wrong Marks Entered"<<endl;
    
    system("PAUSE");
    
    return 0;
}

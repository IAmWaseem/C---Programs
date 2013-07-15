
#include <iostream>
#include <conio.h>
using namespace std;
struct Fraction 
{
    int numerator,denominator;
};

int main() 
{
    Fraction fract1, fract2;
    char operation;
    cout<< "Enter first fraction numerator : "<<endl;
    cin>>fract1.numerator;
    cout<< "/ "<<endl;
    cin>>fract1.denominator;
    cout<< "Enter Operand : ";
    cin>>operation;
    cout<< "Enter second fraction numerator : "<<endl;
    cin>>fract2.numerator;
	cout<< "/ "<<endl;
    cin>>fract2.denominator;
    switch(operation) 
	{
        case '+':
            cout<<"Answer is : " <<(fract1.numerator * fract2.denominator + fract1.denominator * fract2.numerator)<<"/"<<(fract1.denominator * fract2.denominator);
            break;
        case '-':
            cout<<"Answer is : " <<(fract1.numerator * fract2.denominator - fract1.denominator * fract2.numerator)<<"/"<<(fract1.denominator * fract2.denominator);
            break;
        case '*':
            cout<<"Answer is : " <<(fract1.numerator * fract2.numerator)<<"/"<<(fract1.denominator * fract2.denominator);
            break;
        case '/':
            cout<<"Answer is : " <<(fract1.numerator * fract2.denominator)<<"/"<<(fract1.denominator * fract2.numerator);
            break;
        default:
            cout<<"Wrong operand";
            break;
    }
    getch();
    return 0;
}
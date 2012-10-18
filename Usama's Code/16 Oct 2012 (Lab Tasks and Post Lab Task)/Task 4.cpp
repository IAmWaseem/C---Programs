#include <iostream>

using namespace std;

int main()
{
    cout<<"Age Comparison Program"<<endl<<endl;
    int x,y;
    cout<<"Enter age of First Person"<<endl;
    cin>>x;
    cout<<"Enter age of Second Person"<<endl;
    cin>>y;
    cout<<endl<<endl;
    cout<<"The greater age is: ";
    cout<<(x>y? x : y);
    cout<<endl;
    
    system("PAUSE");
    
    return 0;
}

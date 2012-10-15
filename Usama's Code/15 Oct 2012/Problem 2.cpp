#include<iostream>
#include<math.h>
//math.h is needed for using mathematical formulae

using namespace std;

int main()
{
	float u,v,a,b;		
    /*Floats are used so that decimal values can be used and obtained
	Default value of angles will be in radians
    where x and y are R.H.S and L.H.S respectively*/
    
	cout<<"Enter First Angle: ";
	cin>>u;
    cout<<endl;
	cout<<"Enter Second Angle: ";
	cin>>v;
    cout<<endl;
	//1st Equation formula and output
    a = pow(sin(u),2);    
	b = (1-cos(2*u))/2;
    cout<<"1st Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//2nd Equation formula and output
	a=pow(cos(u),2);
	b=(1+cos(2*u))/2;
	cout<<"2nd Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//3rd Equation formula and output
	a=pow(tan(u),2);
	b=(1-cos(2*u))/(1+cos(2*u));
	cout<<"3rd Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//4th Equation formula and output
	a=sin(u)+sin(v);
	b=2*sin((u+v)/2)*cos((u-v)/2);
	cout<<"4th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//5th Equation formula and output
	a=sin(u)-sin(v);
	b=2*cos((u+v)/2)*sin((u-v)/2);
	cout<<"5th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//6th Equation formula and output
	a=cos(u)+cos(v);
	b=2*cos((u+v)/2)*cos((u-v)/2);
	cout<<"6th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//7th Equation formula and output
	a=cos(u)-cos(v);
	b=-2*sin((u+v)/2)*sin((u-v)/2);
	cout<<"7th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//8th Equation formula and output
	a=sin(u)*sin(v);
	b=(cos(u-v)-cos(u+v))/2;
	cout<<"8th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//9th Equation formula and output
	a=cos(u)*cos(v);
	b=(cos(u-v)+cos(u+v))/2;
	cout<<"9th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	//10th Equation formula and output
	a=sin(u)*cos(v);
	b=(sin(u+v)+sin(u-v))/2;
	cout<<"10th Equation-> Left hand Side is: "<<a<<" and Right Hand Side is: "<<b<<endl<<endl;
	// Ending...
	
	system("PAUSE");
	
    return 0;
}


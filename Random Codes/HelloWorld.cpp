# include <iostream>
# include <conio.h> 
# include <math.h>

using namespace std;

int main()

{  float u,v;

  cout << " enter first angle:";
  cin  >> u ;
 
  cout <<"\n";

  cout << " enter second angle:";
  cin  >> v ;
 
  cout<<"\n1st Equation-> Left Hand Side is:"<<pow(sin(u),2)<<" and Right Hand Side is:"<<(1-cos(2*u))/2<<endl; 
  
  cout<<"\n2nd Equation-> Left Hand Side is:"<<pow(cos(u),2)<<" and Right Hand Side is:"<<(1+cos(2*u))/2<<endl; 
  
  cout<<"\n3rd Equation-> Left Hand Side is:"<<pow(tan(u),2)<<" and Right Hand Side is:"<<(1-cos(2*u))/(1+cos(2*u))<<endl; 
  
  cout<<"\n4th Equation-> Left Hand Side is:"<<sin(u)+sin(v)<<" and Right Hand Side is:"<<2*sin((u+v)/2)*cos((u-v)/2)<<endl; 
  
  cout<<"\n5th Equation-> Left Hand Side is:"<<sin(u)-sin(v)<<" and Right Hand Side is:"<<2*cos((u+v)/2)*sin((u-v)/2)<<endl; 
  
  cout<<"\n6th Equation-> Left Hand Side is:"<<cos(u)+cos(v)<<" and Right Hand Side is:"<<2*cos((u+v)/2)*cos((u-v)/2)<<endl; 
  
  cout<<"\n7th Equation-> Left Hand Side is:"<<cos(u)-cos(v)<<" and Right Hand Side is:"<<-2*sin((u+v)/2)*sin((u-v)/2)<<endl; 
  
  cout<<"\n8th Equation-> Left Hand Side is:"<<sin(u)*sin(v)<<" and Right Hand Side is:"<<0.5*(cos(u-v)-cos(u+v))<<endl; 
  
  cout<<"\n9th Equation-> Left Hand Side is:"<<cos(u)*cos(v)<<" and Right Hand Side is:"<<0.5*(cos(u-v)+cos(u+v))<<endl; 
  
  cout<<"\n10th Equation-> Left Hand Side is:"<<sin(u)*cos(v)<<" and Right Hand Side is:"<<0.5*(sin(u-v)+sin(u+v))<<endl; 
  getch();  
  return 0;

}

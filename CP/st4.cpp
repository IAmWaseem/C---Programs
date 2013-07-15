#include<iostream>
using namespace std;
struct employee
{
	int Emp_no, basic_pay, house_rent, medical_allow, conveyance_allow, net_pay;
};
int main()
{
	int val1,val2,val3;
	employee emp;
	cout<<"Enter employee number: ";
	cin>>emp.Emp_no;
	cout<<"Enter basic pay: ";
	cin>>emp.basic_pay;
	emp.house_rent=(45*emp.basic_pay) / 100;
	emp.medical_allow=(5*emp.basic_pay) / 100;
	emp.conveyance_allow=(10*emp.basic_pay) / 100;
	emp.net_pay = emp.basic_pay + emp.house_rent + emp.conveyance_allow + emp.medical_allow;
	cout<<"basic pay: "<<emp.basic_pay<<endl;
	cout<<"House rent: "<<emp.house_rent<<endl;
	cout<<"Medical allowance: "<<emp.medical_allow<<endl;
	cout<<"Conveyance allow : "<<emp.conveyance_allow<<endl;
	cout<<endl;
	cout<<"Net pay : "<<emp.net_pay<<endl;
}
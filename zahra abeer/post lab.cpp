#include <iostream.h>
void main()
{
	long double vp,dp,months; //vp=vehicle price,dp=down payment,months=installment months
	long double pa,npa,mi,ir; //pa=payable amount,npa=new payable amount,mi=monthly installment,ir=interest rate;
	
	cout<<"What is the total cost of car:"<<endl;
	cin>>vp;
    
	cout<<"What is the down payment:"<<endl;
	cin>>dp;

	cout<<"For how much months you want to lease a car:"<<endl;
	cin>>months;

	pa=vp-dp;

	if(months<=12)
		ir=0.10;
	
	if((months>12) && (months<=24))
		ir=0.15;
	
	if((months>24) && (months<=36))
		ir=0.20;
	
	if((months>36) && (months<=48))
		ir=0.25;
	
	if((months>48) && (months<=60))
		ir=0.30;

	npa=(pa+(pa*ir));
	mi=npa/months;

	cout<<"Per month installment is:"<<mi<<endl;

}
	

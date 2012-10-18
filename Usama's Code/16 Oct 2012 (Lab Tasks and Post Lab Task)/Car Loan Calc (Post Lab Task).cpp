#include <iostream>

using namespace std;

int main()
{
    //defining variables
    float tcost; //total cost
    float dwnpmnt; //down payment
    float tinst; //total installments
    float minst; //monthly installment
    float payblamnt; //payable amount
    float npayblamnt; //new payable amount
    float intrt; //interest rate


    
    cout<<"---------- Car Loan Calculator ----------"<<endl<<endl; //program name
    
    cout<<"What is the total Cost of Car: ";
                cin>>tcost;  //asking for total cost of car
                cout<<endl<<endl;
                
    cout<<"What is the Down Payment: ";
                cin>>dwnpmnt;  //asking for downpayment amount
                cout<<endl<<endl;
                
    cout<<"For how many months do you want to Lease a Car: ";
               cin>>tinst;   //asking for number of installment months
               cout<<endl<<endl;    


    //defining interest rates for different groups of installment periods

    if (tinst<= 12)
        intrt = 0.1;
    
    else if ((tinst>12)&&(tinst<=24))
        intrt = 0.15;
    
    else if ((tinst>24)&&(tinst<=36))
        intrt = 0.2;
    
    else if ((tinst>36)&&(tinst<=48))
        intrt = 0.25;
    
    else if ((tinst>48)&&(tinst<=60))
        intrt = 0.3;


               
    //formulae used for calculation           
    payblamnt = tcost - dwnpmnt;      //formula for calculating payable amount
    npayblamnt = payblamnt + (payblamnt*intrt);       //formula for calculating new payble amount
    minst = npayblamnt/tinst;          //formula for calculating monthly installment amount



    //final results printed
    cout<<"Per Month Installment is: "<<minst<<endl<<endl;
    
    system("PAUSE");
    
    return 0;
}

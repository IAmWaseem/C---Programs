// NAME   : SIDRA TARIQ //
// ROLLNO : i110104//




#include<iostream>
using namespace std;
using std::endl;
using std::cout;

class complex
{

private:


	

double r;
double i;



public:


   	complex();
	~complex();
	complex(double );
	complex(double , double );
//	complex(complex);
	complex add(complex , complex);
	complex subtract(complex , complex);
	complex multiply(complex , complex);
//	complex divide(complex c);
	void print();
	void getdata(complex x);
	int getreal();
	int getimag();
	void setreal(double , double);
	void setimag(double , double);


};

complex ::~complex()
{
	cout<<"\nMemory Dealocated";
}
complex::complex() //default constructor//
{

i=0;
r=0;

}

complex::complex(double x) //overloaded constructor//
{
	
 r=x;
 i=0;

}

	
complex::complex(double x , double y) //overloaded constructor that sets real to r and imag to i//
{
	
 r=x;
 i=y;

}

/*complex::complex(complex obj) //copy constructor//
{
	r=obj.r;
	i=obj.i;
}*/

complex complex::add(complex obj1, complex obj2) //adding real and imaginary part//
{
r=obj1.r+obj2.r;
i=obj1.i+obj2.i;
return r,i;
}

complex complex::subtract(complex obj1, complex obj2) // subtracting real and imaginary part//
{
r=obj1.r-obj2.r;
i=obj1.i-obj2.i;
return r,i;
	
}



/*void complex::operator /(complex c) //dividing real and imaginary part//
{


}*/

complex complex::multiply(complex obj1, complex obj2) //multiply complex and imaginary part//
{
obj1.r=obj1.r*obj2.r+obj1.r*obj2.i;
obj1.i=obj1.i*obj2.r+obj1.i*obj2.i;
obj2.r=obj2.r*obj1.r+obj1.r*obj2.i;
obj2.i=obj2.i*obj1.r+obj2.i*obj1.i;
r=obj1.r+obj2.r;
i=obj1.i+obj2.i;
cout<<r<<" + "<<i<<" i"<<endl;
	return r,i;
	
}

void complex::print()
{
	cout<<r<<" + "<<i<<" i"<<endl;
}

void complex::getdata(complex x)
{

cout<<"enter real part of first number"<<endl;
	cin>>r;

		cout<<"enter imaginary part of first number"<<endl;
	cin>>i;

cout<<"enter real part of second number"<<endl;
	cin>>x.r;

		cout<<"enter imaginary part of second number"<<endl;
	cin>>x.i;
	

}

int complex::getreal()
{
	return r;
}


int complex::getimag()
{
 
	return i;
	
}

void complex::setreal(double x , double y)
{
	r=x;
	i=y;
}

void complex::setimag(double x , double y)
{
	r=x;
	i=y;
}


void main()
{



	complex number1,number2,result;
	number1.getdata(number2);

	
		cout<<"THE SUM IS : "<<endl;
		result.add(number1,number2);

	
		cout<<" THE DIFFERENCE IS : "<<endl;
        result.subtract(number1,number2);
	
		cout<<" THE MULTIPLICATION IS : "<<endl;
		result.multiply(number1,number2);
/*	result.divide()
		cout<<" THE DIVISION IS : "<<result.divide<<endl;*/
}



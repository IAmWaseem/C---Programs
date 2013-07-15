#include<iostream>
using namespace std;
  

class complex
{
	double real;
	double imag;

public:
	complex()
	{
		real=0;
		imag=0;
	}


	complex(double r)
	{
		real=r;
		imag=0;
	}


	complex(double r , double i )
	{
		real=r;
		imag=i;
	}

	complex(complex &c)
	{
		real=c.real;
		imag=c.imag;
	}
	void setter(double r , double i);
	complex complex_add(complex c );
	complex complex_subtract(complex c);
	complex complex_multiply(complex c);
	complex complex_divide(complex c);
	void conjugate (complex c);
	void display();
	complex operator+ (complex &c);

};


void complex::setter(double r, double i)
{
	real=r;
	imag=i;
}

complex complex::complex_add(complex c)
{
	complex send;
	send.real = real + c.real;
	send.imag = imag + c.imag;
	return send;
}

complex complex::complex_subtract(complex c)
{
	complex send;
	send.real = real + c.real;
	send.imag = -1*(imag + c.real);
	return send;
}



complex complex::complex_multiply(complex c )
{
	complex send;
	send.real = real *c.real + imag*c.imag;
	send.imag = real *c.imag + c.real*imag;
	return send;
}

void complex::conjugate(complex c)
{
	imag=imag*-1;
}






void complex::display()
{
	if(imag > 0)
	cout << real << " + " << imag << "i " << endl;
	else
	cout << real << " - " << imag << "i " <<endl;
}





int main()
{
			complex obj1,obj2,temp;
			double r , i, r2, i2;
			int choice;

			


				cout<<"Enter first real number\n";
				cin>>r;
				cout<<"Enter first imaginary number\n";
				cin>>i;
				cout<<endl<<endl;

				obj1.setter(r,i);


				cout<<"Enter second real number\n";
				cout<<r2;
				cout<<"Enter second imaginary number\n";
				cout<<i2;

				obj2.setter(r2,i2);


				cout<<"Press 1 to add\n"
					<<"Press 2 to dispaly\n";
				cin>>choice;





			switch(choice)
			{
			case 1:
				{
					temp=obj1.complex_add(obj2);
					temp.display();
					break;
				}
			default:
				{
					cout<<"Invalid case";
					break;
				}
			}
}





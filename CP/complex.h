#ifndef COMPLEX_H
#define COMPLEX_H
class complex
{
	double real;
	double img;
public:
	complex();
	complex(double );
	complex(double,double);
	complex add(complex);
	complex subtract(complex);
	complex multiply(complex);
	complex division(complex);
	void print();
	void setreal(double);
	void setimg(double);
	double getreal();
	double getimg();
};
#endif
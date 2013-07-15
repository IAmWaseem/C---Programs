// Classes

#include<iostream>
#include<conio.h>

using namespace std;

class volume
{
private:
		int length;
		int height;
		int width;
		char *name;
	
public:
		volume();
		volume(int,int,int,char *);
		void setlength(int);
		void setheight(int);
		void setwidth(int);
		void setname(char *);
		void setall(int,int,int,char *);
		int getlength();
		int getheight();
		int getwidth();
		//int getall();
		int cal_vol();
		~volume();
};




int main()
{
	volume v1 , v2;
	volume v3(3,3,3,"Square");
	volume v4(7,6,4,"Area_1");
	//cout<<v3.getall();
	cout<<v3.getheight()<<endl
		<<v3.getlength()<<endl
		<<v3.getwidth()<<endl;

	
	getch();
	
}







volume::volume()
{
	length=0;
	width=0;
	height=0;
	name=0;
}

volume::volume(int a, int b , int c ,  char *n)
{
	length=a;
	width=b;
	height=c;
	name=new char [sizeof(n)+1];
	strcpy(name,n);
}

void volume::setlength(int a)
{
	length=a;
}

void volume::setwidth(int b)
{
	width=b;
}

void volume::setheight(int c)
{
	height=c;
}

void volume::setname(char *n)
{
	name=new char [sizeof(n)+1];
	strcpy(name,n);
}

void volume::setall(int a, int b , int c ,  char *n)
{
	length=a;
	width=b;
	height=c;
	name=new char [sizeof(n)+1];
	strcpy(name,n);
}

int volume::getlength()
{
	return length;
}

int volume::getwidth()
{
	return width;
}

int volume::getheight()
{
	return height;
}

/*char volume::
{
	return name;
}*/

/*void volume::getall()
{
	cout<<"Length : "<<length<<endl
		<<"Width  : "<<width<<endl
		<<"Height : "<<height<<endl
		<<"Name   : "<<name<<endl
		<<endl;
}*/

int volume::cal_vol()
{
	return (length * width * height);
}

volume::~volume()
{
	delete []name;
}
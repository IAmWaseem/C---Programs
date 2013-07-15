#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
struct student
{ 
	int roll_no;
	char name[20],city[20];
	int phone;
	int subjects_numbers[3];
};
int main()
{
	int number, size;
	student *std1;
	student std[100];
	int j = 0;
	cout<<"Enter size : ";
	cin>>size;
	std1=new student[size];

MENU:
	cout<<"Press 1 to enter new student data."<<endl;
	cout<<"Press 2 to view all students data."<<endl;
	cout<<"Press 3 to search a student data by rollno and display its information."<<endl;
	cout<<"Press 4 to make a duplicate of student data by rollno and enter new rollno for the duplicate entry."<<endl;
	cout<<"Press 5 to EXIT program."<<endl;
	cout<<"ENTER NUMBER: ";
	cin>>number;
	switch(number)
	{
	case 1:
		{
			cout<<"Enter roll number?"<<endl;
			cin>>std[j].roll_no;
			cout<<"Enter name of student?"<<endl;
			cin>>std[j].name;
			cout<<"Enter name of city of student?"<<endl;
			cin>>std[j].city;
			cout<<"Enter phone of student?"<<endl;
			cin>>std[j].phone;
			cout<<"Enter subjects of student?"<<endl;
			for(int k=0;k<3;k++)
			{
				cin>>std[j].subjects_numbers[k];
				cout<<endl;
			}
			cout<<endl;
			cout<<"Roll no. : "<<std[j].roll_no<<endl;
			cout<<"Name: "<<std[j].name<<endl;
			cout<<"City: "<<std[j].city<<endl;
			cout<<"Phone: "<<std[j].phone<<endl;
			for(int k=0;k<3;k++)
			{
				cout<<"SUBJECTS:"<<std[j].subjects_numbers[k];
				cout<<endl;
			}
			j++;
			goto MENU;
		}
	case 2:
		{
			for(int i=0;i<j;i++)
			{
				cout<<"Roll no. : "<<std[i].roll_no<<endl;
				cout<<"Name: "<<std[i].name<<endl;
				cout<<"City: "<<std[i].city<<endl;
				cout<<"Phone: "<<std[i].phone<<endl;
				for(int k=0;k<3;k++)
				{
					cout << "SUBJECT MARKS : " << std[i].subjects_numbers[k];	
					cout<<endl;													
				}																
			}
			goto MENU;

		}
	case 3:
		{
			int rollno;
			int check = 0;
			cout<<"Enter roll number: ";
			cin>>rollno;
			for(int i=0;i<j;i++)								
			{
				if(std[i].roll_no==rollno)
				{
					cout<<"Roll no. : "<<std[i].roll_no<<endl;
					cout<<"Name: "<<std[i].name<<endl;
					cout<<"City: "<<std[i].city<<endl;
					cout<<"Phone: "<<std[i].phone<<endl;
					for(int k=0;k<3;k++)
					{
						cout<<"SUBJECTS:"<<std[i].subjects_numbers[k];
						cout<<endl;
					}
					check = 1;
				}
			}
			if(!check)											
			{
				cout << "Not Found" << endl;
			}
			goto MENU;
		}
	case 4:
		{
			int Roll_No;
			cout << "Enter Roll Number of the Source Student : ";
			cin >> Roll_No;
			for(int i = 0; i < j; i++) 
			{
				if(std[i].roll_no == Roll_No)
				{
					strcpy(std[j].city, std[i].city);
					strcpy(std[j].name, std[i].name);
					std[j].phone = std[i].phone;
					std[j].subjects_numbers[0] = std[i].subjects_numbers[0];
					std[j].subjects_numbers[1] = std[i].subjects_numbers[1];
					std[j].subjects_numbers[2] = std[i].subjects_numbers[2];
					cout << "Enter New Roll Number : ";	
					cin >> Roll_No;						
					std[j].roll_no = Roll_No;
					j++;							// You Forgot this
					break;							// and this
				}									
				cout<<"Roll no. : "<<std[j].roll_no<<endl;
				cout<<"Name: "<<std[j].name<<endl;
				cout<<"City: "<<std[j].city<<endl;
				cout<<"Phone: "<<std[j].phone<<endl;
				for(int k=0;k<3;k++)
				{
					cout << "SUBJECT MARKS : " << std[j].subjects_numbers[k];	
					cout<<endl;													
				}																
			}
			goto MENU;								// And also this
			break;
		}
	case 5:
		{
			cout<<"EXIT program";
			(EXIT_SUCCESS);
		}
	}

	getch();
	return 0;
}
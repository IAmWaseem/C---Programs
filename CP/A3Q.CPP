//Danish Muhammad Arif
//i12-0235
// Question 2

#include<iostream>
#include<conio.h>
#include<math.h>
#include<windows.h>

using namespace std;

class AM
{
private:
	int size;
	int *a;
	int count;

public:
	AM(int);
	void Insert(int);
	void Insertat(int,int);
	void Remove(int);
	void Removeat(int);
	void At(int);
	void SortA();
	void SortD();
	void Swap(int,int);
	void Reverse();
	void DMin();
	void DMax();
	void Display();
	void DMean();
	void IsEmpty();
	void IsFull();
	void Total();
	~AM();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int choice,size;
	cout<<"Enter The Size of The Array : ";
	cin>>size;
	cout<<endl<<endl;

	AM Z(size);
	
menu:
	cout<<"----------------------------------\n"
		<<"Enter Chocie\n"
		<<"1. Insert\n"
		<<"2. Insert at a Location\n"
		<<"3. Remove\n"
		<<"4. Remove at a Location\n"
		<<"5. Print on a Specified Location\n"
		<<"6. Sort Ascending\n"
		<<"7. Sort Descending\n"
		<<"8. Swap\n"
		<<"9. Reverse\n"
		<<"10. "
		<<"0. Exit\n"
		<<"----------------------------------\n\n";
	
	cin>>choice;
	if (choice !=0)
	{
		switch(choice)
		{
		case 1:
			{
			
				cout<<endl;
				
				getch();
				system("cls");
				goto menu;
			}
			
		case 2:
			{
			
				cout<<endl;
				
				getch();
				system("cls");
				goto menu;
			}
			
		case 3:
			{
				
				cout<<endl;
				
				getch();
				system("cls");
				goto menu;
			}
			
		case 4:
			{
			
				cout<<endl;
				
				getch();
				system("cls");
				goto menu;
			}
			
		case 5:
			{
			
				getch();
				system("cls");
				goto menu;
			}
			
		case 6:
			{
			
				getch();
				system("cls");
				goto menu;
			}
			
		case 7:
			{
				
				getch();
				system("cls");
				goto menu;
			}
			
		case 8:
			{
			
				getch();
				system("cls");
				goto menu;
			}
			
		case 9:
			{
				
				
				getch();
				system("cls");
				goto menu;
			}

		case 10:
			{
				cout<<"no problemo\n";
				getch();
				system("cls");
				goto menu;
			}
			
		default :
			{
				cout<<"Wrong Choice Entered\n\n";
				
				getch();
				system("cls");
				goto menu;
			}
			
		}
	}	
	else
	{
		
		getch();
		
		return 0;
	}
	
	
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


AM::AM(int a)
{
	size=a;
	a = new int [size];
	count=0;
}

void AM::Insert(int a)
{
	if (count != size)
	{
		a[count]=a;
		count++;
	}

	else
	{
		cout<<"a is Full\n";
	}
}

void AM::Insertat(int a,int b)
{
	//int temp;
	if (count<(size-1))
	{
		a[count+1]=a[count];

		for(int i=count; i>a ; i--)
		{
			a[i]=a[i-1];
		}

		a[a]=b;
	}

	else 
	{
		cout<<"a is Full\n\";
	}
}

void AM::Remove(int a)
{
	for(int i=0; i<count ; i++)
	{
		if(a[i]==a)
		{
			a[i]=a[i+1];
			count--;
		}
	}

	
}

void AM::Removeat(int a)
{
	for (int i=a ; i<count ; i++)
	{
		a[i]=a[i+1];
	}

	count--;
}

void AM::At(int a)
{
	cout<<"Number : "<<a[a]<<endl;
}

void AM::SortA()
{
	int temp;
	for(int i=0 ; i<count ; i++)
	{
		if(a[i]>a[i+1])
		{
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
		}
	}
}

void AM::SortD()
{
	int temp;
	for (int i=0 ; i<count ; i++)
	{
		if(a[i]<a[i+1])
		{
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
		}
	}
}

void AM::Swap(int a, int b)
{
	int temp;

	temp=a[a];
	a[a]=a[b];
	a[b]=temp;

}

void AM::Reverse()
{
	int temp;

	for (int i=0,j=count ; i<(count/2) ; i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}

void AM::DMin()
{
	int temp=1000;
	for (int i=0; i<count ; i++)
	{
		if(a[i]<temp)
			temp=a[i];
	}
	cout<<"Minimum Number : "<<temp<<endl;
}

void AM::DMax()
{
	int temp=0;
	for (int i=0; i<count ; i++)
	{
		if(a[i]>temp)
			temp=a[i];
	}
	cout<<"Maximum Number : "<<temp<<endl;
}


void AM::Display()
{
	for(int i=0;i<count;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void AM::DMean()
{
	int mean=0;

	for(int i=0 ; i<count ; i++)
	{
		mean+=a[i];
	}
	mean/=count;

	cout<<"Mean : "<<mean<<endl;
}

void AM::IsEmpty()
{
	if(count==0)
		cout<<"Array is Empty\n";

}

void AM::IsFull()
{
	if (count==size)
		cout<<"Array is Full\n";
}

void AM::Total()
{
	cout<<"Total Elements : "<<count<<endl;
}

AM::~AM()
{
	delete []a;
	cout<<"deleted"<<endl
}
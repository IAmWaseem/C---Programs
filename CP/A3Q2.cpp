#include<iostream>
#include<conio.h>
#include<cmath>
#include"Header.h"
using namespace std;
Array::Array(int a,int b):size(a)
{
	array1=new int[size];
	total_num=b;
}
void Array::insert()
{
	int num;
	cout<<"Enter elements of array: "<<endl;
	cin>>num;
	array1[total_num]=num;
	total_num++;
}
void Array::insertat(int index)
{
	int num;
	cout<<"Enter number : ";
	cin>>num;
	for(int i=index;i<total_num;i++)
	{
		array1[i+1]=array1[i];
	}
	array1[index]=num;
	total_num++;
}
void Array::remove(int index)
{
	for(int i=0;i<total_num;i++)
	{
		if(array1[i]==index)
		{
			for(int j = i; j < total_num; j++) 
			{
				array1[j] = array1[j+1];
			}
			total_num--;
		}
	}
	for(int i=0;i<total_num;i++)
	{
		cout<<array1[i]<<endl;
	}
}
void Array::removeat(int index)
{
	for(int i=index-1;i<total_num-1;i++)
	{
		array1[i+1]=array1[i+2];
	}
	total_num--;
	for(int i=0;i<size;i++)
	{
		cout<<array1[i]<<endl;
	}
}
void Array::at(int index)
{
	cout<<"Value at "<<index<<" is "<<array1[index]<<endl;
}
void Array::sortasc()
{
	for(int i=0;i<total_num;i++)
	{
		for(int j=0;j<total_num-1-i;j++)
	    {
         if(array1[j]>array1[j+1])
		 {
			 int temp=array1[j+1];
			 array1[j+1]=array1[j];
			 array1[j]=temp;
		 }
	    }
	}
	for(int i=0;i<total_num;i++)
	{
		cout<<array1[i]<<endl;
	}
}
void Array::sortdec()
{
	for(int i=0;i<total_num;i++)
	{
		for(int j=0;j<total_num-1-i;j++)
	    {
         if(array1[j]<array1[j+1])
		 {
			 int temp=array1[j+1];
			 array1[j+1]=array1[j];
			 array1[j]=temp;
		 }
	    }
	}
	for(int i=0;i<total_num;i++)
	{
		cout<<array1[i]<<endl;
	}
}
void Array::swap(int index,int index1)
{
	cout<<array1[index]<<" "<<array1[index1]<<endl;
	int temp=array1[index1];
	array1[index1]=array1[index];
	array1[index]=temp;
	cout<<"After swaping "<<endl;
	cout<<array1[index]<<" "<<array1[index1];
}
void Array::reverse()
{
	for(int i=0;i<total_num;i++)
	{
		for(int j=total_num-1;j>=0;j--)
	    {
			 int temp=array1[j];
			 array1[j]=array1[i];
			 array1[i]=temp;
	    }
	}
	for(int i=0;i<total_num;i++)
	{
		cout<<array1[i]<<endl;
	}
}
void Array::display()
{
	for(int i=0;i<total_num;i++)
	{
		cout<<array1[i]<<endl;
	}
}
void Array::displaymin()
{
	int min=array1[0];
	for(int i=0;i<total_num;i++)
	{
		if(min>array1[i])
		{
			min=array1[i];
		}
	}
	cout<<"Minimum value = " <<min<<endl;
}
void Array::displaymax()
{
	int max=array1[0];
	for(int i=0;i<total_num;i++)
	{
		if(max<array1[i])
		{
			max=array1[i];
		}
	}
	cout<<"Maximum value = " <<max<<endl;
}
void Array::mean()
{
	int total=0,mean;
	for(int i=0;i<total_num;i++)
	{
		total=total+array1[i];
	}
	mean=total/total_num;
	cout<<"\nMean = " <<mean<<endl;
}
void Array::std()
{
	int total=0;
	double mean,total1=0,std;
	for(int i=0;i<total_num;i++)
	{
		total=total+array1[i];
	}
	mean=total/total_num;
	for(int i=0;i<total_num;i++)
	{
		total1=total1+((array1[i]-mean)*(array1[i]-mean));
	}
	std=sqrt(total1/8);

	cout<<"\nStandard deviation  = " <<std<<endl;
}
bool Array::isfull()
{
	if(total_num==size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Array::isempty()
{
	if(total_num<size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Array:: ~Array()
{
	delete []array1;
}
void Array::totalelements()
{
	cout<<"Total numbers of element: " <<total_num;
}
int main() 
{
	int size;
	cout<<"Enter size of array:  ";
	cin>>size;
	Array a1(size,0);
	int choice;
menu:
	cout<<endl;
	cout<<"Press 1 to insert ."<<endl;
	cout<<"Press 2 to insert at specific offset."<<endl;
	cout<<"Press 3 to remove ."<<endl;
	cout<<"Press 4 to remove at specific offset."<<endl;
	cout<<"Press 5 to display element stored at a specified offset."<<endl;
	cout<<"Press 6 to sort in ascending order."<<endl;
	cout<<"Press 7 to sort in descending order."<<endl;
	cout<<"Press 8 to swap two positions."<<endl;
	cout<<"Press 9 to Reverse the contents of the array."<<endl;
	cout<<"Press 10 to Display the minimum of the contents in the array.."<<endl;
	cout<<"Press 11 to Display the max of the contents in the array. ."<<endl;
	cout<<"Press 12 to Display the standard deviation."<<endl;
	cout<<"Press 13 to diplay."<<endl;
	cout<<"Press 14 to Display the arithmetic mean."<<endl;
	cout<<"Press 15 to Display total number of elements."<<endl;
	cout<<"Press 16 to display if array is full."<<endl;
	cout<<"Press 17 to display if array is empty."<<endl;
	cout<<"Press 18 to exit."<<endl;
	cout<<endl;
	cout<<"Enter choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		{
			a1.insert();
		}
		goto menu;
		break;
	case 2:
		{
			int index;
			cout<<"Enter index: "; 
			cin>>index;
			a1.insertat(index);
		}
		goto menu;
		break;
	case 3:
		{
			int index;
			cout<<"Enter number to be removed: "; 
			cin>>index;
			a1.remove(index);
		}
		goto menu;
		break;
	case 4:
		{
			int index;
			cout<<"Enter index: "; 
			cin>>index;
			a1.removeat(index);
		}
		goto menu;
		break;
	case 5:
		{
			int index;
			cout<<"Enter index: "; 
			cin>>index;
			a1.at(index);
		}
		goto menu;
		break;
	case 6:
		{
			a1.sortasc();
		}
		goto menu;
		break;
	case 7:
		{
			a1.sortdec();
		}
		goto menu;
		break;
	case 8:
		{
			int index,index1;
			cout<<"Enter first index: "; 
			cin>>index;
			cout<<"Enter second index: "; 
			cin>>index1;
			a1.swap(index,index1);
		}
		goto menu;
		break;
	
	case 9:
		{
			a1.reverse();
		}
		goto menu;
		break;
	case 10:
		{
			a1.displaymin();
		}
		goto menu;
		break;
	case 11:
		{
			a1.displaymax();
		}
		goto menu;
		break;
	case 12:
		{
			a1.std();
		}
		goto menu;
		break;
	case 13:
		{
			a1.display();
		}
		goto menu;
		break;
	case 14:
		{
			a1.mean();
		}
		goto menu;
		break;
	case 15:
		{
			a1.totalelements();
		}
		goto menu;
		break;
	case 16:
		{
			if(a1.isfull())
			{
				cout<<"\n Array is full ."<<endl;
			}
			else
				cout<<"\n Array is not full ."<<endl;
		}
		goto menu;
		break;
	case 17:
		{
			if(a1.isempty())
			{
				cout<<"\n Array is empty you can add element ."<<endl;
			}
			else
				cout<<"\n Array is not empty ."<<endl;
		}
		goto menu;
		break;
	case 18:
		{
			a1.~Array();
		}
		break;
	}
}
#include <iostream>
#include <string>
using namespace std;

int totalnoofcar = 0;

class Car
{
	
	char *make;
	char *car_model;
	char *reg_no;
	char *color;
	int year;

public:
	char * get_make()
	{
		return make;
	}
	char * get_car_model()
	{
		return car_model;
	}
	char * get_car_color()
	{
		return color;
	}
	char * get_reg_no()
	{
		return reg_no;
	}
	int  get_year()
	{
		return year;
	}
	Car();
	Car(char *,char *,char *,char *,int);
	void init(char *,char *,char *,char *,int);
	~Car();
};
class Garage
{
	//friend void display();
	char *name;
	char *index;
	int capacity;
	Car *car_name;

public:
	Garage();
	Garage(char *, char *, int);
	bool isempty();
	bool isfull();
	void pushcar();
	bool Find(char *);
	bool remove();
	void display();
	~Garage();
};

void main()
{
	Garage menu;
	Car calling;
	do
	{
	int choice;
	cout << "\n\t1.Add car in Garage.\n\t2.Remove car from a garage\n\t3.Display parked cars\n\t4.Find car\n\t5.Check if garage is full\n\t6.To exit\n\n";
	cin  >> choice;
	switch (choice)
	{
	case 1:
		char make[10],model[10],color[10],year,reg_no[10];
		cout << "You have selected to add car.Please enter the data of your car\n";
		cout << "Enter car make:\n";
			cin.getline(make,10,'\n');
			cout << endl;
			cout << "Enter car model:\n";
			cin.getline(model,10,'\n');
			cout << endl;
			cout << "Enter car colour:\n";
			cin.getline(color,10,'\n');
			cout << endl;
			cout << "Enter car registration no:\n";
			cin.getline(reg_no,10,'\n');
			cout << endl;
			cout << "Enter car year:\n";
			cin  >> year;
			cout << endl;
			calling.init(make,model,reg_no,color,year);
			break;
	case 2:
		menu.remove();
		break;
	case 3:
		menu.display();
		break;
	case 4:
		char find[20];
		cout <<"Enter the registration no you want to find\n";
		cin.getline(find,20,'\n');
		menu.Find(find);
		break;
	case 5:
		if (menu.isfull() == true)
			cout << "GARAGE IS FULL\n";
		else
			cout <<"GARAGE IS NOT FULL\n";
		break;
	case 6:
		exit(0);
		break;
	default:
		cout << "Wrong input\n";
	}
	}while(1);

}


//-------------------------------------------------Function Definitions----------------------------------------------

Car::Car()
{
	make = NULL;
	car_model = NULL;
	reg_no = NULL;
	color = NULL;
	year = 0;
	totalnoofcar++;
}

Car::Car(char *no1,char *no2,char *no3,char *no4,int no5)
{
	make = no1;
	car_model = no2;
	reg_no = no3;
	color = no4;
	year = no5;
	totalnoofcar++;
}

Car::~Car()
{

}

void Car::init(char *no1, char *no2, char *no3, char *no4 , int no5 )
{
	make = no1;
	car_model = no2;
	reg_no = no3;
	color = no4;
	year = no5;
	totalnoofcar++;
}

Garage::Garage()
{
	name = NULL;
	index = NULL;
	capacity = 0;
	car_name = NULL;
}
Garage::Garage(char *no1, char *no2, int no3)
{
	no3=10;
	name = new char [strlen(no1)+1];
	index = new char [strlen(no2)+1];
	capacity = no3;
	car_name = new Car [capacity];
}
Garage::~Garage()
{
	delete car_name;
}
bool Garage::isempty()
{
	if (totalnoofcar == NULL)
			return true;
	else
		return false;
}
bool Garage::isfull()
{
	if (totalnoofcar == capacity)
		return true;
	else 
		return false;
}
void Garage::pushcar()
{
	
	static int park = 0;
	char choice;
	do
	{
		cout << "Do you want to park the car\n\t1.Press 'y' to park\n\t2.Press 'n' to not\n\n";
		cin  >> choice;
		cout << endl;
		if (choice == 'y')
		{
			park++;
			if (park == capacity)
				break;
		}
		else
			break;
	}while (totalnoofcar != capacity);
}

bool Garage::Find(char *reg)
{
	Car calling;
	for (int i=0; i<totalnoofcar; i++)
	{
	
		if (strcmp(reg,calling.get_reg_no) == 0)
		{
			return true;
		}

		else 
			return false;
	}
	return 0;	
}
bool Garage::remove()
{
	char regno[11];
	cout << "Enter the registration no you want to delete\n";
	cin.getline(regno,11,'\n');
	cout << endl;

	for (int i=0; i<totalnoofcar; i++)
	{
		/*if (strcmp(regno,==0)
		{
			cout << "car found\n";
			//delete[] temp;
			return true;
		}
		else
			return false;*/
	}
	return 0;
}
void Garage::display()
{
	cout << "**************Details of car******************\n";
	Car display;
	for (int i=0; i < totalnoofcar; i++)
	{
		cout << "Make of car " << i+1 << "is\n";
		cout << display.get_make() <<endl;
		cout << "Model of car " << i+1 << "is\n";
		cout << display.get_car_model()<<endl;
		cout << "Registration of car " << i+1 << "is\n";
		cout << display.get_reg_no() <<endl;
		cout << "Year of car " << i+1 << "is\n";
		cout << display.get_year() <<endl;
		cout << "Colour of car " << i+1 << "is\n";
		cout << display.get_car_color() <<endl;
	}
}
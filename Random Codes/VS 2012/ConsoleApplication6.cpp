#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;

//declaring global counters and ID generators:
int carCount=0;
int carID=0;
int customersCount = 0;
int customersID = 0;
int rented_carsCount = 0;
int rental_transaction_ID = 0;
int repaircount = 0;
int repairID = 0;
int employeecount = 0;
int employeeID = 0;

//declaring enumerated datatypes:
enum Status {Free=1, Busy, Leave}; //to be used for cars and employees
enum customerStatus {OneTime=1, Member};
enum maritalStatus {Married=1, Single, Divorced}; //to be used for employees and customers
enum cardType {MasterCard=1, Visa}; //to be used for credit card typein customers
enum gender {Male=1, Female}; //to be used for employees and customers
enum repair_type {accidental_damage =1 , service, change_of_tyre, car_wash};//repair only

//declaring structures:
struct date
{
	int day;
	int month;
	int year;
};
date currentDate;

struct Cars
{
	int car_id;
	char name[20];
	unsigned int model;
	date entry_date;
	unsigned int rent;
	unsigned int fine;
	Status car_status;
};

struct Customers
{
	unsigned int customer_id;
	char first_name[25];
	char last_name[25];
	char nic[15];
	char contact_number[11];
	char address[45];
	customerStatus customer_status;
	date date_of_joining;
	unsigned int membership_fee;
	char credit_card_number[19];
	date credit_card_expiry;
	cardType card_type;//enum variable
	unsigned int validation_code;
};

struct rented_cars
{
	unsigned int rental_transaction_id;
	unsigned int customer_id;
	unsigned int car_id;
	bool choice_driver;
	date issue_date;
	unsigned int numb_days_rent;
	date return_date;
	unsigned int payment;
};

struct repair
{
	unsigned int repair_id;
	unsigned int car_id;
	repair_type repairType;
	unsigned int repair_cost;
	date repair_date;
};

struct employee
{
	unsigned int employee_id;
	char name[20];
	char designation[20];
	Status employeeStatus;
	char address[45];
	gender employeeGender;
	maritalStatus employeemstatus;
	date d_o_b;
	char contact_numb[11];
	date d_o_j;
	unsigned int salary;
	unsigned int working_days;
};

//function prototypes:
void CurrentDate(void);
void switchboard (Cars[],int, Customers[], int, rented_cars[], int, repair[],int, employee[],int);
void submenu(Cars[], int, Customers[], int, rented_cars[], int, repair[], int, employee[],int);
void incomeExpenditure (rented_cars[], int, repair[], int, Customers[], int);

//Car functions:
void AddCars(Cars[], int); //adding record
void carDelete(Cars[], int, int); // deleting record
void printCar(Cars[], int, int); //printing record
void editCar (Cars[], int, int); //editing record
int searchCarID (Cars[], int, int); //searching record by ID
int searchCarName (Cars[], int, char[], int); //searching record by name

//Customer functions:
void addCustomers(Customers[], int); //adding record
void customersDelete(Customers[], int, int); // deleting record
void printCustomers(Customers[], int, int); //printing record
void editCustomers (Customers[], int, int); //editing record
int searchCustomersID (Customers[], int, int); //searching record by ID
int searchCustomersName (Customers[], int, char[], int); //searching record by name

//Transaction functions:
void addrented_cars(rented_cars[], int, Customers[], int, Cars[], int); //adding record
void rented_carsdelete(rented_cars[], int, int); // deleting record
void printrented_cars(rented_cars[], int, int); //printing record
void editrented_cars (rented_cars[], int, int); //editing record
int searchTransactionID (rented_cars[], int, int); //searching record by ID
int searchTransactionByCar(rented_cars[], int, int, int); //searching record by car ID
int searchTransactionByCustomer(rented_cars[], int, int, int); //searching record by car ID
int searchTransactionByDate(rented_cars[], int, date, date, int); //searching record by car ID
void ReturnMakeBill (rented_cars[], int, Cars[], int);
int calculateBill (rented_cars[], int, int, Cars[], int);

//repair functions:
void addrepair(repair[], int); //adding record
void repairdelete(repair[], int,int); // deleting record
void printrepair(repair[], int,int); //printing record
void editrepair(repair[], int,int); //editing record
int searchrepairID (repair[], int, int); //searching record by ID 

//employee functions:
void addemployee(employee[], int); //adding record
void employeedelete(employee[], int,int); // deleting record
void printemployee(employee[], int,int); //printing record
void editemployee (employee[], int,int); //editing record
int searchemployeeID (employee[], int, int); //searching record by ID
int searchemployeeName (employee[], int, char[], int); //searching record by name

int main()
{
	//declaring arrays:
	const int size = 100;
	Cars arrayCars[size];
	Customers arrayCustomers[size];
	rented_cars arrayrented_cars[size];
	repair arrayrepair[size];
	employee arrayemployee[size];
	
	//Reading variables from files:
	
	//Cars:
	ifstream carinfile("car.dat",ios::binary);
    carinfile.read( ( char*)&carID, sizeof(int));
    carinfile.read( ( char*)&carCount, sizeof(int));
    carinfile.read( ( char*)arrayCars, size * sizeof(Cars));
    carinfile.close();
    
    //Customers:
   	ifstream customerinfile("customer.dat",ios::binary);
    customerinfile.read( ( char*)&customersID, sizeof(int));
    customerinfile.read( ( char*)&customersCount, sizeof(int));
    customerinfile.read( ( char*)arrayCustomers, size * sizeof(Customers));
    customerinfile.close();
    
    //Transactions:
	ifstream transactioninfile("transaction.dat",ios::binary);
    transactioninfile.read( ( char*)&rental_transaction_ID, sizeof(int));
    transactioninfile.read( ( char*)&rented_carsCount, sizeof(int));
    transactioninfile.read( ( char*)arrayrented_cars, size * sizeof(rented_cars));
    transactioninfile.close();
    
	//Employees:
	ifstream employeeinfile("employee.dat",ios::binary);
    employeeinfile.read( ( char*)&employeeID, sizeof(int));
    employeeinfile.read( ( char*)&employeecount, sizeof(int));
    employeeinfile.read( ( char*)arrayemployee, size * sizeof(employee));
    employeeinfile.close();
    
    //Repairs:
    ifstream repairinfile("repair.dat",ios::binary);
    repairinfile.read( ( char*)&repairID, sizeof(int));
    repairinfile.read( ( char*)& repaircount, sizeof(int));
    employeeinfile.read( ( char*)arrayrepair, size * sizeof(repair));
    employeeinfile.close();
	
	//initializing ID's to zero:
	//Cars:
	for (int i=carCount;i<size;i++)
	{
		arrayCars[i].car_id = 0;
	}
	//Customers:
	for (int i=customersCount;i<size;i++)
	{
		arrayCustomers[i].customer_id = 0;
	}
	//Transactions:
	for (int i=rented_carsCount;i<size;i++)
	{
		arrayrented_cars[i].rental_transaction_id = 0;
	}
	//repair:
		for (int i=repaircount;i<size;i++)
	{
		arrayrepair[i].repair_id = 0;
	}
	
	//Employees:
	for (int i=employeecount;i<size;i++)
	{
		arrayemployee[i].employee_id = 0;
	}
	//Other initializations:
	for (int i=rented_carsCount;i<size;i++)
	{
		arrayrented_cars[i].payment = 0;
		arrayrented_cars[i].return_date.day = 0;
		arrayrented_cars[i].return_date.month = 0;
		arrayrented_cars[i].return_date.year = 0;
	}
	for (int i=customersCount;i<size;i++)
	{
		arrayCustomers[i].membership_fee = 0;
	}
	for (int i=repaircount;i<size;i++)
	{
		arrayrepair[i].repair_cost = 0;
	}
	//password form
	const int password = 7;
	char myPassword[password];
	char realPassword[password] = "waseem";
	cout<<"Enter Password"<<endl;
	cin>>myPassword;
	if(strcmp(myPassword, realPassword) == 0)
	{
		//Input current date:
		CurrentDate();
		//main switchboard with further function calls
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
	}
	else
	{
	cout<<"Invalid Password\n";
	}
	
	//Writing variables to binary files:
	
	//Cars:
	ofstream caroutfile("car.dat",ios::binary);
 	caroutfile.write( ( char*)&carID, sizeof(int));
  	caroutfile.write( ( char*)&carCount, sizeof(int));
   	caroutfile.write( ( char*)arrayCars, size * sizeof(Cars));
    caroutfile.close();
    
	//Customers:
    ofstream customeroutfile("customer.dat",ios::binary);
 	customeroutfile.write( ( char*)&customersID, sizeof(int));
  	customeroutfile.write( ( char*)&customersCount, sizeof(int));
   	customeroutfile.write( ( char*)arrayCustomers, size * sizeof(Customers));
    customeroutfile.close();
	
	//Transactions:
	ofstream transactionoutfile("transaction.dat",ios::binary);
    transactionoutfile.write( ( char*)&rental_transaction_ID, sizeof(int));
    transactionoutfile.write( ( char*)&rented_carsCount, sizeof(int));
    transactionoutfile.write( ( char*)arrayrented_cars, size * sizeof(rented_cars));
    transactionoutfile.close();
    
    //Employee:
    ofstream employeeoutfile("employee.dat",ios::binary);
 	employeeoutfile.write( ( char*)&employeeID, sizeof(int));
  	employeeoutfile.write( ( char*)&employeecount, sizeof(int));
   	employeeoutfile.write( ( char*)arrayemployee, size * sizeof(employee));
    employeeoutfile.close();
    
    //repair:
    ofstream repairoutfile("repair.dat",ios::binary);
 	repairoutfile.write( ( char*)&repairID, sizeof(int));
  	repairoutfile.write( ( char*)&repaircount, sizeof(int));
   	repairoutfile.write( ( char*)arrayrepair, size * sizeof(repair));
    repairoutfile.close();
	return 0;
	
}

void CurrentDate()
{
	cout<<"Enter current date in the following format:\n";
	cout<<"<day><Press Enter><month><Press Enter><year><Press Enter>\n";
	cin>>currentDate.day>>currentDate.month>>currentDate.year;
	while (currentDate.day>31 || currentDate.day<=0)
	{
		cout<<"Invalid day. Re-enter.\n";
		cin>>currentDate.day;
	}
	while (currentDate.month>12 || currentDate.month<=0)
	{
		cout<<"Invalid month. Re-enter.\n";
		cin>>currentDate.month;
	}
	while (currentDate.year<2012)
	{
		cout<<"Invalid year. Re-enter.\n";
		cin>>currentDate.year;
	}
	cout<<"Current Date: "<<currentDate.day<<'/'<<currentDate.month<<'/'<<currentDate.year<<endl;
}

void switchboard(Cars arrayCars[], int size, Customers arrayCustomers[], int size2, rented_cars arrayrented_cars[], int size3, repair arrayrepair[],int size4, employee arrayemployee[] ,int size5)
{
	//setw parameter = 52+15 - first string length
	int selection_key;
	cout<<"Press the required key to enter the menu of your choice:\n\n";
	cout<<"Add Car"<<setfill(' ')<<setw(60)<<"Press 1"<<endl;
	cout<<"Add Customer"<<setw(55)<<"Press 2"<<endl;
	cout<<"Repair/Service Car"<<setw(49)<<"Press 3"<<endl;
	cout<<"Add Transaction"<<setw(52)<<"Press 4"<<endl;
	cout<<"Edit/View/Remove Car/Customer/Employee/Transaction/Repair"<<setw(10)<<"Press 5"<<endl;
	cout<<"Add Employee"<<setw(55)<<"Press 6"<<endl;
	cout<<"Return Car and Make Bill"<<setw(43)<<"Press 7"<<endl;
	cout<<"Income/Expenditure Reports"<<setw(41)<<"Press 8"<<endl;
	cout<<"Quit"<<setw(63)<<"Press 9"<<endl<<endl<<endl;
	cin>>selection_key;
	
	switch (selection_key)
	{
		case 1:
		AddCars(arrayCars, size);
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
		break;
	
		case 2:
		addCustomers(arrayCustomers, size);
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
		break;
	
	 	case 3:
		addrepair(arrayrepair, size);
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
	 	break;
		
		case 4:
		addrented_cars(arrayrented_cars, size, arrayCustomers, size, arrayCars, size);
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
		break;
		
		case 5:
	 	submenu(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
	 	switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
	 	break;
	
	 	case 6:
	 	addemployee (arrayemployee, size);
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
	 	break;

	 	case 7:
	 	ReturnMakeBill(arrayrented_cars, size, arrayCars, size);
	 	switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
	 	break;

	 	case 8:
	 	incomeExpenditure (arrayrented_cars, size, arrayrepair, size, arrayCustomers, size);
	 	switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);		 
		break;
		
		case 9:
		cout<<"Quitting Program\n\n";
		break;
		
		default:
		cout<<"Invalid Selection Key entered.\n"; 
		switchboard(arrayCars, size, arrayCustomers, size, arrayrented_cars, size, arrayrepair, size, arrayemployee, size);
		break;
	}
}

void submenu (Cars arrayCars[], int size, Customers arrayCustomers[], int size2, rented_cars arrayrented_cars[], int size3,repair arrayrepair[],int size4,employee arrayemployee[],int size5)
{
	int location, selection_key,selected,selected2, IDsearch, record_count=0, flag=0;
	char nameSearch[20];
	//Purpose of variables:
	//location will hold the location of the record found after searching
	//flag is to check whether or not record has been found
	//record_count holds the number of record found in searching by name,
	//because many records might have same name
	//setw parameter = 30+15 - first string length
	cout<<"Press the required key to select the option of your choice and press Enter:\n\n"<<endl;
	cout<<"Edit/View/Remove Car"<<setw(25)<<"Press 1"<<endl;
	cout<<"Edit/View/Remove Transaction"<<setw(17)<<"Press 2"<<endl;
	cout<<"Edit/View/Remove Employee"<<setw(20)<<"Press 3"<<endl;
	cout<<"Edit/View/Remove Customer"<<setw(20)<<"Press 4"<<endl;
	cout<<"Edit/View/Remove Repair Record"<<setw(15)<<"Press 5"<<endl;
	cout<<"Exit to Main Menu"<<setw(28)<<"Press 6"<<endl;
	cin>>selection_key;
	
	switch(selection_key)
	{
		case 1:
			cout<<"Search the record you wish to view, edit or remove.\n"; 
			cout<<"Press a key to select the option of your choice and press Enter.\n\n\n";
			cout<<"Search by ID"<<setw(14)<<"Press 1\n";
			cout<<"Search by Name"<<setw(12)<<"Press 2\n";
			cin>>selected;
		
			if (selected == 1)
			{
				cout<<"Enter Car ID\n";
				cin>>IDsearch;
				location = searchCarID (arrayCars, size, IDsearch);
				if (location !=-1)
				{
					printCar(arrayCars, size, location);
					cout<<endl<<endl;
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3";
					cin>>selected2;
					if (selected2 == 1)
					{
						carDelete(arrayCars, size, location);
					}
					if (selected2 == 2)
					{
						editCar (arrayCars, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				else
				{
					cout<<"No such record. Returning to main menu."<<endl;
					return;
				}
			}
		
			else if (selected == 2)
			{
				char e[20];
				cin.getline(e, 20, '\n');
				cout<<"Enter Car Name.\n";
				cin.getline(nameSearch, 20, '\n');
				for (int i=0;i<carCount;i++)
				{
					location = searchCarName(arrayCars, size, nameSearch, i);
					if (location!=-1)
					{
						printCar(arrayCars, size , location);
						cout<<endl;
						flag = 1;
						record_count++;
					}
				}
				if (record_count>1)
				{
					cout<<"Enter the record number you wish to edit/delete: ";
					cin>>location;
					location--; //because what the user sees as record n is actually
							//record n-1 in the array storage
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3";
					cin>>selected2;
					if (selected2 == 1)
					{
						carDelete(arrayCars, size, location);
					}
					if (selected2 == 2)
					{
						editCar (arrayCars, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
					else
					{
						cout<<"Invalid key pressed. Returning to main menu.\n";
						return;
					}
				}
				else
				{
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3";
					cin>>selected2;
					if (selected2 == 1)
					{
						carDelete(arrayCars, size, location);
					}
					if (selected2 == 2)
					{
						editCar (arrayCars, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
					else
					{
						cout<<"Invalid key pressed. Returning to main menu.\n";
						return;
					}
				}
				if (flag == 0)
				{
					cout<<"No such record. Returning to main menu."<<endl;
					return;
				}
			}
		
			else
			{
				cout<<"Invalid input. Returning to main menu,\n\n";
				return;
			}
			break;
		
 		case 2:
			cout<<"Press a key to select the option of your choice and press Enter\n\n";
			cout<<"Search Transaction by Transaction ID"<<setw(26)<<"Press 1\n\n"
 			<<"Search Transaction by Car ID"<<setw(20)<<"Press 2\n\n"
 			<<"Search Transaction by Customer ID"<<setw(15)<<"Press 3\n\n"
 			<<"Return to Main Menu"<<setw(31)<<"Press 4\n\n";
 			cin>>selected;
 			if (selected == 1)
 			{
  					int ID;
				 	cout<<"Enter Transaction ID: ";
 					cin>>ID;
				 	location = searchTransactionID(arrayrented_cars, size, ID);
 					if (location != -1)
 					{
 						printrented_cars(arrayrented_cars, size, location);
 						flag = 1;
 						cout<<"To delete this record, press 1.\n"
						<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
						cin>>selected2;
						if (selected2 == 1)
						{
					 		rented_carsdelete (arrayrented_cars, size, location);
						}
						if (selected2 == 2)
						{
							editrented_cars (arrayrented_cars, size, location);
						}
						if (selected2 == 3)
						{
							return;
						}
 					}
 					else
	 					{
	 						cout<<"No such record. Returning to main menu.\n";
	 						return;
	 					}
 			}
			else if (selected == 2)
			{
 					int carID;
					 record_count = 0;
					cout<<"Enter Car ID: ";
					cin>>carID;
					for (int i=0;i<rented_carsCount;i++)
					{
						int location = searchTransactionByCar(arrayrented_cars, size, carID, i);
						if (location != -1)
						{
	 						printrented_cars(arrayrented_cars, size, location);
	 						flag = 1;
	 						record_count++;
	 					}
					}
					if (record_count > 1)
					{
						cout<<"Enter the record number to delete/edit.\n";
						cin>>location;
						location--;
						cout<<"\nTo delete this record, press 1.\n"
						<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
						cin>>selected2;
						if (selected2 == 1)
						{
					 		rented_carsdelete (arrayrented_cars, size, location);
						}
						if (selected2 == 2)
						{
							editrented_cars (arrayrented_cars, size, location);
						}
						if (selected2 == 3)
						{
							return;
						}
					}
					else if (record_count == 1)
					{
						cout<<"\nTo delete this record, press 1.\n"
						<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
						cin>>selected2;
						if (selected2 == 1)
						{
					 		rented_carsdelete (arrayrented_cars, size, location);
						}
						if (selected2 == 2)
						{
							editrented_cars (arrayrented_cars, size, location);
						}
						if (selected2 == 3)
						{
							return;
						}
					}
					if (flag == 0)
					{
						cout<<"No such record. Returning to main menu.\n";
						return;
					}
				}
 			
			else if (selected == 3)
			{
 					int custID;
					 record_count = 0;
					cout<<"Enter Customer ID: ";
					cin>>custID;
					for (int i=0;i<rented_carsCount;i++)
					{
						int location = searchTransactionByCustomer(arrayrented_cars, size, custID, i);
						if (location != -1)
						{
	 						printrented_cars(arrayrented_cars, size, location);
	 						flag = 1;
	 						record_count++;
	 					}
					}
					if (record_count > 1)
					{
						cout<<"Enter the record number to delete/edit.\n";
						cin>>location;
						location--;
						cout<<"\nTo delete this record, press 1.\n"
						<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
						cin>>selected2;
						if (selected2 == 1)
						{
					 		rented_carsdelete (arrayrented_cars, size, location);
						}
						if (selected2 == 2)
						{
							editrented_cars (arrayrented_cars, size, location);
						}
						if (selected2 == 3)
						{
							return;
						}
					}
					else if (record_count == 1)
					{
						cout<<"\nTo delete this record, press 1.\n"
						<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
						cin>>selected2;
						if (selected2 == 1)
						{
					 		rented_carsdelete (arrayrented_cars, size, location);
						}
						if (selected2 == 2)
						{
							editrented_cars (arrayrented_cars, size, location);
						}
						if (selected2 == 3)
						{
							return;
						}
					}
					if (flag == 0)
					{
						cout<<"No such record. Returning to main menu.\n";
						return;
					}
 					break;
			}
			else if (selected == 4)
 					return;
			else
 			{
 					cout<<"Invalid key entered. Returning to main menu.\n\n";
 					return;
 			}
		break;
 		
 		case 3:

 			cout<<"Search the record you wish to view, edit or remove.\n"; 
			cout<<"Press a key to select the option of your choice and press Enter.\n\n\n";
			cout<<"Search by ID"<<setw(10)<<"Press 1\n";
			cout<<"Search by Name"<<setw(8)<<"Press 2\n";
			cin>>selected;
		
			if (selected == 1)
			{
				cout<<"Enter Employee ID\n";
				cin>>IDsearch;
				location = searchemployeeID (arrayemployee, size, IDsearch);
				if (location !=-1)
				{
					printemployee(arrayemployee, size, location);
					cout<<endl<<endl;
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		employeedelete (arrayemployee, size, location);
					}
					if (selected2 == 2)
					{
						editemployee (arrayemployee, size, location);
					}
				}
				else
				{
					cout<<"No such record. Returning to main menu."<<endl;
				}
			}
		
			else if (selected == 2)
			{
				
				char a[20];
				cin.getline (a, 20, '\n');
				cout<<"Enter Employee Name.\n";
				cin.getline (nameSearch, 20, '\n');
				record_count = 0;
				for (int i=0;i<employeecount;i++)
				{
						location = searchemployeeName (arrayemployee, size, nameSearch, i);
					if (location != -1)
					{
						printemployee(arrayemployee, size , location);
						cout<<endl;
						flag = 1;
						record_count++;
					}
				}
				if (record_count>1)
				{
					cout<<"Enter the record number you wish to edit/delete: ";
					cin>>location;
					location--; //because what the user sees as record n is actually
							//record n-1 in the array storage
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		employeedelete (arrayemployee, size, location);
					}
					if (selected2 == 2)
					{
						editemployee (arrayemployee, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				else if (record_count == 1)
				{
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		employeedelete (arrayemployee, size, location);
					}
					if (selected2 == 2)
					{
						editemployee (arrayemployee, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				if (flag == 0)
				{
					cout<<"No such record. Returning to main menu."<<endl;
					return;
				}
			}
			else
			{
				cout<<"Invalid input. Returning to main menu,\n\n";
				return;
			}
			break;
		
		case 4:
			cout<<"Search the record you wish to view, edit or remove.\n"; 
			cout<<"Press a key to select the option of your choice and press Enter.\n\n\n";
			cout<<"Search by ID"<<setw(12)<<"Press 1\n";
			cout<<"Search by Name"<<setw(10)<<"Press 2\n";
			cin>>selected;
		
			if (selected == 1)
			{
				cout<<"Enter Customer ID\n";
				cin>>IDsearch;
				location = searchCustomersID (arrayCustomers, size, IDsearch);
				if (location !=-1)
				{
					printCustomers(arrayCustomers, size, location);
					cout<<endl<<endl;
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		customersDelete (arrayCustomers, size, location);
					}
					if (selected2 == 2)
					{
						editCustomers (arrayCustomers, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				else
				{
					cout<<"No such record. Returning to main menu."<<endl;
					return;
				}
			}
		
			else if (selected == 2)
			{
				record_count = 0;
				cout<<"Enter Customer First Name.\n";
				cin>>nameSearch;
				for (int i=0;i<customersCount;i++)
				{
					location = searchCustomersName(arrayCustomers, size, nameSearch, i);
					if (location != -1)
					{
						printCustomers(arrayCustomers, size , location);
						cout<<endl;
						flag = 1;
						record_count++;
					}
				}
				if (record_count>1)
				{
					cout<<"Enter the record number you wish to edit/delete: ";
					cin>>location;
					location--; //because what the user sees as record n is actually
							//record n-1 in the array storage
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		customersDelete (arrayCustomers, size, location);
					}
					if (selected2 == 2)
					{
						editCustomers (arrayCustomers, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				else if (record_count == 1)
				{
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3\n";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		customersDelete (arrayCustomers, size, location);
					}
					if (selected2 == 2)
					{
						editCustomers (arrayCustomers, size, location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				if (flag == 0)
				{
					cout<<"No such record. Returning to main menu."<<endl;
					return;
				}
			}
		
			else
			{
				cout<<"Invalid input. Returning to main menu,\n\n";
				return;
			}
			break;
		
		case 5:
			cout<<"Search the record you wish to view, edit or remove.\n"; 
			cout<<"Press a key to select the option of your choice and press Enter.\n\n\n";
			cout<<"Search by ID"<<setw(10)<<"Press 1\n";
			cin>>selected;
			if (selected == 1)
			{
				cout<<"Enter Repair ID\n";
				cin>>IDsearch;	
				location = searchrepairID (arrayrepair, size, IDsearch);
				if (location !=-1)
				{
			
				 printrepair(arrayrepair, size, location);
				 	cout<<endl<<endl;
					cout<<"To delete this record, press 1.\n"
					<<"To edit this record, press 2.\nTo return to main menu, press 3";
					cin>>selected2;
					if (selected2 == 1)
					{
				 		repairdelete(arrayrepair, size,location);
					}
					if (selected2 == 2)
					{
						editrepair(arrayrepair, size,location);
					}
					if (selected2 == 3)
					{
						return;
					}
				}
				else
				{
					cout<<"No such record. Returning to main menu."<<endl;
					return;
				}
			}
			break;
		
		case 6:
			return;
			break;
		
		default:
			cout<<"Invalid selection key entered. Returning to Main Menu\n\n";
			return;
	}
}

void AddCars( Cars arrayCars[], int size)
{
	int status;
	cout<<"\n\nEntering Record number "<<carCount+1<<endl;
	arrayCars[carCount].car_id = carID + 1;
	
	char d[20];
	cin.getline(d, 20, '\n');
	cout<<"Enter Car Name: ";
	cin.getline(arrayCars[carCount].name, 20, '\n');
	
	cout<<"Enter Model: ";
	cin>>arrayCars[carCount].model;
	while (arrayCars[carCount].model<1990 || arrayCars[carCount].model>2009 )
	{
		cout<<"Model must be between 1990 and 2009.Re-enter.\n";
		cin>>arrayCars[carCount].model;
	}
	
	cout<<"Enter entry date in the following format:\n <day><Press Enter><month><Press Enter><year><Press Enter>\n";
	cin>>arrayCars[carCount].entry_date.day>>arrayCars[carCount].entry_date.month>>arrayCars[carCount].entry_date.year;
	while (arrayCars[carCount].entry_date.year>currentDate.year)
	{
		cout<<"Incorrect Year. Re-enter year.\n";
		cin>>arrayCars[carCount].entry_date.year;
	}
	if (arrayCars[carCount].entry_date.year==currentDate.year)
	{
		while (arrayCars[carCount].entry_date.month>currentDate.month) 
		{
			cout<<"Incorrect Month. Re-enter month.\n";
			cin>>arrayCars[carCount].entry_date.month;
		}
		if (arrayCars[carCount].entry_date.month==currentDate.month)
		{
			while (arrayCars[carCount].entry_date.day>currentDate.day)
			{
				cout<<"Incorrect day. Re-enter day.\n";
				cin>>arrayCars[carCount].entry_date.day;
			}
		}
	}
	
	cout<<"Enter Rent per Day: ";
	cin>>arrayCars[carCount].rent;
	while (arrayCars[carCount].rent <=0)
	{
		cout<<"Incorrect rent entered. Re-enter.\n";
		cin>>arrayCars[carCount].rent;
	}
	
	cout<<"Enter Fine per Day: ";
	cin>>arrayCars[carCount].fine;
	while (arrayCars[carCount].fine <0)
	{
		cout<<"Incorrect fine entered. Re-enter.\n";
		cin>>arrayCars[carCount].fine;
	}
	
	cout<<"Enter Status (Enter 1 for Free or Enter 2 for busy): ";
	cin>>status;
	switch (status)
	{
		case 1:
			arrayCars[carCount].car_status = Free;
			cout<<"Status set to Free\n";
			break;
		case 2:
			arrayCars[carCount].car_status = Busy;
			cout<<"Status set to Busy\n";
			break;
		default:
			cout<<"Invalid Status Entered. Status set to Free.\n";
			arrayCars[carCount].car_status = Free;
	}
	carCount++;
	carID++;
}

void printCar( Cars arrayCars[], int size, int i)
{
	
	cout<<"\nRecord Number "<<i+1<<endl;	
	cout<<"\nCar ID: "<<arrayCars[i].car_id;
	cout<<"\nCar Name: "<<arrayCars[i].name;
	cout<<"\nModel: "<<arrayCars[i].model;
	cout<<"\nEntry Date: "<<arrayCars[i].entry_date.day<<"/"<<arrayCars[i].entry_date.month<<"/"<<arrayCars[i].entry_date.year;
	cout<<"\nRent per Day: "<<arrayCars[i].rent;
	cout<<"\nFine per Day: "<<arrayCars[i].fine;
	switch (arrayCars[i].car_status)
	{
		case 1:
			cout<<"\nStatus: Free";
			break;
		case 2:
			cout<<"\nStatus: Busy";
			break;
		default:
			cout<<"\nError in programme";
	}
	cout<<endl;
}

void carDelete(Cars arrayCars[], int size, int location)
{
	for (int i=location;i<carCount;i++)
	{
		arrayCars[i].car_id = arrayCars[i+1].car_id;
		strcpy(arrayCars[i].name, arrayCars[i+1].name);
		arrayCars[i].model = arrayCars[i+1].model;
		arrayCars[i].entry_date.day = arrayCars[i+1].entry_date.day;
		arrayCars[i].entry_date.month = arrayCars[i+1].entry_date.month;
		arrayCars[i].entry_date.year = arrayCars[i+1].entry_date.year;
		arrayCars[i].rent= arrayCars[i+1].rent;
		arrayCars[i].fine = arrayCars[i+1].fine;
		arrayCars[i].car_status = arrayCars[i+1].car_status;
	}
	carCount--; //not decrementing carID because thats maintaining unique ID no.s
}

void editCar (Cars arrayCars[], int size, int location)
{
	int selection_key =1, status;
	cout<<"To Edit any field, press the required key and press Enter\n\n"
		<<"Name:"<<setw(22)<<"Press 1\n\n"
		<<"Model:"<<setw(21)<<"Press 2\n\n"
		<<"Entry Date:"<<setw(16)<<"Press 4\n\n"
		<<"Rent per Day:"<<setw(14)<<"Press 5\n\n"
		<<"Fine per Day:"<<setw(14)<<"Press 6\n\n"
		<<"Status:"<<setw(20)<<"Press 7\n\n"
		<<"To Exit to main menu, press 3.\n\n";
	while (selection_key != 3)
	{
	
		cout<<"\nEnter a selection key: ";
		cin>>selection_key;
		switch(selection_key)
		{
			case 1:
				char D[20];
				cin.getline(D, 20, '\n');
				cout<<"Enter a new Car Name:\n";
				cin.getline(arrayCars[location].name, 20, '\n');
				break;
									
			case 2:
				cout<<"Enter a new Model:\n";
				cin>>arrayCars[location].model;
				while (arrayCars[location].model<1990 || arrayCars[location].model>2009 )
				{
					cout<<"Model must be between 1990 and 2009.Re-enter.\n";
					cin>>arrayCars[location].model;
				}
				break;
				
			case 3:
				break;
			
			case 4:
				cout<<"Enter a new Entry date:\n";
				cout<<"Follow the format: <day><Press Enter><month><Press Enter><year><Press Enter>\n";
				cin>>arrayCars[location].entry_date.day;
				cin>>arrayCars[location].entry_date.month;
				cin>>arrayCars[location].entry_date.year;
				while (arrayCars[location].entry_date.year>currentDate.year)
				{
					cout<<"Incorrect Year. Re-enter year.\n";
					cin>>arrayCars[location].entry_date.year;
				}
				if (arrayCars[location].entry_date.year==currentDate.year)
				{
					while (arrayCars[location].entry_date.month>currentDate.month) 
					{
						cout<<"Incorrect Month. Re-enter month.\n";
						cin>>arrayCars[location].entry_date.month;
					}
					if (arrayCars[location].entry_date.month==currentDate.month)
					{
						while (arrayCars[location].entry_date.day>currentDate.day)
						{
							cout<<"Incorrect day. Re-enter day.\n";
							cin>>arrayCars[location].entry_date.day;
						}
					}
				}
				break;
			
			case 5:
				cout<<"Enter a new Rent per Day:\n";
				cin>>arrayCars[location].rent;
				while (arrayCars[location].rent <=0)
				{
					cout<<"Incorrect rent entered. Re-enter.\n";
					cin>>arrayCars[location].rent;
				}
				break;
			
			case 6:
				cout<<"Enter a new Fine per Day:\n";
				cin>>arrayCars[location].fine;
				while (arrayCars[location].fine <=0)
				{
					cout<<"Incorrect fine entered. Re-enter.\n";
					cin>>arrayCars[location].fine;
				}
				break;
			
			case 7:
				cout<<"Enter a new Status (Enter 1 for Free, Enter 2 for Busy):\n";
				cin>>status;
				switch (status)
				{
					case 1:
						arrayCars[location].car_status = Free;
						break;
		
					case 2:
						arrayCars[location].car_status = Busy;
						break;
			
					default:
						cout<<"Invalid status entered. Status set to Free.";
						arrayCars[location].car_status = Free;
				}
				break;

			default:
				cout<<"Invalid selection key entered. Enter numbers from 1 to 7 only.\n\n";
		}
	}
	if (selection_key == 3)
	{
		cout<<"Returning to Main Menu.\n";
		return;
	}
}

void addCustomers( Customers arrayCustomers[], int size)
{
	int custStatus, cardStatus;
	
	cout<<"\n\nEntering Record number "<<customersCount+1<<endl;
	arrayCustomers[customersCount].customer_id = customersID + 1;
	
	cout<<"Enter Customer First Name: ";
	cin>>arrayCustomers[customersCount].first_name;
	
	cout<<"Enter Customer Last Name: ";
	cin>>arrayCustomers[customersCount].last_name;
		
	cout<<"\nEnter NIC number :";
	cin>>arrayCustomers[customersCount].nic;
	
	cout<<"\nEnter Contact number :";
	cin>>arrayCustomers[customersCount].contact_number;
	
	char a[25]; 
	cin.getline(a, 25, '\n');
	
	cout<<"\nEnter Address :";
	cin.getline(arrayCustomers[customersCount].address, 45, '\n');
	
	cout<<"\nEnter Status: (Press 1 for one-time, Press 2 for Member)";
	cin>>custStatus;
	switch (custStatus)
	{
		case 1:
			arrayCustomers[customersCount].customer_status = OneTime;
			cout<<"Status set to One Time";
			break;
		case 2:
			arrayCustomers[customersCount].customer_status = Member;
			cout<<"Status set to Member";
			break;
		default:
			cout<<"Invalid Status Entered. Status set to One Time.";
			arrayCustomers[customersCount].customer_status = OneTime;
	}
			
	if (arrayCustomers[customersCount].customer_status == Member)
	{
		cout<<"\nEnter Date Of Joining :";
		cin>>arrayCustomers[customersCount].date_of_joining.day;
		cin>>arrayCustomers[customersCount].date_of_joining.month;
		cin>>arrayCustomers[customersCount].date_of_joining.year;
		while (arrayCustomers[customersCount].date_of_joining.year>currentDate.year)
		{
			cout<<"Incorrect Year. Re-enter year.\n";
			cin>>arrayCustomers[customersCount].date_of_joining.year;
		}
		if (arrayCustomers[customersCount].date_of_joining.year==currentDate.year)
		{
			while (arrayCustomers[customersCount].date_of_joining.month>currentDate.month) 
			{
				cout<<"Incorrect Month. Re-enter month.\n";
				cin>>arrayCustomers[customersCount].date_of_joining.month;
			}
			if (arrayCustomers[customersCount].date_of_joining.month==currentDate.month)
			{
				while (arrayCustomers[customersCount].date_of_joining.day>currentDate.day)
				{
					cout<<"Incorrect day. Re-enter day.\n";
					cin>>arrayCustomers[customersCount].date_of_joining.day;
				}
			}
		}
		
		cout<<"\nEnter Membership Fee :";
		cin>>arrayCustomers[customersCount].membership_fee;
		while (arrayCustomers[customersCount].membership_fee < 0)
		{
			cout<<"Incorrect Fee. Re-enter fee.\n";
			cin>>arrayCustomers[customersCount].membership_fee;
		}
	}
	
	cout<<"\nEnter Credit Card number :";
	cin>>arrayCustomers[customersCount].credit_card_number;
	
	cout<<"\nEnter Credit Card expiry date:\n";
	cin>>arrayCustomers[customersCount].credit_card_expiry.day;
	cin>>arrayCustomers[customersCount].credit_card_expiry.month;
	cin>>arrayCustomers[customersCount].credit_card_expiry.year;
	
	cout<<"\nEnter Credit Card type: (Press 1 for MasterCard, Press 2 for Visa)";
	cin>>cardStatus;
	switch (cardStatus)
	{
		case 1:
			arrayCustomers[customersCount].card_type = MasterCard;
			break;
	
		case 2:
			arrayCustomers[customersCount].card_type = Visa;
			break;
	
		default:
			cout<<"Invalid Card Type Entered. Card Type set to Master Card.";
			arrayCustomers[customersCount].card_type = MasterCard;
	}
	
	cout<<"\nEnter Validation Code :";
	cin>>arrayCustomers[customersCount].validation_code;
	
	customersCount++;
	customersID++;
}

int searchCarID(Cars arrayCars[], int size, int ID)
{
	bool flag = 0;
	int i;
	for (i=0;i<carCount;i++)
	{
		if (ID == arrayCars[i].car_id)
		{
			flag = 1;
			break;
		}
	}
	if (flag ==1)
		return i;
	else
		return -1;
}

int searchCarName(Cars arrayCars[], int size, char name[], int i )
{
	if (strcmp(name, arrayCars[i].name) == 0)
		return i;
	else
		return -1;
}

int searchCustomersID(Customers arrayCustomers[], int size, int ID)
{
	bool flag = 0;
	int i;
	for (i=0;i<customersCount;i++)
	{
		if (ID == arrayCustomers[i].customer_id)
		{
			flag = 1;
			break;
		}
	}
	if (flag ==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int searchCustomersName(Customers arrayCustomers[], int size, char name[], int i)
{
	if (strcmp(name, arrayCustomers[i].first_name) == 0)
		return i;
	else
		return -1;
}

void customersDelete(Customers arrayCustomers[], int size, int i)
{
	for (int i=i;i<customersCount;i++)
	{
		arrayCustomers[i].customer_id = arrayCustomers[i+1].customer_id;
		strcpy(arrayCustomers[i].first_name, arrayCustomers[i+1].first_name);
		strcpy(arrayCustomers[i].last_name, arrayCustomers[i+1].last_name);
		strcpy(arrayCustomers[i].nic, arrayCustomers[i+1].nic);
		strcpy(arrayCustomers[i].contact_number, arrayCustomers[i+1].contact_number);
		strcpy(arrayCustomers[i].address, arrayCustomers[i+1].address);
		strcpy(arrayCustomers[i].credit_card_number, arrayCustomers[i+1].credit_card_number);
		arrayCustomers[i].customer_status = arrayCustomers[i+1].customer_status;
		arrayCustomers[i].date_of_joining.day=arrayCustomers[i+1].date_of_joining.day;
		arrayCustomers[i].date_of_joining.month=arrayCustomers[i+1].date_of_joining.month;
		arrayCustomers[i].date_of_joining.year=arrayCustomers[i+1].date_of_joining.year;
		arrayCustomers[i].membership_fee = arrayCustomers[i+1].membership_fee;
		arrayCustomers[i].credit_card_expiry.day=arrayCustomers[i+1].credit_card_expiry.day;
		arrayCustomers[i].credit_card_expiry.month=arrayCustomers[i+1].credit_card_expiry.month;
		arrayCustomers[i].credit_card_expiry.year=arrayCustomers[i+1].credit_card_expiry.year;
		arrayCustomers[i].validation_code = arrayCustomers[i+1].validation_code;
		arrayCustomers[i].card_type = arrayCustomers[i+1].card_type;
	}
	customersCount--; //not decrementing customersID cuz thats maintaining unique ID no.s
}

void editCustomers(Customers arrayCustomers[], int size, int location)
{
	int selection_key = 0; //random value to ensure at least one iteration of while loop
	cout<<"To Edit any field, press the required key and press Enter\n\n"
				<<"First Name:"<<setw(26)<<"Press 1\n\n"
				<<"Last Name:"<<setw(27)<<"Press 2\n\n"
				<<"Contact Number:"<<setw(22)<<"Press 4\n\n"
				<<"Address:"<<setw(29)<<"Press 5\n\n"
				<<"Status:"<<setw(30)<<"Press 6\n\n"
				<<"Date of Joining:"<<setw(21)<<"Press 7\n\n"
				<<"Membership Fee:"<<setw(21)<<"Press 8\n\n"
				<<"Credit Card Number:"<<setw(18)<<"Press 9\n\n"
				<<"Credit Car Expiry Date:"<<setw(15)<<"Press 10\n\n"
				<<"Card Type:"<<setw(28)<<"Press 11\n\n"
				<<"Validation Code:"<<setw(22)<<"Press 12\n\n"
				<<"To Exit to main menu, Press 3.\n\n";
	while (selection_key != 3)
	{
		cout<<"\nEnter a selection key: ";
		cin>>selection_key;
		switch(selection_key)
		{
			case 1:
				cout<<"Enter a new First Name:\n";
				cin>>arrayCustomers[location].first_name;
				break;
					
			case 2:
				cout<<"Enter a new Last Name:\n";
				cin>>arrayCustomers[location].last_name;
				break;
					
			case 3:
				break;
				
			case 4:
				cout<<"Enter a new Contact_number:\n";
				cin>>arrayCustomers[location].contact_number; 
				break;

			case 5:
				char a[5];
				cin.getline (a, 5, '\n');
				cout<<"Enter a new Address:\n";
				cin.getline(arrayCustomers[location].address, 45, '\n');
				break;

 			case 6:
				int custStatus;
				cout<<"Enter a new Status:\n";
				cin>>custStatus;
				switch (custStatus)
				{
					case 1:
						arrayCustomers[location].customer_status = OneTime;
						cout<<"Status set to One Time";
						break;
					case 2:
						arrayCustomers[location].customer_status = Member;
						cout<<"Status set to Member";
						break;
					default:
						cout<<"Invalid Status Entered. Status set to One Time.";
						arrayCustomers[location].customer_status = OneTime;
				}
				break;

			case 7:
				cout<<"Enter a new date_of_joining:\n";
				cin>>arrayCustomers[location].date_of_joining.day;
				cin>>arrayCustomers[location].date_of_joining.month;
				cin>>arrayCustomers[location].date_of_joining.year;
				while (arrayCustomers[location].date_of_joining.year>currentDate.year)
				{
					cout<<"Incorrect Year. Re-enter year.\n";
					cin>>arrayCustomers[location].date_of_joining.year;
				}
				if (arrayCustomers[location].date_of_joining.year==currentDate.year)
				{
					while (arrayCustomers[location].date_of_joining.month>currentDate.month) 
					{
						cout<<"Incorrect Month. Re-enter month.\n";
						cin>>arrayCustomers[location].date_of_joining.month;
					}
					if (arrayCustomers[location].date_of_joining.month==currentDate.month)
					{
						while (arrayCustomers[location].date_of_joining.day>currentDate.day)
						{
							cout<<"Incorrect day. Re-enter day.\n";
							cin>>arrayCustomers[location].date_of_joining.day;
						}
					}
				}
				break;

			case 8:
				cout<<"Enter a new membership fee:\n";
				cin>>arrayCustomers[location].membership_fee;
				break;

			case 9:
				cout<<"Enter a new Credit Card number:\n";
				cin>>arrayCustomers[location].credit_card_number;
				break;

			case 10:
				cout<<"Enter a new Credit Card expiry date:\n";
				cin>>arrayCustomers[location].credit_card_expiry.day>>arrayCustomers[location].credit_card_expiry.month>>arrayCustomers[location].credit_card_expiry.year;
				while (arrayCustomers[location].credit_card_expiry.year>currentDate.year)
				{
					cout<<"Incorrect Year. Re-enter year.\n";
					cin>>arrayCustomers[location].credit_card_expiry.year;
				}
				if (arrayCustomers[location].credit_card_expiry.year==currentDate.year)
				{
					while (arrayCustomers[location].credit_card_expiry.month>currentDate.month) 
					{
						cout<<"Incorrect Month. Re-enter month.\n";
						cin>>arrayCustomers[location].credit_card_expiry.month;
					}
					if (arrayCustomers[location].credit_card_expiry.month==currentDate.month)
					{
						while (arrayCustomers[location].credit_card_expiry.day>currentDate.day)
						{
							cout<<"Incorrect day. Re-enter day.\n";
							cin>>arrayCustomers[location].credit_card_expiry.day;
						}
					}
				}
				break;

			case 11:
 				int cardStatus;
		 		cout<<"\nEnter a new Credit Card type: (Press 1 for MasterCard, Press 2 for Visa)";
				cin>>cardStatus;
				switch (cardStatus)
				{
				case 1:
					arrayCustomers[location].card_type = MasterCard;
					break;
		
				case 2:
					arrayCustomers[location].card_type = Visa;
					break;
		
				default:
					cout<<"Invalid Card Type Entered. Card Type set to Master Card.";
					arrayCustomers[location].card_type = MasterCard;
				}
				break;

			case 12:
				cout<<"Enter a new Validation_code:\n";
				cin>>arrayCustomers[location].validation_code;
				break;

			default:
				cout<<"Invalid selection key entered. Enter numbers from 1 to 10 only.\n\n";
		}
	}

	if (selection_key == 3)
	{
		cout<<"Returning to switchboard\n";
		return;
	}
}
void printCustomers( Customers arrayCustomers[], int size, int i)

{
	cout<<"\nRecord Number "<<i+1<<endl;	
	cout<<"Customer ID: "<<arrayCustomers[i].customer_id;
	cout<<"\nCustomers Name: "<<arrayCustomers[i].first_name;
	cout<<' '<<arrayCustomers[i].last_name;		
	cout<<"\nNIC number :"<<arrayCustomers[i].nic;
	cout<<"\nContact number :"<<arrayCustomers[i].contact_number;
	cout<<"\nAddress :"<<arrayCustomers[i].address;
	switch (arrayCustomers[i].customer_status)
	{
		case 1:
			cout<<"\nStatus: One Time";
			break;
		case 2:
			cout<<"\nStatus: Member";
			break;
		default:
			cout<<"\nError in programme";
	}
	cout<<"\nDate Of Joining: "
	<<arrayCustomers[i].date_of_joining.day<<'/'<<arrayCustomers[i].date_of_joining.month<<'/'<<arrayCustomers[i].date_of_joining.year;
	cout<<"\nMembership fee :"<<arrayCustomers[i].membership_fee;
	cout<<"\nCredit Card number :"<<arrayCustomers[i].credit_card_number;
	cout<<"\nCredit Card expiry:" <<arrayCustomers[i].credit_card_expiry.day<<'/'<<arrayCustomers[i].credit_card_expiry.month<<'/'<<arrayCustomers[i].credit_card_expiry.month<<arrayCustomers[i].credit_card_expiry.year;
 	switch (arrayCustomers[i].card_type)
	{
		case 1:
			cout<<"\nCredit Card type : Master Card";
			break;
		case 2:
			cout<<"\nCredit Card type: Visa";
			break;
		default:
			cout<<"\nError in programme";
	}
	cout<<"\nValidation Code :"<<arrayCustomers[i].validation_code;
	cout<<endl;
}
void addrented_cars( rented_cars arrayrented_cars[], int size, Customers arrayCustomers[], int size2, Cars arrayCars[], int size3)
{
	cout<<"\nEntering Record number "<<rented_carsCount+1<<endl;
	arrayrented_cars[rented_carsCount].rental_transaction_id = rental_transaction_ID+1;
	
	cout<<"\nEnter Customer ID\n";
	cin>>arrayrented_cars[rented_carsCount].customer_id;
	int location = searchCustomersID (arrayCustomers, size, arrayrented_cars[rented_carsCount].customer_id);
	cout<<location;
	while (location == -1)
	{
		cout<<"No such customer. Re-enter valid customer ID.\n";
		cin>>arrayrented_cars[rented_carsCount].customer_id;
		location = searchCustomersID (arrayCustomers, size, arrayrented_cars[rented_carsCount].customer_id);
	}
	
	cout<<"\nEnter Car ID\n";
	cin>>arrayrented_cars[rented_carsCount].car_id;
	location = searchCarID (arrayCars, size, arrayrented_cars[rented_carsCount].car_id);
	while (location == -1)
	{
		cout<<"No such car. Re-enter valid car ID.\n";
		cin>>arrayrented_cars[rented_carsCount].car_id;
		location = searchCarID (arrayCars, size, arrayrented_cars[rented_carsCount].car_id);
	}
	cout<<"\nEnter Choice of Driver (0 for yes, any non-zero integer for no)\n";
	cin>>arrayrented_cars[rented_carsCount].choice_driver;
	cout<<"\nEnter Issue Date\n";
	cin>>arrayrented_cars[rented_carsCount].issue_date.day>>arrayrented_cars[rented_carsCount].issue_date.month>>arrayrented_cars[rented_carsCount].issue_date.year;
	while (arrayrented_cars[rented_carsCount].issue_date.year>currentDate.year)
	{
		cout<<"Incorrect Year. Re-enter year.\n";
		cin>>arrayrented_cars[rented_carsCount].issue_date.year;
	}
	if (arrayrented_cars[rented_carsCount].issue_date.year==currentDate.year)
	{
		while (arrayrented_cars[rented_carsCount].issue_date.month>currentDate.month) 
		{
			cout<<"Incorrect Month. Re-enter month.\n";
			cin>>arrayrented_cars[rented_carsCount].issue_date.month;
		}
		if (arrayrented_cars[rented_carsCount].issue_date.month==currentDate.month)
		{
			while (arrayrented_cars[rented_carsCount].issue_date.day>currentDate.day)
			{
				cout<<"Incorrect day. Re-enter day.\n";
				cin>>arrayrented_cars[rented_carsCount].issue_date.day;
			}
		}
	}
	cout<<"\nEnter Number Of Days of Rent\n";
	cin>>arrayrented_cars[rented_carsCount].numb_days_rent;
	while (arrayrented_cars[rented_carsCount].numb_days_rent<=0)
	{
		cout<<"\nInvalid input. Re-enter.\n";
		cin>>arrayrented_cars[rented_carsCount].numb_days_rent;
	}
	rented_carsCount++;
	rental_transaction_ID++;
}

void printrented_cars( rented_cars arrayrented_cars[], int size, int i)
{
	cout<<"\nRecord Number "<<i+1<<endl;	
	cout<<"Rental Transaction ID: "<<arrayrented_cars[i].rental_transaction_id<<endl;
	cout<<"Customer ID: "<<arrayrented_cars[i].customer_id<<endl;
	cout<<"Car ID: "<<arrayrented_cars[i].car_id<<endl;
	if (arrayrented_cars[i].choice_driver)
		cout<<"Choice of Driver: Yes"<<endl;
	else
		cout<<"Choice of Driver: No"<<endl;
	cout<<"Issue Date: "<<arrayrented_cars[i].issue_date.day<<'/'<<arrayrented_cars[i].issue_date.month<<'/'<<arrayrented_cars[i].issue_date.year<<endl;
	cout<<"Number Of Days Of Rent: "<<arrayrented_cars[i].numb_days_rent<<endl;
	cout<<"Return Date: "<<arrayrented_cars[i].return_date.day<<'/'<<arrayrented_cars[i].return_date.month<<'/'<<arrayrented_cars[i].return_date.year<<endl;
	cout<<"Payment: "<<arrayrented_cars[i].payment<<endl;
	cout<<endl;
}

int searchTransactionID(rented_cars arrayrented_cars[], int size, int ID)
{
	bool flag = 0;
	int i;
	for (i=0;i<rented_carsCount;i++)
	{
		if (ID == arrayrented_cars[i].rental_transaction_id)
		{
			flag = 1;
			break;
		}
	}
	if (flag ==1)
		return i;
	else
		return -1;
}

void ReturnMakeBill (rented_cars arrayrented_cars[], int size, Cars arrayCars[], int size2)
{
	int RID;
	//setw parameter = 15+22 - first string length
	cout<<"Enter Rental Transaction ID: ";
	cin>>RID;
	int location = searchTransactionID (arrayrented_cars, size, RID);
	if (location != -1)
	{
		cout<<"\nEnter Return Date\n";
		cin>>arrayrented_cars[location].return_date.day>>arrayrented_cars[location].return_date.month>>arrayrented_cars[location].return_date.year;
		while (arrayrented_cars[location].return_date.year>currentDate.year)
		{
			cout<<"Incorrect Year. Re-enter year.\n";
			cin>>arrayrented_cars[location].return_date.year;
		}
		if (arrayrented_cars[location].return_date.year==currentDate.year)
		{
			while (arrayrented_cars[location].return_date.month>currentDate.month) 
			{
				cout<<"Incorrect Month. Re-enter month.\n";
				cin>>arrayrented_cars[location].return_date.month;
			}
			if (arrayrented_cars[location].return_date.month==currentDate.month)
			{
				while (arrayrented_cars[location].return_date.day>currentDate.day)
				{
					cout<<"Incorrect day. Re-enter day.\n";
					cin>>arrayrented_cars[location].return_date.day;
				}
			}
		}
		cout<<endl<<endl;
		cout<<setfill('*')<<setw(35)<<"Bill/Voucher"<<setw(35)<<"**"<<endl<<endl<<endl;
		cout<<"Rental Transaction ID: "<<setfill(' ')<<setw(15)<<arrayrented_cars[location].rental_transaction_id<<endl;
		cout<<"Customer ID: "<<setw(25)<<arrayrented_cars[location].customer_id<<endl;
		cout<<"Car ID: "<<setw(29)<<arrayrented_cars[location].car_id<<endl;
		cout<<"Issue Date: "<<setw(30)<<arrayrented_cars[location].issue_date.day<<
		'/'<<arrayrented_cars[location].issue_date.month<<'/'<<
		arrayrented_cars[location].issue_date.year<<endl;
		cout<<"Return Date: "<<setw(30)<<arrayrented_cars[location].return_date.day<<
		'/'<<arrayrented_cars[location].return_date.month<<'/'<<
		arrayrented_cars[location].return_date.year<<endl;
		int bill = calculateBill(arrayrented_cars, size, location, arrayCars, size2);
		if (bill != -1)
			arrayrented_cars[location].payment = bill;
		cout<<"Payment(Rupees): "<<setw(24)<<arrayrented_cars[location].payment; 
		cout<<endl;
	}
	else
	{
		cout<<"No such transaction. Returning to main menu.\n";
		return;
	}
	cout<<"To produce another bill, press 1.\n\n"
		<<"To exit to main menu, press 2.\n\n"
		<<"To close application, press 3.\n\n";
	int selection_key;
	cin>>selection_key;
	switch (selection_key)
	{
		case 1:
		ReturnMakeBill (arrayrented_cars, size, arrayCars, size2);
		break;
		
		case 2:
		return;
		break;
		
		case 3:
		break;
		
		default:
		cout<<"Invalid key entered. Returning to main menu.\n\n";
		return;
	}
}

int calculateBill (rented_cars arrayrented_cars[], int size, int i, Cars arrayCars[], int size2)
{
	//Calculate days:
	int yearReturned = arrayrented_cars[i].return_date.year;
	int yearIssued = arrayrented_cars[i].issue_date.year;
	int monthReturned = arrayrented_cars[i].return_date.month;
	int monthIssued = arrayrented_cars[i].issue_date.month;
	int dayReturned = arrayrented_cars[i].return_date.day;
	int dayIssued = arrayrented_cars[i].issue_date.day;
	int years, months, days;
	
	if (yearReturned != yearIssued)
	{
		years = yearReturned - yearIssued;
		if (years>1)
		{
			cout<<"Invalid data, check records. Issue date and return date cannot be more than a year apart.\n";
			return -1;
		}
		days = (((monthReturned-1) * 30) + dayReturned) + (((12 - monthIssued)*30) + (30 - dayIssued));
	}
	else 
	{
		months = monthReturned - monthIssued;
		days = ((months-1)*30) + (30 - dayIssued) + (dayReturned);
	}
	int carId = arrayrented_cars[i].car_id;
	int location = searchCarID(arrayCars, size2, carId);
	int rent = arrayCars[location].rent;
	int fine = arrayCars[location].fine;
	int extraDays = days - arrayrented_cars[i].numb_days_rent;
	int bill;
	if (extraDays>0)
		bill = (rent * days) + (fine * extraDays);
	else 
		bill = rent *days;
	return bill;
}
void rented_carsdelete(rented_cars arrayrented_cars[], int size, int deleted)
{
	for (int i=deleted;i<rented_carsCount;i++)
	{
		arrayrented_cars[i].rental_transaction_id = arrayrented_cars[i+1].rental_transaction_id;
		arrayrented_cars[i].customer_id = arrayrented_cars[i+1].customer_id;
		arrayrented_cars[i].car_id = arrayrented_cars[i+1].car_id;
		arrayrented_cars[i].choice_driver = arrayrented_cars[i+1].choice_driver;
		arrayrented_cars[i].issue_date.day = arrayrented_cars[i+1].issue_date.day;
		arrayrented_cars[i].issue_date.month= arrayrented_cars[i+1].issue_date.month;
		arrayrented_cars[i].issue_date.year= arrayrented_cars[i+1].issue_date.year;
		arrayrented_cars[i].numb_days_rent = arrayrented_cars[i+1].numb_days_rent;
		arrayrented_cars[i].return_date.day = arrayrented_cars[i+1].return_date.day;
		arrayrented_cars[i].return_date.month= arrayrented_cars[i+1].return_date.month;
		arrayrented_cars[i].return_date.year= arrayrented_cars[i+1].return_date.year;		
		arrayrented_cars[i].payment = arrayrented_cars[i+1].payment;
	}	
	rented_carsCount--; //not decrementing carID cuz thats maintaining unique ID no.s
}

void editrented_cars(rented_cars arrayrented_cars[], int size, int location)
{
	int selection_key = 1;
	cout<<"To Edit any field, press the required key and press Enter\n\n"
		<<"Customer ID:Press 2\n\n"
		<<"Car ID:Press 3\n\n"
		<<"Customer Type:Press 4\n\n"
		<<"Choice of Driver:Press 5\n\n"
		<<"Issue Date:Press 6\n\n"
		<<"Number Of Days Of Rent:Press 7\n\n"
		<<"Return Date:Press 8\n\n"
		<<"Payment:Press 9\n\n"
		<<"To Exit to main menu, press 10.\n\n"
		<<"Enter a selection key.";
	while (selection_key != 10)
	{
		cout<<"Enter another selection key to edit more fields or exit: ";
		cin>>selection_key;
		switch(selection_key)
		{
			case 2:
			cout<<"Enter a new Customer ID:\n";
			cin>>arrayrented_cars[location].customer_id;
			break;
									
			case 3:
			cout<<"Enter a new Car ID:\n";
			cin>>arrayrented_cars[location].car_id;
			break;
			
			case 5:
			cout<<"Enter a new Choice Of Driver:(0 for yes, any non-zero integer for no)\n";
			cin>>arrayrented_cars[location].choice_driver;
			break;
				
			case 6:
			cout<<"Enter a new Issue Date:\n";
			cin>>arrayrented_cars[location].issue_date.day>>arrayrented_cars[location].issue_date.month>>arrayrented_cars[location].issue_date.year;
			break;
			
			case 7:
			cout<<"Enter a new Number of Days of Rent:\n";
			cin>>arrayrented_cars[location].numb_days_rent;
			break;

			case 8:
			cout<<"Enter a new Return Date:\n";
			cin>>arrayrented_cars[location].return_date.day>>arrayrented_cars[location].return_date.month>>arrayrented_cars[location].return_date.year;
			while (arrayrented_cars[location].return_date.year>currentDate.year)
			{
				cout<<"Incorrect Year. Re-enter year.\n";
				cin>>arrayrented_cars[location].return_date.year;
			}
			if (arrayrented_cars[location].return_date.year==currentDate.year)
			{
				while (arrayrented_cars[location].return_date.month>currentDate.month) 
				{
					cout<<"Incorrect Month. Re-enter month.\n";
					cin>>arrayrented_cars[location].return_date.month;
				}
				if (arrayrented_cars[location].return_date.month==currentDate.month)
				{
					while (arrayrented_cars[location].return_date.day>currentDate.day)
					{
						cout<<"Incorrect day. Re-enter day.\n";
						cin>>arrayrented_cars[location].return_date.day;
					}
				}
			}
			break;

			case 9:
			cout<<"Enter a new Payment:\n";
			cin>>arrayrented_cars[location].payment;
			break;
			
			case 10:
			return;
			break;

			default:
			cout<<"Invalid selection key entered. Enter numbers from 2 to 10 only.\n\n";
		}
	}
	if (selection_key == 10)
	{
		cout<<"Returning to switchboard\n";
		return;
	}
}

int searchTransactionByCar (rented_cars arrayrented_cars[], int size, int ID, int i)
{
	if (arrayrented_cars[i].car_id == ID)
		return i;
	else
		return -1;
}

int searchTransactionByCustomer (rented_cars arrayrented_cars[], int size, int ID, int i)
{
	if (arrayrented_cars[i].customer_id == ID)
		return i;
	else
		return -1;
}
void addrepair( repair arrayrepair[], int size)
{
  int type;
 cout<<"\n\nEntering Record number "<<repairID+1<<endl;
 arrayrepair[repaircount].repair_id = repairID + 1;
 cout<<"Enter Car ID ";
 cin>>arrayrepair[repaircount].car_id;
 
    cout<<"\nEnter Rpair Type:";
   cout<<"( enter 1 for accidental damage, enter 2 for service, enter 3 for change of tyre, enter 4 for  car wash) ";
 cin>>type;
 switch (type)
 {
  case 1:
    arrayrepair[repaircount].repairType = accidental_damage;
   cout<<"Status set to Accidental damage";
   break;
  case 2:
   arrayrepair[repaircount].repairType = service;
   cout<<"Status set to service";
   break;
  case 3:
   arrayrepair[repaircount].repairType = change_of_tyre;
   cout<<"Status set to change of tyre";
   break;
  case 4:
   arrayrepair[repaircount].repairType = car_wash;
   cout<<"Status set to car wash";
   break;
  default:
   cout<<"Invalid Status Entered. Status set to Accidental Damage.";
   arrayrepair[repaircount].repairType = accidental_damage;
 }
 cout<<endl;
 cout<<"Enter Repair Cost ";
 cin>>arrayrepair[repaircount].repair_cost;
 cout<<"Enter Repair Date ";
 cin>>arrayrepair[repaircount].repair_date.day>>arrayrepair[repaircount].repair_date.month>>arrayrepair[repaircount].repair_date.year;
 repaircount++;
 repairID++;
}

void repairdelete(repair arrayrepair[], int size, int i)
{
 
 for (int i=i;i<repaircount;i++)
 {
  arrayrepair[i].repair_id = arrayrepair[i+1].repair_id;
  arrayrepair[i].car_id = arrayrepair[i+1].car_id;
  arrayrepair[i].repairType = arrayrepair[i+1].repairType;
  arrayrepair[i].repair_cost = arrayrepair[i+1].repair_cost;
  arrayrepair[i].repair_date.day = arrayrepair[i+1].repair_date.day;
  arrayrepair[i].repair_date.month= arrayrepair[i+1].repair_date.month;
  arrayrepair[i].repair_date.year= arrayrepair[i+1].repair_date.year;
 } 
 repaircount--; //not decrementing carID cuz thats maintaining unique ID no.s
}

void editrepair(repair arrayrepair[], int size, int location)
{
	int selection_key=0;
	cout<<"To Edit any field, press the required key and press Enter\n\n"
  	<<"car id:"<<setw(22)<<"Press 1\n\n"
  	<<"repair type:"<<setw(22)<<"Press 2\n\n"
  	<<"repair cost:"<<setw(22)<<"Press 3\n\n"
  	<<"repair date:"<<setw(22)<<"Press 4\n\n"
  	<<"To Exit to main menu, press 5.\n\n";
  	while (selection_key != 5)
	{
		cout<<"\nEnter a selection key: ";
		cin>>selection_key;
		switch(selection_key)
  		{
		   int type;
		   case 1:
		   cout<<"Enter a new Car Id:\n";
		   cin>>arrayrepair[location].car_id;
		   break;
		         
		   case 2:
		   cout<<"Enter a new repair type\n";
		   cin>>type;
   			switch (type)
		    {
		     case 1:
		      arrayrepair[location].repairType = accidental_damage;
		      break;
		  
		     case 2:
		      arrayrepair[location].repairType = service;
		      break;
		     
		     case 3:
		      arrayrepair[location].repairType = change_of_tyre;
		      break;
		     
			 case 4:
		      arrayrepair[location].repairType = car_wash;
		      break; 
		   
		     default:
		      cout<<"Invalid entry, status set to service.";
		      arrayrepair[location].repairType = service;
		    }
   			break;
   
		   case 3:
		   cout<<"Enter  new repair cost:\n";
		   cin>>arrayrepair[location].repair_cost;
		   break;
		  
		   case 4:
		   cout<<"Enter a new repair date:\n";
		   cin>>arrayrepair[location].repair_date.day
		   >>arrayrepair[location].repair_date.month
		   >>arrayrepair[location].repair_date.year;
		   break;
		   
		    default:
		   cout<<"Invalid selection key entered. Enter numbers from 1 to 11 only.\n\n";
  	}
 }
 if (selection_key == 5)
 {
  cout<<"Returning to switchboard\n";
  return;
 }
}

void printrepair( repair arrayrepair[], int size, int i)
{

  cout<<"\nRecord Number "<<i+1<<endl; 
  cout<<"Repair ID: "<<arrayrepair[i].repair_id;
  cout<<"\nCar ID: "<<arrayrepair[i].car_id;
  switch (arrayrepair[i].repairType)
 {
  case 1:
   cout<<"\nStatus: accidental damage";
   break;
  case 2:
   cout<<"\nStatus: service";
   break;
  case 3:
   cout<<"\nStatus:change of type";
   break;
  case 4:
   cout<<"\nStatus:Car wash";
   break;
  default:
   cout<<"\nStatus: accidental damage";
 }
 cout<<endl;
  cout<<"Repair Cost: "<<arrayrepair[i].repair_cost;
  cout<<"Repair Date: "<<arrayrepair[i].repair_date.day<<'/'<<arrayrepair[i].repair_date.month<<'/'<<arrayrepair[i].repair_date.year;
  cout<<endl;
 
}

int searchrepairID(repair arrayrepair[], int size, int ID)
{
 bool flag = 0;
 int i;
 for (i=0;i<repaircount;i++)
 {
  if (ID == arrayrepair[i].repair_id)
  {
   flag = 1;
   break;
  }
 }
 if (flag ==1)
  return i;
 else
  return -1;
}


void addemployee( employee arrayemployee[], int size)
{
	int status, maritial_status, gender;
	cout<<"\n\nEntering Record number "<<employeecount+1<<endl;
	arrayemployee[employeecount].employee_id = employeeID + 1;
	
	char a[20];
	cin.getline(a, 20, '\n');
	cout<<"Enter Employee Name: ";
	cin.getline(arrayemployee[employeecount].name, 20,'\n');
		
	cout<<"\nEnter Designation: ";
	cin.getline(arrayemployee[employeecount].designation, 20, '\n');
	
	cout<<"\nEnter status: (Enter  1 for Free, Enter 2 for busy, Enter 3 for  leave) ";
	cin>>status;
	
	switch (status)
	{
		case 1:
			arrayemployee[employeecount].employeeStatus = Free;
			cout<<"Status set to Free";
			break;
		case 2:
			arrayemployee[employeecount].employeeStatus = Busy;
			cout<<"Status set to Busy";
			break;
		case 3:
			arrayemployee[employeecount].employeeStatus = Leave;
			cout<<"Status set to Leave";
			break;
		default:
			cout<<"Invalid Status Entered. Status set to Free.";
			arrayemployee[employeecount].employeeStatus = Free;
	}
	char f[40];
	cin.getline(f, 40, '\n');
	cout<<"\nEnter address: ";
	cin.getline(arrayemployee[employeecount].address, 45, '\n');
	
	cout<<"\nEnter Gender: ";
	cin>>gender;
	
	switch (gender)
	{
		case 1:
			arrayemployee[employeecount].employeeGender = Male;
			cout<<"male";
			break;
		case 2:
			arrayemployee[employeecount].employeeGender= Female;
			cout<<"female";
			break;
		default:
			cout<<"Invalid Entry. Set to male";
			arrayemployee[employeecount].employeeGender = Male;
	}
	cout<<"\nEnter Marital Status: (1-married, 2-single, 3-divorced)";
	cin>>maritial_status;
	
	switch (maritial_status)
	{
		case 1:
			arrayemployee[employeecount].employeemstatus = Married;
			break;
		case 2:
			arrayemployee[employeecount].employeemstatus = Single;
			break;
		case 3:
			arrayemployee[employeecount].employeemstatus = Divorced;
			break;
		default:
			cout<<"Invalid Entry. Set to single.";
			arrayemployee[employeecount].employeemstatus = Single;
	}
	cout<<"\nEnter Date of Birth: ";
	cin>>arrayemployee[employeecount].d_o_b.day;
	cin>>arrayemployee[employeecount].d_o_b.month;
	cin>>arrayemployee[employeecount].d_o_b.year;
	
	cout<<"\nEnter Contact Number: ";
	cin>>arrayemployee[employeecount].contact_numb;
	
	cout<<"\nEnter Date of Joining: ";
	cin>>arrayemployee[employeecount].d_o_j.day;
	cin>>arrayemployee[employeecount].d_o_j.month;
	cin>>arrayemployee[employeecount].d_o_j.year;
	while (arrayemployee[employeecount].d_o_j.year>currentDate.year)
	{
		cout<<"Incorrect Year. Re-enter year.\n";
		cin>>arrayemployee[employeecount].d_o_j.year;
	}
	if (arrayemployee[employeecount].d_o_j.year==currentDate.year)
	{
		while (arrayemployee[employeecount].d_o_j.month>currentDate.month) 
		{
			cout<<"Incorrect Month. Re-enter month.\n";
			cin>>arrayemployee[employeecount].d_o_j.month;
		}
		if (arrayemployee[employeecount].d_o_j.month==currentDate.month)
		{
			while (arrayemployee[employeecount].d_o_j.day>currentDate.day)
			{
				cout<<"Incorrect day. Re-enter day.\n";
				cin>>arrayemployee[employeecount].d_o_j.day;
			}
		}
	}
	
	cout<<"\nEnter Salaray: ";
	cin>>arrayemployee[employeecount].salary;
	
	cout<<"\nEnter Working Days: ";
	cin>>arrayemployee[employeecount].working_days;
	
	employeecount++;
	employeeID++;
}

int searchemployeeID(employee arrayemployee[], int size, int ID)
{
	bool flag = 0;
	int i;
	for (i=0;i<employeecount;i++)
	{
		if (ID == arrayemployee[i].employee_id)
		{
			flag = 1;
			break;
		}
	}
	if (flag ==1)
		return i;
	else
		return -1;
}

int searchemployeeName(employee arrayemployee[], int size, char name[], int i )
{
	if (strcmp(name, arrayemployee[i].name) == 0)
		return i;
	else
		return -1;
}

void employeedelete(employee arrayemployee[], int size, int i)
{
	
		arrayemployee[i].employee_id = arrayemployee[i+1].employee_id;
		strcpy(arrayemployee[i].name, arrayemployee[i+1].name);
		strcpy(arrayemployee[i].designation, arrayemployee[i+1].designation);
		arrayemployee[i].employeeStatus = arrayemployee[i+1].employeeStatus;
		strcpy(arrayemployee[i].address, arrayemployee[i+1].address);
		arrayemployee[i].employeeGender = arrayemployee[i+1].employeeGender;
		arrayemployee[i].employeemstatus = arrayemployee[i+1].employeemstatus;
		arrayemployee[i].d_o_b.day= arrayemployee[i+1].d_o_b.day;
		arrayemployee[i].d_o_b.month= arrayemployee[i+1].d_o_b.month;
		arrayemployee[i].d_o_b.year= arrayemployee[i+1].d_o_b.year;
		strcpy(arrayemployee[i].contact_numb, arrayemployee[i+1].contact_numb);
		arrayemployee[i].d_o_j.day= arrayemployee[i+1].d_o_j.day;
		arrayemployee[i].d_o_j.month= arrayemployee[i+1].d_o_j.month;
		arrayemployee[i].d_o_j.year= arrayemployee[i+1].d_o_j.year;
		arrayemployee[i].salary = arrayemployee[i+1].employee_id;
		arrayemployee[i].working_days = arrayemployee[i+1].working_days;
		
	
	employeecount--; //not decrementing carID cuz thats maintaining unique ID no.s
}
void editemployee(employee arrayemployee[], int size, int location)
{
	int selection_key=0; 


		cout<<"To Edit any field, press the required key and press Enter\n\n"
		<<"Name:"<<setw(28)<<"Press 1\n\n"
		<<"Designation:"<<setw(21)<<"Press 2\n\n"
		<<"status:"<<setw(26)<<"Press 3\n\n"
		<<"address:"<<setw(25)<<"Press 4\n\n"
		<<"Gender:"<<setw(26)<<"Press 5\n\n"
		<<"Maritial Status:"<<setw(17)<<"Press 6\n\n"
		<<"Date of Birth:"<<setw(19)<<"Press 7\n\n"
		<<"contact Number::"<<setw(17)<<"Press 8\n\n"
		<<"Date of joining:"<<setw(17)<<"Press 9\n\n"
		<<"salary:"<<setw(27)<<"Press 10\n\n"
		<<"working days:"<<setw(21)<<"Press 11\n\n"
		<<"To Exit to main menu, press 12.\n\n";
	while (selection_key != 12)
	{
		cout<<"\nEnter a selection key: ";
		cin>>selection_key;
		switch(selection_key)
		{
			case 1:
			char b[20];
			cin.getline (b, 20, '\n');
			cout<<"Enter a new Employee Name:\n";
			cin.getline(arrayemployee[location].name, 20, '\n');
			break;
									
			case 2:
			cout<<"Enter a new Designation:\n";
			cin>>arrayemployee[location].designation;
			break;
			
			case 3:
			cout<<"Enter a new Status (Enter 1 for Free, Enter 2 for Busy):\n";
			int status;
				cin>>status;
				switch (status)
				{
					case 1:
						arrayemployee[location].employeeStatus = Free;
						break;
		
					case 2:
						arrayemployee[location].employeeStatus = Busy;
						break;
			
					case 3:
						arrayemployee[employeecount].employeeStatus = Leave;
						break;
					default:
						cout<<"Invalid status entered. Status set to Free.";
						arrayemployee[location].employeeStatus = Free;
				}
				break;
		
			case 4:
			cout<<"Enter a new address:\n";
			cin.getline(arrayemployee[location].address, 45, '\n');
			break;
				
			case 5:
				int gender;
				cout<<"Enter a new gender (Enter 1 for male, Enter 2 for female):\n";
				cin>>gender;
				switch (status)
				{
					case 1:
						arrayemployee[location].employeeGender = Male;
						break;
		
					case 2:
						arrayemployee[location].employeeGender = Female;
						break;
			
					default:
						cout<<"Invalid entry";
				}
				break;
			break;
			
			case 6:
				cout<<"Enter a new Maritial Status (Enter 1 for Married, Enter 2 for Single, Enter 3 for Divorced):\n";
				cin>>status;
				switch (status)
				{
					case 1:
						arrayemployee[location].employeemstatus = Married;
						break;
		
					case 2:
						arrayemployee[location].employeemstatus = Single ;
						break;
					
					case 3:
						arrayemployee[employeecount].employeemstatus = Divorced;
						break;
						
			
					default:
						cout<<"Invalid entry, set to single";
						arrayemployee[location].employeemstatus = Single ;
				}
				break;

			case 7:
			cout<<"Enter a new Date of Birth:\n";
			cin>>arrayemployee[location].d_o_b.day>>arrayemployee[location].d_o_b.month>>arrayemployee[location].d_o_b.year;
			break;

			case 8:
			cout<<"Enter a new contact Number:\n";
			cin>>arrayemployee[location].contact_numb;
			break;

			case 9:
			cout<<"Enter a new Date of joining:\n";
			cin>>arrayemployee[location].d_o_j.day>>arrayemployee[location].d_o_j.month>>arrayemployee[location].d_o_j.year;
;
			break;

			case 10:
			cout<<"Enter new salary:\n";
			cin>>arrayemployee[location].salary;
			break;

			case 11:
			cout<<"Enter new working days:\n";
			cin>>arrayemployee[location].working_days;
			break;

			
			default:
			cout<<"Invalid selection key entered. Enter numbers from 1 to 11 only.\n\n";
		}
	}
	if (selection_key == 12)
	{
		cout<<"Returning to switchboard\n";
		return;
	}
}
void printemployee( employee arrayemployee[], int size, int i)
{
		cout<<"\nRecord Number "<<i+1<<endl;	
		cout<<"Employee ID: "<<arrayemployee[i].employee_id;
		cout<<"\nEmployee Name: "<<arrayemployee[i].name;
		cout<<"\nEmployee Designation: "<<arrayemployee[i].designation;
		switch (arrayemployee[i].employeeStatus)
	{
		case 1:
			cout<<"\nStatus: Free";
			break;
		case 2:
			cout<<"\nStatus: Busy";
			break;
		case 3:
			cout<<"\nStatus:Leave";
			break;
		default:
			cout<<"\nError in programme";
	}
	cout<<endl;

		cout<<"\nEmployee Address: "<<arrayemployee[i].address;
		switch (arrayemployee[i].employeeGender)
	{
		case 1:
			cout<<"\ngender: male";
			break;
		case 2:
			cout<<"\ngender: female";
			break;
		default:
			cout<<"\nError in programme";
	}
	cout<<endl;
		switch (arrayemployee[i].employeemstatus)
	{
		case 1:
			cout<<"\nStatus: married";
			break;
		case 2:
			cout<<"\nStatus: single";
			break;
		case 3:
			cout<<"\nStatus: Divorced";
			break;
		default:
			cout<<"\nError in programme";
	}
	cout<<endl;
	cout<<"\nEmployee Date of Birth: "<<arrayemployee[i].d_o_b.day<<'/'
	<<arrayemployee[i].d_o_b.month<<'/'<<arrayemployee[i].d_o_b.year;
	cout<<"\nEmployee Contact Number: "<<arrayemployee[i].contact_numb;
	cout<<"\nEmployee Date of joining: "<<arrayemployee[i].d_o_j.day<<'/'
	<<arrayemployee[i].d_o_j.month<<'/'<<arrayemployee[i].d_o_j.year;
	cout<<"\nEmployee Salary: "<<arrayemployee[i].salary;
	cout<<"\nEmployee Working Days: "<<arrayemployee[i].working_days;
	cout<<endl;
}


void incomeExpenditure(rented_cars arrayrented_cars[], int size, repair arrayrepair[], int size2, Customers arrayCustomers[], int size3)
{
	cout<<"Incomes and Expenditures Until Current Date:\n";
	cout<<"Income:\n";
	cout<<"Membership Fee: ";
	int total = 0;
	for (int i=0;i<customersCount;i++)
	{
		total = total + arrayCustomers[i].membership_fee;
	}
	cout<<total<<endl;
	cout<<"Rental Transactions: ";
	int total2 = 0;
	for (int i=0;i<rented_carsCount;i++)
	{
		total2 = total2 + arrayrented_cars[i].payment;
	}
	cout<<total2<<endl;
	cout<<"Total Income: "<<total + total2<<endl<<endl;
	cout<<"Expense:\n";
	cout<<"Repair Expense: ";
	int expense = 0;
	for (int i=0;i<repaircount;i++)
	{
		expense = expense + arrayrepair[i].repair_cost;
	}
	cout<<expense;
	cout<<endl<<endl;
	cout<<"TOTAL PROFIT: "<<total + total2 - expense<<endl;
}

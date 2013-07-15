#include<iostream>
#include<string>
#include<conio.h>
#include<ctime>
#include<fstream>
#include<Windows.h>

using namespace std;

///////////////////////////////////////////////////ACCOUNT MASTER CLASS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Account
{
protected:

	float ammount;
	string acc_type;
	string card_type;
public:

	Account()
	{
		int type;
		ammount=0;
		cout << "Constructor of Account" << endl;

	}
	virtual void Withdrawl()=0;
	virtual ~Account(){

	}

};

///////////////////////////////////////////////////SAVINGS ACCOUNT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Saving_account:virtual public Account
{
private:

	int acc_no[4];
public:
	Saving_account(int a) {

	}
	Saving_account()
	{
		cout << "Constructor of  Saving account" << endl;
		cout << "Enter ammount you want to deposit in your savings account: ";
		cin >> ammount;
	}

	void Withdrawl_check_book();
	void Withdrawl()
	{
		double withdraw;
		cout<<"How much would you like to withdraw from your account?"<<endl;
		cin>>withdraw;

		if(withdraw>ammount||withdraw==ammount&&withdraw>=5000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax): "<<ammount<<endl;
		}
		else if(withdraw>ammount||withdraw==ammount&&withdraw>=5000&&withdraw>50000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			ammount=ammount-(ammount*0.05);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 0.5% gov tax): "<<ammount<<endl;
		}

	}				
};

///////////////////////////////////////////////////CURRENT ACCOUNT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Checking_account:virtual public Account
{
private:

	int acc_no[4];
public:
	Checking_account(int a) {

	}
	Checking_account()
	{
		cout << "Constructor of Checking account" << endl;
		cout << "Enter ammount you want to deposit in your current account: ";
		cin >> ammount;
		cout<<"\n\nAs per conditions, interest of 1% has been added to your current balance for this month.";
		cout<<"Your new balance is: "<<(ammount*0.01)+ammount;
	}

	void Withdrawl()
	{
		double withdraw;
		cout<<"How much would you like to withdraw from your account?"<<endl;
		cin>>withdraw;

		if(withdraw>ammount||withdraw==ammount&&withdraw>=5000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 2.5% gov tax): "<<ammount<<endl;
		}
		else
		{
			cout << "Invalid Input" << endl;
		}

	}
};

////////////////////////////////////////////////////CARD MASTER CLASS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Card: public Checking_account, public Saving_account
{
protected:
	int type;
public: 
	Card() : Checking_account(1), Saving_account(2)
	{}
	double getamount() {
		return ammount;
	}
	void Withdrawl()=0;

};

////////////////////////////////////////////////////MASTER CARD\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class master: public Card
{
private:
	int m_number[4];

public:
	master()
	{
		srand(time(0));
		for(int i=0; i < 4; i++)
		{
			m_number[i]=0 + rand()% + 9;
		}

		cout << "You chose master card" << endl;
		cout << "Your card number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << m_number[i];
		}
		cout << endl;

	}

	void Withdrawl()
	{
		double withdraw=0;
		cout<<"How much would you like to withdraw from your account?"<<endl;
		cin>>withdraw;

		if(withdraw>ammount||withdraw==ammount&&withdraw>=5000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 2.5% gov tax): "<<ammount<<endl;
		}
		else
		{
			cout << "Invalid Input"<< endl;
		}
		ofstream outFile("Transactions.dat", ios::binary | ios::app);
		if(!outFile) {
			cout << "File cannot be opened" << endl;
			return;
		}
		outFile.write((char*)&ammount, sizeof(ammount));
		outFile.close();

	}

};

////////////////////////////////////////////////////VISA CARD\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class visa: public Card
{
private:     
	int v_number[4];

public:
	visa()
	{
		srand(time(0));
		for(int i=0; i < 4; i++)
		{
			v_number[i]=0 + rand()% + 9;
		}

		cout << "You chose visa card" << endl;
		cout << "Your card number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << v_number[i];
		}
	}

	void Withdrawl()
	{
		double withdraw=0;
		cout<<"How much would you like to withdraw from your account?"<<endl;
		cin>>withdraw;

		if(withdraw>ammount||withdraw==ammount&&withdraw>=5000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 2.5% gov tax): "<<ammount<<endl;
		}
		else if(withdraw>ammount||withdraw==ammount&&withdraw>=5000&&withdraw>50000)
		{
			cout << "Invalid Input";
		}
		ofstream outFile("Transactions.dat", ios::binary | ios::app);
		if(!outFile) {
			cout << "File cannot be opened" << endl;
			return;
		}
		outFile.write((char*)&ammount, sizeof(ammount));
		outFile.close();

	}
};

////////////////////////////////////////////////////LOCAL CARD\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class local: public Card
{
private:
	int l_number[4];

public:
	local()
	{
		srand(time(0));
		for(int i=0; i < 4; i++)
		{
			l_number[i]=0 + rand()% + 9;
		}

		cout << "You chose local card" << endl;
		cout << "Your card number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << l_number[i];
		}

	}

	void Withdrawl()
	{
		double withdraw;
		cout<<"How much would you like to withdraw from your account?"<<endl;
		cin>>withdraw;

		if(withdraw>ammount||withdraw==ammount&&withdraw>=5000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 2.5% gov tax): "<<ammount<<endl;
		}
		else if(withdraw>ammount||withdraw==ammount&&withdraw>=5000&&withdraw>50000)
		{
			ammount=ammount-withdraw;
			ammount=ammount-(ammount*0.002);
			ammount=ammount-(ammount*0.05);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 0.5% gov tax): "<<ammount<<endl;
		}
		ofstream outFile("Transactions.dat", ios::binary | ios::app);
		if(!outFile) {
			cout << "File cannot be opened" << endl;
			return;
		}
		outFile.write((char*)&ammount, sizeof(ammount));
		outFile.close();
	}

};

////////////////////////////////////////////////////CUSTOMER CLASS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class customer
{
protected:
	string acc_type;
	string card_type;
	string name;
	int CNIC[13];
	string address;
	int telephone;
	int day;
	int year;
	int month;
	int acc_number[4];
	int pin[4];
	Account* ACC_TYPE;
	Card* card_ptr;

public:
	customer()
	{
		cout << "Constructor of Customer being called" << endl;
		short int choice;
		bool exit=false;
		while(exit==false)
		{

			cout << "1. Current Account" << endl;
			cout << "2. Savings Account" << endl;
			cout << "Press 1 or 2 to choose your account type" << endl;
			cin >> choice;
			switch(choice)
			{
			case 1:
				{
					acc_type="Current";

					ACC_TYPE= new Checking_account;
					exit=true;
					break;
				}
			case 2:
				{
					acc_type="Savings";

					ACC_TYPE= new Saving_account;
					exit=true;
					break;
				}
			default:
				{
					cout << "Wrong input!\nEnter again" << endl;
					break;
				}
			}
		}
		int type;
		do
		{
		cout<<"What type of card would you like to possess?"<<endl
			<<"1.Master Card"<<endl
			<<"2.Visa Card"<<endl
			<<"3.Local Card"<<endl<<endl;
		cin>>type;
			if(type==1)
			{
				card_ptr=new master;
			}

			if(type==2)
			{
				card_ptr=new visa;
			}

			if(type==3)
			{
				card_ptr=new local;
			}

			else
			{
				break;
			}
		} while(choice != 1 && choice != 2 && choice != 3);
		cout << "Enter name: ";
		fflush(stdin);
		getline(cin,name);
		cout << "Enter CNIC number: ";

		for(int i=0; i < 5; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		for(int i=5; i < 12; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		CNIC[12] = _getche();

		cout << "\nEnter Address: "; 
		fflush(stdin);
		getline(cin,address);
		cout << "Enter Telephone number: ";
		cin >> telephone;
		cout << "Enter Date of birth in the format mm-dd-yyyy" << endl;
		cout << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
		srand(time(0));
		for(int i=0; i < 4; i++)
		{

			acc_number[i]= 0 + rand() % 10;
			pin[i]= 0 + (rand() % 10)+1;
		}

		cout << "Your Account number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << acc_number[i];
		}
		_getch();


		cout << "\nYou pin number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << pin[i];
		}
		_getch();
		menu();
	}
	void menu() {
		int Choice;
		do {
			cout << "1. Mini-Statement" << endl;
			cout << "2. Withdraw Money via Credit Card"<< endl;
			cout << "3. Withdraw Money via Check Book" << endl;
			cout << "4. Balance Enquiry" << endl;
			cout << "5. Transaction History" << endl;
			cout << "6. Exit" << endl;
			cout << "Enter Choice : ";
			cin >> Choice;
			switch(Choice) {
			case 1:
				break;
			case 2:
				card_ptr -> Withdrawl();
				write();
				break;
			case 3:
				ACC_TYPE -> Withdrawl();
				write();
				break;
			case 4:
				cout << "Your Account Balance is " << card_ptr -> getamount() << endl;
				break;
			case 5:
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
			}
		} while(Choice != 6);
	}
	void write() {
		ofstream outFile("Transactions.dat", ios::binary | ios::app);
		if(!outFile) {
			cout << "File Cannot be opened" << endl;
		}
		else {
			int size;
			size = name.length();
			outFile.write((char*)&size, sizeof(size));
			outFile.write((char*)name.c_str(), size);
			outFile.write((char*)&CNIC, sizeof(CNIC));
			size = acc_type.length();
			outFile.write((char*)&size, sizeof(size));
			outFile.write((char*)acc_type.c_str(), size);
			size = card_type.length();
			outFile.write((char*)&size, sizeof(size));
			outFile.write((char*)card_type.c_str(), size);
			size = address.length();
			outFile.write((char*)&size, sizeof(size));
			outFile.write((char*)address.c_str(), size);
			outFile.write((char*)&telephone, sizeof(telephone));
			outFile.write((char*)&day, sizeof(day));
			outFile.write((char*)&year, sizeof(year));
			outFile.write((char*)&month, sizeof(month));
			outFile.write((char*)&acc_number, sizeof(acc_number));
			outFile.write((char*)&pin, sizeof(pin));
			outFile.flush();
			outFile.close();
		}
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "CNIN: " << CNIC << endl;
		cout << "Account number: " << acc_number << endl;
	}

	void modify()
	{
		cout << "Alter Name: " << name << endl;
		getline(cin,name);

		cout << "Alter CNIC: " << CNIC << endl;
		for(int i=0; i < 5; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		for(int i=5; i < 12; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		CNIC[12] = _getche();

		cout << "\nChange address: "; 
		fflush(stdin);
		getline(cin,address);
		cout << "Change Telephone number: ";
		cin >> telephone;
		cout << "Change Date of birth in the format mm-dd-yyyy" << endl;
		cout << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
	}

};

////////////////////////////////////////////////////EMPLOYEE CLASS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class employee
{
protected:
	string acc_type;
	string card_type;
	string name;
	int CNIC[13];
	string address;
	int telephone;
	int day;
	int year;
	int month;
	int acc_number[4];
	int pin[4];
	double balance;

public:
	employee()
	{
		balance=0;
		cout << "Constructor of Employee being called" << endl;
		short int choice;

		cout<<"Current balance: "<<balance;

		cout << "Enter name: ";
		fflush(stdin);
		getline(cin,name);
		cout << "Enter CNIC number: ";

		for(int i=0; i < 5; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		for(int i=5; i < 12; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		CNIC[12] = _getche();

		cout << "\nEnter Address: "; 
		fflush(stdin);
		getline(cin,address);
		cout << "Enter Telephone number: ";
		cin >> telephone;
		cout << "Enter Date of birth in the format mm-dd-yyyy" << endl;
		cout << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
		srand(time(0));
		for(int i=0; i < 4; i++)
		{

			acc_number[i]= 0 + rand() % 10;
			pin[i]= 0 + (rand() % 10)+1;
		}

		cout << "Your Account number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << acc_number[i];
		}
		_getch();


		cout << "\nYou pin number is: ";
		for(int i=0; i < 4; i++)
		{
			cout << pin[i];
		}
		_getch();
	}

	void display()
	{
		cout << "Name: " << name << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "Account number: " << acc_number << endl;
	}

	void modify()
	{
		cout << "Alter Name: " << name << endl;
		getline(cin,name);

		cout << "Alter CNIC: " << CNIC << endl;
		for(int i=0; i < 5; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		for(int i=5; i < 12; i++)
		{
			CNIC[i] = _getche();
		}
		cout << "-";
		CNIC[12] = _getche();

		cout << "\nChange address: "; 
		fflush(stdin);
		getline(cin,address);
		cout << "Change Telephone number: ";
		cin >> telephone;
		cout << "Change Date of birth in the format mm-dd-yyyy" << endl;
		cout << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
	}

	void withdrawl()
	{
		double withdraw1;
		cout<<"How much would you like to withdraw from your account?"<<endl;
		cin>>withdraw1;

		if(withdraw1>balance||withdraw1==balance&&withdraw1>=5000)
		{
			balance=balance-withdraw1;
			balance=balance-(balance*0.002);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax): "<<balance<<endl;
		}
		else if(withdraw1>balance||withdraw1==balance&&withdraw1>=5000&&withdraw1>50000)
		{
			balance=balance-withdraw1;
			balance=balance-(balance*0.002);
			balance=balance-(balance*0.05);
			cout<<"Withdrawl successful. Current balance(subject to 0.2% service tax and 0.5% gov tax): "<<balance<<endl;
		}

	}

};


////////////////////////////////////////////////////PARENT BANK CLASS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class bank
{
private:
	customer* cust;
	employee* emp;
public:
	bank()
	{
		while(1)
		{
			cout<<"Are you logging in as a"<<endl<<"1.Customer"<<endl<<"2.Employee"<<endl;
			int choice;
			cin>>choice;
			if(choice==1)
			{
				customer c;
				cust=&c;
				//write(c);
				//read(c);
			}
			else if(choice==2)
			{
				employee e;
				emp=&e;
			}
			else
			{
				cout<<"Type does not exit. Try again";
			}
		}
	}

	void read(customer y)
	{
		cout << "Extracting from file..." << endl;
		ifstream ifile("bank.dat", ios::binary);
		if(ifile.fail())
		{
			cout << "File does not exist." << endl;
			return;
		}
		int check=1;
		while(true)
		{

			ifile.read((char*)&y , sizeof(y));
			if(ifile.eof())
			{

				break;
			}
			check++;
		}
		ifile.close();
		cout << "Here are the accounts present in file Bank." << endl;
	}
	~bank() {

	}


};

////////////////////////////////////////////////////WELCOME SCREEN\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void welcome_screen()
{
	char intro[]="Greetings";
	char intro2[]="Welcome to next generation banking.";
	char intro3[]="Brought to you first by our brilliant Head of IT, Sarmad Hasan.";

	for(int i=0;i<11;i++)
	{
		cout<<intro[i];
		Sleep(50);
	}
	cout<<endl<<endl<<endl<<endl;

	for(int j=0;j<36;j++)
	{
		cout<<intro2[j];
		Sleep(50);
	}
	cout<<endl<<endl<<endl<<endl;

	for(int k=0;k<74;k++)
	{
		cout<<intro3[k];
		Sleep(50);
	}

	system("cls");

	cout<<"                   FFFFFFFFFFF    A          SSSS    TTTTTTTTTTT"<<endl
		<<"                   F             A A        S             T     "<<endl
		<<"                   F            A   A       S             T     "<<endl
		<<"                   FFFFFF      A     A       SSSS         T     "<<endl
		<<"                   F          AAAAAAAAA          S        T     "<<endl
		<<"                   F         A         A         S        T     "<<endl
		<<"                   F        A           A    SSSS         T     "<<endl;
	Sleep(1000);
	system("cls");
}

int main()
{
	welcome_screen();
	system("cls");
	bank UBL;


}
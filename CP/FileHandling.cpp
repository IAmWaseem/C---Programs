#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct cdStruct //Structure containing Cd Database Elements
{
	string title;
	string artist;
	int numberOfSongs;
	int number;	
	cdStruct *next;
};

void save(cdStruct *ptr)	//Function that saves database info to file
{
	ofstream dataFile;
	dataFile.open("output.txt", ios::out | ios::app);
	dataFile << ptr->title << endl;
	dataFile << ptr->artist << endl;
	dataFile << ptr->numberOfSongs << endl;
	dataFile << ptr->number << endl;
	dataFile.close();			
}

void saveStructList(cdStruct *start)	//Function that passes database info to the save function

{
	ofstream dataFile;
	dataFile.open("output.txt",ios::trunc);
	dataFile.close();
	cdStruct *ptr = start->next;
	while(ptr)
	{
		save(ptr);
		ptr = ptr->next;
	}
}

void addLoadEntry(cdStruct* start)      
{
	ifstream dataFile("output.txt", ios::in);
	if(!dataFile) //file not open
		return; //return back to main

	while(!dataFile.eof());
	{
		cdStruct* newStruct = new cdStruct;
		getline(dataFile, newStruct->title);
		getline(dataFile, newStruct->artist);
		dataFile >> newStruct->numberOfSongs;
		dataFile >> newStruct->number;

		if(start == NULL)
		{
			start = newStruct; //if the first node (first link) is null, set the memory there
			start->next = NULL;
			return; //get out of the function
		}

		cdStruct *ptr = start;
		while(ptr->next != NULL) // loop through all the nodes to until you hit the end
			ptr = ptr->next;

		//ok now were are at the very last node
		ptr->next = newStruct;
		ptr->next->next = NULL;
	}
	dataFile.close();

} 

/*
void addLoadEntry(cdStruct* start)	//Function that creates a new structure
{
fstream dataFile("output.txt", ios::in);

//while(!dataFile.eof());
{
cdStruct* newStruct = new cdStruct;
cdStruct *newEntry = newStruct;  //getnewstruct()
getline(dataFile, newStruct->title);
getline(dataFile, newStruct->artist);
dataFile >> newStruct->numberOfSongs;
dataFile >> newStruct->number;
cdStruct *ptr = start;
while(ptr->next) // while the current entry points to ANOTHER entry
ptr = ptr->next;
// at this point ptr is a valid entry that points to null so it is the end (or tail) of the list
ptr->next = newEntry;
ptr->next->next = NULL;
}
dataFile.close();

}
*/

void printStruct(cdStruct *ptr)	//Function that prints database
{
	cout << "Title: " << ptr->title << endl;
	cout << "Artist: " << ptr->artist << endl;
	cout << "# of Songs: " << ptr->numberOfSongs << endl;
	cout << "ID #: " << ptr->number << endl;
}

void printStructList(cdStruct *start) //Function that sends database information to print function
{
	cdStruct *ptr = start->next;
	while(ptr)
	{
		printStruct(ptr);
		ptr = ptr->next;
	}
}

void modifyStruct(cdStruct *start, int find)	//Function to modifiy an existing database element
{
	cdStruct *current;
	cdStruct *previous;

	current = start->next; // Start the Current to the first real rec
	previous = start; // Start points to the first real rec
	while(current)
	{
		if(current->number == find) // Modifies the entry
		{
			cout << "Enter Cd Title: ";
			getline(cin, current->title);
			cout<< "Enter Artist Name: ";
			getline(cin, current->artist);
			cout << "Enter # of Songs: ";
			cin >> current->numberOfSongs;
			current->number = find;
			return;
		}

		else
		{
			previous = current;
			current = current->next; 
		}
		// This code bumps both the previous and current 
		// pointers one step down the line
	}

}

cdStruct *getNewStuct()	//Function to dynamically create a new structure as needed
{			
	cdStruct* newStruct = new cdStruct;
	cout << "Enter Cd Title: ";
	getline(cin, newStruct->title);
	cout<< "Enter Artist Name: ";
	getline(cin, newStruct->artist);
	cout << "Enter # of Songs: ";
	cin >> newStruct->numberOfSongs;
	cout<< "Enter Id # ";
	cin >> newStruct->number;
	return newStruct;
}

void addEntry(cdStruct* start)	//Function that creates a new structure
{
	cdStruct *newEntry = getNewStuct();
	cdStruct *ptr = start;
	while(ptr->next) // while the current entry points to ANOTHER entry
		ptr = ptr->next;
	// at this point ptr is a valid entry that points to null so it is the end (or tail) of the list
	ptr->next = newEntry;
	ptr->next->next = NULL;
}

int main()
{
	cdStruct *start = new cdStruct; // first element will NOT handle any info
	start->next = NULL;
	int temp, userChoice;
	do
	{
		// print menu
		cout << "------- Super CD 2.0 --------" << endl << endl;
		cout << "1. Print CD Database" << endl;
		cout << "2. Create a New Entry" << endl;
		cout << "3. Modify an Existing Entry" << endl;
		cout << "4. Save Database" << endl; 
		cout << "5. Load Database" << endl;
		cout << "6. Exit " << endl << endl;
		cout << "Your Selection -> ";

		cin >> userChoice;
		cin.ignore(200,'\n');
		switch(userChoice)
		{
		case 1:	//print user mendu
			printStructList(start);
			break;

		case 2:	//allow user to make a new entry
			addEntry(start);
			break;

		case 3:	//allow user to modify an existing entry
			cout<<"Enter number to be modified: ";
			cin >> temp;
			cin.ignore(200,'\n');
			modifyStruct(start, temp);
			break;

		case 4:	//allow user to save the database to file
			saveStructList(start);
			break;

		case 5:	//allow user to load an existing database
			addLoadEntry(start);
			break;

		case 6:	//allow user to exit the program
			cout << endl << "You Chose to Exit" << endl;

		} // switch
	}while(userChoice != 6);

	return 0;
}
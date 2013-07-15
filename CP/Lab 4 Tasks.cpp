#include <iostream>

using namespace std;

struct Item {
	int ID;
	char Name[50];
	int Quantity;
	Item *Next;
};

Item *First = NULL;

void SwitchBoard();
void StoreInformation(Item*);
void AddItem();
void AddItemAtHead();
bool AddItemAtMiddle(int);
void AddItemAtTail();
void DisplayAllItems();
void SellItem();
void DeleteItem();
void ModifyItem();
void FindItem(int);
//void DeleteAll();

int main() {
	SwitchBoard();
	return 0;
}

void SwitchBoard() {
	system("cls");
	int Choice;
	cout << "MAIN MENU" << endl << endl;
	cout << "[1] Add a New Item to Store" << endl;
	cout << "[2] Sell an Item from Store" << endl;
	cout << "[3] Delete an Item from Store" << endl;
	cout << "[4] Modify Name of an Item from Store" << endl;
	cout << "[5] Find an Item in the Store" << endl;
	cout << "[6] Display All Items" << endl;
	cout << "[7] Exit The Application" << endl << endl;
	cout << "Enter Choice[1-6]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			AddItem();
			SwitchBoard();
			break;
		case 2:
			SellItem();
			system("pause");
			SwitchBoard();
			break;
		case 3:
			DeleteItem();
			system("pause");
			SwitchBoard();
			break;
		case 4:
			ModifyItem();
			system("pause");
			SwitchBoard();
			break;
		case 5:
			int ID;
			cout << "Enter ID of the Item : ";
			cin >> ID;
			FindItem(ID);
			system("pause");
			SwitchBoard();
			break;
		case 6:
			DisplayAllItems();
			system("pause");
			SwitchBoard();
			break;
		case 7:
			cout << "Exiting..." << endl;
			//DeleteAll();
			system("pause");
			exit(1);
			break;
		default:
			cout << "Invalid Choice" << endl;
			system("pause");
			SwitchBoard();
			break;
	}
}

void StoreInformation(Item *myItem) {
	cout << "Enter ID of the Item : ";
	cin >> myItem -> ID;
	cout << "Enter Name of the Item : ";
	fflush(stdin);
	cin.getline(myItem -> Name, 50);
	cout << "Enter Quantity of the Item : ";
	cin >> myItem -> Quantity;
	return;
}

void AddItem() {
	system("cls");
	int Choice, Key;
	cout << "Add Item" << endl << endl;
	cout << "[1] Add Item at Start" << endl;
	cout << "[2] Add Item at Middle" << endl;
	cout << "[3] Add Item at End" << endl;
	cout << "[4] Return to Main Menu" << endl << endl;
	cout << "Enter Choice[1-4]: ";
	cin >> Choice;
		switch(Choice) {
		case 1:
			AddItemAtHead();
			cout << "Item Added Successfully" << endl;
			system("pause");
			AddItem();
			break;
		case 2:
			cout << "Enter ID of the Item to Add After : ";
			cin >> Key;
			if(AddItemAtMiddle(Key)) {
				cout << "Item Added Successfully" << endl;
			}
			system("pause");
			AddItem();
			break;
		case 3:
			AddItemAtTail();
			cout << "Item Added Successfully" << endl;
			system("pause");
			AddItem();
			break;
		case 4:
			SwitchBoard();
			break;
		default:
			cout << "Invalid Choice" << endl;
			system("pause");
			AddItem();
			break;
	}
	return;
}

void AddItemAtHead() {
	Item *Node;
	Node = new Item;
	StoreInformation(Node);
	Node -> Next = First;
	First = Node;
	return;
}

void AddItemAtTail() {
	Item *Node, *Current = First;
	Node = new Item;
	StoreInformation(Node);
	Node -> Next = NULL;
	if(First == NULL) {
		First = Node;
		return;
	}
	while(Current -> Next != NULL) {
		Current = Current -> Next;
	}
	Current -> Next = Node;
	return;
}

bool AddItemAtMiddle(int Key) {
	Item *Node, *Current, *Previous;
	Node = new Item;
	Current = First;
	Previous = First;
	while(Current -> ID != Key) {
		if(Current -> Next == NULL) {
			cout << "ID Not Found" << endl;
			return false;
		}
		Previous = Current;
		Current = Current -> Next;
	}
	StoreInformation(Node);
	Node -> Next = Previous -> Next;
	Previous -> Next = Node;
	return true;
}

void DisplayAllItems() {
	Item *Current;
	Current = First;
	while(Current != NULL) {
		cout << "Item ID : " << Current -> ID << endl;
		cout << "Item Name : " << Current -> Name << endl;
		cout << "Item Quantity : " << Current -> Quantity << endl << endl;
		Current = Current -> Next;
	}
	return;
}

void SellItem() {
	int ID, ItemsToSell;
	Item *Current, *Previous;
	Current = First;
	cout << "Enter ID of the Item : ";
	cin >> ID;
	while(Current != NULL && Current -> ID != ID) {
		Previous = Current;
		Current = Current -> Next;
	}
	if(Current == NULL)	{
		cout << "Item not found with that ID" << endl;
		return;
	}
	cout << "How Many Items to Sell : ";
	cin >> ItemsToSell;
	if(Current -> Quantity < ItemsToSell) {
		cout << "Not Enough Quantity of Items Available" << endl;
		return;
	}
	else {
		Current -> Quantity -= ItemsToSell;
		cout << ItemsToSell << " Items Sold" << endl;
	}
	if(Current -> Quantity == 0) {
		cout << "Item Deleted as it is not longer in Stock" << endl;
		if (Current == First) {
			First = First -> Next;
		}
		else {
			Previous -> Next = Current -> Next;
		}
		delete Current;
	}
	return;
}

void DeleteItem() {
	int ID;
	Item *Current, *Previous;
	Current = First;
	cout << "Enter ID of the Item : ";
	cin >> ID;
	while(Current != NULL && Current -> ID != ID) {
		Previous = Current;
		Current = Current -> Next;
	}
	if(Current == NULL)	{
		cout << "Item not found with that ID" << endl;
		return;
	}
	if (Current == First) {
		First = First -> Next;
	}
	else {
		Previous -> Next = Current -> Next;
	}
	delete Current;
	cout << "Item Deleted Successfully" << endl;
	return;
}

void ModifyItem() {
	char Name[50];
	int ID;
	Item *Current = First;
	cout << "Enter ID of the Item : ";
	cin >> ID;
	while(Current != NULL && Current -> ID != ID) {
		Current = Current -> Next;
	}
	if(Current == NULL) {
		cout << "Item not found with that ID" << endl;
		return;
	}
	cout << "Enter New Name for the Item : ";
	fflush(stdin);
	cin.getline(Name,50);
	strcpy(Current -> Name, Name);
	cout << "Name Changed Successfully" << endl;
	return;
}

void FindItem(int ID) {
	Item *Current = First;
	while(Current != NULL && Current -> ID != ID) {
		Current = Current -> Next;
	}
	if(Current == NULL) {
		cout << "Item not found with that ID" << endl;
		return;
	}
	cout << "Item ID : " << Current -> ID << endl;
	cout << "Item Name : " << Current -> Name << endl;
	cout << "Item Quantity : " << Current -> Quantity << endl << endl;
	return;
}
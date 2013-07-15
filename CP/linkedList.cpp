//============================================================================
// Name        : linkedList.cpp
// Author      : Sibt ul Hussain
//============================================================================

#include <iostream>
using namespace std;
// declare the Node structure.
struct Node {
	int data;
	Node *link;
};
/*Function adds a new node at the front end of linklist */
void AddAtFront(Node *&head, Node*&tail) {

	Node *var = new Node;
	cout << " Enter the Value of Element: ";
	cin >> var->data;

	if (head == NULL && tail == NULL) // first element, link list is empty
			{
		head = var; // our head and tail will be pointing to the same Node.
		tail = var; // head=tail=var;
	} else {
		var->link = head; // first chain the existing head to the current newly created node

		head = var; // update the head information
	}
}
/*Function adds a new node at the back end of linklist */
void AddAtBack(Node *&head, Node*&tail) {
	Node *var = new Node;
	cout << " Enter the Value of Element: ";
	cin >> var->data;

	if (head == NULL && tail == NULL) // first element, link list is empty
			{
		head = var; // our head and tail will be pointing to the same Node.
		tail = var; // head=tail=var;
	} else {
		tail->link = var; // first, chain the new node to the tail of existing list

		tail = var; // update the tail information,
	}
}

void PrintList(Node *&head, Node*&tail)
/*Print the link list starting from the head to tail*/{
	if (head == NULL && tail == NULL) // list is empty
			{
		cout << "\n List is empty, so displaying nothing";
		return;
	}
	Node *currNode = head; // start from the head node.
	int count = 0;
	do { // loop from head to tail
		 // first, displ
		cout << "\n Node Number = " << ++count << " Has data ="
				<< currNode->data;
		currNode = currNode->link; //update the currNode such that it points to next node now.
	} while (currNode != 0); // stop if currNode == 0 because we have reached at the end of list..
}

void DeleteFromFront(Node *&head, Node*&tail)
/*Function delete an existing node from the front
 * We Perform reverse procedure of AddatFront*/{

	if (head == NULL && tail == NULL) // first element, link list is empty
			{
		cout << "\n Sorry, List is empty cannot delete from front";

	} else if (head == tail) {
		// there is only single element in the list
		Node *var = head;
		head = NULL;
		tail = NULL;
		cout << " \n Deleted Node has following data --->" << var->data;
		delete var; // delete the data pointed by var
	} else {
		Node *var = head;
		head = head->link; // move the head one node forward
		cout << " \n Deleted Node has following data --->" << var->data;
		delete var; // delete the previous head node...
	}
}

void DeleteFromBack(Node *&head, Node*&tail)
/*Function delete an existing node from back
 * We Perform reverse procedure of AddatBack*/{

	if (head == NULL && tail == NULL) // first element, link list is empty
			{
		cout << "\n Sorry, List is empty cannot delete from back";

	} else if (head == tail) {
		// there is only single element in the list
		Node *var = head;
		head = NULL;
		tail = NULL;
		cout << " \n Deleted Node has following data --->" << var->data;
		delete var; // delete the data pointed by var
	} else {
		Node *currNode = head; // start from the head node from the head
		while (currNode->link != tail) // move current node until it link to the end node..
			currNode = currNode->link;
		Node *var = tail;
		currNode->link = NULL; // first put null to next link.
		tail = currNode; // update the tail..
		cout << " \n Deleted Node has following data --->" << var->data;
		delete var; // delete the old tail node..
	}
}

//
int main(void) {
	Node *head, *tail;
	head = NULL;
	tail = NULL; // both head and tail initially points to NULL
	int choice = 0;
	while (1) {
		cout << "\n --------------MENU ------------ " << endl
				<< " Press 1. To Enter at the Front " << endl
				<< " Press 2. To Enter at the Back" << endl
				<< " Press 3. To Delete from the Front " << endl
				<< " Press 4. To Delete from the Back" << endl
				<< " Press 5. To Print the Complete List from head to tail"
				<< endl << " Press 6: To Exit" << endl
				<< "\n ------------------------------- " << endl
				<< "Your Choice :";
		cin >> choice;
		switch (choice) {
		case 1:
			AddAtFront(head, tail);
			break;
		case 2:
			AddAtBack(head, tail);
			break;
		case 3:
			DeleteFromFront(head, tail);
			break;
		case 4:
			DeleteFromBack(head, tail);
			break;
		case 5:
			PrintList(head, tail);
			break;
		case 6:
			cout << " \n Exiting .... " << endl;
			return 0;
		default:
			cout << "\n Invalid Option, Please use any of the listed options"
					<< endl;
		}

	}
}

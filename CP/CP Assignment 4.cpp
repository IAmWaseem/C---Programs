// Name    : Waseem Hassan Shahid
// Roll No : i12-0097
// Section : F

/*
#include <iostream>

using namespace std;

// Class Node
class Node {
	friend class SparseVector;
	public:
		Node();
		int GetValue();
	private:
		int Index;
		int Value;
		Node* Next;
};

// Function Node::Node()
Node::Node() {
	Index = Value = 0;
	Next = NULL;
}
// Function int Node::GetValue()
int Node::GetValue() {
	return this -> Value;
}

// Class SparseVector
class SparseVector {
	friend ostream& operator<<(ostream& out, SparseVector &sv);
	public:
		SparseVector();
		SparseVector(int size);
		void SetElement(int i, int value);
		void PrintVector();
		void StoreVector();
		int GetElement(int i);
		int GetSize() const;
		SparseVector operator+(const SparseVector &obj) const;
		SparseVector operator-(const SparseVector &obj) const;
		SparseVector operator*(const SparseVector &obj) const;
		SparseVector operator=(const SparseVector &obj);
		void operator+=(const SparseVector &obj);
		void operator-=(const SparseVector &obj);
		bool operator==(const SparseVector &obj);
		bool operator!=(const SparseVector &obj);
		~SparseVector();
	private:
		Node* GetNode(int i, Node* root) const;
		Node* InsertNode(int i, int value, Node* root) const;
		Node* DeleteNode(int i, Node* root);
		Node* Vector;														// Points to the Start of the Vector
		const int Size;														// Size of Sparse Vector
};


// Function ostream& operator<<(ostream& out, SparseVector &sv)
ostream& operator<<(ostream& out, SparseVector &sv) {
	Node* Temp;
	for(int i = 0; i < sv.Size; i++) {
		Temp = sv.GetNode(i, sv.Vector);
		if(Temp != NULL) {
			out << "Index : " << i << "\t" << "Value : " << Temp -> GetValue() << endl;
		}
	}
	return out;
}

// Function SparseVector::SparseVector()
SparseVector::SparseVector() : Size(0) {
	Vector = NULL;
}

// Function SparseVector::SparseVector(int size)
SparseVector::SparseVector(int size) : Size(size) {
	Vector = NULL;
}

// Function void SparseVector::SetElement(int i, int value)
void SparseVector::SetElement(int i, int value) {
	this -> Vector = InsertNode(i, value, this -> Vector);
	return;
}

// Function void SparseVector::PrintVector()
void SparseVector::PrintVector() {
	Node* Temp;
	for(int i = 0; i < this -> Size; i++) {
		Temp = GetNode(i, this -> Vector);
		if(Temp == NULL) {
			cout << "\t-";
		}
		else {
			cout << "\t" << Temp -> Value;
		}
	}
}

// Function void SparseVector::StoreVector()
void SparseVector::StoreVector() {
	int Temp;
	for(int i = 0; i < this -> Size; i++) {
		cout << "Enter Value : ";
		cin >> Temp;
		if(Temp != 0) {
			this -> Vector = InsertNode(i, Temp, this -> Vector);		
		}
	}
}

// Function int SparseVector::GetElement(int i)
int SparseVector::GetElement(int i) {
	Node* Temp;
	Temp = GetNode(i, this -> Vector);
	if(Temp != NULL) {
		return Temp -> Value;
	}
	return 0;
}

// Function int SparseVector::GetSize() const
int SparseVector::GetSize() const {
	return Size;
}

// Function SparseVector SparseVector::operator+(const SparseVector &obj) const
SparseVector SparseVector::operator+(const SparseVector &obj) const {
	if(this -> Size != obj.Size) {
		cout << "Cannot Add these 2 Vectors" << endl;
		return NULL;
	}
	SparseVector *Temp = new SparseVector(this -> Size);
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 == NULL && Temp2 == NULL) {
			continue;
		}
		else if(Temp1 == NULL && Temp2 != NULL) {
			Temp -> Vector = InsertNode(i, Temp2 -> Value, Temp -> Vector);
		}
		else if(Temp1 != NULL && Temp2 == NULL) {
			Temp -> Vector = InsertNode(i, Temp1 -> Value, Temp -> Vector);
		}
		else if(Temp1 != NULL && Temp2 != NULL) {
			Temp -> Vector = InsertNode(i, Temp1 -> Value + Temp2 -> Value, Temp -> Vector);
		}
		else {
			continue;
		}
	}
	return *Temp;
}

//Function SparseVector SparseVector::operator-(const SparseVector &obj) const
SparseVector SparseVector::operator-(const SparseVector &obj) const {
	if(this -> Size != obj.Size) {
		cout << "Cannot Subtract these 2 Vectors" << endl;
		return NULL;
	}
	SparseVector *Temp = new SparseVector(this -> Size);
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 == NULL && Temp2 == NULL) {
			continue;
		}
		else if(Temp1 == NULL && Temp2 != NULL) {
			Temp -> Vector = InsertNode(i, -(Temp2 -> Value), Temp -> Vector);
		}
		else if(Temp1 != NULL && Temp2 == NULL) {
			Temp -> Vector = InsertNode(i, Temp1 -> Value, Temp -> Vector);
		}
		else if(Temp1 != NULL && Temp2 != NULL && (Temp1 -> Value - Temp2 -> Value != 0)) {
			Temp -> Vector = InsertNode(i, Temp1 -> Value - Temp2 -> Value, Temp -> Vector);
		}
		else {
			continue;
		}
	}
	return *Temp;
}

// Function SparseVector SparseVector::operator*(const SparseVector &obj) const
SparseVector SparseVector::operator*(const SparseVector &obj) const {
	if(this -> Size != obj.Size) {
		cout << "Cannot Multiply these 2 Vectors" << endl;
		return NULL;
	}
	SparseVector *Temp = new SparseVector(this -> Size);
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 != NULL && Temp2 != NULL) {
			Temp -> Vector = InsertNode(i, Temp1 -> Value * Temp2 -> Value, Temp -> Vector);
		}
	}
	return *Temp;
}

//Function SparseVector SparseVector::operator=(const SparseVector &obj)
SparseVector SparseVector::operator=(const SparseVector &obj) {
	if(this -> Size != obj.Size) {
		cout << "Cannot Assign these 2 Vectors" << endl;
		return NULL;
	}
	for(int i = 0; i < this -> Size; i++) {
		this -> Vector = DeleteNode(i, this -> Vector);
	}
	Node* Temp;
	for(int i = 0; i < obj.Size; i++) {
		Temp = GetNode(i, obj.Vector);
		if(Temp != NULL) {
			this -> Vector = InsertNode(i, Temp -> Value, this -> Vector);
		}
	}
	return *this;
}

// Function void SparseVector::operator+=(const SparseVector &obj)
void SparseVector::operator+=(const SparseVector &obj) {
	if(this -> Size != obj.Size) {
		cout << "Cannot Assign these 2 Vectors" << endl;
		return;
	}
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 == NULL && Temp2 == NULL) {
			continue;
		}
		else if(Temp1 != NULL && Temp2 != NULL) {
			Temp1 -> Value += Temp2 -> Value;
		}
		else if(Temp1 == NULL && Temp2 != NULL) {
			this -> Vector = InsertNode(i, Temp2 -> Value, this -> Vector);
		}
		else {
			continue;
		}
	}
}

// Function void SparseVector::operator-=(const SparseVector &obj)
void SparseVector::operator-=(const SparseVector &obj) {
	if(this -> Size != obj.Size) {
		cout << "Cannot Assign these 2 Vectors" << endl;
		return;
	}
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 == NULL && Temp2 == NULL) {
			continue;
		}
		else if(Temp1 != NULL && Temp2 != NULL) {
			Temp1 -> Value -= Temp2 -> Value;
		}
		else if(Temp1 == NULL && Temp2 != NULL) {
			this -> Vector = InsertNode(i, -(Temp2 -> Value), this -> Vector);
		}
		else {
			continue;
		}
	}
}

// Function bool SparseVector::operator==(const SparseVector &obj)
bool SparseVector::operator==(const SparseVector &obj) {
	if(this -> Size != obj.Size) {
		return false;
	}
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 == NULL && Temp2 == NULL) {
			continue;
		}
		else if(Temp1 == NULL && Temp2 != NULL) {
			return false;
		}
		else if(Temp1 != NULL && Temp2 == NULL) {
			return false;
		}
		else if(Temp1 -> Value != Temp2 -> Value) {
			return false;
		}
	}
	return true;
}

// Function bool SparseVector::operator!=(const SparseVector &obj)
bool SparseVector::operator!=(const SparseVector &obj) {
	if(this -> Size != obj.Size) {
		return true;
	}
	Node* Temp1;
	Node* Temp2;
	for(int i = 0; i < this -> Size; i++) {
		Temp1 = GetNode(i, this -> Vector);
		Temp2 = GetNode(i, obj.Vector);
		if(Temp1 == NULL && Temp2 == NULL) {
			continue;
		}
		else if(Temp1 == NULL && Temp2 != NULL) {
			return true;
		}
		else if(Temp1 != NULL && Temp2 == NULL) {
			return true;
		}
		else if(Temp1 -> Value != Temp2 -> Value) {
			return true;
		}
	}
	return false;
}

// Function SparseVector::~SparseVector()
SparseVector::~SparseVector() {
	for(int i = 0; i < this -> Size; i++) {
		Node* Temp = DeleteNode(i, this -> Vector);
		if(Temp != NULL) {
			this -> Vector = Temp;
		}
	}
}

// Function Node* SparseVector::GetNode(int i, Node* root) const
Node* SparseVector::GetNode(int i, Node* root) const {
	if(root == NULL) {
		return NULL;
	}
	else if(root -> Index > i) {
		return NULL;
	}
	else if(root -> Index == i) {
		return root;
	}
	else if(root -> Index < i && root -> Next != NULL) {
		return GetNode(i, root -> Next);
	}
	return NULL;
}

// Function Node* SparseVector::InsertNode(int i, int value, Node* root) const
Node* SparseVector::InsertNode(int i, int value, Node* root) const {
	if(root == NULL) {
		root = new Node;
		root -> Index = i;
		root -> Value = value;
		root -> Next = NULL;
	}
	else if(root -> Index > i) {
		Node* Temp = root;
		root = new Node;
		root -> Index = i;
		root -> Value = value;
		root -> Next = Temp;
	}
	else if(root -> Index == i) {
		root -> Value = value;
	}
	else if(root -> Index < i) {
		if(root -> Next != NULL && root -> Next -> Index > i) {
			Node* Temp = new Node;
			Temp -> Index = i;
			Temp -> Value = value;
			Temp -> Next = root -> Next;
			root -> Next = Temp;
		}
		else {
			root -> Next = InsertNode(i, value, root -> Next);
		}
	}
	return root;
}

// Function Node* SparseVector::DeleteNode(int i, Node* root)
Node* SparseVector::DeleteNode(int i, Node* root) {
	if(root == NULL) {
		return NULL;
	}
	else if(root -> Index > i) {
		return NULL;
	}
	else if(root -> Index == i) {
		Node* Temp;
		Temp = root -> Next;
		delete root;
		root = Temp;
		return root;
	}
	else if(root -> Index < i) {
		if(root -> Next == NULL) {
			delete root;
			return NULL;
		}
		else {
			//return DeleteNode(i, root -> Next);
			return NULL;
		}
	}
	return NULL;
}

// Function int main()
int main() {
	SparseVector v1(10);
	SparseVector v2(10);
	v1.StoreVector();
	SparseVector v3(10);
	v2.StoreVector();
	cout << v3;
	cout << v1;
	cout << v2;
	cout << v1 * v2;
	cout << v1 + v2;
	cout << v2 - v2;
	v1 += v2;
	v2 += v3;
	if(v1 == v2) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	if(v1 != v2) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}
*/

#include <iostream>
#include <iomanip>

using namespace std;

class List
{
    friend class SparseVector;
    private:
        struct Node
		{
            int Index;
            int Value;
            Node *Next;
        };
        Node *Head;
        int Count;
    public:
        List();
        void Add(int i, int val);
        int DisplaySpecific(int i) const;
        int GetCount() const;
        List::Node* GetNode(int i);
};

class SparseVector
{
    friend ostream& operator<<(ostream& out, SparseVector& sv);
    public:
        SparseVector();
        SparseVector(int size);
        SparseVector(const SparseVector &sv);
        int GetSize() const;
        int GetElement(int col) const;
        void SetElement(int col);
        void operator=(const SparseVector& sv);
        SparseVector& operator+(const SparseVector& sv) const;
		SparseVector& operator-(const SparseVector& sv) const;
		bool operator==(const SparseVector& sv);
		bool operator!=(const SparseVector& sv);
		SparseVector& operator*(const SparseVector& sv) const;
		void operator+=(const SparseVector& sv);
		void operator-=(const SparseVector& sv);
        // ~SparseVector();
    private:
        bool IsFull() const;
        List Vector;
        const int Size;
};

ostream& operator<<(ostream& out, SparseVector& sv)
{
    cout << "Column\t\t" << "Value" << endl << endl;
    for(int i = 1; i <= sv.Size; i++)
	{
        out << setw(5) << i << setw(16) << sv.Vector.DisplaySpecific(i) << endl;
    }
    return out;
}

SparseVector::SparseVector() : Vector(), Size(0)
{

}

SparseVector::SparseVector(int size) : Vector(), Size(size)
{

}

SparseVector::SparseVector(const SparseVector &sv) : Size(sv.Size)
{
    Vector = sv.Vector;
}

int SparseVector::GetSize() const
{
    return Size;
}

int SparseVector::GetElement(int col) const
{
    if(col > Size || col <= 0 || IsFull())
	{
        cout << "Column Does Not Exist" << endl;
        return EOF;
    }
    return Vector.DisplaySpecific(col);
}

void SparseVector::SetElement(int col)
{
    if(col > Size || col <= 0 || IsFull())
	{
        cout << "Column Does Not Exist" << endl;
        return;
    }
    int value;
    cout << "Enter Value : ";
    cin >> value;
    Vector.Add(col, value);
}

bool SparseVector::IsFull() const
{
    if(Vector.Count == Size) {
        return true;
    }
    return false;
}

void SparseVector::operator=(const SparseVector& sv)
{
	if(Size != sv.Size)
	{
		cout << "Cannot Assign 2 Vectors" << endl;
		return;
	}
	else
	{
		List::Node* Current = sv.Vector.Head;
		Vector.Head = NULL;
		while(Current != NULL)
		{
			Vector.Add(Current -> Index, Current -> Value);
			Current = Current -> Next;
		}
	}
}

SparseVector& SparseVector::operator+(const SparseVector& sv) const
{
    SparseVector *temp;
	temp = new SparseVector(sv.Size);
    if(Size != sv.Size)
	{
        cout << "Cannot add these Vectors" << endl;
    }
    else
	{
		List::Node* Current = sv.Vector.Head;
		List::Node* CurrentThis = Vector.Head;
		while(Current != NULL)
		{
			if(Current -> Index == CurrentThis -> Index)
			{
				temp -> Vector.Add(Current -> Index, Current -> Value + CurrentThis -> Value);
			}
			else
			{
				temp -> Vector.Add(Current -> Index, Current -> Value);
				temp -> Vector.Add(CurrentThis -> Index, CurrentThis -> Value);
			}
			Current = Current -> Next;
			CurrentThis = CurrentThis -> Next;
		}
	}
	return *temp;
}

SparseVector& SparseVector::operator-(const SparseVector& sv) const
{
	SparseVector *temp;
	temp = new SparseVector(sv.Size);
    if(this -> Size != sv.Size)
	{
        cout << "Cannot subtract these Vectors" << endl;
    }
    else
	{
		List::Node* Current = sv.Vector.Head;
		List::Node* CurrentThis = Vector.Head;
		while(Current != NULL)
		{
			if(Current -> Index == CurrentThis -> Index && (Current -> Value - CurrentThis -> Value != 0))
			{
				temp -> Vector.Add(Current -> Index, CurrentThis -> Value - Current -> Value);
			}
			else
			{
				temp -> Vector.Add(Current -> Index, -(Current -> Value));
				temp -> Vector.Add(CurrentThis -> Index, CurrentThis -> Value);
			}
			Current = Current -> Next;
			CurrentThis = CurrentThis -> Next;
		}
	}
	return *temp;
}

bool SparseVector::operator==(const SparseVector& sv)
{
	if(Size != sv.Size) 
	{
		return false;
	}
	List::Node* Current = sv.Vector.Head;
	List::Node* CurrentThis = Vector.Head;
	while(Current != NULL) 
	{
		if(Current -> Index != CurrentThis -> Index) 
		{
			return false;
		}
		else if(Current -> Value != CurrentThis -> Value)
		{
			return false;
		}
		Current = Current -> Next;
		CurrentThis = CurrentThis -> Next;
	}
	return true;
}

bool SparseVector::operator!=(const SparseVector& sv) 
{
	if(Size != sv.Size)
	{
		return true;
	}
	List::Node* Current = sv.Vector.Head;
	List::Node* CurrentThis = Vector.Head;
	while(Current != NULL) 
	{
		if(Current -> Index != CurrentThis -> Index)
		{
			return true;
		}
		else if(Current -> Value != CurrentThis -> Value)
		{
			return true;
		}
		Current = Current -> Next;
		CurrentThis = CurrentThis -> Next;
	}
	return false;
}

SparseVector& SparseVector::operator*(const SparseVector& sv) const
{
	SparseVector *temp;
	temp = new SparseVector(sv.Size);
    if(this -> Size != sv.Size)
	{
        cout << "Cannot multiply these Vectors" << endl;
    }
    else
	{
		List::Node* Current = sv.Vector.Head;
		List::Node* CurrentThis = Vector.Head;
		while(Current != NULL)
		{
			if(Current -> Index == CurrentThis -> Index)
			{
				temp -> Vector.Add(Current -> Index, Current -> Value * CurrentThis -> Value);
			}
			Current = Current -> Next;
			CurrentThis = CurrentThis -> Next;
		}
	}
	return *temp;
}

void SparseVector::operator+=(const SparseVector& sv)
{
	if(Size != sv.Size) 
	{
		cout << "Cannot add these vectors" << endl;
	}
	else {
		List::Node* Current = sv.Vector.Head;
		List::Node* CurrentThis = Vector.Head;
		while(Current != NULL) {
			if(Current -> Index == CurrentThis -> Index)
			{
				CurrentThis -> Value += Current -> Value;
			}
			else
			{
				Vector.Add(Current -> Index, Current -> Value);
			}
		}
	}
}

void SparseVector::operator-=(const SparseVector& sv)
{
	if(Size != sv.Size)
	{
		cout << "Cannot subtract these vectors" << endl;
	}
	else
	{
		List::Node* Current = sv.Vector.Head;
		List::Node* CurrentThis = Vector.Head;
		while(Current != NULL)
		{
			if(Current -> Index == CurrentThis -> Index)
			{
				CurrentThis -> Value -= Current -> Value;
			}
			else
			{
				Vector.Add(Current -> Index, -(Current -> Value));
			}
		}
	}
}

List::List()
{
    Head = NULL;
    Count = 0;
}

void List::Add(int i, int val)
{
    Node *node = new Node;
    node -> Index = i; node -> Value = val;
    if(Head == NULL)
	{
        node -> Next = Head;
        Head = node;
        Count++;
        return;
    }
    Node *Current = Head;
    Node *Previous = Current;
    while(Current != NULL && i >= Current -> Index)
	{
        if(Current -> Index == i)
		{
            Current -> Value = val;
            delete node;
            return;
        }
        Previous = Current;
        Current = Current -> Next;
    }
    if(Current == Head) 
	{
        node -> Next = Head;
        Head = node;
    }
    else
	{
        node -> Next = Previous -> Next;
        Previous -> Next = node;
    }
    Count++;
}

int List::DisplaySpecific(int i) const
{
    Node *Current = Head;
    while(Current != NULL && Current -> Index != i)
	{
        Current = Current -> Next;
    }
    if(Current == NULL)
	{
        return 0;
    }
    return Current -> Value;
}

int List::GetCount() const
{
    return Count;
}

List::Node* List::GetNode(int i)
{
    Node *Current = Head;
    for(int j = 1; j < i; j++)
	{
        Current = Current -> Next;
    }
    return Current;
}

int main() 
{
    int size;
    cout << "Enter Size of Vector : ";
    cin >> size;
    SparseVector v1(size);
    SparseVector v2(size);
    SparseVector v3(size);
    v1.SetElement(1);
    v1.SetElement(3);
    v1.SetElement(5);
    v1.SetElement(4);
    v1.SetElement(2);
	v3 = v1;
	v2 = v1 * v3;
    cout << v1;
    cout << v3;
	cout << v2;
	if(v1 == v2) {
		cout << "True";
	}
	else {
		cout << "False";
	}
    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

class List {
    friend class SparseVector;
    private:
        struct Node {
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

class SparseVector {
    friend ostream& operator<<(ostream& out, SparseVector& sv);
    public:
        SparseVector();
        SparseVector(int size);
        SparseVector(const SparseVector &sv);
        int GetSize() const;
        int GetElement(int col) const;
        void SetElement(int col);
        SparseVector& operator=(const SparseVector& sv);
        SparseVector& operator+(const SparseVector& sv);
        void operator+=(const SparseVector& sv);
        // ~SparseVector();
    private:
        bool IsFull() const;
        List Vector;
        const int Size;
};

ostream& operator<<(ostream& out, SparseVector& sv) {
    cout << "Column\t\t" << "Value" << endl << endl;
    for(int i = 1; i <= sv.Size; i++) {
        out << setw(5) << i << setw(16) << sv.Vector.DisplaySpecific(i) << endl;
    }
    return out;
}

SparseVector::SparseVector() : Vector(), Size(0) {

}

SparseVector::SparseVector(int size) : Vector(), Size(size) {

}

SparseVector::SparseVector(const SparseVector &sv) : Size(sv.Size) {
    Vector = sv.Vector;
}

int SparseVector::GetSize() const {
    return Size;
}

int SparseVector::GetElement(int col) const {
    if(col > Size || col <= 0 || IsFull()) {
        cout << "Column Does Not Exist" << endl;
        return EOF;
    }
    return Vector.DisplaySpecific(col);
}

void SparseVector::SetElement(int col) {
    if(col > Size || col <= 0 || IsFull()) {
        cout << "Column Does Not Exist" << endl;
        return;
    }
    int value;
    cout << "Enter Value : ";
    cin >> value;
    Vector.Add(col, value);
}

bool SparseVector::IsFull() const {
    if(Vector.Count == Size) {
        return true;
    }
    return false;
}

SparseVector& SparseVector::operator=(const SparseVector& sv) {
    SparseVector temp(sv.Size);
    //*this = temp;
    return temp;
}

SparseVector& SparseVector::operator+(const SparseVector& sv) {
    SparseVector temp(this -> Size);
    if(this -> Size != sv.Size) {
        cout << "Cannot add these Vectors" << endl;
    }
    else {
        temp.Vector.Head = temp.Vector.GetNode(1);
        for(int i = 2; i <= this -> Vector.Count; i++) {
            List::Node *temp1 = this -> Vector.GetNode(i);
            for(int j = 1; j <= sv.Vector.Count; j++) {
                if(CheckNode()) {

                }
            }
        }
    }
}

void SparseVector::operator+=(const SparseVector& sv) {

}

List::List() {
    Head = NULL;
    Count = 0;
}

void List::Add(int i, int val) {
    Node *node = new Node;
    node -> Index = i; node -> Value = val;
    if(Head == NULL) {
        node -> Next = Head;
        Head = node;
        Count++;
        return;
    }
    Node *Current = Head;
    Node *Previous = Current;
    while(Current != NULL && i >= Current -> Index) {
        if(Current -> Index == i) {
            Current -> Value = val;
            delete node;
            return;
        }
        Previous = Current;
        Current = Current -> Next;
    }
    if(Current == Head) {
        node -> Next = Head;
        Head = node;
    }
    else {
        node -> Next = Previous -> Next;
        Previous -> Next = node;
    }
    Count++;
}

int List::DisplaySpecific(int i) const {
    Node *Current = Head;
    while(Current != NULL && Current -> Index != i) {
        Current = Current -> Next;
    }
    if(Current == NULL) {
        return 0;
    }
    return Current -> Value;
}

int List::GetCount() const {
    return Count;
}

List::Node* List::GetNode(int i) {
    Node *Current = Head;
    for(int j = 1; j < i; j++) {
        Current = Current -> Next;
    }
    return Current;
}

int main() {
    int size;
    cout << "Enter Size of Vector : ";
    cin >> size;
    SparseVector v1(size);
    SparseVector v2 = v1;
    SparseVector v3;
    v3 = v1;
    v1.SetElement(1);
    v1.SetElement(3);
    v1.SetElement(5);
    v1.SetElement(4);
    v1.SetElement(2);
    cout << v1;
    cout << v3;
    return 0;
}

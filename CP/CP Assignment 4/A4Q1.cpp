// Name    : Waseem Hassan Shahid
// Roll No : i12-0097
// Section : F

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

// Function SparseVector SparseVector::operator-(const SparseVector &obj) const
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

// Function SparseVector SparseVector::operator=(const SparseVector &obj)
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

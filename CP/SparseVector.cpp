#include <iostream>

using namespace std;

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

Node::Node() {
    Index = Value = 0;
    Next = NULL;
}

int Node::GetValue() {
    return this -> Value;
}

class SparseVector {
    friend ostream& operator<<(ostream& out, SparseVector &sv);
    public:
        SparseVector();
        SparseVector(int size);
        int GetSize() const;
        void SetElement(int i, int value);
        int GetElement(int i);
        void PrintVector();
        void StoreVector();
        bool operator==(SparseVector obj);
        void operator=(SparseVector &obj);
        ~SparseVector();
    private:
        Node* GetNode(int i, Node* root);
        Node* InsertNode(int i, int value, Node* root);
        Node* DeleteNode(int i, Node* root, Node* Parent);
        int Size;
        Node* Vector;
};

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

SparseVector::SparseVector() {
    Size = 0;
    Vector = NULL;
}

SparseVector::SparseVector(int size) {
    Size = size;
    Vector = NULL;
}

int SparseVector::GetSize() const {
    return Size;
}

Node* SparseVector::GetNode(int i, Node* root) {
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

Node* SparseVector::InsertNode(int i, int value, Node* root) {
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

Node* SparseVector::DeleteNode(int i, Node* root, Node* Parent) {
    if(root == NULL) {
        return NULL;
    }
    else if(root -> Index > i) {
        return NULL;
    }
    else if(root -> Index == i) {
        if(Parent == NULL) {
            Node* Temp;
            Temp = root -> Next;
            delete root;
            root = Temp;
            return root;
        }
        else {
            if(root -> Index == Parent -> Index) {
                delete root;
                return NULL;
            }
            else {
                Parent -> Next = root -> Next;
            }
            delete root;
            return NULL;
        }
    }
    else if(root -> Index < i) {
        if(root -> Next == NULL || root -> Index > i) {
            return NULL;
        }
        else {
            return DeleteNode(i, root -> Next, root);
        }
    }
    return NULL;
}

void SparseVector::SetElement(int i, int value) {
    this -> Vector = InsertNode(i, value, this -> Vector);
    return;
}

int SparseVector::GetElement(int i) {
    Node* Temp;
    Temp = GetNode(i, this -> Vector);
    if(Temp != NULL) {
        return Temp -> Value;
    }
    return 0;
}

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

bool SparseVector::operator==(SparseVector obj) {
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

void SparseVector::operator=(SparseVector &obj) {
    for(int i = 0; i < this -> Size; i++) {
        this -> Vector = DeleteNode(i, this -> Vector, NULL);
    }
    this -> Size = obj.Size;
    for(int i = 0; i < obj.Size; i++) {
        Node* Temp = GetNode(i, obj.Vector);
        if(Temp != NULL) {
            this -> Vector = InsertNode(i, Temp -> Value, this -> Vector);
        }
    }
}

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

SparseVector::~SparseVector() {
    for(int i = 0; i < this -> Size; i++) {
        Node* Temp = DeleteNode(i, this -> Vector, NULL);
        if(Temp != NULL) {
            this -> Vector = Temp;
        }
    }
}

int main() {
    SparseVector v1(10);
    SparseVector v2(10);
    v1.StoreVector();
    v2 = v1;
    cout << v1;
    cout << v2;
    if(v1 == v2) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}

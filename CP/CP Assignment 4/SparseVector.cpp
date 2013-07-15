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
    if(this -> Size != sv.Size)
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

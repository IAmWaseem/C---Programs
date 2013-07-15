/*
#include <iostream>

using namespace std;

class Complex {
	public:
		Complex();
		Complex(double r);
		Complex(double r, double i);
		Complex Add(Complex C);
		Complex Subtract(Complex C);
		Complex Multiply(Complex C);
		Complex Divide(Complex C);
		void Print();
		void SetReal(double r);
		void SetImaginary(double i);
		double SetReal();
		double SetImaginary();
	private:
		double Real;
		double Imaginary;
};

int main() {
	Complex z1(0);
	cout << z1.SetImaginary();
	return 0;
}

Complex::Complex() {
	Real = Imaginary = 0;
}

Complex::Complex(double r) {
	Real = r; Imaginary = 0;
}

Complex::Complex(double r, double i) {
	Real = r; Imaginary = i;
}

Complex Complex::Add(Complex C) {
	Complex z;
	z.Real = Real + C.Real;
	z.Imaginary = Imaginary + C.Imaginary;
	return z;
}

Complex Complex::Subtract(Complex C) {
	Complex z;
	z = Real - C.Real;
	z = Imaginary - C.Imaginary;
	return z;
}

Complex Complex::Multiply(Complex C) {
	Complex z;
	z.Real = (Real * C.Real) - (Imaginary * C.Imaginary);
	z.Imaginary = (Real * C.Imaginary) + (C.Real * Imaginary);
	return z;
}

Complex Complex::Divide(Complex C) {
	Complex z;

	return z;
}

void Complex::Print() {
	cout << Real << " + " << Imaginary << "i" << endl;
}

void Complex::SetReal(double r) {
	Real = r;
}

void Complex::SetImaginary(double i) {
	Imaginary = i;
}

double Complex::GetReal() {
	return Real;
}

double Complex::GetImaginary() {
	return Imaginary;
}
*/

#include <iostream>

using namespace std;

class Array {
	public:
		Array();
		Array(int size);
		void Insert(int value);
		void InsertAt(int value, int offset);
		void Remove(int value);
		void RemoveAt(int offset);
		void At(int offset);
		void SortAscending();
		void SortDescending();
		void Swap(int offset1, int offset2);
		void Reverse();
		void DisplayMin();
		void DisplayMax();
		void DisplayStandardDeviation();
		void Display();
		void DisplayMean();
		bool IsEmpty();
		bool IsFull();
		void TotalElements();
	private:
		int *Data;
		const int Size;
		int Current;
};

// Main Function
int main() {
	int Size;
	cout << "Enter Size of Array : ";
	cin >> Size;
	Array Data(Size);
	int temp;
	for(int i = 0; i < Size - 2; i++) {
		cout << "Enter Data : ";
		cin >> temp;
		Data.Insert(temp);
	}
	Data.InsertAt(5,3);
	Data.Display();
	Data.Reverse();
	Data.Display();
	Data.DisplayMean();
	Data.DisplayStandardDeviation();
	return 0;
}

// Default Array Constructor
Array::Array() : Data(NULL), Size(0), Current(0) {

}

// Parameterized Array Constructor
Array::Array(int size) : Size(size) {
	Data = new int[size];
	Current = 0;
}

// Parameterized Array Constructor
void Array::Insert(int value) {
	Data[Current] = value;
	Current++;
}

// Array::InsertAt Function
void Array::InsertAt(int value, int offset) {
	if(offset > Current) {
		cout << "Offset Given is Greater than the Current Values in the Array" << endl;
		return;
	}
	for(int i = Current; i >= offset; i--) {
		Data[i] = Data[i - 1];
	}
	Data[offset - 1] = value;
	Current++;
}

// Array::Remove Function
void Array::Remove(int value) {
	int Instances = 0;
	for(int i = 0; i < Current; i++) {
		if(Data[i] == value) {
			Instances++;
			for(int j = i; j < Current - 1; j++) {
				Data[i] = Data[i + 1];
			}
			Current--;
		}
	}
	cout << Instances << " Instances of " << value << " Removed" << endl;
}

// Array::RemoveAt Function
void Array::RemoveAt(int offset) {
	if(offset >	Current) {
		cout << "Offset Given is Greater than the Current Values in the Array" << endl;
		return;
	}
	for(int i = offset; i < Current; i++) {
		Data[i] = Data[i + i];
	}
	Current--;
}

// Array::At Function
void Array::At(int offset) {
	if(offset > Current) {
		cout << "Offset Given is Greater than the Current Values in the Array" << endl;
		return;
	}
	cout << "Value at " << offset << " = " << Data[offset - 1] << endl;
}

// Array::SortAscending Function
void Array::SortAscending() {
	int temp;
	for(int i = 0; i < Current; i++) {
		for(int j = i; j < Current - i - 1; j++) {
			if(Data[i] > Data[i + 1]) {
				temp = Data[i];
				Data[i] = Data[i + 1];
				Data[i + 1] = temp;
			}
		}
	}
}

// Array::SortDescending Function
void Array::SortDescending() {
	int temp;
	for(int i = 0; i < Current; i++) {
		for(int j = i; j < Current - i - 1; j++) {
			if(Data[i] < Data[i + 1]) {
				temp = Data[i];
				Data[i] = Data[i + 1];
				Data[i + 1] = temp;
			}
		}
	}
}

// Array::Swap Function
void Array::Swap(int offset1, int offset2) {
	if(offset1 > Current || offset2 > Current) {
		cout << "Offset Given is Greater than the Current Values in the Array" << endl;
		return;
	}
	int temp = Data[offset1 - 1];
	Data[offset1 - 1] = Data[offset2 - 1];
	Data[offset2 - 1] = temp;
}

// Array::Reverse Function();
void Array::Reverse() {
	int temp;
	for(int i = 0, j = Current - 1; i != j; i++, j--) {
		temp = Data[i];
		Data[i] = Data[j];
		Data[j] = temp;
	}
}

void Array::DisplayMin() {
	int Min = Data[0];
	for(int i = 0; i < Current; i++) {
		if(Data[i] < Min) {
			Min = Data[i];
		}
	}
	cout << "Minimum Value in the Array is " << Min << endl;
}

void Array::DisplayMax() {
	int Max = Data[0];
	for(int i = 0; i < Current; i++) {
		if(Data[i] > Max) {
			Max = Data[i];
		}
	}
	cout << "Maximum Value in the Array is " << Max << endl;
}

void Array::DisplayStandardDeviation() {
	int Sum = 0;
	for(int i = 0; i < Current; i++) {
		Sum += Data[i];
	}
	double Mean = static_cast <double> (Sum) / Current;
	double DevSum = 0;
	for(int i = 0; i < Current; i++) {
		DevSum += pow(Data[i] - Mean, 2);
	}
	double DevSumDiv = DevSum / Current;
	double StandardDeviation = sqrt(DevSumDiv);
	cout << "Standard Deviation is " << StandardDeviation << endl;
}

void Array::Display() {
	cout << "Values = ";
	for(int i = 0; i < Current; i++) {
		cout << Data[i] << " ";
	}
	cout << endl;
}

void Array::DisplayMean() {
	int Sum = 0;
	for(int i = 0; i < Current; i++) {
		Sum += Data[i];
	}
	double Mean = Sum / static_cast <double> (Current);
	cout << "Mean of Values is " << Mean << endl;
}

bool Array::IsEmpty() {
	if(Current == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Array::IsFull() {
	if(Current == Size) {
		return true;
	}
	else {
		return false;
	}
}

void Array::TotalElements() {
	cout << "Total Elements in the Array = " << Current;
}
#include <iostream>

using namespace std;

class Shape {
	public:
		Shape();
		~Shape();
		Shape(int, int, int, char*);
		void SetLength(int);
		void SetWidth(int);
		void SetHeight(int);
		void SetName(char*);
		void SetAll(int, int, int, char*);
		int GetLength();
		int GetWidth();
		int GetHeight();
		char* GetName();
		void PrintAll();
	private:
		int Length;
		int Width;
		int Height;
		char *Name;
};

Shape::Shape() {

}

Shape::~Shape() {
	//delete Name;
}


Shape::Shape(int L, int W, int H, char *N) {
	SetAll(L,W,H,N);
	return;
}
void Shape::SetAll(int L, int W, int H, char* N) {
	Length = L;
	Width = W;
	Height = H;
	Name = new char[strlen(N)];
	strcpy(Name, N);
	return;
}

void Shape::SetLength(int L) {
	Length = L;
	return;
}

void Shape::SetWidth(int W) {
	Width = W;
	return;
}

void Shape::SetHeight(int H) {
	Height = H;
	return;
}

void Shape::SetName(char* N) {
	Name = new char[strlen(N)];
	strcpy(Name, N);
	return;
}

int Shape::GetLength() {
	return Length;
}

int Shape::GetWidth() {
	return Width;
}

int Shape::GetHeight() {
	return Height;
}

char* Shape::GetName() {
	return  Name;
}

void Shape::PrintAll() {
	cout << "Name : " << Name << endl;
	cout << "Length : " << Length << endl;
	cout << "Width : " << Width << endl;
	cout << "Height : " << Height << endl;
	return;
}

int main() {
	Shape S1(2,2,2,"Cube");
	cout << "Name : " << S1.GetName() << endl;
	cout << "Length : " << S1.GetLength() << endl;
	cout << "Width : " << S1.GetWidth() << endl;
	cout << "Height : " << S1.GetHeight() << endl;
	Shape S2;
	S2.SetLength(5);
	S2.SetWidth(4);
	S2.SetHeight(6);
	S2.SetName("Triangle");
	cout << "Name : " << S2.GetName() << endl;
	cout << "Length : " << S2.GetLength() << endl;
	cout << "Width : " << S2.GetWidth() << endl;
	cout << "Height : " << S2.GetHeight() << endl;
	system("pause");
	return 0;
}

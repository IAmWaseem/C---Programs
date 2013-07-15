#include <iostream>

using namespace std;

class Shape {
	protected:
		string Type;
	public:
		virtual void Area_Calculator() = 0;
};

class Rectangle : public Shape {
	protected:
		float Height;
		float Width;
	public:
		Rectangle(float h, float w) {
			Height = h; Width = w;
		}
		void Area_Calculator() {
			cout << "Area : " << Height * Width << endl;
		}
};

class Triangle : public Shape {
	protected:
		float Base;
		float Height;
	public:
		Triangle(float b, float h) {
			Base = b; Height = h;
		}
		void Area_Calculator() {
			cout << "Area : " << 0.5 * Base * Height << endl;
		}
};

class Circle : public Shape {
	protected:
		float Radius;
	public:
		Circle(float r) {
			Radius = r;
		}
		void Area_Calculator() {
			cout << "Area : " << 3.14 * Radius * Radius << endl;
		}
};

int main() {
	Shape *s1;
	Rectangle r(2,2);
	s1 = &r;
	s1 -> Area_Calculator();
	Triangle t(2,2);
	s1 = &t;
	s1 -> Area_Calculator();
	Circle c(2);
	s1 = &c;
	s1 -> Area_Calculator();
	return 0;
}

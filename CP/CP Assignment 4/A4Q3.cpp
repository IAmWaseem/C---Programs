// Name    : Waseem Hassan Shahid
// Roll No : i12-0097
// Section : F

#include <iostream>

using namespace std;

class GeometricShape {
    public:
        void CalculateArea(double r);
        void CalculateArea(int w, int h);
        void CalculateArea(double b, double h);
    private:

};

void GeometricShape::CalculateArea(double r) {
    cout << "Area of Circle : " << 3.14 * r * r << endl;
}

void GeometricShape::CalculateArea(int w, int h) {
    cout << "Area of Rectangle : " << w * h << endl;
}

void GeometricShape::CalculateArea(double b, double h) {
    cout << "Area of Triangle : " << 0.5 * b * h << endl;
}

int main() {
    int Choice;
    GeometricShape obj;
    cout << "[1] Area of Circle" << endl
         << "[2] Area of Rectangle" << endl
         << "[3] Area of Triangle" << endl << endl
         << "Enter Choice : ";
    cin >> Choice;
    if(Choice == 1) {
        double r;
        cout << "Enter Radius : ";
        cin >> r;
        obj.CalculateArea(r);
    }
    else if(Choice == 2) {
        int w, h;
        cout << "Enter Width : ";
        cin >> w;
        cout << "Enter Height : ";
        cin >> h;
        obj.CalculateArea(w,h);
    }
    else if(Choice == 3) {
        double b, h;
        cout << "Enter Base : ";
        cin >> b;
        cout << "Enter Hypotenuse : ";
        cin >> h;
        obj.CalculateArea(b,h);
    }
    return 0;
}

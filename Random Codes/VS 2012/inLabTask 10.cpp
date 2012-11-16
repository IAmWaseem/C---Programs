/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	cout << "sizeof int : " << sizeof(int) << endl;
	cout << "sizeof char : " << sizeof(char) << endl;
	cout << "sizeof float : " << sizeof(float) << endl;
	cout << "sizeof unsigned int : " << sizeof(unsigned int) << endl;
	cout << "sizeof long int : " << sizeof(long int) << endl;
	cout << "size of long double : " << sizeof(long double) << endl;
	cout << "sizeof double : " << sizeof(double) << endl;
	cout << "sizeof double long : " << sizeof(double long) << endl;
	getch();
	return 0;
}
*/

/*  // 10.1a
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[10];
	float FloatArray[15];
	double DoubleArray[20];
	char CharacterArray[25];
	cout << "Memory Size of Integer Type Array of 10 Indexes : " << sizeof(IntegerArray) << endl;
	cout << "Memory Size of Float Type Array of 15 Indexes : " << sizeof(FloatArray) << endl;
	cout << "Memory Size of Double Type Array of 20 Indexes : " << sizeof(DoubleArray) << endl;
	cout << "Memory Size of Character Type Array of 25 Indexes : "<< sizeof(CharacterArray) << endl;
	getch();
	return 0;
}
*/

/*  // 10.2a
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6] = {10,10,10,10,10,10};
	double DoubleArray[5] = {0.5, 0.5, 0.5, 0.5, 0.5};
	char CharacterArray[4] = {'a','a','a','\0'};
	getch();
	return 0;
}
*/

/*  //10.2b
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	cout << "Enter Value of Integer Type Array at Location 0 : ";
	cin >> IntegerArray[0];
	cout << "Enter Value of Integer Type Array at Location 1 : ";
	cin >> IntegerArray[1];
	cout << "Enter Value of Integer Type Array at Location 2 : ";
	cin >> IntegerArray[2];
	cout << "Enter Value of Integer Type Array at Location 3 : ";
	cin >> IntegerArray[3];
	cout << "Enter Value of Integer Type Array at Location 4 : ";
	cin >> IntegerArray[4];
	cout << "Enter Value of Integer Type Array at Location 5 : ";
	cin >> IntegerArray[5];
	cout << "Enter Value of Double Type Array at Location 0 : ";
	cin >> DoubleArray[0];
	cout << "Enter Value of Double Type Array at Location 1 : ";
	cin >> DoubleArray[1];
	cout << "Enter Value of Double Type Array at Location 2 : ";
	cin >> DoubleArray[2];
	cout << "Enter Value of Double Type Array at Location 3 : ";
	cin >> DoubleArray[3];
	cout << "Enter Value of Double Type Array at Location 4 : ";
	cin >> DoubleArray[4];
	cout << "Enter Value of Character Type Array at Location 0 : ";
	cin >> CharacterArray[0];
	cout << "Enter Value of Character Type Array at Location 1 : ";
	cin >> CharacterArray[1];
	cout << "Enter Value of Character Type Array at Location 2 : ";
	cin >> CharacterArray[2];
	cout << "Enter Value of Character Type Array at Location 3 : ";
	cin >> CharacterArray[3];
	getch();
	return 0;
}
*/

/*  // 10.3a
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6] = {10,10,10,10,10,10};
	double DoubleArray[5] = {0.5, 0.5, 0.5, 0.5, 0.5};
	char CharacterArray[4] = {'a','a','a','a'};
	cout << "IntegerArray[0] = " << IntegerArray[0] << endl;
	cout << "IntegerArray[1] = " << IntegerArray[1] << endl;
	cout << "IntegerArray[2] = " << IntegerArray[2] << endl;
	cout << "IntegerArray[3] = " << IntegerArray[3] << endl;
	cout << "IntegerArray[4] = " << IntegerArray[4] << endl;
	cout << "IntegerArray[5] = " << IntegerArray[5] << endl;
	cout << "DoubleArray[0] = " << DoubleArray[0] << endl;
	cout << "DoubleArray[1] = " << DoubleArray[1] << endl;
	cout << "DoubleArray[2] = " << DoubleArray[2] << endl;
	cout << "DoubleArray[3] = " << DoubleArray[3] << endl;
	cout << "DoubleArray[4] = " << DoubleArray[4] << endl;
	cout << "CharacterArray[0] = " << CharacterArray[0] << endl;
	cout << "CharacterArray[1] = " << CharacterArray[1] << endl;
	cout << "CharacterArray[2] = " << CharacterArray[2] << endl;
	cout << "CharacterArray[3] = " << CharacterArray[3] << endl;
	getch();
	return 0;
}
*/

/*  // 10.3b
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	cout << "Enter Value of Integer Type Array at Location 0 : ";
	cin >> IntegerArray[0];
	cout << "Enter Value of Integer Type Array at Location 1 : ";
	cin >> IntegerArray[1];
	cout << "Enter Value of Integer Type Array at Location 2 : ";
	cin >> IntegerArray[2];
	cout << "Enter Value of Integer Type Array at Location 3 : ";
	cin >> IntegerArray[3];
	cout << "Enter Value of Integer Type Array at Location 4 : ";
	cin >> IntegerArray[4];
	cout << "Enter Value of Integer Type Array at Location 5 : ";
	cin >> IntegerArray[5];
	cout << "Enter Value of Double Type Array at Location 0 : ";
	cin >> DoubleArray[0];
	cout << "Enter Value of Double Type Array at Location 1 : ";
	cin >> DoubleArray[1];
	cout << "Enter Value of Double Type Array at Location 2 : ";
	cin >> DoubleArray[2];
	cout << "Enter Value of Double Type Array at Location 3 : ";
	cin >> DoubleArray[3];
	cout << "Enter Value of Double Type Array at Location 4 : ";
	cin >> DoubleArray[4];
	cout << "Enter Value of Character Type Array at Location 0 : ";
	cin >> CharacterArray[0];
	cout << "Enter Value of Character Type Array at Location 1 : ";
	cin >> CharacterArray[1];
	cout << "Enter Value of Character Type Array at Location 2 : ";
	cin >> CharacterArray[2];
	cout << "Enter Value of Character Type Array at Location 3 : ";
	cin >> CharacterArray[3];
	cout << "Value of Integer Type Array at Location 0 : " << IntegerArray[0] << endl;
	cout << "Value of Integer Type Array at Location 1 : " << IntegerArray[1] << endl;
	cout << "Value of Integer Type Array at Location 2 : " << IntegerArray[2] << endl;
	cout << "Value of Integer Type Array at Location 3 : " << IntegerArray[3] << endl;
	cout << "Value of Integer Type Array at Location 4 : " << IntegerArray[4] << endl;
	cout << "Value of Integer Type Array at Location 5 : " << IntegerArray[5] << endl;
	cout << "Value of Double Type Array at Location 0 : " << DoubleArray[0] << endl;
	cout << "Value of Double Type Array at Location 1 : " << DoubleArray[1] << endl;
	cout << "Value of Double Type Array at Location 2 : " << DoubleArray[2] << endl;
	cout << "Value of Double Type Array at Location 3 : " << DoubleArray[3] << endl;
	cout << "Value of Double Type Array at Location 4 : " << DoubleArray[4] << endl;
	cout << "Value of Character Type Array at Location 0 : " << CharacterArray[0] << endl;
	cout << "Value of Character Type Array at Location 1 : " << CharacterArray[1] << endl;
	cout << "Value of Character Type Array at Location 2 : " << CharacterArray[2] << endl;
	cout << "Value of Character Type Array at Location 3 : " << CharacterArray[3] << endl;
	getch();
	return 0;
}
*/

/*  //10.4a
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	for(int i=0;i<6;i++) {
		cout << "Enter Value of Integer Type Array at Location " << i << " : ";
		cin >> IntegerArray[i];
	}
	for(int i=0;i<5;i++) {
		cout << "Enter Value of Double Type Array at Location " << i << " : ";
		cin >> DoubleArray[i];
	}
	for(int i=0;i<4;i++) {
		cout << "Enter Value of Character Type Array at Location " << i << " : ";
		cin >> CharacterArray[i];
	}
	getch();
	return 0;
}
*/

/*  //10.4b
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	for(int i=0;i<6;i++) {
		cout << "Enter Value of Integer Type Array at Location " << i << " : ";
		cin >> IntegerArray[i];
	}
	for(int i=0;i<5;i++) {
		cout << "Enter Value of Double Type Array at Location " << i << " : ";
		cin >> DoubleArray[i];
	}
	for(int i=0;i<4;i++) {
		cout << "Enter Value of Character Type Array at Location " << i << " : ";
		cin >> CharacterArray[i];
	}
	for(int i=0;i<6;i++) {
		cout << "IntegerArray[" << i << "] = " << IntegerArray[i] << endl;
	}
	for(int i=0;i<5;i++) {
		cout << "DoubleArray[" << i << "] = " << DoubleArray[i] << endl;
	}
	for(int i=0;i<4;i++) {
		cout << "CharacterArray[" << i << "] = " << CharacterArray[i] << endl;
	}
	getch();
	return 0;
}
*/
/*  //10.5a
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	int i=0;
	while(i<6) {
		cout << "Enter Value of Integer Type Array at Location " << i << " : ";
		cin >> IntegerArray[i];
		i++;
	}
	i=0;
	while(i<5) {
		cout << "Enter Value of Double Type Array at Location " << i << " : ";
		cin >> DoubleArray[i];
		i++;
	}
	i=0;
	while(i<4) {
		cout << "Enter Value of Character Type Array at Location " << i << " : ";
		cin >> CharacterArray[i];
		i++;
	}
	getch();
	return 0;
}
*/

/* // 10.6
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	int i=0;
	while(i<6) {
		cout << "Enter Value of Integer Type Array at Location " << i << " : ";
		cin >> IntegerArray[i];
		i++;
	}
	i=0;
	while(i<5) {
		cout << "Enter Value of Double Type Array at Location " << i << " : ";
		cin >> DoubleArray[i];
		i++;
	}
	i=0;
	while(i<4) {
		cout << "Enter Value of Character Type Array at Location " << i << " : ";
		cin >> CharacterArray[i];
		i++;
	}
	i=0;
	while(i<6) {
		cout << "IntegerArray[" << i << "] = " << IntegerArray[i] << endl;
		i++;
	}
	i=0;
	while(i<5) {
		cout << "DoubleArray[" << i << "] = " << DoubleArray[i] << endl;
		i++;
	}
	i=0;
	while(i<4) {
		cout << "CharacterArray[" << i << "] = " << CharacterArray[i] << endl;
		i++;
	}
	getch();
	return 0;
}
*/

//10.7
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int max=0,arr[5],sum=0;
	for(int i=0;i<5;i++) {
		cout << "Enter Integer Value : ";
		cin >> arr[i];
	}
	int min=arr[0];
	for(int i=0;i<5;i++) {
		sum=sum+arr[i];
		if(arr[i]>max) {
			max = arr[i];
		}
		if(arr[i]<min) {
			min = arr[i];
		}
	}
	cout << "Average of Numbers : " <<sum/5 << endl;
	cout << "Maximum Value : " << max << endl;
	cout << "Minimum Value : " << min << endl;
	getch();
	return 0;
}
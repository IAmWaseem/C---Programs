#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

void Write(const vector<string>&);
void Read();

int main() {
	vector<string> Names;
	time_t now = time(NULL);
    struct tm *t = localtime(&now);
   printf( "%d\n", t->tm_mon+1 );
   printf( "%d\n", t->tm_mday );
   printf( "%d\n", t->tm_year+1900 );
   printf( "%d\n", t->tm_hour );
   printf( "%d\n", t->tm_min );
   printf( "%d\n", t->tm_sec );
	if(Names.empty()) {
		cout << "Names Vector is Empty" << endl;
	}
	int Size;
	cout << "How many Names you want to Enter : ";
	cin >> Size;
	string Temp;
	for(int i = 0; i < Size; i++) {
		cin >> Temp;
		Names.push_back(Temp);
	}
	for(unsigned int i = 0; i < Names.size(); i++) {
		cout << "Name : " << Names[i] << endl;
	}
	cout << endl;
	string temp;
	cout << "Enter Name to Search : ";
	cin >> temp;
	for(unsigned int i = 0; i < Names.size(); i++) {
		if(temp == Names[i]) {
			Names.erase(Names.begin() + i);
		}
	}
	cout << "After Deleting" << endl << endl;
	for(unsigned int i = 0; i < Names.size(); i++) {
		cout << "Name : " << Names[i] << endl;
	}
	cout << endl;
	Names.insert(Names.begin() + 1, Names.at(0));
	for(unsigned int i = 0; i < Names.size(); i++) {
		cout << "Name : " << Names[i] << endl;
	}
	cout << Names.front() << endl;
	cout << Names.back() << endl;
	Names.clear();
	if(Names.empty()) {
		cout << "Vector is now Empty" << endl;
	}
	cout << Names[0]; // Names.at(0);
	Write(Names);
	//Read();
}

void Write(const vector<string>& Names) {
	ofstream outFile("Names.dat", ios::out | ios::binary);
	int length = 0;
	for(unsigned int i = 0; i < Names.size(); i++) {
		length += Names[i].length();
	}
	outFile.write((char*)&length, sizeof(int));
	outFile.write((char*)&Names, length);
	outFile.flush();
	outFile.close();
}

void Read() {
	vector<string> Names;
	ifstream inFile("Names.dat", ios::in | ios::binary);
	int length;
	inFile.read((char*)&length, sizeof(int));
	//Names.resize(length);
	//Names.capacity();
	inFile.read((char*)&Names, length);
	inFile.close();
	for(unsigned int i = 0; i < Names.size(); i++) {
		cout << "Name : " << Names[i] << endl;
	}
}
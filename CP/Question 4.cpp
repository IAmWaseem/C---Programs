#include <iostream> 
#include <conio.h> 
using namespace std;

class uniquely_Identified
{
private: 
	const int ID;
	static int total_objects;

public: 
	uniquely_Identified(): ID(total_objects+1){
		total_objects++;
	}
	int Get_id() const;

};

int uniquely_Identified::total_objects=0;



int uniquely_Identified::Get_id() const{

	return ID;
}

int main(){
	uniquely_Identified obj1;
	uniquely_Identified obj2;
	uniquely_Identified obj3;


	cout << obj1.Get_id() << endl;
	cout << obj2.Get_id() << endl;
	cout << obj3.Get_id() << endl;
	return 0;
}



#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::string Name;
	std::string Telephone;
	std::string Address;
	std::fstream File("teledir.txt", std::ios::in | std::ios::out);
	while(std::cin >> Name >> Telephone >> Address) {
		File << Name << "\t" << Telephone << "\t" << Address << "\n";
	}
	while(!File.eof() && !File.fail()) {
		File >> Name >> Telephone >> Address;
		std::cout << "Name : " << Name << std::endl << "Telephone : " << Telephone << std::endl << "Address : " << Address << std::endl << std::endl;
	}
	File.close();
	return 0;
}
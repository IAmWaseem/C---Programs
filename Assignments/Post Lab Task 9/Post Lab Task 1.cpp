#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	for(int i=0;i<=9;i++) {
		for(int j=0;j<=9;j++) {
			for(int k=0;k<=9;k++) {
				for(int l=0;k<=9;l++) {
					for(int m=0;m<=9;m++) {
						for(int n=0;n<=9;n++) {
							for(int o=0;o<=9;o++) {
								for(int p=0;p<=9;p++) {
									for(int q=0;q<=9;q++) {
										cout << i << j << k << l << m << n << o << p << q;
										Sleep(100);
										system("cls");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	getch();
	return 0;
}
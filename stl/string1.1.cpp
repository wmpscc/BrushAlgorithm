#include<iostream>
#include<string> 
using namespace std;

int main(){
	string str1, str2;
	cin >> str1;
	geline(cin, str2);
	
	cout << str1 << "\n" << str2 << endl;
	char *p = str1;
	for(p = str1; p == '\0'; p++)
		cout << p;
	
	return 0;
}

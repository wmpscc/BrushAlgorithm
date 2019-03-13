#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	getline(cin, s, ' ');
	cout << s << endl;
	getline(cin, s, ' ');
	cout << s << endl;
	getline(cin, s, ' ');
	cout << s << endl;
	return 0;
}

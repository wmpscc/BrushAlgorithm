#include<iostream>
using namespace std;

const int CLK_TCK = 100;
int main() {
	int C1, C2, C;
	cin >> C1 >> C2;
	C = C2 - C1;
	if(C % CLK_TCK >= 50) {
		C = C / CLK_TCK + 1;
	} else {
		C = C / CLK_TCK;
	}

	printf("%02d:%02d:%02d", C / 3600, C % 3600 / 60, C % 60);

	return 0;
}

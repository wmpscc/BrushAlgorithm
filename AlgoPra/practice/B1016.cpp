#include<iostream>
using namespace std;

char numA[12], numB[12];
int main() {
	int sumA = 0, sumB = 0;
	int a, b;
	scanf("%s%d%s%d", numA, &a, numB, &b);
	int i = 0;
	while(numA[i] != '\0') {
		if(numA[i++] - '0' == a) sumA = sumA*10+a;
	}
	i = 0;
	while(numB[i] != '\0') {
		if(numB[i++] - '0' == b) sumB =sumB *10 +b;
	}

	cout << sumA + sumB;
	
	return 0;
}



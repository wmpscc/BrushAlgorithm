#include<iostream>
using namespace std;

int main() {
	int N;
	int a, A, b, B;
	int ansA = 0, ansB = 0;
	cin >> N;
	while(N--) {
		cin >> a >> A>> b>> B;
		if(a + b == A && a + b != B)
			ansB++;
		else if(a + b != A && a + b == B)
			ansA++;
	}
	cout << ansA << " " << ansB;

	return 0;
}

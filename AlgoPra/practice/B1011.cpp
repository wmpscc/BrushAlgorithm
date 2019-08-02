#include<iostream>
using namespace std;

int main() {
	int n;
	long long A, B, C;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A >> B>> C;
		if(A +B > C) cout << "Case #" << i << ": true" << endl;
		else cout << "Case #" << i << ": false" << endl;
	}
	return 0;
}

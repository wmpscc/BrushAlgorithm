#include<iostream>
using namespace std;

int num[101];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	M = M % N;
	for(int i = 0; i < M; i++) {
		int last = num[N - 1];
		for(int j = N -1; j > 0; j--)
			num[j] = num[j-1];
		num[0] = last;
	}
	for(int i = 0; i < N; i++){
		if(i != N -1)
			cout << num[i] << " ";
		else cout << num[i];
	}
		
	return 0;
}

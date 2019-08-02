#include<iostream>
using namespace std;

bool isAWin(char A, char B) {
	if(A == 'C' && B == 'J')
		return true;

}

int main() {
	int N;
	char A, B;
	scanf("%d", &N);
	getchar();
	int times = N;

	int winA[3] = {0}; // C J B
	int winB[3] = {0}; // C J B
	int countA = 0;
	int countB = 0;
	int countAB = 0;

	while(N--) {
		A = getchar();
		getchar();
		B = getchar();
		if(N != 0)
			getchar();

		if (A == B) {
			countAB++;
			continue;
		}

		if(A == 'C' && B == 'J') {
			winA[0]++;
			countA++;
		} else if(A == 'J' && B == 'B') {
			winA[1]++;
			countA++;
		} else if(A == 'B' && B == 'C') {
			winA[2]++;
			countA++;
		}

		if(B == 'C' && A == 'J') {
			winB[0]++;
			countB++;
		} else if(B == 'J' && A == 'B') {
			winB[1]++;
			countB++;
		} else if(B == 'B' && A == 'C') {
			winB[2]++;
			countB++;
		}
	}
	printf("%d %d %d\n", winA[0] + winA[1] + winA[2], countAB, times - (winA[0] + winA[1] + winA[2] + countAB));
	printf("%d %d %d\n", winB[0] + winB[1] + winB[2], countAB, times - (winB[0] + winB[1] + winB[2] + countAB));

	if(winA[2] >= winA[0] && winA[2] >= winA[1])
		printf("B");
	else if (winA[0] >= winA[1])
		printf("C");
	else printf("J");
	printf(" ");
	if(winB[2] >= winB[0] && winB[2] >= winB[1])
		printf("B");
	else if (winB[0] >= winB[1])
		printf("C");
	else printf("J");

	return 0;
}

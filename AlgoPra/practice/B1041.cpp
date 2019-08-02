#include<iostream>
using namespace std;

typedef struct {
	long long id;
	int seat_num;
	int test_num;
} Student;

Student stu[1010];
int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%lld%d%d", &stu[i].id, &stu[i].seat_num, &stu[i].test_num);
	}
	int M, num;
	scanf("%d", &M);
	
	for(int i = 0; i < M; i++) {
		scanf("%d", &num);
		for(int j = 0; j < N; j++) {
			if(stu[j].seat_num == num) {
				printf("%lld %d\n", stu[j].id, stu[j].test_num);
			}
		}
	}

	return 0;
}

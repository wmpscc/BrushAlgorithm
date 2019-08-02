#include<iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int num;
	int f; // ำเสý
	int op = 1; // 1 ีý 0 ธบ
	int max = -1;
	int count_two = 0;
	int count_three = 0;
	int sum = 0;
	int sum_even = 0;
	int sum_cross = 0;
	int count_x = 0;

	for(int i = 0; i < N; i++) {
		scanf("%d", &num);
		f = num % 5;
		if(f == 2)
			count_two++;
		else if(f == 3) {
			sum += num;
			count_three++;
		}
		else if(f == 4)
			if(num > max) max = num;
		if(f == 0 && num %2 ==0)
			sum_even += num;
		if(f == 1) {
			count_x++;
			if (op == 1) {
				sum_cross += num;
				op = 0;
			} else {
				sum_cross -= num;
				op = 1;
			}
		}
	}

	if(sum_even == 0) printf("N ");
	else printf("%d ", sum_even);
	if(count_x == 0) printf("N ");
	else printf("%d ", sum_cross);
	if(count_two == 0) printf("N ");
	else printf("%d ", count_two);
	if(sum == 0)printf("N ");
	else printf("%.1f ", (double)sum / count_three);
	if(max == -1) printf("N");
	else printf("%d", max);
	
	return 0;
}


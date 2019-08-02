#include<iostream>
using namespace std;

struct Student {
	char name[11];
	char id[11];
	int score;
} stu[1000];

int main() {
	int N;
	scanf("%d", &N);
	struct Student *ans_min;
	struct Student *ans_max;
	int score_max = -1;
	int score_min = 101;
	for(int i = 0; i < N; i++) {
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].score);
		if(stu[i].score > score_max) {
			score_max = stu[i].score;
			ans_max = &stu[i];
		}
		if(stu[i].score < score_min) {
			score_min = stu[i].score;
			ans_min = &stu[i];
		}
	}
	printf("%s %s\n", ans_max->name, ans_max->id);
	printf("%s %s", ans_min->name, ans_min->id);

	return 0;
}

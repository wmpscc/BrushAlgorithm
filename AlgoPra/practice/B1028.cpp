#include<iostream>
using namespace std;

struct Peope {
	char name[20];
	int year;
	int month;
	int day;
} temp, min_peo, max_peo;

bool isLegal(struct Peope t) {

	int age = 20140906 - (t.year*10000+t.month*100+t.day);
	if(age < 0 || age > 2000000)
		return false;
	else return true;
}

int main() {
	int N;
	cin >> N;
	int min_age = 20140907;
	int max_age = 0;
	int count = 0;
	while(N--) {
		scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
		if(isLegal(temp)) {
			count++;
			if(20140906 - (temp.year*10000+temp.month*100+temp.day) > max_age) {
				max_age = 20140906 - (temp.year*10000+temp.month*100+temp.day);
				max_peo = temp;
			}
			if(20140906 - (temp.year*10000+temp.month*100+temp.day) < min_age) {
				min_age = 20140906 - (temp.year*10000+temp.month*100+temp.day);
				min_peo = temp;
			}
		}
	}
	if(count == 0)
		printf("0");
	else
		printf("%d %s %s", count, max_peo.name, min_peo.name);

	return 0;
}

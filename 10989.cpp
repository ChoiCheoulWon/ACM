#include"iostream"
#include<stdio.h>

using namespace std;

int main() {
	int N;
	int C[10001] = { 0 };

	scanf("%d", &N);
	//cin >> N;
	
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		//cin >> num;
		C[num]++;
	}
	int i = 0;

	while (i <= 10000) {
		if (C[i] > 0) {
			printf("%d\n", i);
			//cout << i << '\n';
			C[i]--;
		}
		else
			i++;
	}

	return 0;
}
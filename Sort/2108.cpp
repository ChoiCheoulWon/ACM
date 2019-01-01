#include<stdio.h>
#include<cmath>

void quicksort(double num[], int left, int right);

int main() {

	int N;
	// -4000~4000의 빈도수를 저장하기 위한 배열
	int count[8001] = { 0 };
	//int num[500000];
	scanf("%d", &N);

	double* num = new double[N];

	for (int i = 0; i < N; i++) {
		scanf("%lf", &num[i]);
		count[(int)num[i] + 4000]++;
	}
	
	quicksort(num, 0, N - 1);

	double sum = 0;

	for (int i = 0; i < N; i++) {
		sum += num[i];
	}
	// 평균값(첫째 자리에서 반올림)
	printf("%.0lf\n", floor(sum / N + 0.5));
	// 중앙값
	printf("%.0lf\n", num[N / 2]);
	// 최빈값
	int max = 0;
	for (int i = 0; i < 8001; i++) {
		if (count[i] > max) {
			max = count[i];
		}
	}
	int dup = 0, first;
	for (int i = 0; i < 8001; i++) {
		if (count[i] == max && dup == 1) {
			printf("%d\n", i - 4000);
			dup++;
			break;
		}
		if (count[i] == max && dup == 0) {
			dup++;
			first = i - 4000;
		}
	}
	if (dup == 1) {
		printf("%d\n", first);
	}
	// 범위(최대값과 최소값의 차이)
	printf("%.0lf\n", num[N - 1] - num[0]);
	return 0;
}

void quicksort(double num[], int left, int right) {
	int i = left, j = right;
	int pivot = num[i];
	int temp;
	while (i <= j) {
		while (num[i] < pivot) {
			i++;
		}
		while (num[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j) {
		quicksort(num, left, j);
	}
	if (i < right) {
		quicksort(num,i, right);
	}

}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100002

int n, m;
int A[MAX];

int compare(const int* a, const int* b) {
	if (*b < *a) return 1;
	else return -1;
}

int find(int x) {
	int st = 0;
	int en = n-1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (A[mid] == x) return 1;
		else if (x < A[mid]) en = mid - 1;
		else if (x > A[mid]) st = mid + 1;
	}
	return 0;
}

int main() {	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, n, sizeof(int), compare);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);

		printf("%d\n", find(x));
	}

	return 0;
}
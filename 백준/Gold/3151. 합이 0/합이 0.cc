#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

int n;
int feat[MAX];
int flag;
int sum;
long long cnt;

int binary_search_lower(int A, int idx) {
	int st = idx + 1;
	int en = n;
	int mid;
	while (st < en) {
		mid = (st + en) / 2;
		if (feat[mid] >= -sum) en = mid;
		else if (feat[mid] < -sum) st = mid + 1;
	}
	return st;
}

int binary_search_upper(int A, int idx) {
	int st = idx + 1;
	int en = n;
	int mid;
	while (st < en) {
		mid = (st + en) / 2;
		if (feat[mid] > -sum) en = mid;
		else if (feat[mid] <= -sum) st = mid + 1;
	}
	return st;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> feat[i];
	}

	sort(feat, feat + n);
	for (int i = 0; i < n-2; i++) {
		if (feat[i] > 0) break;
		for (int j = i + 1; j < n-1; j++) {
			sum = feat[i] + feat[j];
			cnt += (binary_search_upper(i, j) - binary_search_lower(i, j));
			//cout << i << " " << j << ": " << cnt << endl;
		}
	}

	cout << cnt;

	return 0;
}

/*
-6 -5 -4 -4 0 1 2 2 3 7
-7 -6 -5 -4 -3 -2 -1 0 7
*/
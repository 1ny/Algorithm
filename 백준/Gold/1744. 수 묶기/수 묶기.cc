#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50

int main() {
	int n;
	int arr[MAX];
	int ret = 0;
	int cntZero = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) ret++;
	}
	sort(arr, arr + n);
	int first = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			if (i % 2 == 1) ret += first;
			break;
		}
		if (i % 2 == 0) {
			first = arr[i];
			if (i == n - 1) ret += first;
			continue;
		}
		ret += first * arr[i];
	}

	first = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] <= 1) {
			if ((n - i) % 2 == 0) ret += first;
			break;
		}
		if ((n - i) % 2 == 1) {
			first = arr[i];
			if (i == 0) ret += first;
			continue;
		}
		ret += first * arr[i];
	}

	cout << ret;
}
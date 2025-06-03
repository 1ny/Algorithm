#include "iostream"
#include "algorithm"
using namespace std;

#define MAX 100000

int n;
long long feat[MAX];
int minA, minB;
long long sum = 2 * 1000000000;

void binary_search(int idx) {
	int st = idx + 1;
	int en = n - 1;
	int mid;
	while (st <= en) {
		mid = (st + en) / 2;
		if (feat[idx] * feat[mid] < 0) {
			if (abs(feat[idx]) < abs(feat[mid])) en = mid - 1;
			else if (abs(feat[idx]) > abs(feat[mid])) st = mid + 1;
			else
			{
				sum = 0;
				minA = feat[idx];
				minB = feat[mid];
				return;
			}
		}
		else
		{
			if (abs(feat[idx]) < abs(feat[mid])) en = mid - 1;
			else if (abs(feat[idx]) > abs(feat[mid])) st = mid + 1;
		}
		if (abs(feat[idx] + feat[mid]) < sum) {
			minA = feat[idx];
			minB = feat[mid];
			sum = abs(feat[idx] + feat[mid]);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> feat[i];
	}

	for (int i = 0; i < n; i++) {
		binary_search(i);
	}

	cout << minA << " " << minB;

	return 0;
}
/*
  0  1 2 3  4  5  6   7
-103 1 2 4 98 99 100 103
-103 > 4

  0   1    2   3   4  5  6
-103 -100 -99 -98 -4 -2 -1
-103 > -98

0 1 2 3  4   5   6
1 2 4 98 99 100 103
1 < 98

  0    1   2   3  4 5 6  7
-103 -100 -99 -2 -1 0 4 98
99
103 > 1
103 > 4


0    1   2  3   4   5   6   7   8
-100 -2 -1  0  101 102 103 104 105
-100 < 101
-100 > -1
*/
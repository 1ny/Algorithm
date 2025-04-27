#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<int> L;

int binSearch() {
	long long st = 1;
	long long en = 1000000000;
	long long mid = 0;
	long long max = 0;
	while (st <= en)
	{
		long sum = 0;
		mid = (st + en+1) / 2;
		for (int i = 0; i < n; i++) {
			sum += L[i] / mid;
		}
		if (sum < m) en = mid - 1;
		else if (sum >= m) {
			st = mid + 1;
			if (mid > max) max = mid;
		}
	}
	return max;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		L.push_back(x);
	}

	sort(L.begin(), L.end());

	cout << binSearch();

	return 0;
}
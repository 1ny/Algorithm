#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int k, n;
vector<int> length;

int binSearch() {
	long long st = 1;
	long long en = pow(2, 31) - 1;
	long long mid = 0;
	long long max = 0;
	while (st <= en)
	{
		long long sum = 0;
		mid = (st + en+1) / 2;
		for (int i = 0; i < k; i++) {
			sum += length[i] / mid;
		}
		//cout << "mid: " << mid << endl;
		//cout << "st: " << st << ", en: " << en << endl;
		//cout << sum << endl;
		if (sum < n) en = mid - 1;
		else if (sum >= n) {
			if (mid > max) max = mid;
			st = mid + 1;
		}
	}
	return max;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		length.push_back(x);
	}

	cout << binSearch();

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> height;

int binSearch() {
	long long st = 0;
	long long en = height[height.size() - 1];
	long long mid;
	long long max = 0;
	while (st < en)
	{
		long long sum = 0;
		mid = (st + en + 1) / 2;
		for (int i = 0; i < n; i++) {
			if(height[i] > mid) sum += height[i] - mid;
		}
		//cout << "mid: " << mid << endl;
		//cout << "sum: " << sum << endl;
		//cout << "st: " << st << ", en: " << en << endl;
		if (sum < m) en = mid - 1;
		else if (sum >= m) st = mid;
	}
	return st;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		height.push_back(x);
	}

	sort(height.begin(), height.end());
	//for (int i = 0; i < n; i++) {
	//	cout << height[i] << " ";
	//}
	cout << binSearch();

	return 0;
}
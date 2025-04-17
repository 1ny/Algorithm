#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	vector<long> nums;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long x;
		cin >> x;
		nums.push_back(x);
	}

	while (m--) {
		long x = 0, y = 0;
		long idx = 0;
		//for (int i = 0; i < n; i++) {
		//	cout << nums[i] << " ";
		//}
		//cout << endl;
		sort(nums.begin(), nums.end());
		x = nums[0];
		y = nums[1];
		nums[0] = x + y;
		nums[1] = nums[0];
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}

	cout << sum;
}
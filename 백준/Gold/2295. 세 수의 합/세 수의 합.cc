#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> u;
vector<int> u2;

int binSearch(int x) {
	int st = 0;
	int en = u2.size();
	int mid;
	while (st <= en) {
		mid = (st + en) / 2;
		if (x < u2[mid]) en = mid - 1;
		else if (x > u2[mid]) st = mid + 1;
		else return 1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		u.push_back(x);
	}

	sort(u.begin(), u.end());
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			u2.push_back(u[i] + u[j]);
		}
	}

	sort(u2.begin(), u2.end());
	u2.erase(unique(u2.begin(), u2.end()), u2.end());

	int max = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (binSearch(u[i] - u[j]))
			{
				cout << u[i];
				return 0;
			}
		}
	}

	return 0;
}
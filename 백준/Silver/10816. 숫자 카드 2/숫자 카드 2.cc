#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500005

int n, m;
int arr[MAX];

int binSearch_lower(int x) {
	int st = 0;
	int en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (x <= arr[mid]) en = mid;
		else st = mid + 1;
	}
	return st;
}

int binSearch_upper(int x) {
	int st = 0;
	int en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (x < arr[mid]) en = mid;
		else st = mid + 1;
	}
	return st;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		int ret = binSearch_upper(x) - binSearch_lower(x);
		//cout << binSearch_upper(x) << " " << binSearch_lower(x) << "\n";
		cout << ret << " ";
	}

	return 0;
}
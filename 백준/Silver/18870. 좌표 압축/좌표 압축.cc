#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000005

int n;
int x[MAX];
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		arr.push_back(x[i]);
	}

	sort(arr.begin(), arr.end());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(arr.begin(), arr.end(), x[i]) - arr.begin() << " ";
	}


	return 0;
}
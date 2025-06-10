#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

#define MAX 2000

int n;
vector<int> a;
int result;

void search(int i) {
	for (int j = 0; j < n; j++) {
		if (i == j) continue;
		int idx = lower_bound(a.begin(), a.end(), a[i] - a[j]) - a.begin();
		while (idx < n && a[idx] == a[i] - a[j]) {
			if (idx != i && idx != j) {
				result++;
				return;
			}
			idx++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int va;
		cin >> va;
		a.push_back(va);
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		search(i);
	}

	cout << result;

	return 0;
}

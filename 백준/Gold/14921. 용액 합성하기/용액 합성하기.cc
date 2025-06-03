#include "iostream"
#include "algorithm"
using namespace std;

#define MAX 100000

int n;
int feat[MAX];
long long sum = 2*100000000;
long long result;

void binary_search(int idx) {
	int st = idx + 1;
	int en = n - 1;
	int mid;
	while (st <= en) {
		mid = (st + en) / 2;
		if (abs(feat[idx]) > abs(feat[mid])) st = mid + 1;
		else if (abs(feat[idx]) <= abs(feat[mid])) en = mid - 1;
		//else if (feat[idx] * feat[mid] > 0) { sum = 2 * abs(feat[mid]); result = 2 * feat[mid]; return; }
		//else { sum = 0; result = 0; return; }
		if (abs(feat[idx] + feat[mid]) <= sum) {
			result = feat[idx] + feat[mid];
			sum = abs(result);
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

	cout << result;

	return 0;
}

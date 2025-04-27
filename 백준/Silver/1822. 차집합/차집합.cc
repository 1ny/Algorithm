#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int na, nb;
vector<int> a, b;
vector<int> ret;

int binSearch(int x)
{
	int st = 0;
	int en = nb - 1;
	int mid;
	while (st <= en)
	{
		mid = (st + en) / 2;
		if (x == b[mid]) return 1;
		else if (x < b[mid]) en = mid - 1;
		else if (x > b[mid]) st = mid + 1;
	}
	return 0;
}

int main() {
	int x;
	cin >> na >> nb;
	for (int i = 0; i < na; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < nb; i++) {
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < na; i++) {
		if (!binSearch(a[i])) ret.push_back(a[i]);
	}

	cout << ret.size() << endl;
	if (!ret.size()) return 0;
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}

	return 0;
}
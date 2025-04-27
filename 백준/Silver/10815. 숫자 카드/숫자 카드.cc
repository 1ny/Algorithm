#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> card;

int binSearch(int x) {
	int st = 0;
	int en = card.size()-1;
	int mid;
	while (st <= en)
	{
		mid = (st + en) / 2;
		if (card[mid] == x) return 1;
		else if (x < card[mid]) en = mid - 1;
		else st = mid + 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		card.push_back(x);
	}
	sort(card.begin(), card.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << binSearch(x) << " ";
	}

	return 0;
}
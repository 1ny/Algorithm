#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int n;
	vector<pair<long, long>> sch;
	//vector<long> endT;

	cin >> n;
	for (int i = 0; i < n; i++) {
		long si, ti;
		cin >> si >> ti;
		sch.push_back({ si, 1 });
		sch.push_back({ ti, -1 });
	}

	// 가장 많은 수업이 열리는 시간에서의 수업의 개수가 곧 강의실 최소값이다
	sort(sch.begin(), sch.end());
	int cur = 0;	// 현재 시간에 열려있는 강의실 개수
	int idx = 0;
	int curT = sch[0].first;	// 현재 시간
	int ret = 0;
	while (1) {
		while (idx < 2 * n && sch[idx].first == curT)
		{
			cur += sch[idx].second;
			idx++;
		}
		curT++;
		if (idx == 2 * n) break;
		ret = max(ret, cur);
	}

	cout << ret;

	return 0;
}
#endif
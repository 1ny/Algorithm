#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_M 100
#define MAX_N 10000

int m, n;
int s[MAX_M][MAX_N];

void compass(int a[], int idx) // 좌표 압축
{
	vector<int> v(a, a + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++) {
		s[idx][i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
	//for (int i = 0; i < n; i++) {
	//	cout << s[idx][i] << " ";
	//}
	//cout << endl;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		compass(s[i], i);
	}
	
	int cnt = 0;
	for (int i = 0; i < m-1; i++) {
		for (int j = i + 1; j < m; j++) {
			int flag = 0;
			for (int k = 0; k < n; k++) {
				if (s[i][k] != s[j][k]) {
					flag = 1;
					break;
				}
			}
			if (!flag) cnt++;
		}
	}

	cout << cnt;

	return 0;
}
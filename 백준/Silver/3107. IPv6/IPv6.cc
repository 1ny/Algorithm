#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
using namespace std;

string str, p;
int len[8];
int cnt, cnt_result, cnt_all;
vector<pair<string, int>> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ':') {
			p.push_back(str[i]);
			cnt++;
		}
		if(str[i] == ':' || i == str.length() - 1) {
			if (i == 1 && p.empty()) continue;
			result.push_back({ p, cnt });
			if(!p.empty()) cnt_result++;
			cnt_all++;
			cnt = 0;
			p.clear();
		}
		//if (str[i] == ':' && str.length() - 1 == i && cnt_result != 8) {
		//	result.push_back({ p, cnt });
		//	cnt_result++;
		//}
	}

	//cout << cnt_result << endl;
	//cout << cnt_all << endl;
	int result_cnt = 0;
	for (int i = 0; i < cnt_all; i++) {
		if (result[i].first.empty()) {
			for (int k = 0; k < 8 - cnt_result; k++) {
				result_cnt++;
				cout << "0000";
				if (result_cnt != 8) cout << ":";
			}
		}
		else
		{
			for (int j = 0; j < 4 - result[i].second; j++) cout << '0';
			cout << result[i].first;
			if (i != cnt_all - 1) cout << ":";
			result_cnt++;
		}
	}

	return 0;
}
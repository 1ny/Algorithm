#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cntSv, cntK; // 증설된 서버 수
vector<int> clk(1002);

int solution(vector<int> players, int m, int k) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int answer = 0; // 증설 횟수
    
    for(int i=0; i<24; i++) {
        for(int j=0; j<cntSv; j++) {
            clk[j]++;
        }
        
        cntK = 0;
        for(int j=0; j<cntSv; j++) {
            if(clk[j] == k) cntK++;
        }

        for(int j=0; j<cntSv; j++) {
            if(clk[j] == k) remove(clk.begin(), clk.end(), k);
        }
        cntSv -= cntK;
        
        if(players[i] >= m && cntSv < players[i] / m) {
            // cout << i << " : " << cntSv << ", " << players[i] / m - cntSv << endl;
            answer += players[i] / m - cntSv;
            cntSv += players[i] / m - cntSv;
        }
        
        cout << i << " : " << players[i] << " " << cntSv << " " << endl;
    }
    
    return answer;
}

/*

*/
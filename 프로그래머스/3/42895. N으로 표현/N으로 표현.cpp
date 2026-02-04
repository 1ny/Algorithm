#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> dp(9);

int solution(int N, int number) {
    if(N == number) return 1;
    int answer = 0;
    
    dp[1].insert(N);
    for(int i=2; i<=8; i++) {
        int cont = 0;
        for(int j=0; j<i; j++) {
            cont = cont * 10 + N;
        }
        dp[i].insert(cont);
        
        for(int f=1; f<i; f++) {
            int s = i - f;
            
            for(auto b : dp[f]) {
                for(auto a : dp[s]) {
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b == 0) continue;
                    dp[i].insert(a/b);
                }
            }
        }
        if(dp[i].count(number)) return i;
    }
    
    return -1;
}
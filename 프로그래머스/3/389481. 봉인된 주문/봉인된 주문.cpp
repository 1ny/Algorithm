#include <string>
#include <vector>
#include "iostream"
#include "algorithm"
using namespace std;

long long powers[12];
void precompute_powers() {
    powers[0] = 1;
    for (int i = 1; i < 12; i++) {
        powers[i] = powers[i - 1] * 26;
    }
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    precompute_powers();

    vector<long long> bans_num;
    for(int i=0; i<bans.size(); i++) {
        long long base = 0;
        int ban_len = bans[i].length();
        if(ban_len > 1) {
            for(int j=1; j<ban_len; j++) {
                base += powers[ban_len-j];
            }
        }
        for(int j=0; j<ban_len; j++) {
            base += ((bans[i][j] - 'a' + 1) - 1) * powers[ban_len - j - 1];
        }
        base++;
        bans_num.push_back(base);
    }
    sort(bans_num.begin(), bans_num.end());
    for(int i=0; i<bans.size(); i++) {
        if(bans_num[i] <= n) n++;
        else break;
    }
    
    long long ref_n = n;
    int n_len = 0;
    for(int i=1; i<=11; i++) {
        if((ref_n - powers[i]) < 0) {
            n_len = i;
            break;
        }
        ref_n = ref_n - powers[i];
    }

    ref_n--;
    for(int i=n_len-1; i>=0; i--) {
        answer += 'a' + (ref_n / powers[i]);
        // cout << (ref_n / powers[i]) << " ";
        ref_n %= static_cast<long long>(powers[i]);
        // cout << ref_n << endl;
    }
    return answer;
}

/*
n = 26 원래는 z였는데,
d랑 e를 지우면
ab가 된다. x는 28
n+2가 된다는 뜻!

근데 z를 지우면..?
aa가 된다..! 
aa는 원래 27번째였는데..!
n+1이 된다는 뜻!

근데 x, y, z, aa를 지우면?
v, w, ab, ac, ad
ad가 된다.
ad = 원래 30이다!
n+3에다가 또 +1이 된다. 왜냐? 
x 24 -> n++ = 27
y 25 -> n++ = 28
z 26 -> n++ = 29
aa 27 -> n++ = 30

그러면 x, y, z, ae를 지우면?
v w aa ab ac ad af
result = ac 29
x 24 -> n++ = 27
y 25 -> n++ = 28
z 26 -> n++ = 29
ae 31 -> n 그대로

순서가 바뀌면?
x, ae, y, z
result = ac 29
x 24 -> n++ = 27
ae 31 -> n 그대로
y 25 -> n++ = 28
z 26 -> n++ = 29

아까것도 순서가 바뀌면?
x, aa, y, z
x 24 -> n++ = 27
aa 27 -> n++ = 28
y 25 -> n++ = 29
z 26 -> n++ = 30


aa = 26 + 1
ab = 26 + 2
ba = 26 + 26*1 + 1
bb = 26 + 26*1 + 2
ca = 26 + 26*2 + 1

aaa = 26 + 26^2 + 1
aba = 26 + 26^2 + 26*1 + 1
azz = 26 + 26^2 + 26*25 + 26
baa = 26 + 26^2 + 26^26 + 1
*/
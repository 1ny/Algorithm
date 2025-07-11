#include <stdio.h>
#include <string.h>

#define MAX_TYPE 7
#define MAX_MENTOR 22
#define MAX_REQS 301

int en[MAX_TYPE][MAX_MENTOR];  // 각 유형별 상담사 종료시간
int mem[MAX_TYPE];             // 각 유형별 상담사 수
int wait[MAX_TYPE];            // 현재 시뮬레이션 대기 시간
int min_wait[MAX_TYPE];        // 최소 대기 시간 기록

void calc_wait_time(int k, int** reqs, int reqs_rows, int* output_wait) {
    memset(en, 0, sizeof(en));
    memset(output_wait, 0, sizeof(min_wait));

    for (int i = 0; i < reqs_rows; i++) {
        int st = reqs[i][0];
        int du = reqs[i][1];
        int type = reqs[i][2];

        // 가장 빨리 가능한 상담사 찾기
        int min_idx = 0;
        for (int j = 1; j < mem[type]; j++) {
            if (en[type][j] < en[type][min_idx])
                min_idx = j;
        }

        if (st >= en[type][min_idx]) {
            en[type][min_idx] = st + du;
        } else {
            output_wait[type] += en[type][min_idx] - st;
            en[type][min_idx] += du;
        }
    }
}

int solution(int k, int n, int** reqs, size_t reqs_rows, size_t reqs_cols) {
    int answer = 0;

    for (int i = 1; i <= k; i++) mem[i] = 1;
    n -= k;

    calc_wait_time(k, reqs, reqs_rows, min_wait);

    while (n > 0) {
        int max_gain = -1, best_type = -1;
        int temp_wait[MAX_TYPE];

        for (int i = 1; i <= k; i++) {
            mem[i]++;
            calc_wait_time(k, reqs, reqs_rows, temp_wait);
            int gain = min_wait[i] - temp_wait[i];
            if (gain > max_gain) {
                max_gain = gain;
                best_type = i;
                memcpy(min_wait, temp_wait, sizeof(min_wait));
            }
            mem[i]--;
        }

        mem[best_type]++;
        n--;
    }

    for (int i = 1; i <= k; i++) {
        answer += min_wait[i];
    }

    return answer;
}

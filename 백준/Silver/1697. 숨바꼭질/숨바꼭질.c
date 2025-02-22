#include <stdio.h>
#include <stdbool.h>

#define MAX 100001

int n, k; // 수빈이 위치 n, 동생 위치 k
int queue[MAX];
int sec[MAX];
int front = 0, rear = 0;

void push(int x) {
    queue[rear++] = x;
}

void pop(int* x) {
    *x = queue[front++];
}

bool is_empty() {
    return front == rear;
}

void bfs(void) {
    while(!is_empty()) {
        int curX;
        pop(&curX);
        if(curX == k) return;
        int dx[3] = {curX-1, curX+1, curX*2};
        for(int i=0; i<3; i++) {
            int nx = dx[i];
            if(nx < 0 || nx >= MAX) continue;
            if(sec[nx] >= 0) continue;
            sec[nx] = sec[curX] + 1;
            push(nx);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<MAX; i++) {
        sec[i] = -1;
    }
    push(n);
    sec[n] = 0;
    bfs();

    // for(int i=0; i<30; i++) {
    //     printf("[%d]test: %d\n", i, sec[i]);
    // }
    // printf("---------------\n");

    printf("%d", sec[k]);

    return 0;
}
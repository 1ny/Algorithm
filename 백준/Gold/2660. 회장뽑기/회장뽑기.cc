#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX (51*51)

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

Node* adj[MAX];
int n;
int queue[MAX], dist[MAX];
int front, rear;
int score[MAX];
int min = MAX, num;

void push(int x) {
	queue[rear++] = x;
}

int pop() {
	return queue[front++];
}

bool is_empty() {
	return front == rear;
}

int bfs(int st) {
	int max = 0;
	memset(queue, 0, sizeof(queue));
	memset(dist, -1, sizeof(dist));
	push(st);
	dist[st] = 0;
	while (!is_empty()) {
		int cur = pop();
		Node* temp = adj[cur];
		while (temp != NULL) {
			int nxt = temp->vertex;
			temp = temp->next;
			if (dist[nxt] >= 0) continue;
			push(nxt);
			dist[nxt] = dist[cur] + 1;
			if (dist[nxt] > max) max = dist[nxt];
		}
	}

	//printf("max: %d\n", max);
	return max;
}

void add_node(int u, int v) {
	Node* new_node = (Node*)malloc(sizeof(Node*));
	new_node->vertex = v;
	new_node->next = adj[u];
	adj[u] = new_node;
}

int main() {
	scanf("%d", &n);
	while(1) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u == -1 || v == -1) break;
		add_node(u, v);
		add_node(v, u);
	}

	for (int i = 1; i <= n; i++) {
		score[i] = bfs(i);
		if (score[i] < min) min = score[i];
	}

	//for (int i = 1; i <= n; i++) {
	//	printf("%d ", score[i]);
	//}
	//printf("\n");

	for (int i = 1; i <= n; i++) {
		if (score[i] == min) num++;
	}

	printf("%d %d\n", min, num);
	for (int i = 1; i <= n; i++) {
		if (score[i] == min) printf("%d ", i);
	}

	return 0;
}
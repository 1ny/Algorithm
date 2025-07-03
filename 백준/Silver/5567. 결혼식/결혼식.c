#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 501

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

int n, m, result;
Node* adj[MAX];
int queue[MAX];
int vis[MAX];
int front, rear;
int top = -1;
int depth = 1;

void add_node(int u, int v) {
	Node* new_node = (Node*)malloc(sizeof(Node*));
	new_node->vertex = v;
	new_node->next = adj[u];
	adj[u] = new_node;
}

void push(int x) {
	queue[rear++] = x;
}
int pop() {
	return queue[front++];
}
bool is_empty() {
	return front == rear;
}

void bfs(int st) {
	push(st);
	vis[st] = 1;
	while (depth--) {
		int cur = pop();
		Node* temp = adj[cur];
		while(temp != NULL) {
			int nxt = temp->vertex;
			temp = temp->next;
			if (vis[nxt]) continue;
			push(nxt);
			vis[nxt] = 1;
			result++;
			if (cur == st) depth++;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_node(u, v);
		add_node(v, u);
	}

	bfs(1);

	printf("%d", result);

	return 0;
}
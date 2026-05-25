#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX], stack[MAX];
int top = -1, n;

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v;
}

void topologicalSort() {

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order:\n");

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
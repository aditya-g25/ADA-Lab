#include <stdio.h>

#define INF 99999
#define MAX 10

void floydWarshall(int graph[MAX][MAX], int n) {

    int dist[MAX][MAX];

    // Copy graph to dist matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest path matrix
    printf("Shortest Distance Matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int n, graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("(Use %d for INF)\n", INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);

    return 0;
}
#include <stdio.h>

#define MAX 20

struct Edge {
    int u, v, w;
};

struct Edge edges[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[a] = b;
}

void sortEdges(int e) {
    struct Edge temp;

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(e);

    printf("Edges in MST:\n");

    for (int i = 0; i < e; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            printf("%d - %d : %d\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].w);

            unionSet(a, b);
        }
    }

    return 0;
}
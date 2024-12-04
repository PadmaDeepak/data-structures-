#include <stdio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited[], int start) {
    int queue[MAX], rear = -1, front = -1, i;


    for (int k = 0; k < MAX; k++)
        visited[k] = 0;


    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) {
        start = queue[front++];
        printf("%d -> ", start);

        for (i = 0; i < MAX; i++) {

            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;

    printf("Enter the adjacency matrix of the graph (%d x %d):\n", MAX, MAX);
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);

    printf("BFS Traversal starting from node 0:\n");
    bfs(adj, visited, 0);
    return 0;
}



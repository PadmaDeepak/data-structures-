
#include <stdio.h>
#define MAX 5

void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX], top = -1, i;


    for (int k = 0; k < MAX; k++)
        visited[k] = 0;


    stack[++top] = start;
    visited[start] = 1;


    while (top != -1) {
        start = stack[top--];
        printf("%d -> ", start);

        for (i = 0; i < MAX; i++) {

            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
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

    // Perform DFS from the first node (0)
    printf("DFS Traversal starting from node 0:\n");
    dfs(adj, visited, 0);



    return 0;
}

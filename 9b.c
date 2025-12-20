#include <stdio.h>

#define MAX 10

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(graph, n, i);
        }
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    dfs(graph, n, 0);

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is CONNECTED\n");
    return 0;
}

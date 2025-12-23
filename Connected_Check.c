#include <stdio.h>

int graph[20][20], visited[20], n;

void DFS(int v)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    DFS(0);   // Start DFS from vertex 0

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

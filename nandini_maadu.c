#include <stdio.h>
#include <stdlib.h>
#define V 5
#define MAXQ 5

void addedge(int adj[V][V],int u,int v){
    adj[u][v]=1;
    adj[v][u]=1;
}

void displayAdjacencyMatrix(int adj[V][V]){
    for(int i=0;i<V;i++)
        printf(" %d",i);
    printf("\n");

    for(int i=0;i<V;i++){
        printf("%d [",i);
        for(int j=0;j<V;j++){
            printf("%d ",adj[i][j]);
        }
        printf("]\n");
    }
}

void displayBFS(int q[MAXQ],int front,int rear,int visited[V],int res[V],int resSize){
    printf("\n\nPrinting queue content- front: %d, rear: %d ; ",front,rear);
    for(int i=front;i<rear;i++)
        printf("[%d]=%d ",i,q[i]);

    printf("\nVisited array: ");
    for(int i=0;i<V;i++)
        printf("[%d]=%d ",i,visited[i]);

    printf("\nResult array: ");
    for(int i=0;i<resSize;i++)
        printf("[%d]=%d ",i,res[i]);
}

void bfs(int adj[V][V],int res[V],int *resSize){
    int front=0;
    int rear=0;
    int q[MAXQ];
    int visited[V]={0};
    int src=0;
    visited[src]=1;
    q[rear++]=src;

    while(front<rear){
        displayBFS(q,front,rear,visited,res,*resSize);
        int curr=q[front++];
        res[(*resSize)++]=curr;

        for(int x=0;x<V;x++){
            if(adj[curr][x] && !visited[x]){
                visited[x]=1;
                q[rear++]=x;
            }
        }
    }
}

int main(){
    int adj[V][V]={0};
    addedge(adj,1,2);
    addedge(adj,1,0);
    addedge(adj,2,0);
    addedge(adj,2,3);
    addedge(adj,2,4);

    displayAdjacencyMatrix(adj);

    int res[V];
    int resSize=0;

    bfs(adj,res,&resSize);

    printf("\nFinal Result: ");
    for(int i=0;i<resSize;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}

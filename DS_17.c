
#include <stdio.h>
#include <stdlib.h>

void bfs(int N, int adj[][N], int src){
    int vis[N]; for(int i=0;i<N;i++) vis[i]=0;
    int q[N], front=0, rear=0; q[rear++]=src; vis[src]=1;
    while(front<rear){
        int u=q[front++]; printf("%d ", u);
        for(int v=0;v<N;v++) if(adj[u][v] && !vis[v]){ vis[v]=1; q[rear++]=v; }
    }
}
void dfsUtil(int u, int N, int adj[][N], int vis[]){
    vis[u]=1; printf("%d ", u);
    for(int v=0;v<N;v++) if(adj[u][v] && !vis[v]) dfsUtil(v,N,adj,vis);
}
void dfs(int N,int adj[][N], int src){
    int vis[N]; for(int i=0;i<N;i++) vis[i]=0; dfsUtil(src,N,adj,vis);
}

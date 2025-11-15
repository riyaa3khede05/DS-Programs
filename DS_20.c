#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

void topoKahn(int N, int adj[][N]){
    int indeg[N]; for(int i=0;i<N;i++) indeg[i]=0;
    for(int u=0;u<N;u++) for(int v=0;v<N;v++) if(adj[u][v]) indeg[v]++;
    int q[N], f=0,r=0;
    for(int i=0;i<N;i++) if(indeg[i]==0) q[r++]=i;
    int cnt=0;
    while(f<r){
        int u=q[f++]; printf("%d ", u);
        cnt++;
        for(int v=0;v<N;v++) if(adj[u][v]){
            if(--indeg[v]==0) q[r++]=v;
        }
    }
    if(cnt!=N) printf("\nGraph has cycle, no topological ordering\n");
}

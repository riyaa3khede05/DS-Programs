#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
int N; 
int adj[MAXN][MAXN];
int disc[MAXN], low[MAXN], parent[MAXN], ap[MAXN], timeD;

void APUtil(int u){
    disc[u]=low[u]=++timeD;
    int children=0;
    for(int v=0; v<N; v++){
        if(!adj[u][v]) continue;
        if(!disc[v]){
            children++; parent[v]=u; APUtil(v);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if(parent[u]==-1 && children>1) ap[u]=1;
            if(parent[u]!=-1 && low[v] >= disc[u]) ap[u]=1;
        } else if(v!=parent[u]){
            if(low[u] > disc[v]) low[u] = disc[v];
        }
    }
}

int isBiconnected(){
    for(int i=0;i<N;i++){ disc[i]=low[i]=0; parent[i]=-1; ap[i]=0; }
    timeD=0; APUtil(0);
    for(int i=0;i<N;i++) if(!disc[i]) return 0; // not connected
    for(int i=0;i<N;i++) if(ap[i]) return 0; // articulation point exists
    return 1;
}

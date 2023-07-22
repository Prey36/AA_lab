#include <iostream>
#include<bits/stdc++.h>

using namespace std;
const int t=6;
bool bfs(int s,int rgraph[t][t],int p[]){
    int visited[t] = {0};
    queue<int> q;
    q.push(s);
    visited[s]=1;
    p[s]=-1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0;v<t;v++){
            if(visited[v]==0 && rgraph[u][v] >0){
                if(v==t-1){
                    p[v]=u;
                    return true;
                }
                q.push(v);
                visited[v]=1;
                p[v]=u; 
            }
        }
    }
    return false;
}

int ford_fulkerson(int s,int graph[t][t]){
    int rgraph[t][t];
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            rgraph[i][j]=graph[i][j];
        }
    }
    int parent[t];
    int max_flow=0;
    while(bfs(0,rgraph,parent)){
        int path_flow = INT_MAX,u=0;
        for(int v=t-1;v!=s;v=parent[v]){
            u=parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        for(int v=t-1;v!=s;v=parent[v]){
            u=parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}

int main() {
    int graph[6][6]={{0,16,13,0,0,0},
                    {0,0,10,12,0,0},    
                    {0,4,0,0,14,0},               
                    {0,0,0,0,0,20},
                    {0,0,0,7,0,4},
                    {0,0,0,0,0,0},
                };
    int max_flow=ford_fulkerson(0,graph);
    cout << max_flow;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n=4;
vector<pair<int,int>> vp;

int kargers_algo(vector<vector<int>> g,vector<vector<int>> g1,int u,int v,vector<pair<int,int>> temp){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int cnt=0;
            if(u==i  && v==j){
                g1[i][j] = g1[j][i] = 0;
            }
            else if(u==i  && v==i){
                if(g[u][j] > 0){
                    cnt+=g[u][j];
                }
                if(g[v][j] > 0){
                    cnt+=g[v][j];
                }
                g1[u][j] = g1[v][j] = cnt;
            }
            else if(u==j  && v==j){
                if(g[u][i] > 0){
                    cnt+=g[u][i];
                }
                if(g[v][i] > 0){
                    cnt+=g[v][i];
                }
                g1[u][i] = g1[v][i] = cnt;
            }
            else{
                g1[i][i] = g[i][i];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j){
                g1[i][j] = g1[j][i];
            }
        }
    }
    n=n-1;
    vector<vector<int>> g2(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            g2[i][j] = g1[i][j];
        }
    }
    if(n> 2){
        int r = rand() % temp.size();
        u = vp[r].first;
        v = vp[r].second;
        temp.erase(temp.begin()+r);
        kargers_algo(g,g2,u,v,temp);
    }
    return g2[0][1];
}

int main(){    
    int ans=INT_MAX;
    vector<vector<int>> g = {{0,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] == 1){
                pair<int,int>temp;
                temp.first= i;
                temp.second = j;
                vp.push_back(temp);
            }
        }
    }
    vector<vector<int>> g1(n,vector<int>(n));
    for(int i=0;i<1;i++){
        g1 = g;
        vector<pair<int,int>> temp(vp.size());
        for(int i=0;i<vp.size();i++){
            temp[i]=vp[i];   
        }
        int r = rand() % vp.size();
        int u = vp[r].first;
        int v = vp[r].second;
        temp.erase(temp.begin()+r);
        int temp2=kargers_algo(g,g1,u,v,temp);
        ans=min(ans,temp2);
    }
    cout << ans ;
}

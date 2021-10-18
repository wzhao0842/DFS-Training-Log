//Build Road
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], vector<bool>& visited, int node){
    visited[node] = 1;
    for(auto u:adj[node]){
        if(!visited[u]){
            dfs(adj, visited, u);
        }
    }
}

int main(){
    int n, m; scanf("%d%d", &n, &m);
    vector<int> adj[n+5];
    for(int i=0;i<m;i++){
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    vector<int> Unconnected;
    vector<bool> visited(n+5, 0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            Unconnected.push_back(i);
            dfs(adj, visited, i);
            cnt++;
        }
    }
    printf("%d\n", cnt-1);
    for(int i=1;i<Unconnected.size();i++){
        printf("%d %d\n", Unconnected[i-1], Unconnected[i]);
    }
}

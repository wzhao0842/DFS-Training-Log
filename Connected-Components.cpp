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

//Moocast
#include <bits/stdc++.h>

using namespace std;

struct cow{
    int x, y, dis;
};

void dfs(vector<int> adj[], vector<bool>& visited, int node){
    visited[node] = 1;
    for(auto u:adj[node]){
        if(!visited[u]){
            dfs(adj, visited, u);
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    vector<cow> cows(n+5);
    vector<int> adj[n+5];
    vector<bool> visited(n+5, 0);
    for(int i=0;i<n;i++){
        scanf("%d%d%d", &cows[i].x, &cows[i].y, &cows[i].dis);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //any decimal need to increment the value by 1
            double preDis = (double)sqrt(pow(cows[i].x-cows[j].x, 2) + pow(cows[i].y-cows[j].y, 2));
            int realDis = preDis; 
            if(realDis != preDis){
                realDis += 1; 
            }
            if(realDis <= cows[i].dis){
                adj[i].push_back(j);
            }
        }
    }

    dfs(adj, visited, 0);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(visited[i]){
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

//fence planing
#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int x1=INF, x2 = -1, y=-1, y2=INF;

void dfs(vector<int> adj[], vector<bool>& visited, pair<int, int> cows[], int node){
    x1 = min(x1,cows[node].first);
    x2 = max(x2, cows[node].first);
    y = max(y, cows[node].second);
    y2 = min(y2, cows[node].second);
    visited[node] = 1;
    for(auto u:adj[node]){
        if(!visited[u]){
            dfs(adj, visited, cows, u);
        }
    }
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    pair<int, int> cows[n+5];
    for(int i=1;i<=n;i++){
        int a, b; scanf("%d%d", &a, &b);
        cows[i].first = a;
        cows[i].second = b;
    }
    vector<bool> visited(n+5, 0);
    vector<int> adj[n+5];
    for(int i=0;i<m;i++){
        int a, b; scanf("%d%d", &a, &b); 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INF;
    int area = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj, visited, cows, i);
            area = (abs(x1 - x2) + abs(y - y2)) * 2;
            ans = min(ans, area); 
            x1=INF, x2 = -1, y=-1, y2=INF;
        }
    }
    printf("%d", ans);
}


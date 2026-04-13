#include<bits/stdc++.h>
using namespace std;
 
int n, m; 
vector<vector<int>> g;
vector<int> vis;
 
void dfs(int node){
    vis[node] = 1;
    for(int neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh);
        }
    }
}
 
void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    vector<int> bridges;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            bridges.push_back(i);
            dfs(i);
        }
    }
    int cc = bridges.size();
    cout << cc - 1 << '\n';
    for(int i = 0; i <  cc - 1; i++){
        cout << bridges[i] << " " << bridges[i + 1] << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    solve();
    return 0;
}
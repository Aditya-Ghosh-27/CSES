#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, m;
vector<vector<int>> g;
bool is_bipartite = true;
vector<int> col;
 
void dfs(int node, int color) {
    col[node] = color;
    for(int i : g[node]) {
        if(col[i] == 0) {
            dfs(i, 3 - color);
        } else if(col[i] == col[node]){
            is_bipartite = false;
        }
    }
}
 
void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    for(int i = 1; i <= n; i++) {
        if(col[i] == 0) {
            dfs(i, 1);
        }
    }
 
    if(is_bipartite) {
        for(int i = 1; i <= n; i++) {
            cout << col[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
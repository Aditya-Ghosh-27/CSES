#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, m;
vector<vector<int>> g;
bool has_cycle = false;
vector<int> col;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;
 
void dfs(int node, int par) {
    parent[node] = par;
    col[node] = 2;
    for(int i : g[node]) {
        if(has_cycle) return;
        if(col[i] == 1) {
            dfs(i, node);
        } else if(col[i] == 2 && i != par) {
            has_cycle = true;
            cycle_start = i;
            cycle_end = node;
            return;
        }
    }
    col[node] = 3;
}
 
void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    for(int i = 1; i <= n; i++) {
        if(col[i] == 1){
            dfs(i, 0);
            if(has_cycle) break;
        }
    }
 
    if(has_cycle) {
        vector<int> path;
        int v = cycle_end;
        while(v != cycle_start) {
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(cycle_start);
        reverse(path.begin(), path.end());
        path.push_back(cycle_start);
        cout << path.size() << '\n';
        for(auto x : path){
            cout << x << " ";
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}

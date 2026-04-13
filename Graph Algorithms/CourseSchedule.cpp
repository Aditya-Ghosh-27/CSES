#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;

void solve(){
    int n, m; cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    // kahn's algo
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto& v : g[node]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }

    if((int)topo.size() != n){
        cout << "IMPOSSIBLE" << '\n';
    } else {
        for(auto v : topo){
            cout << v << " ";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
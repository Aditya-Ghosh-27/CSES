#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;

int n, m;
vector<vector<int>> g;
vector<int> dist;
vector<int> parent;

void bfs(int src){
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);

    queue<int> q;
    dist[src] = 1;
    q.push(src);
    while(!q.empty()){
        auto node = q.front();
        q.pop();

        for(auto v : g[node]){
            if(dist[v] > dist[node] + 1){
                dist[v] = dist[node] + 1;
                parent[v] = node;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);

    if(dist[n] == INF){
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] << '\n';

        int curr = n;
        vector<int> path;
        while(curr != -1){
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for(auto x : path) cout << x << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
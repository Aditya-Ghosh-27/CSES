#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[a][b], c);
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
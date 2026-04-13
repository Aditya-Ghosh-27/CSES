#include<bits/stdc++.h>
using namespace std;
 
int n, m;
vector<string> g;
vector<vector<int>> vis;
 
int dx[] = {0, 1, 0 ,-1};
int dy[] = {1, 0, -1 ,0};
 
bool check(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
 
void dfs(pair<int, int> k){
    int x = k.first, y = k.second;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx, ny) && g[nx][ny] == '.'){
            if(!vis[nx][ny]){
                dfs({nx, ny});
            }
        }
    }
}
 
void solve(){
    cin >> n >> m;
    g.resize(n);
    vis.resize(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && g[i][j] == '.'){
                dfs({i, j});
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    solve();
    return 0;
}
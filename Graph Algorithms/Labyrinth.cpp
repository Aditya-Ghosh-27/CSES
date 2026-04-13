#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
using state = pair<int, int>;
#define F first 
#define S second 

int n, m; 
vector<vector<char>> g;
vector<vector<int>> dist;
vector<vector<state>> parent;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

bool check(int r, int c){
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void bfs(state src){
    dist.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<state>(m, {-1, -1}));

    queue<state> q;
    dist[src.F][src.S] = 0;
    q.push(src);
    while(!q.empty()){
        auto node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = node.F + dr[i];
            int nc = node.S + dc[i];
            if(check(nr, nc) && g[nr][nc] != '#'){
                if(dist[nr][nc] > dist[node.F][node.S] + 1){
                    dist[nr][nc] = dist[node.F][node.S] + 1;
                    parent[nr][nc] = node;
                    q.push({nr, nc});
                }
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n, vector<char>(m));

    state st, en;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c == 'A'){
                st = {i, j};
            } else if(c == 'B'){
                en = {i, j};
            }
            g[i][j] = c;
        }
    }

    bfs(st);

    if(dist[en.F][en.S] == INF){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[en.F][en.S] << '\n';

        vector<state> path;
        state curr = en;
        while(curr.F != -1 && curr.S != -1){
            path.push_back(curr);
            curr = parent[curr.F][curr.S];
        }

        reverse(path.begin(), path.end());

        string moves = "";
        for(size_t i = 0; i < path.size() - 1; i ++){
            int rdiff = path[i + 1].F - path[i].F;
            int cdiff = path[i + 1].S - path[i].S;

            if(rdiff == 1){
                moves += "D";
            } else if(rdiff == -1){
                moves += "U";
            } else if(cdiff == 1){
                moves += "R";
            } else if(cdiff == -1){
                moves += "L";
            }
        }

        cout << moves << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
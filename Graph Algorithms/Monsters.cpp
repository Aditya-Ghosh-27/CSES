#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
using state = pair<int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<int>> mdist(n, vector<int>(m, INF));
    vector<vector<char>> parent(n, vector<char>(m));

    queue<state> mq;
    queue<state> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x; cin >> x;
            if(x == 'A'){
                dist[i][j] = 0;
                q.push({i, j});
            } else if(x == 'M'){
                mdist[i][j] = 0;
                mq.push({i, j});
            }
            grid[i][j] = x;
        }
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    string dir_chars = "URDL";

    auto check = [&](int r, int c) -> bool {
        return (r >= 0 && r < n && c >= 0 && c < m);
    };

    // multisource bfs for monsters
    while(!mq.empty()){
        auto [r, c] = mq.front();
        mq.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(check(nr, nc) && grid[nr][nc] != '#'){
                if(mdist[nr][nc] > mdist[r][c] + 1){
                    mdist[nr][nc] = mdist[r][c] + 1;
                    mq.push({nr, nc});
                }
            }
        }
    }

    // bfs for 'A'
    bool possible = false;
    int exit_r = -1, exit_c = -1;

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        if(r == 0 || r == n - 1 || c == 0 || c == m - 1){
            possible = true;
            exit_r = r;
            exit_c = c;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(check(nr, nc) && grid[nr][nc] != '#'){
                if(dist[nr][nc] > dist[r][c] + 1 && dist[r][c] + 1 < mdist[nr][nc]){
                    dist[nr][nc] = dist[r][c] + 1;
                    parent[nr][nc] = dir_chars[i];
                    q.push({nr, nc});
                }
            }
        }
    }


    if(possible){
        cout << "YES\n";
        cout << dist[exit_r][exit_c] << '\n';

        string path = "";
        int curr_r = exit_r;
        int curr_c = exit_c;
        while(grid[curr_r][curr_c] != 'A'){
            char move = parent[curr_r][curr_c];
            path += move;

            if(move == 'U') curr_r++;
            else if(move == 'R') curr_c--;
            else if(move == 'D') curr_r--;
            else if(move == 'L') curr_c++;
        }

        reverse(path.begin(), path.end());
        cout << path << '\n';
    } else {
        cout << "NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
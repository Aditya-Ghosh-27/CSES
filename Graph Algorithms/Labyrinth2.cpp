#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Direction arrays for Up, Down, Right, Left
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dir_char[4] = {'U', 'D', 'R', 'L'};

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    pair<int, int> start, end;

    // Read the grid and locate 'A' (start) and 'B' (end)
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            } else if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    // visited array to keep track of explored cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // move_dir stores the index (0 to 3) of the direction taken to reach a cell
    vector<vector<int>> move_dir(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    // Standard BFS
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        // Stop early if we reached 'B'
        if (r == end.first && c == end.second) {
            found = true;
            break;
        }

        // Check all 4 adjacent directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            // Check boundaries and whether the cell is unvisited and not a wall
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (!visited[nr][nc] && grid[nr][nc] != '#') {
                    visited[nr][nc] = true;
                    move_dir[nr][nc] = i; // Record how we got here!
                    q.push({nr, nc});
                }
            }
        }
    }

    // Output phase
    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        string path = "";
        pair<int, int> curr = end;

        // Backtrack from 'B' to 'A' using the reverse map
        while (curr != start) {
            int d = move_dir[curr.first][curr.second];
            path += dir_char[d]; // Append the character (U, D, R, L)
            
            // Subtract the direction's delta to step backwards to the parent cell
            curr.first -= dx[d];
            curr.second -= dy[d];
        }

        // Reverse the string because we tracked from end to start
        reverse(path.begin(), path.end());
        
        cout << path.length() << "\n";
        cout << path << "\n";
    }

    return 0;
}
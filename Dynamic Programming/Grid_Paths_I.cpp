#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    if(grid[0][0] == '*'){
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            } else {
                int top = i ? dp[i - 1][j] : 0;
                int left = j ? dp[i][j - 1] : 0;
                dp[i][j] = (top + left) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
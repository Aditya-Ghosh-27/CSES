#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int MOD = 1e9+7;

// rec(i, x): returns the no of ordered ways to construct a sum of x using the ith coing one or more no
//  of times.

void solve(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int k = 1; k <= x; k++){
            // skip ith coin
            int skip = dp[i + 1][k];

            // pick the ith coin
            int pick = 0;
            if(k >= coins[i]){
                pick = dp[i][k - coins[i]];
            }

            dp[i][k] = (pick + skip) % MOD;
        }
    }

    cout << dp[0][x] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
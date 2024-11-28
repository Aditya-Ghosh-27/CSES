#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    // base case
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int k = 1; k <= x; k++){
            int pick = 0;
            if(coins[i] <= k){
                // pick the ith coin
                pick = dp[i][k - coins[i]];
            }
            // skip the ith coin
            int skip = dp[i + 1][k];
            dp[i][k] = (pick + skip) % MOD;
        }
    }

    // final subproblem
    cout << dp[0][x] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
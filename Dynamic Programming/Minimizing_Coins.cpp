#include <bits/stdc++.h>
using namespace std;
#define int long long

// rec(x): min no of coins needed to construct x

void solve(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= coins[j]){
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
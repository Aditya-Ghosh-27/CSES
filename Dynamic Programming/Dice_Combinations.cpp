#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9+7;

// dp[i] = no of ways to construct a sum of i by throwing a dice 1 or more times

void solve(){
    int n; cin >> n;
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i >= j){
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> dp(n + 1);

    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++){
        dp[i] = ((i - 1) * ((dp[i - 2] + dp[i - 1]) % MOD)) % MOD;
    }

    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
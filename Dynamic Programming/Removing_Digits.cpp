#include <bits/stdc++.h>
using namespace std;
#define int long long

// dp[x]: returns the min step required to reach 0 from x

void solve(){
    int n; cin >> n;

    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        string num = to_string(i);
        for(char c : num){
            int digit = c - '0';
            if(digit != 0){
                dp[i] = min(dp[i], 1 + dp[i - digit]);
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
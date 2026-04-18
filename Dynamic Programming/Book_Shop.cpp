#include <bits/stdc++.h>
using namespace std;
// #define int long long

// dp[i][x]: returns the max no of pages from [i.. n] with x price left

void solve(){
    int n, x; cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(2, vector<int>(x + 1, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int w = 1; w <= x; w++){
            dp[i & 1][w] = dp[(i + 1) & 1][w];
            
            if(w >= prices[i]){
                dp[i & 1][w] = max(dp[i & 1][w], pages[i] + dp[(i + 1) & 1][w - prices[i]]);
            }
        }
    }

    cout << dp[0][x] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
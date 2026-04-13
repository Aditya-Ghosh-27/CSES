#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++) cin >> arr[i];

    int dp[n] = {0};
    dp[0] = arr[0];
    int ans = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
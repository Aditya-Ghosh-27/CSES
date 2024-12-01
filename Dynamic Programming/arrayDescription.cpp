#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

bool valid(int x, int m){
    return x >= 1 && x <= m;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    // dp[i][k] = no. of ways to build a prefix of size i such that the last element of the prefix is k


    // base case: dp[i][k] = 1 if (a[0] = 0 or a[1] = k)
    for(int i = 1; i <= m; i++){
        if(a[0] == 1 || a[0] == 0){
            dp[1][i] = 1;
        }
    } 

    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){
            // finding dp[i][k] here
            if(a[i-1] != 0 && a[i-1] != k){
                dp[i][k] = 0;
                continue;
            }

            for(int prev = k-1; prev <= k+1; prev++){
                if(!valid(prev, m)){
                    continue;
                }
                // transition
                dp[i][k] = (dp[i][k] + dp[i-1][prev]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n][i]) % MOD;
    }

    // final subproblem
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> val(n);
    vector<int> weight(n);

    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> val[i];

    vector<vector<int>> dp(n+1, vector<int>(x + 1, 0));
    
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int w = weight[i - 1];
            int value = val[i - 1];

            if(w <= j){
                dp[i][j] = max(dp[i - 1][j], value + dp[i - 1][j - w]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][x] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
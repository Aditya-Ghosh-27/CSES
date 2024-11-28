#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

void solve(){
    int n; cin >> n;

    // here, dp[i] = min. no. of steps required to reach i
    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        string number = to_string(i);
        for(char c : number){
            int digit = c - '0';
            if(digit != 0){
                // transition
                dp[i] = min(dp[i], dp[i - digit]);
            }
        }
    }

    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
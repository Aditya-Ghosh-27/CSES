#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // initializing dp array with some large value
    vector<ll> dp(x + 1, 1e9);

    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j < n; j++){
            if(a[j] <= i){
                dp[i] = min(dp[i], 1 + dp[i - a[j]]);
            }
        }
    }
    
    cout << (dp[x] < 1e9 ? dp[x] : -1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
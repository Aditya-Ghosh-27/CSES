#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());

    int max_reachable = 1;

    for(int coin : coins){
        if(coin > max_reachable){
            break;
        }

        max_reachable += coin;
    }

    cout << max_reachable << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

// c1 + c2 <= x

void solve(){
    int n, x; cin >> n >> x; 
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int cnt = 0;
    int l = 0, r = n - 1;
    while(l <= r){
        if(l == r){
            l++; r--;
        } else if(weights[l] + weights[r] <= x){
            l++; r--;
        } else if(weights[l] + weights[r] > x){
            r--;
        }
        cnt++;
    }

    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
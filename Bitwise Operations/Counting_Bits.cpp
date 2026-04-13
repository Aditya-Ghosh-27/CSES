#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    int total = n + 1;

    int ans = 0;
    for(int i = 0; i < 60; i++){
        int full = total / (1LL << (i + 1));
        int left = total % (1LL << (i + 1));
        int extra = max(0LL, left - (1LL << i));
        ans += (full * (1LL << i)) + extra;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
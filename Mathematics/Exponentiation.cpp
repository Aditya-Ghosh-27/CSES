#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int binpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int a, b; cin >> a >> b;
    cout << binpow(a, b) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int T; cin >> T; while(T--)
    solve();
    return 0;
}
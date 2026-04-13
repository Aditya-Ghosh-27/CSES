#include <bits/stdc++.h>
using namespace std;
#define int long long

// I need to understand the math part of this question later

int binpow(int a, int b, int MOD = 1e9+7){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int a, b, c; cin >> a >> b >> c;
    int MOD = 1e9+7;
    int power = binpow(b, c, MOD - 1);
    cout << binpow(a, power, MOD) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int T; cin >> T; while(T--)
    solve();
    return 0;
}
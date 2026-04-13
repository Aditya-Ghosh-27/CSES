#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
const int N = 1e6;

vector<int> fact, invFact;

int binpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int modInverse(int num){
    return binpow(num, MOD - 2);
}

void precompute(){
    fact.assign(N + 1, 1);
    invFact.assign(N + 1, 1);

    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (i * fact[i - 1]) % MOD;
    }

    invFact[N] = modInverse(fact[N]);
    for(int i = N - 1; i >= 1; i--){
        invFact[i] = ((i + 1) * invFact[i + 1]) % MOD;
    }
}

int ncr(int n, int r){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invFact[n - r]) % MOD) * invFact[r]) % MOD;
}

void solve(){
    int a, b; cin >> a >> b;
    cout << ncr(a, b) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    precompute();
    
    int T; cin >> T; while(T--)
    solve();
    return 0;
}
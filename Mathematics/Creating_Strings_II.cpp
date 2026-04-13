#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
const int N = 1e6;

vector<int> fact, invFact;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
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

void solve(){
    string s; cin >> s;
    int n = s.length();

    vector<int> freq(26, 0);
    for(char c : s){
        freq[c - 'a']++;
    }

    int numerator = fact[n];
    int ans = 1;
    ans = (ans * numerator) % MOD;

    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            ans = (ans * invFact[freq[i]]) % MOD;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    precompute();
    
    solve();
    return 0;
}
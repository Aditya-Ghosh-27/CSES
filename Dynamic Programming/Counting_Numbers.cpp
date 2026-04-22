#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, n;
string L, R;

void build_strings(int l, int r){
    L = to_string(l);
    R = to_string(r);
    string temp = "";
    int cnt = R.length() - L.length();
    while(cnt--){
        temp += '0';
    }
    L = temp + L;
    n = R.length();
}

int dp[20][2][2][10][2];
int rec(int i, bool tlo, bool thi, int last, bool zero){
    // pruning
    // base case
    if(i == n) return 1;

    // cache check
    if(dp[i][tlo][thi][last][zero] != -1) return dp[i][tlo][thi][last][zero];

    // compute
    int ans = 0;
    int lo = 0, hi = 9;
    if(tlo) lo = L[i] - '0';
    if(thi) hi = R[i] - '0';

    for(int dig = lo; dig <= hi; dig++){
        if(!zero && dig == last) continue;

        int ntlo = tlo, nthi = thi;
        if(dig != L[i] - '0') ntlo = 0;
        if(dig != R[i] - '0') nthi = 0;

        int nzero = zero;
        if(dig != 0) nzero = 0;

        ans += rec(i + 1, ntlo, nthi, dig, nzero);
    }

    // save and return
    return dp[i][tlo][thi][last][zero] = ans;
}

void solve(){
    cin >> a >> b;
    build_strings(a, b);

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
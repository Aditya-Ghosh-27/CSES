#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    int x, a, b, c; cin >> x >> a >> b >> c;

    arr[0] = x;
    for(int i = 1; i < n; i++){
        arr[i] = ((a * arr[i - 1]) + b) % c;
    }

    int window_xor = 0;;
    vector<int> window_xors;
    for(int i = 0; i < n; i++){
        window_xor ^= arr[i];
        if((i - k) >= 0) window_xor ^= arr[i - k];
        if(i >= (k - 1)) window_xors.push_back(window_xor);
    }

    int ans = 0;
    for(int x : window_xors){
        ans ^= x;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
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

    int window_sum = 0;
    vector<int> window_sums;
    for(int i = 0; i < n; i++){
        window_sum += arr[i];
        if((i - k) >= 0) window_sum -= arr[i - k];
        if(i >= (k - 1)) window_sums.push_back(window_sum);
    }

    int ans = 0;
    for(int x : window_sums){
        ans ^= x;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
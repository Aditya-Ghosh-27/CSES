#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n, q; cin >> n >> q;
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
 
    int prefixSum[n + 1];
    prefixSum[0] = 0;
    for(int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
 
    while(q--){
        int l, r; cin >> l >> r;
        cout << (prefixSum[r] - prefixSum[l - 1]) << '\n';
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n, q; cin >> n >> q;
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
 
    int prefixXor[n + 1];
    prefixXor[0] = 0;
    for(int i = 1; i <= n; i++){
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }
 
    while(q--){
        int l, r; cin >> l >> r;
        cout << (prefixXor[r] ^ prefixXor[l - 1]) << '\n';
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
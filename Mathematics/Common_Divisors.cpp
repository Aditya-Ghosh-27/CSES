#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    int arr[n];
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    vector<int> freq(mx + 1, 0);
    for(int x : arr){
        freq[x]++;
    }

    for(int gcd = mx; gcd >= 1; gcd--){
        int cnt = 0;
        for(int multiple = gcd; multiple <= mx; multiple += gcd){
            cnt += freq[multiple];
        }

        if(cnt >= 2){
            cout << gcd << '\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
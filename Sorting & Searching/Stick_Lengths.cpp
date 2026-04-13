#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int median_pos = (n & 1) ? (n + 1) / 2 : n / 2;
    int median = arr[median_pos - 1];
    int cost = 0;
    for(int i = 0; i < n; i++){
        cost += abs(median - arr[i]);
    }

    cout << cost << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
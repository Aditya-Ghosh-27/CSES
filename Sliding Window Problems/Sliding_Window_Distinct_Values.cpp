#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
        if((i - k) >= 0){
            mp[arr[i - k]]--;
            if(mp[arr[i - k]] == 0){
                mp.erase(arr[i - k]);
            }
        }
        if(i >= (k - 1)) cout << mp.size() << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, target; cin >> n >> target;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> mp;
    mp[0] = 1;
    int currSum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        currSum += arr[i];
        cnt += mp[currSum - target];
        mp[currSum]++;
    }

    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
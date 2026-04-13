#include <bits/stdc++.h>
using namespace std;
#define int long long

// count the number of subarrays where its sum is divisible by n

// -> sum of subarray = (pref[r] - pref[l - 1]) % n == 0
// -> pref[r] % n - pref[l - 1] % n  + n = 0
// -> pref[r] % n + n = pref[l - 1] % n
// -> currSum % n + n = pref[l - 1] % n

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> mp(n, 0);
    mp[0] = 1;
    int currSum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        currSum = (currSum + arr[i] % n + n) % n;
        cnt += mp[currSum];
        mp[currSum]++;
    }

    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
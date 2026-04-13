#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k;
    int arr[n], sum = 0, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
        sum += arr[i];
    }

    auto check = [&](int mid) -> bool {
        int subarray_sum = 0, cnt = 1;
        for(int i = 0; i < n; i++){
            subarray_sum += arr[i];
            if(subarray_sum > mid){
                cnt++;
                subarray_sum = arr[i];
                if(cnt > k) return false;
            }
        }
        return true;
    };

    int lo = mx, hi = sum, ans = 0;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
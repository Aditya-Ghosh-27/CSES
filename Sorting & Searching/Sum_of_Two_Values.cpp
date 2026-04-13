#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, x; cin >> n >> x;
    // (value, position)
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    bool found = false;
    int l = 0, r = n - 1;
    while(l < r){
        if(arr[l].first + arr[r].first == x){
            found = true;
            break;
        } else if(arr[l].first + arr[r].first > x){
            r--;
        } else if(arr[l].first + arr[r].first < x){
            l++;
        }
    }

    if(found){
        cout << arr[l].second << " " << arr[r].second << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
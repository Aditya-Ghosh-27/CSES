#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> tops;
    for(int i = 0; i < n; i++){
        int cube; cin >> cube;

        auto it = upper_bound(tops.begin(), tops.end(), cube);
        if(it == tops.end()){
            tops.push_back(cube);
        } else {
            *it = cube;
        }
    }

    cout << tops.size() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
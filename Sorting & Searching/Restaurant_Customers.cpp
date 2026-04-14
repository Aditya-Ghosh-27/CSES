#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> events;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }

    sort(events.begin(), events.end());

    int cnt = 0, ans = 0;
    for(size_t i = 0; i < events.size(); i++){
        cnt += events[i].second;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
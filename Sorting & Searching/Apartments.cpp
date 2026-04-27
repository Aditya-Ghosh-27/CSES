#include <bits/stdc++.h>
using namespace std;
#define int long long

// 45 60 60 80
// 30 60 75

// k = 5
// x = 45
// [x - k, x + k]
// [40, 50]

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> applicants(n), apartments(m);
    for(int i = 0; i < n; i++) cin >> applicants[i];
    for(int i = 0; i < m; i++) cin >> apartments[i];

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if(apartments[j] >= applicants[i] - k && apartments[j] <= applicants[i] + k){
            ans++;
            i++; j++;
        } else if(apartments[j] < applicants[i] - k){
            j++;
        } else {
            i++;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n + 1);
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]){
            rounds++;
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;

        int x = arr[a];
        int y = arr[b];

        // pair = {value - 1, value}
        set<pair<int, int>> st; // stores the affected pairs

        if(x - 1 >= 1) st.insert({x - 1, x});
        if(x + 1 <= n) st.insert({x, x + 1});
        if(y - 1 >= 1) st.insert({y - 1, y});
        if(y + 1 <= n) st.insert({y, y + 1});

        for(auto& pairs : st){
            if(pos[pairs.second] < pos[pairs.first]){
                rounds--;
            }
        }

        // perform the swap
        swap(arr[a], arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;

        for(auto& pairs : st){
            if(pos[pairs.second] < pos[pairs.first]){
                rounds++;
            }
        }

        cout << rounds << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
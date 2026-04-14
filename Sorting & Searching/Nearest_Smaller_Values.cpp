#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> stk;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        while(!stk.empty() && arr[stk.back()] >= arr[i]){
            stk.pop_back();
        }

        if(stk.empty()){
            ans.push_back(0);
        } else {
            ans.push_back(stk.back());
        }
        
        stk.push_back(i);
    }

    for(int x : ans){
        cout << x << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
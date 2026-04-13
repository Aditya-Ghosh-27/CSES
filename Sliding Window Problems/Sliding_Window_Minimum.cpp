#include <bits/stdc++.h>
using namespace std;
#define int long long

struct monotone_deque{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back() > x) dq.pop_back();
        dq.push_back(x);
    }

    int getMin(){
        return dq.front();
    }

    void erase(int x){
        if(x == dq.front()) dq.pop_front();
    }   
};

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    int x, a, b, c; cin >> x >> a >> b >> c;

    arr[0] = x;
    for(int i = 1; i < n; i++){
        arr[i] = ((a * arr[i - 1]) + b) % c;
    }

    vector<int> window_mins;
    monotone_deque md;
    for(int i = 0; i < n; i++){
        md.insert(arr[i]);
        if((i - k) >= 0) md.erase(arr[i - k]);
        if(i >= (k - 1)) window_mins.push_back(md.getMin());
    }

    int ans = 0;
    for(int x : window_mins){
        ans ^= x;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
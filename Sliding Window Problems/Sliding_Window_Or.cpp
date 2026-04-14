#include <bits/stdc++.h>
using namespace std;
#define int long long

struct BitwiseORWindow {
    vector<int> bitCount;
    int current_or;

    BitwiseORWindow(){
        bitCount.assign(32, 0);
        current_or = 0;
    }

    void add(int x){
        while(x){
            int bit = __builtin_ctzll(x);
            if(bitCount[bit] == 0){
                current_or |= (1LL << bit);
            }
            bitCount[bit]++;
            x &= (x - 1);
        }
    }

    void remove(int x){
        while(x){
            int bit = __builtin_ctzll(x);
            bitCount[bit]--;
            if(bitCount[bit] == 0){
                current_or ^= (1LL << bit);
            }
            x &= (x - 1);
        }
    }

    int get_or(){
        return current_or;
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

    int ans = 0;
    BitwiseORWindow ds;
    for(int i = 0; i < n; i++){
        ds.add(arr[i]);
        if((i - k) >= 0) ds.remove(arr[i - k]);
        if(i >= (k - 1)) ans ^= ds.get_or();
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
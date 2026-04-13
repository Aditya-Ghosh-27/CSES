#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> freq;
    int head = -1, tail = 0, ans = 0;
    while(tail< n){
        while(head + 1< n && freq[arr[head + 1]] == 0){
            head++;
            freq[arr[head]]++;
        }
        ans = max(ans, head - tail + 1);
        if(tail <= head){
            freq[arr[tail]]--;
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
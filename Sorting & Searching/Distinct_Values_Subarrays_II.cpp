#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int dcnt = 0;   
    map<int, int> freq;
    int head = -1, tail = 0, ans = 0;
    while(tail < n){
        while(head + 1 < n && (freq[arr[head + 1]] > 0 || dcnt < k)){
            head++;
            if(freq[arr[head]] == 0) dcnt++;
            freq[arr[head]]++;
        }
        ans += (head - tail + 1);
        if(tail <= head){
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0) dcnt--;
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
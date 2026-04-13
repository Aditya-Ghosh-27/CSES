#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, target; cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // 2 pointer code
    int sum = 0;
    int head = -1, tail = 0, ans = 0;
    while(tail < n){
        while(head + 1 < n && sum + arr[head + 1] <= target){
            head++;
            sum += arr[head];
        }
        if(sum == target){
            ans++;
        }
        if(tail <= head){
            sum -= arr[tail];
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
 
    cout << ans << '\n';


    // prefix sum + hashmap code
    unordered_map<int, int> mp;
    mp[0] = 1;
    int currSum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        currSum += arr[i];
        cnt += mp[currSum - target];
        mp[currSum]++;
    }

    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
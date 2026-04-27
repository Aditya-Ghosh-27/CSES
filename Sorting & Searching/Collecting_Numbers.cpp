#include <bits/stdc++.h>
using namespace std;
#define int long long

// there can be 2 scenarios

// after i have found x, i need to find x + 1
// 1. x + 1 is present after x i.e on the right hand side of x
// 2. x + 1 is present before x i.e on the left hand side of x

// so we need to collect the position of each element while taking input

void solve(){
    int n; cin >> n;
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        pos[num] = i;
    }

    int rounds = 1;
    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]){
            rounds++;
        }
    }

    cout << rounds << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
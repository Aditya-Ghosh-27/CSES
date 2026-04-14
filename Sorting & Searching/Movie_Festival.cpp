#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> movie_times(n);
    for(int i = 0; i < n; i++){
        cin >> movie_times[i].first >> movie_times[i].second;
    }

    sort(movie_times.begin(), movie_times.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    });
    
    int cnt = 0;
    int last_end = 0;

    for(int i = 0; i < n; i++){
        int start = movie_times[i].first;
        int end = movie_times[i].second;

        if(start >= last_end){
            cnt++;
            last_end = end;
        }
    }

    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
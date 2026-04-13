#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int block_size = (int)sqrt(n); // B = root(n)
    int blocks_cnt = (n + block_size - 1) / block_size; // no of blocks

    vector<int> blocks(blocks_cnt, INT_MAX); 
    for(int i = 0; i < n; i++){
        blocks[i / block_size] = min(arr[i], blocks[i / block_size]);
    }

    while(q--){
        int L, R; cin >> L >> R;
        L--; R--;

        int block_L = L / block_size, block_R = R / block_size;

        int ans = INT_MAX;

        if(block_L == block_R){
            for(int i = L; i <= R; i++){
                ans = min(ans, arr[i]);
            }
        } else {
            // partial left block
            int end_of_left_block = ((block_L + 1) * block_size) - 1;
            for(int i = L; i <= end_of_left_block; i++){
                ans = min(ans, arr[i]);
            }

            // complete middle block
            for(int i = block_L + 1; i <= block_R - 1; i++){
                ans = min(ans, blocks[i]);
            }

            // partial_right_block
            int start_of_right_block = block_R * block_size;
            for(int i = start_of_right_block; i <= R; i++){
                ans = min(ans, arr[i]);
            }
        }

        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
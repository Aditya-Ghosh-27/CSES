#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2e5;
vector<int> arr(N);
 
struct node{
    int sum;
    node(){
        sum = 0;
    }
};
 
vector<node> t(4*N);
 
node merge(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}
 
void build(int id, int l, int r){
    if(l == r){
        t[id].sum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    t[id] = merge(t[2*id], t[2*id + 1]);
}
 
void update(int id, int l, int r, int pos, int val){
    if(pos < l || pos > r){
        return;
    }
    if(l == r){
        t[id].sum = val;
        arr[pos] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2*id], t[2*id + 1]);
}
 
node query(int id, int l, int r, int lq, int rq){
    if(lq > r || l > rq){
        return node();
    }
    if(lq <= l && r <= rq){
        return t[id];
    }
    int mid = (l + r) / 2;
    return merge(query(2*id, l, mid, lq, rq), query(2*id + 1, mid + 1, r, lq, rq));
}
 
void solve(){
    int n, q; cin >> n >> q;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    build(1, 0, n - 1);
 
    while(q--){
        int choice; cin >> choice;
        if(choice == 1){
            int i, x; cin >> i >> x;
            i--;
            update(1, 0, n - 1, i, x);
        } else{
            int l, r; cin >> l >> r;
            l--; r--;
            cout << query(1, 0, n - 1, l, r).sum << '\n';
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve();
    return 0;
}
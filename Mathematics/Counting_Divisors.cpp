#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6;

vector<int> spf(MAXN + 1);

// SPF = smallest prime factorization
// spf[i] = stores the smallest prime factor of i 

void build_spf(){  // log
    for(int i = 1; i <= MAXN; i++) spf[i] = i;

    for(int i = 2; i * i <= MAXN; i++){
        if(spf[i] == i){  // i is prime
            for(int j = i * i; j <= MAXN; j += i){
                if(spf[j] == j){
                    spf[j] = i;  // mark the smallest prime factor
                }
            }
        }
    }
}

void solve(){
    int num; cin >> num;
    int divisors = 1;

    while(num != 1){  // log base spf[num] (num)
        int curr_prime = spf[num];
        int cnt = 0;

        while(num % curr_prime == 0){
            cnt++;
            num /= curr_prime;
        }

        divisors *= (cnt + 1);
    }

    cout << divisors << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    build_spf();
    
    int T; cin >> T; while(T--)
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){
    int N; cin >> N;

    int G = 0;
    for(int i = 1; i <= N; ++i){
        int L, R; cin >> L >> R;

        for(int j = L; j <= R && G != 1; ++j){
            G = __gcd(G, j);
        }
    }

    cout << (G == 1 ? "TIDAK" : "YA") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1; //cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}

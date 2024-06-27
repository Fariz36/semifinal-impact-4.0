#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
//#define endl '\n'
#define debug(x) cerr << #x << " = " << x << endl

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int ans = 0;
void solve() {
  int n;
  cin >> n;

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;

    if (l != r) {
      cout << "NO" << endl;
      return;
    }
    v.push_back(l);
  }

  int g = 0;
  for (auto i : v) {
    g = __gcd(g, i);
  }
  if (g == 1) {
    cout << "NO" << endl;
    return;
  }
  else {
    cout << "YES" << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  //cin >> tc;

  while (tc--) {
    solve();
  }
}
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
#define endl '\n'
#define debug(x) cerr << #x << " = " << x << endl

const int mod = 998244353;
const int maxn = 5e3 + 5;

int n;
vector<int> adj[maxn];
int subtree[maxn];
int dp[maxn][5];
int ans = 0;

void dfs(int u, int par) {
  subtree[u] = 1;
  dp[u][0] = 1;

  for (auto v : adj[u]) {
    if (v == par) continue;

    dfs(v, u);
    subtree[u] += subtree[v];

    dp[u][4] += 4 * subtree[v] * dp[u][3] % mod;
    dp[u][3] += 3 * subtree[v] * dp[u][2] % mod;
    dp[u][2] += 2 * subtree[v] * dp[u][1] % mod;
    dp[u][1] += subtree[v] * dp[u][0] % mod;

    dp[u][4] %= mod;
    dp[u][3] %= mod;
    dp[u][2] %= mod;
    dp[u][1] %= mod;
  }

  //cout << "\n-----\n" << u << " : ";
  //cout << dp[u][4] << " " << dp[u][3] << " " << dp[u][2] << " " << dp[u][1] << " " << dp[u][3]*(n - subtree[u]) << endl;
  //cout << "-----\n";

  //ans += dp[u][4] + 4*dp[u][3]*(n - subtree[u]) + 4*dp[u][3] + 12*dp[u][2]*(n - subtree[u]);
  ans += dp[u][4] + 4*dp[u][3]*(n - subtree[u]);
  ans %= mod;
}

void solve() {
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  } 

  dfs(1, -1);

  cout << ans << endl;
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
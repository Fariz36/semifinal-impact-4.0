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
const int maxn = 1005;

int dp1[10*maxn][maxn], dp2[10*maxn][maxn];
int cnt1[10*maxn][maxn], cnt2[10*maxn][maxn];

int expo(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b&1) res = res*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return res;
}

int f(int x) {
  return (x*(x+1)/2)%mod;
}

int ans = 0;


void solve() {
  int n, l, r;
  cin >> n >> l >> r;

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i <= 9; i++) {
    dp1[i][1] = dp2[i][1] = i;
    cnt1[i][1] = cnt2[i][1] = 1;
  }
  cnt1[0][1] = 0;
  cnt1[0][0] = cnt2[0][0] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9*n; j++) {
      for (int k = 0; k <= 9; k++) {
        if (j - k < 0) continue;
        cnt1[j][i] += cnt1[j-k][i-1];
        dp1[j][i] += 10*dp1[j-k][i-1] + cnt1[j-k][i-1]*k;

        cnt2[j][i] += cnt2[j-k][i-1];
        dp2[j][i] += 10*dp2[j-k][i-1] + cnt2[j-k][i-1]*k;

        cnt1[j][i] %= mod;
        dp1[j][i] %= mod;
        cnt2[j][i] %= mod;
        dp2[j][i] %= mod;
      }
    }
  }
  
  int ans = 0;
  int L = l, R = r;
  
  for (int i = max(l, r); i <= n; i++) {
    l = L;
    r = R;


    int sub = abs(i - l - r);
    if (l+r > i) {
      l -= sub;
      r -= sub;
    }

    for (int j = 0; j <= 9*n; j++) {
      int left = 0;
      if (l == 0) left = expo(10, sub-1);
      int right = expo(10, sub);
      int sum = f(right-1) - f(left-1);
      sum = ((sum%mod) + mod)%mod;

      int kiri = cnt1[j][l];
      int kanan = cnt2[j][r];

      int sum_kiri = dp1[j][l];
      int sum_kanan = dp2[j][r];

      int cont_kiri = 0;
      int cont_kanan = 0;
      int cont_tengah = 0;

      cont_kiri += (sum_kiri*expo(10, sub + r)%mod)*kanan%mod;
      cont_kiri *= right - left;
      cont_kiri %= mod;
      cont_kiri += mod;
      cont_kiri %= mod;

      cont_kanan += sum_kanan*kiri%mod;
      cont_kanan *= right - left;
      cont_kanan %= mod;
      cont_kanan += mod;
      cont_kanan %= mod;

      cont_tengah += (sum*expo(10, r))%mod*kiri%mod*kanan%mod;

      ans += (cont_kiri + cont_kanan + cont_tengah);
      ans %= mod;
    }
    //cout << i << " " << l << " " << r << " " << sub << " : " << ans << endl;
  }

  cout << ans << endl;

   auto end = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  std::chrono::duration<double> elapsed = end - start;

  // Output the elapsed time in seconds
  //std::cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
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
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

const int mod = 1e9 + 7;
const int maxn = 1005;

int prec[maxn];
int dp1[10*maxn][maxn], dp2[10*maxn][maxn];
int cnt1[10*maxn][maxn], cnt2[10*maxn][maxn];
int pref1[2][10*maxn], pref2[2][10*maxn], pref3[2][10*maxn], pref4[2][10*maxn], pref5[2][10*maxn], pref6[2][10*maxn];

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

  prec[0] = 1;
  for (int i = 1; i <= n; i++) prec[i] = (10*prec[i-1]) % mod;

  for (int i = 0; i <= 9; i++) {
    dp1[i][1] = dp2[i][1] = i;
    cnt1[i][1] = cnt2[i][1] = 1;
  }
  cnt1[0][1] = 0;
  cnt1[0][0] = cnt2[0][0] = 1;

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 9*n; j++) {
      pref1[i%2][j] = pref1[i%2][j-1] + dp1[j][i];
      pref2[i%2][j] = pref2[i%2][j-1] + cnt1[j][i];
      pref3[i%2][j] = pref3[i%2][j-1] + dp2[j][i];
      pref4[i%2][j] = pref4[i%2][j-1] + cnt2[j][i];
      pref5[i%2][j] = pref5[i%2][j-1] - j*cnt1[j][i];
      pref6[i%2][j] = pref6[i%2][j-1] - j*cnt2[j][i];
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9*n; j++) {
        int left = max(-1ll, j-10);
        cnt1[j][i] += pref2[(i+1)%2][j] - pref2[(i+1)%2][left];
        dp1[j][i] += 10*(pref1[(i+1)%2][j] - pref1[(i+1)%2][left]) + (pref5[(i+1)%2][j] - pref5[(i+1)%2][left] + j*(pref2[(i+1)%2][j] - pref2[(i+1)%2][left]));

        cnt2[j][i] += pref4[(i+1)%2][j] - pref4[(i+1)%2][left];
        dp2[j][i] += 10*(pref3[(i+1)%2][j] - pref3[(i+1)%2][left]) + (pref6[(i+1)%2][j] - pref6[(i+1)%2][left] + j*(pref4[(i+1)%2][j] - pref4[(i+1)%2][left]));
        
        cnt1[j][i] %= mod;
        dp1[j][i] %= mod;
        cnt2[j][i] %= mod;
        dp2[j][i] %= mod;
        
        pref1[i%2][j] = pref1[i%2][j-1] + dp1[j][i];
        pref2[i%2][j] = pref2[i%2][j-1] + cnt1[j][i];
        pref3[i%2][j] = pref3[i%2][j-1] + dp2[j][i];
        pref4[i%2][j] = pref4[i%2][j-1] + cnt2[j][i];
        pref5[i%2][j] = pref5[i%2][j-1] - j*cnt1[j][i];
        pref6[i%2][j] = pref6[i%2][j-1] - j*cnt2[j][i];

        pref1[i%2][j] %= mod;
        pref2[i%2][j] %= mod;
        pref3[i%2][j] %= mod;
        pref4[i%2][j] %= mod;
        pref5[i%2][j] %= mod;
        pref6[i%2][j] %= mod;
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

    for (int j = 0; j <= 9*i; j++) {
      int left = 0;
      if (l == 0 && sub > 0) left = prec[sub-1];
      int right = prec[sub];
      int sum = f(right-1) - f(left-1);
      sum = ((sum%mod) + mod)%mod;

      int kiri = cnt1[j][l];
      int kanan = cnt2[j][r];

      int sum_kiri = (dp1[j][l]*kanan) % mod;
      sum_kiri *= prec[sub+r];
      sum_kiri %= mod;

      int sum_kanan = (dp2[j][r]*kiri)%mod;

      int cont_kiri = sum_kiri*(right - left);;
      int cont_kanan = sum_kanan*(right - left);;
      int cont_tengah = (kiri*kanan) % mod;

      cont_kiri %= mod;
      cont_kanan %= mod;

      cont_tengah *= sum;
      cont_tengah %= mod;
      cont_tengah *= prec[r];
      cont_tengah %= mod;

      ans += (cont_kiri + cont_kanan + cont_tengah) % mod;
      ans %= mod;
    }
  }

  cout << (ans + mod) % mod << endl;

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
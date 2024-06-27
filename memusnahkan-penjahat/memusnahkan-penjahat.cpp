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

int f(int x) {
	int ans = 0;
	for (int i = -1*(x + x/2); i <= (x+x/2); i++) {
		int l = i, r= i+1;
		double hi_l_square = max((3.0*x*x)/4 - l*x - l*l, (3.0*x*x)/4 + l*x - l*l);
		double hi_r_square = max((3.0*x*x)/4 - r*x - r*r, (3.0*x*x)/4 + r*x - r*r);

		int hi_l, hi_r;
		if (hi_l_square <= 0) hi_l = 0;
		else hi_l = sqrt(hi_l_square);

		if (hi_r_square <= 0) hi_r = 0;
		else hi_r = sqrt(hi_r_square);

		ans += min(hi_l, hi_r);
		//cout << l << " " << r << " " << hi_l_square << " " << hi_r_square << endl;
	}
	return 2*ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	auto start = std::chrono::high_resolution_clock::now();

	int l = 1, r = ceil(sqrt(2*n + 69)), ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (f(mid) >= n) {
			ans = mid;
			r = mid - 1;
		} 
		else {
			l = mid + 1;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  std::chrono::duration<double> elapsed = end - start;

  // Output the elapsed time in seconds
  //std::cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
	cout << ans << endl;
}
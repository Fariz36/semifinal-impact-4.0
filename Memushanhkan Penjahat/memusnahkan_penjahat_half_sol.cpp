#include <bits/stdc++.h>
using namespace std;

#define int long long

bool inside(double x, double y, double r) {
	return x*x + y*y <= r*r;
}

signed main() {
	

	int n, ans;
	cin >> n;

	auto start = std::chrono::high_resolution_clock::now();
	int left = 0, right = 1e3;

	while (left <= right) {
		int r = (left + right) / 2;

		int cnt = 0;
		for (int j = -3*r/2 - 1; j <= 3*r/2 + 1; j++) {
			for (int k = -3*r/2 - 1; k <= 3*r/2 + 1; k++) {
				double x1 = j, y1 = k, x2 = j+1, y2 = k, x3 = j, y3 = k+1, x4 = j+1, y4 = k+1;
				
				if ((inside(x1 - r/2, y1, r) && inside(x2 - r/2, y2, r) && inside(x3 - r/2, y3, r) && inside(x4 - r/2, y4, r)) ||
				    (inside(x1 + r/2, y1, r) && inside(x2 + r/2, y2, r) && inside(x3 + r/2, y3, r) && inside(x4 + r/2, y4, r))) {
					cnt++;
				}
			}
		}
		//cout << r << " " << cnt << endl;
		if (cnt >= n) {
			ans = r;
			right = r - 1;
		} else {
			left = r + 1;
		}	
	}

	cout << ans << endl;

	auto end = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  std::chrono::duration<double> elapsed = end - start;

  // Output the elapsed time in seconds
  //std::cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
}

// https://codeforces.com/problemset/problem/1676/E

// We can make a prefix sum for an array with candies smallest to largest.
// Each index k in the prefix sum is the sum of the smallest k candies.
// Binary search returns the largest index that does not exceed x, which is the answer.

#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	ull a[n], ps[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	// Build the prefixsum array
	sort(a, a+n);
	ps[0] = a[n - 1];
	for(int i = 1; i < n; i++)
		ps[i] = ps[i - 1] + a[n - i - 1];

	// Make each binary search query
	while(k--) {
		ull x; cin >> x;

		int l = 0, r = n - 1, g;
		while(l <= r) {
			g = (r + l)/2;

			if(ps[g] == x) {
				l = g;
				break;
			}

			if(ps[g] < x) l = g + 1;
			else r = g - 1;
		}
		cout << (l < n ? l + 1 : -1 ) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

// https://codeforces.com/contest/2134/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// k === -1 (mod k+1)
// a_i === n (mod k+1)

// a_i + nk === n - n (mod k+1)
// a_i + nk === 0 (mod k+1)


void solve() {
	int n, k;
	cin >> n >> k;

	ull a[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];

	for(int i = 0;i < n;i++)
		a[i] += k*(a[i]%(k+1));

	for(int i = 0;i < n;i++)
		cout << a[i] << ' ';

	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

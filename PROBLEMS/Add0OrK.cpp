// https://codeforces.com/contest/2134/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Let n be an integer such that 
// n = a_i mod (k + 1)

// We can use the following congruence
// k ≡ -1 (mod k + 1)
// a_i + nk ≡ n - n (mod k + 1)
// a_i + nk ≡ 0 (mod k + 1)

// Adding n * k makes a_i divisible by k + 1 which is guaranteed to be greater or equal than 2
// We can apply this operation to every element of 'a' and make the set 'a' have a gcd of at least k + 1

void solve() {
	int n, k;
	cin >> n >> k;

	ull a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		a[i] += k * (a[i] % (k + 1));

	for(int i = 0; i < n; i++)
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

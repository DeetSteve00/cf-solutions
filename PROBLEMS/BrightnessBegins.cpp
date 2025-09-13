// https://codeforces.com/contest/2020/problem/B
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Observation:
// Every bulb will be switched n times where n is the amount of divisors of the ith bulb.
// Each bulb's state is either one or zero, so we can measure its state by taking n (mod 2) where
// if n === 0 (mod 2) then the bulb is on
// if n === 1 (mod 2) then the bulb is off
//
// After all i operations of switching the bulbs, only perfect square bulbs will remain off (1 mod 2)
// This is because perfect squares have an odd number of divisors.

// Proof: 
// Let k be any integer, k can be represented as the product of its prime factorization
// k = p_1^e_1 * p_2^e_1 * ... * p_n^e_n
// The number of divisors of k is the product of every exponent of every prime.
// (e_1 + 1)(e_2 + 1)...(e_n + 1)
//
// Since k^2 is a perfect square, the prime factorization of k^2 is
// k^2 = p_1^(2*e_1) * p_2^(2*e_2) * ... * p_n*(2*e_n)
//
// The number of primes of k^2 is
// (2*e_1 + 1)(2*e_2 + 1)...(2*e_n + 1)
//
// Every number expressed as 2*k + 1 is not divisible by 2, so the final product is also not divisible by 2.

// This transforms the problem into:
// What's the first number n that is greater or equal than k non perfect square integers?
// k = n - squares up to n
// k = n - floor(sqrt(n))
// we can bin search ts fr

void solve() {
	ll k; cin >> k;
	k--;

	ll l = 1, r = 1e18+1e18;
	while(l <= r) {
		ll g = (l + r)/2, rt = sqrtl(g);
		if(g - rt > k) r = g - 1;
		else if(g - rt <= k) l = g + 1;
	}
	cout << l << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

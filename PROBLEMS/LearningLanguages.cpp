// https://codeforces.com/contest/277/problem/A

// Possible solution: Construct a DSU of every language 
// For every employee, join every language they know in the same set.
// If an employee knows 0 languages, exclude them from DSU.
// #sets + #employees_that_know_0_languages is the answer

#include <bits/stdc++.h>
using namespace std;

vector<int> dsu, sz;
int c = 0;

int find(int n) {
	if(dsu[n] == -1 || dsu[n] == n) return dsu[n];
	else return find(dsu[n]);
}

void merge(int a, int b) {
	int pA = find(a), pB = find(b);

	if(pA == -1) {
		pA = dsu[a] = a;
		c++;
	}
	if(pB == -1) {
		pB = dsu[b] = b;
		c++;
	}
	if(pA == pB) return;
	
	if(sz[pA] > sz[pB]) {
		dsu[pB] = pA;
		sz[pA] += sz[pB];
	} else {
		dsu[pA] = pB;
		sz[pB] += sz[pA];
	}
	c--;
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	dsu.resize(m);
	sz.resize(m);
	
	// On this DSU implementation, there might exist the possibility a language is not used.
	// Unused languages will point to -1, otherwise, they must point to their set parent or themselves.
	for(int i = 0; i < m; i++) {
		dsu[i] = -1;
		sz[i] = 1;
	}

	int r = 0;
	while(n--) {
		int k;	cin >> k;
		if(k == 0) r++;
		else if(k == 1) {
			int u; cin >> u;
			if(dsu[u-1] == -1) {
				dsu[u-1] = u-1;
				c++;
			}
		} else {
			int u, v; cin >> u;
			for(int i = 1; i < k; i++) {
				cin >> v;
				merge(u-1, v-1);
				u = v;
			}
		}
	}
	// There exists the possibility that the DSU is not used, when every employee knows 0 languages.
	cout << (c > 0 ? c - 1 : 0) + r << '\n';
	return 0;
}

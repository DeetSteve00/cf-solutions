//https://codeforces.com/contest/580/problem/C
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> c, v;
int n, m, ans = 0;

void dfs(int n, int d) {
	if(v[n] || d > m) return;
	v[n] = 1;

	if(c[n]) d++;
	else d = 0;

	if(tree[n].size() == 1 && d <= m && n != 0) ans++;

	for(int k : tree[n])
		dfs(k, d);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;

	c.resize(n); v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		v[i] = 0;
	}

	tree.resize(n);
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}

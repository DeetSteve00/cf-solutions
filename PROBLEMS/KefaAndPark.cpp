//https://codeforces.com/contest/580/problem/C
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> c;
int n, m, ans = 0;

void dfs(int n, int p, int d) {
	if(d > m) return;

	if(c[n]) d++;
	else d = 0;

	if(tree[n].size() == 1 && d <= m && n != 0) ans++;

	for(int k : tree[n])
		if(k != p) dfs(k, n, d);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;

	c.resize(n);
	for(int& k : c)
		cin >> k;

	tree.resize(n);
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(0, -1, 0);
	cout << ans << '\n';
	return 0;
}

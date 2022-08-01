#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned ll
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1e9

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

const int mod = 1e9 + 7;

int type;
int n, m;
int s[101][101];

queue<pair<int, int>> q;

int main(void) {
	fastio;
	int c = 1;
	while(cin >> type) {
		cout << "Case " << c << ":\n";
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> s[i][j];
		int w = 0;
		while(s[0][w] != 1)
			w++;
		q.push(mp(0, w));
		while(q.size()) {
			pair<int, int> curr = q.front();
			q.pop();
			for(int d = (type == 1)? 0 : 1; d < 4; d++) {
				int i2 = curr.f + d4i[d], j2 = curr.s + d4j[d];
				if(i2 >= 0 && i2 < n && j2 >= 0 && j2 < m)
					if(s[i2][j2] == 1 && !(i2 == 0 && j2 == w))
						s[i2][j2] = s[curr.f][curr.s] + 1, q.push(mp(i2, j2));
			}
		}
		for(int i = 0; i < m; i++)
			cout << s[0][i] << ' ';
		cout << '\n';
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < m; j++)
				if(s[i][j] != 1)
					cout << s[i][j] << ' ';
				else
					cout << "0 ";
			cout << '\n';
		}
		c++;
	}
	
	return 0;
}
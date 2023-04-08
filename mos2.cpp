#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
const int MAX = 2e5+5;
const int LIMIT = 10e6+2;
const int block = 500;
int l[MAX], r[MAX], arr[MAX],cnt[LIMIT];
ll current = 0;
ll ans[MAX];
vector<int> v[505][505];
int n, q;

inline void add(int i) {
	ll x, y;
	y = arr[i];
	x = cnt[y];
	current -= (x*x*y);
	x++;
	cnt[y]++;
	current += (x*x*y);
}

inline void remove(int i) {
	ll x, y;
	y = arr[i];
	x = cnt[y];
	current -= (x*x*y);
	x--;
	cnt[y]--;
	current += (x*x*y);
}

int main (void) {
	scanf ("%d%d", &n,&q);
	int i;
	for (i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
	}
	for (i = 0; i < q; i++) {
		scanf ("%d%d", &l[i], &r[i]);
		v[l[i]/block][r[i]/block].push_back(i);
	}
	int lll = 0, rr  = -1;
	int sz = n/block+1;
	int a, b;
	int j, k;
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			for (k = 0; k < v[i][j].size(); k++) {
				int inx = v[i][j][k];
				a = l[inx]-1;
				b = r[inx]-1;
			//	cout<<a<<" "<<b<<endl;
				while (rr < b) {
					rr++;
					add(rr);
				}
				while (rr > b) {
					remove(rr);
					rr--;
				}
				while (lll < a) {
					remove(lll);
					lll++;
				}
				while (lll > a) {
					lll--;
					add(lll);
				}
				ans[inx] = current;
			}
		}
	}
	for (i = 0; i < q; i++) {
		printf ("%lld\n", ans[i]);
	}
	return 0;
}

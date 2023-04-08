#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define itr iterator
#define ritr reverse_iterator
#define psh push_back
#define mk make_pair
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define scint(a) scanf("%d", &a)
#define scll(a) scanf("%lld", &a)
#define print(a) printf("%d\n", a)
#define prll(a) printf("%lld\n", a)
#define MOD 1000000007ll
#define inf 1000000000ll
#define MAX 1000005

int arr[MAX];
vector<int> seg[MAX];
int n;


void merge (int a, int b, int c) {
	std::vector<int> :: itr it1, it2;
	it1 =  seg[a].begin();
	it2 = seg[b].begin();
	while (it1 != seg[a].end() || it2 != seg[b].end()) {
		if (it1 != seg[a].end() && it2 != seg[b].end()) {
			if (*it1 <= *it2) {
				seg[c].psh(*it1);
				it1++;
			}else {
				seg[c].psh(*it2);
				it2++;
			}
		} else if (it1 != seg[a].end()) {
			seg[c].psh(*it1);
			it1++;
		} else {
			seg[c].psh(*it2);
			it2++;
		}
	}
	return ;
}

void setSeg (int l, int r, int pos) {
	if (l == r) {
		seg[pos].psh(arr[l]);
		return ;
	}
	int mid;
	mid = l + (r-l)/2;
	setSeg (l, mid, 2*pos+1);
	setSeg (mid+1, r, 2*pos+2);
	merge (2*pos+1, 2*pos+2, pos);
	return ;
}

int compute (int pos, int x, int y) {
	return (upper_bound(seg[pos].begin(), seg[pos].end(), y)) - (lower_bound (seg[pos].begin(), seg[pos].end(),x));
}

int query (int qlow, int qhigh, int x, int y, int l, int r, int pos) {
	if (qlow > qhigh) {
		return 0;
	}
	if (r < qlow || l > qhigh) {
		return 0;
	}
	if (qlow <= l && qhigh >= r) {
		return compute (pos, x, y);
	}

	int mid = l + (r-l)/2;

	return query (qlow, qhigh, x, y, l, mid, 2*pos+1) + query (qlow, qhigh, x, y, mid + 1, r, 2*pos+2);
}

int main (void) {
	freopen ("input.in", "r", stdin);

	scint (n);

	for (int i = 0; i < n; i++) {
		scint (arr[i]);
	}

	setSeg (0, n-1, 0);

	int l, r, x, y;
	int q;
	scint (q);

	while (q--) {
		scint (l), scint (r),  scint (x), scint (y);
		cout<<query(l-1, r-1, x, y, 0, n-1, 0) <<endl;
	}

	return 0;
}

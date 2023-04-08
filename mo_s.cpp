#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

int n, q;
ll current_ans;
ll ans[200002];
typedef struct {
	int first;
	int second;
	int i;
} node;
node p[200002];
int block_size;
int cnt[1000010];
int arr[200002];

inline bool mo_cmp (node x, node y) {
//	ll b_x =
//	ll b_y =
	if((x.first)/block_size != (y.first)/block_size) {
		return x.first < y.first;
	}
	return x.second < y.second;
}


inline void include (int i) {
	ll x = cnt[arr[i]];
	current_ans -= (x*x*(ll)arr[i]);
	cnt[arr[i]]++;
	x++;
	current_ans += (x*x*(ll)arr[i]);
}

inline void exclude(int i) {
	ll x = cnt[arr[i]];
	current_ans -= (x*x*(ll)arr[i]);
	cnt[arr[i]]--;
	x--;
	current_ans += (x*x*(ll)arr[i]);
}

int main (void) {
	scanf ("%d", &n);
	scanf ("%d", &q);
	block_size = (int)sqrt(n);
	ll i;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < q; i++) {
		scanf ("%d%d", &(p[i].first), &(p[i].second));
		p[i].i = i;
	}
	sort (p, p+q, mo_cmp);
	// for (i = 0; i < q; i++) {
	// 	cout<<p[i].first<<" "<<p[i].second<<" "<<p[i].i<<endl;
	// }
	// return 0;
	int mo_left = 0;
	int mo_right = -1;
	int left, right;
	for (i = 0; i < q; i++) {
		left = (p[i].first)-1;
		right = (p[i].second)-1;
	//	cout<<left<<" "<<right<<endl;
		while (mo_right < right){
			mo_right++;
			include(mo_right);
		}
		while (mo_right > right) {
			exclude(mo_right);
			mo_right--;
		}

		while (mo_left < left) {
			exclude(mo_left);
			mo_left++;
		}
		while (mo_left > left) {
			mo_left--;
			include(mo_left);
		}
		ans[p[i].i] = current_ans;
	}
	for (i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}

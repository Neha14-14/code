#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define itr iterator
#define ritr reverse_iterator
#define pint pair<int, int>
#define pll pair<ll, ll>
#define S second
#define F first
#define v(a) vector<a>
#define mk(a, b) make_pair(a, b)
#define psh(a) push_back(a)
#define mem(arr, a) memset(arr, a, sizeof(arr))
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll

int n, arr[100000];
int dp[1000];

int main (void) {
	sc (n);
	int i;
	for (i = 0; i < n; i++) {
		sc (arr[i]);
	}

	int temp, j;
	for (i = 1; i <= n; i++) {
		temp = INT_MIN;
		for (j = 1; j <= i; j++) {
			temp = max(temp, arr[j-1]+dp[i-j]);
		}
		dp[i] = temp;
	}

	cout<<dp[n]<<endl;
	return 0;
}

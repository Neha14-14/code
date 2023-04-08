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

int main (void) {
	freopen ("input.in", "r", stdin);
	int i;
	int n;
	vector<string> v;
	string s;
	sc (n);

	for (i = 0; i < n; i++) {
		cin>>s;
		v.push_back (s);
	}

	int * cnt;
	map<vector<int>, vector<string > > mp;
	for (i = 0; i < n; i++) {
		int j = 0;
		vector<int> vv(26, 0);
		while (v[i][j] != '\0') {
			vv [v[i][j]-'a']++;
			j++;
		}
		mp[vv].push_back(v[i]);
	}

	map<vector<int>, vector<string > > :: itr itt;
	itt = mp.begin();
	vector<string> :: itr it;
	std::cout <<mp.size()<< std::endl;
	while (itt != mp.end()) {
		it = (itt->second).begin();
		while (it != (itt->second).end()) {
			cout<<*it<<endl;
			it++;
		}
		itt++;
	}

	return 0;
}

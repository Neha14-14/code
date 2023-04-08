#include<bits/stdc++.h>
#define ll long long
const int k = 16;
const int N = 1e5;
const int ZERO = 0; // gcd(ZERO, x) = gcd(x, ZERO) = x (for any x > 0)

int table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];

int main()
{
    int l, r, g, n;
		cin>>l>>r;
		l /= g;
		r /= g;
		if (l == 0 && r == 0) {
			cout<<0<<endl;
		}if (l == 1 && r == 1) {
			cout<<1<<endl;
		}
		int i;
		int n = r-l+1;
		int arr[n];
		for (i = 0; i < n; i++) {
			arr[i] = l+i;
		}
    // for(int i = 0; i < n; i++)
    //     cin >> Arr[i]; // between 1 and 10^9

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    // main part of the solution
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        int R = i; // we will move R forward as long as gcd(Arr_i, Arr_i+1, ..., Arr_R) != 1
        // or until R reaches n.

        int g = ZERO;
        for(int j = k; j >= 0; j--) {
            if(R + (1 << j) - 1 >= n)
                continue; // we do not want to exceed array size

            if(__gcd(g, table[R][j]) > 1) {
                // Even if we add 2^j more values, gcd is still > 1. Therefore,
                // we move R forward and update gcd appropriately.
                g = __gcd(g, table[R][j]);
                R += 1 << j;
            }
        }

        // In the end, either R = n or gcd(Arr_i, Arr_i+1, ..., Arr_R) = 1.
        answer += n - R;
    }
		answer *= 2;
		if(l <= 1) {
			answer++;
		}
    cout << answer << endl;
    return 0;
}

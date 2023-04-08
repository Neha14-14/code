#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll q = 101, d = 33;
string pat, txt;

void search()
{
	int M = pat.size();
	int N = txt.size();
	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;
	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M-1; i++)
		h = (h*d)%q;
	// Calculate the hash value of pattern and first
    	// window of text
	for (i = 0; i < M; i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}

	for (i = 0; i <= N - M; i++)
	{

		if ( p == t )
		{
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j])
					break;
			}

			if (j == M)
				printf("Pattern found at index %d \n", i);
		}

		// Calculate hash value for next window of text: Remove
       		// leading digit, add trailing digit

		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			if (t < 0)
			t = (t + q);
		}
	}
}

int main()
{
	cin>>txt>>pat;
	search();
	return 0;
}

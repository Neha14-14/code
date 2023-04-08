#include<bits/stdc++.h>
#define MAX 10000000;
using namespace std;

int min (int a, int b)
{
	if (a < b) {
		return a;
	}else{
		return b;
	}
}

void setSeg(int * seg, int * arr, int low, int high, int pos) {

	if (low == high) {
		seg[pos] = arr[low];
		return ;
	}

	int mid ;
	mid = (low+high)/2;

	setSeg(seg, arr, low, mid, 2*pos+1);
	setSeg(seg, arr, mid+1, high, 2*pos + 2);

	seg[pos] = min(seg[2*pos+1], seg[2*pos+2]);
	return ;
}


int segMin(int * seg, int qlow, int qhigh, int low, int high, int pos)
{
	if  (low >= qlow && high <= qhigh) {
		//printf("Success1\n");
		return seg[pos];
	}

	if (qlow > high || qhigh < low) {
		//printf("Success2\n");
		return 0;
	}

	int mid;
	mid = (low+high)/2;
	//printf("Success3\n");
	return segMin(seg, qlow, qhigh, low, mid, 2*pos+1) + segMin(seg, qlow, qhigh, mid+1, high, 2*pos+2);
}


void update(int * seg, int * arr, int q, int low, int high, int pos, int val)
{
	if (low == high) {
		arr[low] = val;
		seg[pos] = val;
		return ;
	}

	int mid;
	mid = (low+high) / 2;

	if(q >= low && q<= mid) {
		update(seg, arr, q, low, mid, 2*pos+1, val);
	}else{
		update(seg, arr, q, mid+1, high, 2*pos+2, val);
	}

	seg[pos] = seg[2*pos+1] + seg[2*pos+1];
	return ;
}


int main (void)
{
	int n;

	scanf ("%d", &n);

	int size;
	int ctr = 1;

	while (ctr<n) {
		ctr <<= 1;
	}

	size = 2*ctr -1 ;

	//printf("%d" , size);
	int i, arr[n], seg[size];
	memset(seg, 0, sizeof(seg));

	for (i = 0; i < n; i++){
		scanf ("%d", &arr[i]);
	}
	setSeg(seg, arr, 0, n-1, 0);

/*	for (i = 0; i < size; i++) {
		printf("%d ", seg[i]);
	}*/

	//printf("\n");

	int q, x,y, o;

	scanf("%d", &q);

	while (q--) {
		scanf("%d",&o);
		if (o){
			scanf("%d%d", &x, &y);
			printf("%d\n", segMin(seg, x, y, 0, n-1, 0));
		}else{
			scanf ("%d%d", &x, &i);
			update(seg, arr, x, 0, n-1, 0, i);
		}

	}

	return 0;
}

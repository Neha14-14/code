#include<bits/stdc++.h>
using namespace std;

void setSeg(int * seg, int * arr, int low, int high, int pos)
{
  if (low == high) {
    seg[pos] = arr[low];
    return;
  }

  int mid;
  mid = (low+high)/2;

  setSeg(seg, arr, low, mid, 2*pos+1);
  setSeg(seg, arr, mid+1, high, 2*pos+2);

  seg[pos] = seg[2*pos+1] + seg[2*pos+2];

  return ;
}

void update(int * seg, int * lazy, int * arr, int qlow, int qhigh, int low, int high, int pos, int val)
{
  if(low > high) {
    return;
  }

  if (lazy[pos] != 0) {
    seg[pos] += (high-low+1)*lazy[pos];
    if (low != high) {
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  if (high < qlow || low > qhigh) {
    return ;
  }

  if (qlow <= low && qhigh >= high) {
      seg[pos] += (high - low+1)*val;
      if (low != high) {
        lazy[2*pos+1] += val;
        lazy[2*pos+2] += val;
      }
      return ;
  }
  int mid = (low+high)/2;

  update(seg, lazy, arr, qlow, qhigh, low, mid, 2*pos+1, val);
  update(seg, lazy, arr, qlow, qhigh, mid+1, high, 2*pos+2, val);
  seg[pos] = seg[2*pos+1] + seg[2*pos+2];
  return;
}

int query(int * seg, int * lazy, int * arr, int qlow, int qhigh, int low, int high, int pos)
{
  if (low>high) {
    return 0;
  }

  if (lazy[pos] != 0) {
    seg[pos] += (high - low + 1) *lazy[pos];
    if (low != high) {
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  if (high < qlow || low > qhigh) {
    return 0;
  }

  if (qlow <= low && qhigh >= high) {
    return seg[pos];
  }
  int mid;
  mid = (low+high) / 2;

  return query(seg, lazy, arr, qlow, qhigh, low, mid, 2*pos+1) + query(seg, lazy, arr, qlow, qhigh, mid+1, high, 2*pos+2);
}

int main (void)
{
  int n;
  scanf ("%d", &n);

  int ctr = 1;

  while (ctr < n) {
    ctr <<=1;
  }
  int size;
  size = 2 * ctr - 1;

  int arr[n], seg[size], lazy[size];
  memset(seg, 0, sizeof(seg));
  memset(lazy, 0, sizeof(lazy));

  int i;

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  setSeg(seg, arr, 0, n-1, 0);

  for (i = 0; i < size; i++) {
    printf("%d ", seg[i]);
  }

  printf("\n");

  int q;
  scanf ("%d", &q);

  int o, x, y, val;
  while (q--) {
    scanf("%d", &o);

    if(o) {
      scanf ("%d%d", &x, &y);
      printf("%d\n", query(seg, lazy, arr, x, y, 0, n-1, 0));
    }else{
      scanf ("%d%d%d", &x, &y, &val);
      update(seg, lazy, arr, x, y, 0, n-1, 0, val);
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[200005]; cin>>n;
  for (int i=0; i<n; ++i) cin>>a[i];
  sort(a,a+n);
  int cnt=1;
  for (int i=1; i<n; ++i) {
    if (a[i]!= a[i-1]) cnt++;
  }
  cout<<cnt;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k, q, a[100005], p[100005]; p[0]=0;
  cin >> n >>k;
  for(int i = 1;i <=n; ++i){
    cin>>a[i];
    p[i]=p[i-1];
    if(a[i] == k) p[i]++;
  }
  cin>>q;
  while(q--){
    int l,r;
    cin >> l>>r;
    cout<< p[r]-p[l-1] <<'\n';
  }
  return 0;
}

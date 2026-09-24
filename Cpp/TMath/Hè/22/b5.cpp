#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n>>q;
  vector<int> d(n+3,0);
  for (int i=0; i<q; i++){
    int x,y; cin>>x>>y;
    d[x]^=1,d[y+1]^=1;
  }
  int cur=0;
  for (int i=1; i<=n; i++){
    cur^=d[i];
    cout<<cur<<" ";
  }
  return 0;
}

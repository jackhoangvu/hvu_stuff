#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  m=m%(n*(n+1)/2);
  for(int i=1; i<=n; ++i){
    if(m<i) {cout<<m; return 0;}
    m-=i;
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  int cnt=0;
  for (int i=n; i<=m; i++){
    long long s=sqrt(i);
    if(s*s==i) cnt++;
  }
  cout<<cnt*(cnt-1)/2<<"\n";
  return 0;
}

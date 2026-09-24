#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int ans=0;
  for (int i=0; i<n; i++){
    int x,y,z;
    cin>>x>>y>>z;
    int cnt=x+y+z;
    if(cnt>=2) ans++;
  }
  cout<<ans<<"\n";
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> pos(n+2);
  for (int i=1; i<=n; i++){
    int x; cin>>x;
    pos[x]=i;
  }
  int ans=1;
  for (int i=1; i<n; i++){
    if(pos[i+1]<pos[i]) ans++;
  }
  cout<<ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,p[105], g[105]; cin>>n;
  for (int i=1; i<=n; i++){
    cin>>p[i];
  }
  for (int i=1; i<=n; i++){
    g[p[i]]=i;
  }
  for (int i=1; i<=n; i++){
    cout<<g[i]<<" ";
  }
  return 0;
}

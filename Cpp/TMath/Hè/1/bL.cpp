#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int mx=-INT32_MAX;
  int mi=INT32_MAX;
  for (int i=0; i<n; i++){
    int x; cin>>x;
    mx=max(mx,x);
    mi=min(mi,x);
  }
  cout<<abs(mx-mi)<<"\n";
  return 0;
}

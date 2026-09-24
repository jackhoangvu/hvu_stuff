#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin>>n>>x;
  vector<int> a(n-1);
  for (int i=0; i<n-1; i++){
    cin>>a[i];
  }
  int ans=1;
  for (int i=0; i<n-1; i++){
    if(a[i]-x>0) ans++;
  }
  cout<<ans;
  return 0;
}

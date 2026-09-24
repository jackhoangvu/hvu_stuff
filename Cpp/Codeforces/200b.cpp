#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[102]; cin>>n;
  double ans=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    ans+=a[i];
  }
  ans/=n;
  cout<<fixed<<setprecision(12)<<ans;
  return 0;
}

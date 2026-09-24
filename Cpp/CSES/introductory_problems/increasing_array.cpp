#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[200005];cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  if(n==1){cout<<"0"; return 0;}
  long long ans=0;
  for (int i=0; i<n-1; i++){
    if(a[i+1]<a[i]) {
      ans+=(a[i]-a[i+1]);
      a[i+1]=a[i];
    }
  }
  cout<<ans;
  return 0;
}

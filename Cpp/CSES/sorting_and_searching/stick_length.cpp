#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[200005];
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int med=a[n/2];
  long long ans=0;
  for (int i=0; i<n; i++){
    ans+=abs(a[i]-med);
  }
  cout<<ans;
  return 0;
}

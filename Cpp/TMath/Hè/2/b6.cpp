#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int ans=a[0];
  for (int i=0; i<n-1; i++){
    ans=gcd(ans,a[i+1]);
  }
  cout<<ans;
  return 0;
}

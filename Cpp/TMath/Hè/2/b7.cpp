#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long ans=a[0];
  for (int i=0; i<n-1; i++){
    ans=lcm(ans,a[i+1]);
  }
  cout<<ans;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int l,n; cin>>l>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int ans=-1;
  ans=max(a[0],l-a[n-1]);
  for (int i=0; i<n-1; i++){
    ans=max(ans,abs(a[i]-a[i+1])/2);
  }
  cout<<ans<<"\n";
  return 0;
}

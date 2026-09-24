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
  int mx=INT32_MIN;
  for (int i=0; i<n; i++){
    for (int j=i+1; j<n; j++){
      mx=max(mx,a[j]-a[i]);
    }
  }
  cout<<mx;
  return 0;
}

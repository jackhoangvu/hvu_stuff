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
  sort(a.begin(),a.end());
  cout<<max(abs(a[0]+a[1]),abs(a[n-1]+a[n-2]));
  return 0;
}

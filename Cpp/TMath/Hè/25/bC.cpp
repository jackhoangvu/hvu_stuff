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
  int q; cin>>q;
  vector<int> t(q);
  for (int i=0; i<q; i++){
    cin>>t[i];
  }
  sort(a.begin(),a.end());
  for (int i=0; i<q; i++){
    auto it=upper_bound(a.begin(),a.end(),t[i]);
    cout<<it-a.begin()<<"\n";
  }
  return 0;
}

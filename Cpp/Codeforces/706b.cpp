#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  cin>>q;
  vector<int> b(n+1);
  for (int i=0; i<q; i++){
    cin>>b[i];
  }
  sort(a.begin(),a.end());
  for (int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  for (int i=0; i<q; i++){
    auto it=upper_bound(a.begin(),a.end(),b[i]);
    if(it!=a.end()) cout<<*it<<" ";
    else cout<<0<<" ";
  }
  return 0;
}

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
  vector<int> t;
  for (int i=0; i<n; i++){
    auto it=upper_bound(t.begin(),t.end(),a[i]);
    if(it==t.end()) t.push_back(a[i]);
    else *it=a[i];
  }
  cout<<t.size()<<"\n";
  return 0;
}

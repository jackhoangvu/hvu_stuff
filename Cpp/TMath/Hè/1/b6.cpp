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
  sort(a.begin(),a.end(),greater<long long>());
  for (int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

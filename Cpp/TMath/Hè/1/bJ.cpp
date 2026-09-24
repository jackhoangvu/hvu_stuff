#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  int c1=0;
  vector<long long> k1;
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]!=1) k1.push_back(a[i]);
    else c1++;
  }
  sort(k1.begin(),k1.end(),greater<long long>());
  for (int i=0; i<k1.size()-1; i++){
    if(k1[i]==3&&k1[i+1]==2) swap(a[i],a[i+1]);
  }
  for (int i=0; i<c1; i++){
    cout<<1;
    if(i!=c1-1) cout<<" ";
  }
  if(c1>0) cout<<" ";
  for (int i=0; i<k1.size(); i++){
    cout<<k1[i]<<" ";
  }
  return 0;
}

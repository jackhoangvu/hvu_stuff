#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int m,l; cin>>m>>l;
  vector<int> b(m);
  for (int i=0; i<m; i++){
    cin>>b[i];
  }
  // long long sa=0, sb=0;
  vector<long long> sa,sb;
  long long ca=0,cb=0;
  for (int i=0; i<k; i++){
    ca+=a[i];
  }
  for (int i=0; i<l; i++){
    cb+=b[i];
  }
  sa.push_back(ca);
  sb.push_back(cb);
  for (int i=k; i<n; i++){
    ca=ca-a[i-k]+a[i];
    sa.push_back(ca);
  }
  for (int i=l; i<m; i++){
    cb=cb-b[i-l]+b[i];
    sb.push_back(cb);
  }
  map<long long,long long> freq;
  for(auto i:sa){
    freq[i]++;
  }
  long long ans=0;
  for(auto i:sb){
    auto it=freq.find(i);
    if(it != freq.end()){
      ans+=it->second;
    }
  }
  cout<<ans;
  return 0;
}

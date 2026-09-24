#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  long long sum=0;
  if(k>=n) cout<<0<<"\n";
  else{
    for(int i=0; i<n-k; i++){
      sum+=a[i];
    }
    cout<<sum<<"\n";
  }
  return 0;
}

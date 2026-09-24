#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; long long k; cin>>n>>k;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int l=0; long long s=0;
  int ans=1e9;
  for(int r=0; r<=n; r++){
    s+=a[r];
    while(s>=k){
      if(s==k) ans=min(ans,r-l+1);
      s-=a[l];
      l++;
    }
  }
  if(ans==1e9) cout<<0<<"\n";
  else cout<<ans<<"\n";
  return 0;
}

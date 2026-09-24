#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n>>q;
  vector<long long> a(n+5);
  vector<long long> pref(n+5,0);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  for (int i=1; i<=n; i++){
    if(i!=1){
      pref[i]=pref[i-1]+a[i];
    }
    else{
      pref[i]=a[i];
    }
  }
  for (int i=1; i<=q; i++){
    long long a,b; cin>>a>>b;
    cout<<pref[b]-pref[a-1]<<"\n";
  }
  return 0;
}

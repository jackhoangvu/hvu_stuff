#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b,k; cin>>a>>b>>k;
  vector<bool> sq(b+1,false);
  for (int i=1; i*i<=b; i++){
    if(i*i>=a){
      sq[i*i]=true;
    }
  }
  vector<int> pref(b+1,0);
  for (int i=a; i<=b; i++){
    pref[i]=pref[i-1]+sq[i];
  }
  if(pref[b]-pref[a-1]<k){
    cout<<-1;
    return 0;
  }
  int ans=-1;
  int l=1,r=b-a+1;
  while(l<=r){
    bool ok=true;
    int mid=(l+r)/2;
    for (int i=a; i<=b-mid+1; i++){
      if(pref[i+mid-1]-pref[i-1]<k){
        ok=false;
        break;
      }
    }
    if(ok){
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }
  cout<<ans;
  return 0;
}

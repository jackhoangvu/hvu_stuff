#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll k;
vector<ll> a;
ll solve1(){
  ll ans=0;
  for(int l=1; l<=n; l++){
    ll s1=0,s2=0;
    bool ie=false,io=false;
    for(int r=l; r<=n; r++){
      if(a[r]%2==0) s1+=a[r],ie=true;
      else s2+=a[r],io=true;
      ll d=s1-s2;
      if(ie&&io&&0<=d&&d<=k) ans++;
    }
  }
  return ans;
}
ll solve2(){
  unordered_map<ll,ll> freq;
  ll pref=0;
  ll ans=0;
  freq[0]=1;
  for(int i=1; i<=n; i++){
    if(a[i]%2==0) pref+=a[i];
    else pref-=a[i];
    auto it=freq.find(pref);
    if(it!=freq.end()) ans+=it->second;
    freq[pref]++;
  }
  return ans;
}
ll solve3(){
  unordered_map<ll,ll> freq;
  ll pref=0;
  ll ans=0;
  freq[0]=1;
  for(int i=1; i<=n; i++){
    if(a[i]%2==0) pref+=a[i];
    else pref-=a[i];
    for(ll d=0; d<=k; d++){
      ll need=pref-d;
      auto it=freq.find(need);
      if(it!=freq.end()) ans+=(it->second);
    }
    freq[pref]++;
  }
  ll e=0;
  ll sum=0;
  int l=1;
  for(int r=1; r<=n; r++){
    if(a[r]%2==1){
      sum=0;
      l=r+1;
      continue;
    }
    sum+=a[r];
    while(sum>k&&l<=r){
      sum-=a[l];
      l++;
    }
    e+=r-l+1;
  }
  return ans-e;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  a.resize(n+1);
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  if(n<=2000) cout<<solve1();
  else if(k==0) cout<<solve2();
  else cout<<solve3();
  return 0;
}

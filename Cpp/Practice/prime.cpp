#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
bool p[mxn];
void sang(int mx=mxn){
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  for(long long i=2; i*i<=mx; i++){
    for(long long j=i*i; j<=mx; j+=i){
      p[j]=false;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  sang();
  vector<long long> a(n);
  vector<long long> cnt(mxn,0);
  for (long long i=0; i<n; i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  long long ans=0;
  for (long long i=2; i<=mxn; i++){
    if(p[i]&&cnt[i]>1){
      ans+=(cnt[i]*(cnt[i]-1)/2);
    }
  }
  if(cnt[1]>0){
    for (long long i=2; i*i<=mxn; i++){
      if(p[i]){
        ans+=(cnt[1]*cnt[i*i]);
      }
    }
  }
  cout<<ans;
}

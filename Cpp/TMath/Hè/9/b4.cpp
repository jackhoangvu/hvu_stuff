#include <bits/stdc++.h>

using namespace std;
const long long mxn=1e6+5;
bool p[mxn];
void sang(long long mx=mxn){
  p[0]=p[1]=false;
  for(long long i=2; i*i<=mx; i++){
    if(p[i]){
      for(long long j=i*i; j<=mx; j+=i){
        p[j]=false;
      }
    }
  }
}
bool pr(long long n){
  if(n<mxn) return p[n];
  for(long long i=2; i*i<=n; i++){
    if(p[i]&&n%i==0) return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  fill(p,p+mxn,true);
  sang();
  while(t--){
    long long n; cin>>n;
    int cnt=0;
    for(int i=0; i<6; i++){
      if(pr(n+i)) cnt++;
    }
    if(cnt==2) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
  }
  return 0;
}

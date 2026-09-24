#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
bool p[mxn];
long long pr(long long n){
  if(n<=1) return false;
  long long cnt=0;
  long long mx=sqrt(n);
  for(int i=1; i<=mx; i++){
    if(n%i==0){
      cnt++;
      if(i*i!=n) cnt++;
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  long long mx=sqrt(mxn);
  for(long long i=2; i<=mx; i++){
    if(p[i]){
      for(long long j=i*i; j<=mx; j+=i){
        p[j]=false;
      }
    }
  }
  while(t--){
    long long a,b; cin>>a>>b;
    long long cnt=0;
    for (int i=a; i<=b; i++){
      if(p[pr(i)]) cnt++;
    }
    cout<<cnt<<"\n";
  }

  return 0;
}

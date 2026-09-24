#include <bits/stdc++.h>

using namespace std;
const int mxn=200000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> scp(mxn+5);
  long long s=sqrt(mxn);
  for(long long i=2; i<=s; i++){
    if(scp[i]==0){
      scp[i]=i;
      for(int j=i*i; j<=mxn; j+=i)
        if(scp[j]==0) scp[j]=i;
    }
  }
  vector<long long> cnt(mxn+5);
  long long c=0, ans=0;
  for(int i=0; i<n; i++){
    int x; cin>>x;
    if(x==0){
      c++;
      continue;
    }
    int y=x, fi=1;
    for(int p=2; p*p<=y; p++){
      int odd=0;
      while(y%p==0){
        y/=p;
        odd^=1;
      }
      if(odd) fi*=p;
    }
    if(y>1) fi*=y;
    ans+=cnt[fi];
    cnt[fi]++;
  }
  ans+=c*(n-c)+c*(c-1)/2;
  cout<<ans;
  return 0;
}

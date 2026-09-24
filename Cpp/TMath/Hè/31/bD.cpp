#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,x,m;
  cin>>n>>x>>m;
  vector<int> pos(m,0);
  vector<int> a(m+2);
  vector<long long> s(m+2);
  long long ans=0,sum=0,len=0,cnt=0,sl=0;
  a[1]=x;
  pos[a[1]]=1;
  s[1]=a[1];
  for(int i=1;; i++){
    if(i==n){
      ans=s[i];
      break;
    }
    a[i+1]=(long long)a[i]*a[i]%m;
    if(pos[a[i+1]]!=0){
      len=i+1-pos[a[i+1]];
      cnt=(n-pos[a[i+1]]+1)/len;
      sum=s[i]-s[pos[a[i+1]]-1];
      sl=(n-pos[a[i+1]]+1)%len;
      ans=s[pos[a[i+1]]-1]+sum*cnt;
      for(int j=0; j<sl; j++) ans+=a[pos[a[i+1]]+j];
      break;
    }
    s[i+1]=s[i]+a[i+1];
    pos[a[i+1]]=i+1;
  }
  cout<<ans;
}

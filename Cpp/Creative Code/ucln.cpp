#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[105];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
    int x=a[i];
    for(int p=2; p*p<=x; ++p){
      while(x %p==0){
        mp[p]++;
        x/=p;
      }
    }
    if(x >1) mp[x]++;
  }
  long long d=1,c=0;
  for(auto [p,s]:mp){
    int t=s/n;
    for(int i=0; i<t; ++i) d*=p;
    for(int i=0; i<n; ++i){
      int x =a[i], cnt=0;
      while(x %p==0){
        cnt++;
        x/= p;
      }
      if(cnt <t) c += t-cnt;
    }
  }
  cout<<d <<' '<< c;
}

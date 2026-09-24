#include <bits/stdc++.h>
using namespace std;
int n,k,x;
long long cnt[6], s;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for (int i=0; i<n;++i){
    cin>>x;
    cnt[x]++;
  }
  if (k==1) s= cnt[1];
  if (k==2) s=cnt[2]+ cnt[1]/2;
  if (k==3) {
    s=cnt[3];
    long long t= min(cnt[1],cnt[2]);
    s+=t; cnt[1]-=t;cnt[2]-=t;
    s += cnt[1]/3;
  }
  if (k==4) {
    s=cnt[4];
    long long t= min(cnt[1],cnt[3]);
    s+=t; cnt[1]-=t;cnt[3]-=t;
    s+=cnt[2]/2;cnt[2]%=2;
    t=min(cnt[1]/2,cnt[2]);
    s+=t; cnt[1]-=t*2;cnt[2]-=t;
    s += cnt[1]/4;
  }
  if (k==5) {
    s=cnt[5];
    long long t= min(cnt[1],cnt[4]);
    s+=t; cnt[1]-=t;cnt[4]-=t;
    t= min(cnt[2],cnt[3]);
    s+=t; cnt[2]-=t;cnt[3]-=t;
    t= min(cnt[1]/2,cnt[3]);
    s+=t; cnt[1]-=t*2;cnt[3]-=t;
    t =min(cnt[1],cnt[2]/2);
    s+=t; cnt[1]-=t;cnt[2]-=t*2;
    s += cnt[1]/5;
  }
  cout<<s/3;
  return 0;
}

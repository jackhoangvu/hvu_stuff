#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long rangeSum(int x,long long start,long long step,long long l,long long r){
  if(l>r) return 0;
  if(x==0) return start%mod;
  long long half=1LL<<(x-1);
  long long step2=(step*2)%mod;
  long long res=0;
  long long l1=max(l,1LL),r1=min(r,half);
  if(l1<=r1) res=(res+rangeSum(x-1,start,step2,l1,r1))%mod;
  long long l2=max(l,half+1)-half,r2=min(r,2*half)-half;
  long long start2=(start+step)%mod;
  if(l2<=r2) res=(res+rangeSum(x-1,start2,step2,l2,r2))%mod;
  return res;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    long long n;
    long long l,r;
    cin>>n>>l>>r;
    int x=0;{
      long long tmp=n;
      while(tmp>1){
        tmp>>=1;
        x++;
      }
    }
    long long ans=rangeSum(x,1,1,l,r);
    ans=((ans%mod)+mod)%mod;
    cout<<ans<<"\n";
  }
}

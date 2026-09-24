#include <bits/stdc++.h>

using namespace std;
long long n,k,d;
long long a[1000005];
bool ch(long long mid){
  long long ans=LLONG_MAX;
  long long m=max(1LL,k-mid+1);
  long long lf=min(k,n-mid+1);
  if(mid==0) return true;
  for (int l=m; l<=lf; l++){
    long long d1=(a[k]-a[l])+(a[l+mid-1]-a[k])+(a[k]-a[l]);
    long long d2=(a[k]-a[l])+(a[l+mid-1]-a[k])+(a[l+mid-1]-a[k]);
    ans=min(d1,d2);
    if(ans<=d) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("NhatBi1.Inp","r",stdin);
  freopen("NhatBi1.Out","w",stdout);
  cin>>n>>k>>d;
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  long long l=0,r=n;
  long long ans=0;
  while(l<=r){
    long long mid=(l+r)/2;
    if(ch(mid)){
      ans=mid;
      l=mid+1;
    }
    else r=mid-1;
  }
  cout<<ans<<"\n";
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,k;
  cin>>n>>k;
  vector<long long> a(n+2),b(n+2);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  for (int i=1; i<=n; i++){
    cin>>b[i];
  }
  vector<long long> f(n+1,0),g(n+1,0);
  f[1]=a[1];
  g[1]=a[1]*b[1];
  for (int i=2; i<=n; i++){
    f[i]=f[i-1]+a[i];
    g[i]=g[i-1]+a[i]*b[i];
  }
  long long s1=0,s2=0,s3=0;
  long long ans=-1e18;
  for (int i=1; i<=n-k+1; i++){
    s1=g[i-1];
    s2=f[i+k-1]-f[i-1];
    s3=g[n]-g[i+k-1];
    ans=max(ans,s1+s2+s3);
  }
  cout<<ans;
  return 0;
}

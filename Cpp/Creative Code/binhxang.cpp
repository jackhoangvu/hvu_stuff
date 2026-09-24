#include <bits/stdc++.h>

using namespace std;
int n,k;
int a[200005];
bool check(int x){
  int cnt=1,e=a[1];
  for (int i=2; i<=n; i++){
    if(a[i]-e>x){
      e=a[i-1]; cnt++;
      if(a[i]-e>x) return false;
    }
  }
  if(cnt<=k) return true;
  else return false;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  int l=0,r=1e9;
  int ans=0;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(check(mid)){ans=mid; r=mid-1;}
    else l=mid+1;
  }
  cout<<ans<<"\n";
  return 0;
}

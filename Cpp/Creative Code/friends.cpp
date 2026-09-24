#include<bits/stdc++.h>
using namespace std;
int n,k,h[200005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=0; i<n; i++) cin>>h[i];
  sort(h,h+n);
  long long ans=0;
  int j=0;
  for(int i=0; i<n; i++){
    while(h[i]-h[j]>k) j++;
    ans+=(i-j);
  }
  cout<<ans;
  return 0;
}

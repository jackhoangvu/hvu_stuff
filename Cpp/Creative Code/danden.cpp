#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  long long cnt=0;
  for(int i=0; i<n; ++i){
    cin>>a[i];
    if(a[i]==1) cnt++;
  }
  int mi=k+1;
  int cur=0;
  for(int i=0;i<k; i++){
    if(a[i]==1) cur++;
  }
  mi=cur;
  for(int i=1; i<=n-k; ++i){
    if(a[i-1]==1) cur--;
    if(a[i+k-1]==1) cur++;
    mi=min(mi,cur);
  }
  long long ans=cnt+k-2LL*mi;
  cout<<ans<<"\n";
  return 0;
}

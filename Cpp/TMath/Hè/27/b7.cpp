#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  long long t=0;
  for(int i=0; i<n; i++){
    cin>>a[i];
    t+=a[i];
  }
  if(t%3!=0){cout<<0<<"\n"; return 0;}
  long long ne=t/3;
  long long ans=0;
  long long cnt=0;
  long long sum=0;
  for(int i=0; i<n-1; i++){
    sum+=a[i];
    if(sum==2*ne){
      ans+=cnt;
    }
    if(sum==ne){
      cnt++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}

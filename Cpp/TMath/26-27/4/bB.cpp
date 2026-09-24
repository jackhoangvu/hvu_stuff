#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n>>q;
  vector<long long> a(n+2);
  long long v=0;
  for(int i=0; i<n; i++){
    long long x; cin>>x;
    a[i]=x-v;
    v=x;
  }
  while(q--){
    long long l,r,k; cin>>l>>r>>k;
    a[l-1]+=k;
    if(r<n) a[r]-=k;
  }
  long long cur=0;
  for(int i=0; i<n; i++){
    cur+=a[i];
    cout<<cur<<" ";
  }
  return 0;
}

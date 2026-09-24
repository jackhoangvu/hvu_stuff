#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>q;
  vector<int> a(n),b(m);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int i=0; i<m; i++){
    cin>>b[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  while(q--){
    int x; cin>>x;
    long long cntA=upper_bound(a.begin(),a.end(),x)-a.begin(),cntB=b.end()-lower_bound(b.begin(),b.end(),x);
    cout<<cntA*cntB<<'\n';
  }
  return 0;
}

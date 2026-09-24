#include <bits/stdc++.h>
using namespace std;
const int mxn=1000005;
int pref[mxn];
int d[mxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=1; i<=mxn; i++){
    for(int j=i; j<=mxn; j+=i){
      d[j]++;
    }
  }
  for(int i=1; i<=mxn; i++){
    pref[i]=pref[i-1]+(d[i]==4);
  }
  int t; cin>>t;
  while(t--){
    int l,r; cin>>l>>r;
    cout<<pref[r]-pref[l-1]<<"\n";
  }
  return 0;
}

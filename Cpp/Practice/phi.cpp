#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+2;
int phi[mxn+3];
void sang(){
  for (int i=1; i<=mxn; i++){
    phi[i]=i;
  }
  for (int i=2; i<=mxn; i++){
    if(phi[i]==i){
      for (int j=i; j<=mxn; j+=i){
        phi[j]-=(phi[j]/i);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  sang();
  while(t--){
    int n; cin>>n;
    cout<<phi[n]<<"\n";
  }
  return 0;
}

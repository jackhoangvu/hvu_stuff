#include <bits/stdc++.h>

using namespace std;
const int mxn=1e5;
int ans[mxn];
int spf[mxn];
void sang(){
  for (int i=2; i<=mxn; i++){
    spf[i]=i;
  }
  for (int i=2; i*i<=mxn; i++){
    if(spf[i]==i){
      for (int j=i*i; j<=mxn; j+=i){
        if(spf[j]==j){
          spf[j]=i;
        }
      }
    }
  }
  for (int i=2; i<=mxn; i++){
    ans[spf[i]]++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  sang();
  while(n--){
    long long x; cin>>x;
    if(x>1e5) cout<<0<<"\n";
    else cout<<ans[x]<<"\n";
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
int pos[mxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int c=1;
  for (int i=0; i<n; i++){
    int x; cin>>x;
    for (int j=0; j<x; j++){
      pos[c++]=i+1;
    }
  }
  int m; cin>>m;
  while(m--){
    int x; cin>>x;
    cout<<pos[x]<<"\n";
  }
  return 0;
}

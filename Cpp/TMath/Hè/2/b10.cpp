#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
long long d[mxn];
void sang(){
  for (int i=1; i<=mxn; i++){
    for (int j=i; j<mxn; j+=i){
      d[j]++;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q; cin>>q;
  sang();
  while(q--){
    long long n; cin>>n;
    cout<<d[n]<<"\n";
  }
  return 0;
}

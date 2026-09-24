#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
long long d[mxn];
void prs(){
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
  int n; cin>>n;
  prs();
  while(n--){
    long long x; cin>>x;
    cout<<d[x]<<"\n";
  }
  return 0;
}

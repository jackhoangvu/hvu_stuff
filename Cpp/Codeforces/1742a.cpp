#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int a,b,c; cin>>a>>b>>c;
    int sum=a+b+c;
    // if
    if(a==sum/2) cout<<a<<"\n";
    else if(b==sum/2) cout<<b<<"\n";
    else cout<<c<<"\n";
  }
  return 0;
}

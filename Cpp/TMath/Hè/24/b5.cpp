#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  cout<<n/2<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
// this problem is problem E which is like there is a number n, you have the max gcd of i,j that i<j<=n or something, for example if n=3 then there is (0,1),(0,2),(0,3),(1,2),(1,3),(2,3) and max is 1. the teacher said that just n/2 so yeah i didnt know about this, its really surprising, oh my gosh why all of these problems are just hard....

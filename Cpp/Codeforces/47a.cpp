#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,ok =false;cin>>n;
  if(n==1) {cout<<"YES"; return 0;}
  //b(n)=a(a-1)/2 check 2*b(n)= a(a-1)

  for(int i=2; i<=n; i++){
    if((i*(i-1) == 2*n)) {ok=true; break;}
  }
  if(ok==true) cout<<"YES";
  else cout<<"NO";
  return 0;
}

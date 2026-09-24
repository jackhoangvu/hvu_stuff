#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    if((a==1&&b!=2)||(b==1&&a!=2)) cout<<"NO"<<"\n";
    else if((a==0&&b!=0)||(a!=0&&b==0)) cout<<"NO"<<"\n";
    else if((a+b)%3==0){
      if(a<=2*b&&b<=2*a) cout<<"YES"<<"\n";
      else cout<<"NO"<<"\n";
    }
    else cout<<"NO"<<"\n";
  }
  return 0;
}

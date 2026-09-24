#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b;
  while(cin>>a>>b){
    if(b==0) cout<<-1<<"\n";
    else if(a%b==0) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
  }
  return 0;
}

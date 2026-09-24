#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin>>n;
  int cnt=0;
  string s=to_string(n);
  for(char c:s){
    if(c=='4'|| c=='7') cnt++;
  }
  if(cnt==4 or cnt==7) cout<<"YES";
  else cout<<"NO";
  return 0;
}

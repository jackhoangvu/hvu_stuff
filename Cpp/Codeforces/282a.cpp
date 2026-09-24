#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int c1=0,c2=0;
  for (int i=0; i<n; i++){
    string s; cin>>s;
    for(char c:s){
      if(c=='+') c1++;
      else if(c=='-') c2++;
    }
  }
  cout<<(c1-c2)/2<<"\n";
  return 0;
}

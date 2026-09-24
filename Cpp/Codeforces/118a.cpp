#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;

  for(char &c:s){
    c=tolower(c);
  }
  for(int i=0; i<s.length();){
    char c=s[i];
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'){
      s.erase(i,1);
    }
    else{
      i++;
    }
  }
  string n;
  for(char c:s){
    n+='.';
    n+=c;
  }
  cout<<n<<"\n";
  return 0;
}

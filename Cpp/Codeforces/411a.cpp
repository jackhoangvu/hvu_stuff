#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  bool ok1=false;
  bool ok2=false;
  bool ok3=false;
  bool lenok=false;

  if(s.length()>=5) {lenok=true;}
  for(char c:s){
    if(isdigit(c)){
      ok1=true;
    }
    else if(islower(c)){
      ok2=true;
    }
    else if(isupper(c)){
      ok3=true;
    }
  }
  if(ok1&&ok2&&ok3&&lenok) {cout<<"Correct"; return 0;}
  cout<<"Too weak";
}

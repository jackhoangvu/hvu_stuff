#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> t(n+2);
  vector<string> dir(n+2);
  for (int i=0; i<n; i++){
    cin>>t[i]>>dir[i];
  }
  int dis=0;
  for (int i=0; i<n; i++){
    if(dis==0){
      if(dir[i]=="South"){
        dis+=t[i];
        if(dis>20000){cout<<"NO"<<"\n"; return 0;}
      }
      else if(dir[i]=="North"||dir[i]=="East"||dir[i]=="West"){cout<<"NO"<<"\n"; return 0;}
    }
    else if(dis==20000){
      if(dir[i]=="North"){
        dis-=t[i];
        if(dis<0){cout<<"NO"<<"\n"; return 0;}
      }
      else if(dir[i]=="South"||dir[i]=="East"||dir[i]=="West"){cout<<"NO"<<"\n"; return 0;}
    }
    else if((dir[i]=="North"&&dis-t[i]<0)||(dir[i]=="South"&&dis+t[i]>20000)){
      cout<<"NO"<<"\n"; return 0;
    }
    else{
      if(dir[i]=="North") dis-=t[i];
      else if(dir[i]=="South") dis+=t[i];
    }
  }
  if(dis==0) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
  return 0;
}

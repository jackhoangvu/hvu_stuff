#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string hateit="I hate it", hatethat="I hate that",loveit="I love it",lovethat="I love that";
  if(n==1){cout<<hateit<<"\n"; return 0;}
  if(n==2){cout<<hatethat<<" "<<loveit<<"\n"; return 0;}
  if(n%2==0){
    for (int i=0; i<n/2-1; i++){
      cout<<hatethat<<" "<<lovethat<<" ";
    }
    cout<<hatethat<<" "<<loveit<<"\n";
  }
  else{
    for (int i=0; i<(n-1)/2; i++){
      cout<<hatethat<<" "<<lovethat<<" ";
    }
    cout<<hateit<<"\n";
  }
  return 0;
}

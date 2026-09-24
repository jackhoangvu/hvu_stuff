#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  cout<< (n*n+1)/2<<'\n';
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if((i+j)%2==0) cout<<"C";
      else cout<<".";
    }
    cout<<"\n";
  }
  return 0;
}

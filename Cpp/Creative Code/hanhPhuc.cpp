#include<bits/stdc++.h>
using namespace std;
int n,h[30005];
long long ans=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>h[i];
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      ans+=h[i]*h[j];
    }
  }
  cout<<ans;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int mx=0;
  int h=a[0];
  for(int i=1; i<n; i++){
    mx=max(mx,h-a[i]);
    h=max(h,a[i]);
  }
  if(mx>0){
    cout<<mx;
  }
  else{
    cout<<-1;
  }
  return 0;
}

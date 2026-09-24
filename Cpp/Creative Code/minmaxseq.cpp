#include<bits/stdc++.h>
using namespace std;
int n,a[100002];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  int minA=*min_element(a+1,a+1+n);
  int maxA=*max_element(a+1,a+1+n);
  int ans=n;
  int iMin=0;
  int iMax=0;
  for(int j=1; j<=n; j++){
    if(a[j]==minA){
      iMin=j;
      if(iMax>0){
        ans=min(ans,j-iMax+1);
      }
    }
    if(a[j]==maxA){
      iMax=j;
      if(iMin>0){
        ans=min(ans,j-iMin+1);
      }
    }
  }
  cout<<ans;
  return 0;
}

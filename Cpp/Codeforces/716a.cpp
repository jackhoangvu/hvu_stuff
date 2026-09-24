#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k, a[100005], cnt=1; cin>>n>>k;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<n-1; i++){
    if(a[i+1]-a[i]<=k){
      cnt++;
    }
    else{
      cnt=1;
    }
  }
  cout<<cnt;
  return 0;
}

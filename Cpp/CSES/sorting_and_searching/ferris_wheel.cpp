#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x, a[200005],ans=0;
  cin>>n>>x;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a,a+n);
  //two-pointer, choose lightest+heaviest
  // 2 3 7 9
  // x=10
  int l=0, r=n-1;
  while(l<=r){
    if(a[l]+a[r]>x) {r--; ans++;}
    else{
      ans++;
      l++;
      r--;
    }
  }
  cout<<ans;
  return 0;
}

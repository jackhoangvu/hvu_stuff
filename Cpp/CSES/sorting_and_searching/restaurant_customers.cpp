#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[200005], b[200005];
  for (int i=0; i<n; i++){
    cin>>a[i]>>b[i];
  }
  sort(a,a+n);
  sort(b,b+n);
  int i=0, j=0;
  int cur=0, mx=0;
  while(i<n){
    if(a[i]<b[j]){
      i++;
      cur++;
      mx=max(mx,cur);
    }
    else{
      cur--;
      j++;
    }
  }
  cout<<mx;
  // 5 8
  // 2 4
  // 3 9
  // 2 4
  // 3 8
  // 5 9
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[1005],cnt=0; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=1; i<n; i++){
    int e=*min_element(a,a+i);
    int f=*max_element(a,a+i);
    if(a[i]<e || a[i]>f) {cnt++;}
  }
  cout<<cnt;
  return 0;
}

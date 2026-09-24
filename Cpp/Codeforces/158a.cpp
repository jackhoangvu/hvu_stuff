#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k,a[55]; cin>>n>>k;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int tar=a[k-1];
  int cnt=0;
  for (int i=0; i<n; i++){
    if(a[i]>=tar&&a[i]>0) cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}

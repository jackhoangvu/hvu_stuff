#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[100005];
  cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int cur=1,mx=1;
  for (int i=0; i<n-1; i++){
    if(a[i]<=a[i+1]) {cur++; mx=max(mx,cur);}
    else{cur=1;}
  }
  cout<<mx<<"\n";
  return 0;
}

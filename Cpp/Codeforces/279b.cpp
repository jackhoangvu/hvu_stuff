#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,t; cin>>n>>t;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int l=0;
  int cur=0,mx=0;
  for(int r=0; r<n; r++){
    cur+=a[r];
    while(cur>t){
      cur-=a[l];
      l++;
    }
    mx=max(mx,r-l+1);
  }
  cout<<mx<<"\n";
  return 0;
}

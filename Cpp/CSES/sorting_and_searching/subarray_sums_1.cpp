#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long x;
  cin>>n>>x;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int l=0,cnt=0;
  long long cur=0;
  for (int r=0; r<n; r++){
    cur+=a[r];
    while(cur>x&&l<=r){
      cur-=a[l];
      l++;
    }
    if(cur==x) cnt++;
  }
  cout<<cnt;
  return 0;
}

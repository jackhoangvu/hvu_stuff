#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x, a[105]; cin>>n>>x;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int lo=0, hi=n-1;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(a[mid]==x) {cout<<mid; return 0;}
    else if(a[mid]<x) lo=mid+1;
    else hi=mid-1;
  }
  return 0;
}

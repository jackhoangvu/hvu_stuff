#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k,n,w;
  cin>>k>>n>>w;
  long long sum=w*(w+1)/2;
  sum*=k;
  cout<<max((long long)0,sum-n)<<"\n";
  return 0;
}

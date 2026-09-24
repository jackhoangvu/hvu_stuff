#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long n,k,m; cin>>n>>k>>m;
    if(n<k){cout<<0<<"\n"; continue;}
    long long q=(n-k)/m+1;
    long long l=2*k+m*(q-1);//f+l=k+k+m*(q-1)
    cout<<q*l/2<<"\n";
  }
  return 0;
}

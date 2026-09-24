#include <bits/stdc++.h>

using namespace std;
void rec(long long n,long long u,long long w,long long v){
  if(n==0) return;
  rec(n-1,u,v,w);
  cout<<"disk "<<n<<" from "<<u<<" to "<<v<<"\n";
  rec(n-1,w,u,v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  rec(n,1,2,3);
  return 0;
}

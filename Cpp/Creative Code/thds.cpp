#include <bits/stdc++.h>

using namespace std;
int n;
int m;
int a[1000005];
int b[1000005];
void rec(int c[],int sz,int pos,long long sum){
  if(pos==sz){
    cout<<sum<<"\n";
    return;
  }
  rec(c,sz,pos+1,sum+c[pos]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cin>>m;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<m; i++){
    cin>>b[i];
  }
  rec(a,n,0,0);
  rec(b,m,0,0);
  return 0;
}

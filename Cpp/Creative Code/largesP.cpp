#include<bits/stdc++.h>
using namespace std;
int n, k, a[100003], Pos[100003];
int main(){
  ios::sync_with_stdio(0);
  cin>>n>>k;
  for(int i = 1; i <= n; i++) cin>>a[i];
  for(int i = 1; i <= n; i++) Pos[a[i]] = i;
  int x = n;
  for(int i = 1; i <= n; i++){
    if(k == 0) break;
    if(a[i] == x) {x--; continue;}
    int ii = Pos[x];
    Pos[a[i]] = ii;
    swap(a[i], a[ii]);
    k--;
    x--;
  }
  for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
}

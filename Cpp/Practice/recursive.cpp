#include <bits/stdc++.h>

using namespace std;
int n,k;
vector<int> a;
vector<bool> used;
void rec(int pos){
  if(pos==k){
    for (int i=0; i<k; i++){
      cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;
  }
  for (int i=1; i<=n; i++){
    if(!used[i]){
      a[pos]=i;
      used[i]=true;
      rec(pos+1);
      used[i]=false;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>k>>n;
  a.resize(k);
  used.assign(k,false);
  rec(0);
  return 0;
}

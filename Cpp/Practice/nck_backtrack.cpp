#include <bits/stdc++.h>

using namespace std;
int n,k;
vector<int> a;
vector<int> c;
int cnt=0;
void rec(int pos,int idx){
  if(pos==k){
    cnt++;
    for (int i=0; i<k; i++){
      cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;
  }
  for (int j=idx; j<n; j++){
    a[pos]=c[j];
    rec(pos+1,j+1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>k>>n;
  a.resize(k);
  c.resize(n);
  for (int i=0; i<n; i++){
    cin>>c[i];
  }
  sort(c.begin(),c.end());
  rec(0,0);
  cout<<cnt;
  return 0;
}

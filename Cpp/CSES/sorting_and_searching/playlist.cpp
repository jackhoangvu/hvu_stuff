#include <bits/stdc++.h>

using namespace std;
const int MiN=-INT32_MAX;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[200005]; cin>>n;
  int l=0, cnt=0, mx=MiN;
  set<int> u;
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(u.find(a[i])==u.end()){
      u.insert(a[i]);
      cnt++;
      mx=max(cnt,mx);
    }
    else{
      while(u.find(a[i])!=u.end()){
        u.erase(a[l]);
        l++;
        cnt--;
      }
      u.insert(a[i]);
      cnt++;
      mx=max(cnt,mx);
    }
  }
  cout<<mx;
  return 0;
}

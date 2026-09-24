#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[200005]; cin>>n;
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  int b[200005], c[200005];
  map<int,int> d;
  d[a[1]]++;
  for (int i=2; i<=n; i++){
    auto it=d.upper_bound(a[i]);
    if(it==d.end()){
      it--;
      b[i]=a[i]-it->first;
      c[i]=it->second;
    }
    else{
      b[i]=it->first - a[i];
      c[i]=it->second;
      if(it!=d.begin()){
        it--;
        int e=a[i]-it->first;
        if(e<b[i]){
          b[i]=e;
          c[i]=it->second;
        }
        else if(e==b[i]) c[i]+=it->second;
      }
    }
    d[a[i]]++;
  }
  for (int i=2; i<=n; i++){
    cout<<b[i]<<" ";
  }
  cout<<"\n";
  for (int i=2; i<=n; i++){
    cout<<c[i]<<" ";
  }
  return 0;
}

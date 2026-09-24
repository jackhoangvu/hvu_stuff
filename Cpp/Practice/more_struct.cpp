#include <bits/stdc++.h>

using namespace std;
struct St{
  int a,b,idx;
};
bool cmp(St& x,St& y){
  return x.b<y.b;
}
bool res(St& x, St& y){
  return x.idx<y.idx;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<St> v;
  for (int i=0; i<n; i++){
    St x; cin>>x.a>>x.b;
    x.idx=i;
    v.push_back(x);
  }
  sort(v.begin(),v.end(),cmp);
  long long ans=0;
  int rem=m;
  for (int i=0; i<n; i++){
    if(rem<0) break;
    long long k=min(v[i].a,rem);
    ans+=(k*v[i].b);
    rem-=k;
    v[i].a=k;
  }
  cout<<ans<<"\n";
  sort(v.begin(),v.end(),res);
  for (int i=0; i<n; i++){
    cout<<v[i].a<<"\n";
  }
}

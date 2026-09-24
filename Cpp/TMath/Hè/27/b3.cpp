#include<bits/stdc++.h>
using namespace std;
struct HS{
  string name; int toan,tin;
};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<HS> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i].name>>a[i].toan>>a[i].tin;
  }
  sort(a.begin(),a.end(),[](const HS &x,const HS &y){
    if(x.toan!=y.toan) return x.toan>y.toan;
    if(x.name!=y.name) return x.name<y.name;
    return x.tin<y.tin;
  });
  for(auto s:a){
    cout<<s.name<<" "<<s.toan<<" "<<s.tin<<"\n";
  }
  return 0;
}

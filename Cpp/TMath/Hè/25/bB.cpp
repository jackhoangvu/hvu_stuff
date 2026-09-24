#include<bits/stdc++.h>
using namespace std;
struct HS{
  string name; int toan,tin;
};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<HS>a(n);
  for(int i=0; i<n; i++){
    cin>>a[i].name>>a[i].toan>>a[i].tin;
  }
  sort(a.begin(),a.end(),[](HS x,HS y){
    int sx=(x.toan>=8?1:0)+(x.tin>=8?1:0);
    int sy=(y.toan>=8?1:0)+(y.tin>=8?1:0);
    if(sx!=sy) return sx>sy;
    int tx=x.toan+x.tin;
    int ty=y.toan+y.tin;
    if(tx!=ty) return tx>ty;
    return x.name<y.name;
  });
  for(auto s:a){
    cout<<s.name<<" "<<s.toan<<" "<<s.tin<<"\n";
  }
  return 0;
}

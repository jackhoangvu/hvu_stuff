#include <bits/stdc++.h>
using namespace std;
int n,m,a[102], x[102],y[102],c[102];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
    c[i]=a[i];
  }
  cin>>m;
  for(int i=0; i<m; ++i){
    cin>>x[i]>>y[i];
    int w=x[i]-1;
    if(w==0) {
      if(n>=2) c[1]+=c[0]-y[i];
      c[0]=0;
    }
    else if(w==n-1) {
      c[w-1]+=(y[i]-1);
      c[w]=0;
    }
    else {
      c[w-1]+=(y[i]-1);
      c[w+1]+=c[w]-y[i];
      c[w]=0;
    }
  }
  for(int i=0; i<n; ++i){
    cout<<c[i]<<"\n";
  }

  //10,10,10,10,10
  //2 (wire) 5 (bird)->
  //4 go a[i-1] 5 go a[i+1]
  //0 12 0 12 10
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
pair<int,int> q[200005],eff[200005];
int top=0;
int b[200005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  int a[200005];
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<m; i++){
    cin>>q[i].first>>q[i].second;
  }
  for(int i=m-1; i>=0; i--){
    if(!top||q[i].second>eff[top-1].second){
      eff[top++]=q[i];
    }
  }
  int mx=eff[top-1].second;
  copy(a,a+mx,b);
  sort(b,b+mx);
  int l=0,r=mx-1;
  int idx=mx-1,cur=top-1;
  while(l<=r){
    while(cur>0&&idx<eff[cur-1].second){
      cur--;
    }
    if(eff[cur].first==1) a[idx]=b[r--];
    else a[idx]=b[l++];
    idx--;
  }
  for (int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

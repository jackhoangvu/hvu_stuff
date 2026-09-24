#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],b[1000005];
bool d=false;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(b,-1,sizeof(b));
  int min=1000005;
  cin>>n>>k;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int i=0; i<n; i++){
    if(b[a[i]]!=-1){
      int c=i-b[a[i]];
      if(c<k){
        d=true;
        if(a[i]<min){
          min=a[i];
        }
      }
    }
    b[a[i]]=i;
  }
  if(d) cout<<min;
  else cout<<-1;
  return 0;
}

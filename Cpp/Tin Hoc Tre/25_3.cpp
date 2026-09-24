#include <bits/stdc++.h>

using namespace std;
const int INF=1e9+1;
const int mxs=20;
int mi=INF;
map<vector<int>,int> vist;
void duyet(vector<int> arr,int step){
  if(step>=mxs) return;
  if(step>=mi) return;
  if (vist.count(arr) &&vist[arr]<=step) return;
  vist[arr]=step;
  bool ok=true;
  for (int i=0; i<arr.size(); i++){
    if(arr[i]!=0) {ok=false; break;}
  }
  if(ok){mi=min(mi,step); return;}
  int sz=arr.size();
  for(int i=0; i<=sz-4; i++){
    int a=arr[i];
    int b=arr[i+1];
    int c=arr[i+2];
    int d=arr[i+3];
    vector<int> nxt=arr;
    nxt[i]=abs(a-b);
    nxt[i+1]=abs(b-c);
    nxt[i+2]=abs(c-d);
    nxt[i+3]=abs(d-a);
    duyet(nxt,step+1);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<int> a;
  while(cin>>n){
    a.push_back(n);
  }
  duyet(a,0);
  cout<<mi<<"\n";
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
bool col[8],diag1[16],diag2[16];
int cnt=0;
vector<string> b(8);
void solve(int r){
  if(r==8){cnt++; return;}
  for(int c=0; c<8; c++){
    if(b[r][c]=='*'||col[c]||diag1[r-c+7]||diag2[r+c]) continue;
    col[c]=diag1[r-c+7]=diag2[r+c]=true;
    solve(r+1);
    col[c]=diag1[r-c+7]=diag2[r+c]=false;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<8; i++){
    cin>>b[i];
  }
  solve(0);
  cout<<cnt<<"\n";
  return 0;
}

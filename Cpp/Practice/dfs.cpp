#include <bits/stdc++.h>

using namespace std;
const int mxn=1e4+5;
int n,m;
vector<string> grid;
bool vis[mxn];
void dfs(int sr,int sc){
  stack<pair<int,int>> st;
  st.push({sr,sc});
  grid[sr][sc]='#';
  int dr[]={-1,1,0,0};
  int dc[]={0,0,-1,1};
  while(!st.empty()){
    auto [r,c]=st.top();
    st.pop();
    for(int i=0; i<4; i++){
      int nr=r+dr[i];
      int nc=c+dc[i];
      if(0<=nr&&nr<n&&0<=nc&&nc<m&&grid[nr][nc]=='.'){
        grid[nr][nc]='#';
        st.push({nr,nc});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  grid.resize(n);
  for (int i=0; i<n; i++){
    cin>>grid[i];
  }
  int ans=0;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if(grid[i][j]=='.'){
        ans++;
        dfs(i,j);
      }
    }
  }
  cout<<ans<<"\n";
  return 0;
}

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
# define MAX_N 250000
#define MAX_M 1000000000

int n, m;
int ranks[MAX_N*2];
int my_rank;
pair<int, int> cache[MAX_N];
bool cached[MAX_N];
int black[3*MAX_N+1], grey[3*MAX_N+1], white[3*MAX_N+1];

pair<int, int> simulate(int start)
{
  int targ= start>>1;
  if (cached[targ]) return cache[targ];
  if (my_rank== 1) cache[targ]= make_pair(1, 0);
  else if (my_rank<= n+1){
    memset(black, 0, sizeof(black));
    memset(grey, 0, sizeof(grey));
    memset(white, 0, sizeof(white));
    grey[start>>1]= 1;
    for (int i=1; i<n*2; i++){
      int target= (i-1+(i>start ? 1 : 0))>>1;
      if (ranks[i]<my_rank) black[target]++;
      else white[target]++;
    }
    int archer1, archer2;
    if (start<2){
      archer1= ranks[1];
      archer2= my_rank;
    }
    else {
      archer1= ranks[1];
      archer2= ranks[2];
    }
    int s_black= 0, s_grey= 0, s_white= 0;
    if (archer1<my_rank) s_black++;
    else if (archer1== my_rank) s_grey++;
    else s_white++;
    if (archer2<my_rank) s_black++;
    else if (archer2== my_rank) s_grey++;
    else s_white++;
    int cumulative_black= 0, cumulative_grey= 0, cumulative_white= 0;
    int seen= -1;
    int bumps= 0;
    for (int round=0; round<3*n; round++){
      if (round>= 2*n && (s_grey== 1)){
        seen= round;
        break;
      }
      int loser;
      if (s_black>0){
        if (s_black== 2) loser= 0;
        else if (s_grey== 1){
          loser= 1;
          bumps++;
        }
        else loser= 2;
      }
      else loser= 2;
      int new_p= round+n;
      if (new_p<= 3*n){
        if (loser== 0){
          black[new_p]++;
          s_black--;
        }
        else if (loser== 1){
          grey[new_p]++;
          s_grey--;
        }
        else {
          white[new_p]++;
          s_white--;
        }
      }
      cumulative_black+= black[round+1];
      cumulative_grey+= grey[round+1];
      cumulative_white+= white[round+1];
      if (cumulative_black>0){
        s_black++;
        cumulative_black--;
      }
      else if (cumulative_grey>0){
        s_grey++;
        cumulative_grey--;
      }
      else {
        s_white++;
        cumulative_white--;
      }
    }
    if (m>seen) bumps++;
    cache[targ]= make_pair(n-((m-seen+n-1)%n), bumps);
  }
  else {
    int white_local[n], grey_local[n];
    memset(white_local, 0, sizeof(white_local));
    memset(grey_local, 0, sizeof(grey_local));
    grey_local[start>>1]= 1;
    for (int i=1; i<2*n; i++)
      if (ranks[i]>my_rank)
        white_local[(i-1+(i>start ? 1 : 0))>>1]++;
    int shift_white= 0, shift_grey= 0;
    int bumps= 0;
    for (int it=0; it<3; it++){
      int pos= 0;
      do {
        int cur_white= white_local[pos]+shift_white;
        int cur_grey= grey_local[pos]+shift_grey;
        if (cur_white+cur_grey>1){
          if (pos>0){
            white_local[pos]= 1;
            shift_white= cur_white-1;
            grey_local[pos]= 0;
            if (cur_grey>0) shift_grey= cur_grey;
            else shift_grey= 0;
          }
          else {
            if (cur_grey>0){
              grey_local[pos]= 1;
              white_local[pos]= 0;
              shift_grey= cur_grey-1;
              shift_white= cur_white;
            }
            else {
              grey_local[pos]= 0;
              white_local[pos]= 1;
              shift_grey= 0;
              shift_white= cur_white-1;
            }
          }
        }
        else {
          if (pos>0){
            white_local[pos]= cur_white;
            grey_local[pos]= cur_grey;
            shift_white= 0;
            shift_grey= 0;
          }
          else {
            if (cur_grey>0) bumps++;
            white_local[pos]= 0;
            grey_local[pos]= 0;
            shift_white= cur_white;
            shift_grey= cur_grey;
          }
        }
        if (pos== 0) pos= n-1;
        else pos--;
      } while (pos>0);
    }
    int i;
    for (i=0; i<n; i++)
      if (grey_local[i]>0){
        cache[targ]= make_pair(i+1, bumps);
        break;
      }
    assert(i<n && grey_local[i]>0);
  }
  cached[targ]= 1;
  return cache[targ];
}

pair<int, int> search(int s, int e)
{
  pair<int, int> start, end, mid;
  int mi;
  start= simulate(s*2-1);
  end= simulate(e*2-1);
  while ((e-s)>1){
    mi= (s+e)>>1;
    mid= simulate(mi*2-1);
    if (start.first<mid.first){
      e= mi;
      end= mid;
    }
    else {
      s= mi;
      start= mid;
    }
  }
  if (start.first<end.first) return make_pair(start.first, s);
  else return make_pair(end.first, e);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(cached, 0, sizeof(cached));
  cin>>n>>m;
  assert(1<=n && n<=MAX_N);
  assert(2*n<=m && m<=MAX_M);
  m= 2*n+(m%n);
  for (int i=0; i<n*2; i++) cin>>ranks[i];
  my_rank= ranks[0];
  int best_start;
  pair<int, int> start, end, mid;
  int s= 1, e= n, mi;
  start= simulate(s*2-1);
  end= simulate(e*2-1);
  if (start.second>end.second){
    while ((e-s)>1){
      mi= (s+e)>>1;
      mid= simulate(mi*2-1);
      if (mid.second>end.second){
        s= mi;
        start= mid;
      }
      else {
        e= mi;
        end= mid;
      }
    }
    if (start.second>end.second) mi= e;
    else mi= s;
    pair<int, int> start_side= search(1, mi-1);
    pair<int, int> end_side= search(mi, n);
    if (start_side.first<end_side.first) best_start= start_side.second;
    else best_start= end_side.second;
  }
  else {
    pair<int, int> best= search(1, n);
    best_start= best.second;
  }
  cout<<best_start<<"\n";
  return 0;
}

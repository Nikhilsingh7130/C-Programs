#include <bits/stdc++.h>
using namespace std;
vector<int> mergeK(const vector<vector<int>>& lists){
  struct Node{ int val, i, j; };
  auto cmp = [](const Node&a,const Node&b){ return a.val > b.val; };
  priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
  for(int i=0;i<(int)lists.size();++i) if(!lists[i].empty()) pq.push({lists[i][0], i, 0});
  vector<int> out;
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    out.push_back(cur.val);
    if (cur.j + 1 < (int)lists[cur.i].size())
      pq.push({lists[cur.i][cur.j+1], cur.i, cur.j+1});
  }
  return out;
}
int main(){
  vector<vector<int>> lists = {{1,4,7},{2,5,8},{3,6,9}};
  auto out = mergeK(lists);
  for(int x: out) cout<<x<<' ';
  cout<<"\n";
  return 0;
}

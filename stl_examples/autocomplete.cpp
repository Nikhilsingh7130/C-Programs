#include <bits/stdc++.h>
using namespace std;
vector<string> prefix_search(const vector<string>& dict, const string& p){
  auto lo = lower_bound(dict.begin(), dict.end(), p);
  vector<string> res;
  for (auto it = lo; it != dict.end(); ++it){
    if (it->compare(0, p.size(), p) != 0) break;
    res.push_back(*it);
  }
  return res;
}
int main(){
  vector<string> dict = {"apple","apply","banana","band","bandana","cat"};
  sort(dict.begin(), dict.end());
  for (auto &s : prefix_search(dict, "ban")) cout<<s<<"\n";
  return 0;
}

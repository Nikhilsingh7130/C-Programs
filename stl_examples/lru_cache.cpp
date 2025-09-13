#include <bits/stdc++.h>
using namespace std;
class LRUCache {
  using ListIt = list<pair<int,int>>::iterator;
  int cap;
  list<pair<int,int>> dll;
  unordered_map<int,ListIt> mp;
public:
  LRUCache(int capacity): cap(capacity) {}
  int get(int key){
    auto it = mp.find(key);
    if (it==mp.end()) return -1;
    dll.splice(dll.begin(), dll, it->second);
    return it->second->second;
  }
  void put(int key, int value){
    if (auto it = mp.find(key); it != mp.end()) {
      it->second->second = value;
      dll.splice(dll.begin(), dll, it->second);
      return;
    }
    if ((int)dll.size() == cap) {
      auto last = dll.back(); mp.erase(last.first); dll.pop_back();
    }
    dll.emplace_front(key, value);
    mp[key] = dll.begin();
  }
};
int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1) << "\n"; // 1
    cache.put(3,3);
    cout<<cache.get(2) << "\n"; // -1
    return 0;
}

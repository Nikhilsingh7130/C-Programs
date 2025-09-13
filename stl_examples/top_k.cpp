#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    if(!(cin>>N>>K)) return 0;
    unordered_map<string,int> cnt; cnt.reserve(N*2);
    for(int i=0;i<N;++i){ string s; cin>>s; cnt[s]++; }
    vector<pair<string,int>> v; v.reserve(cnt.size());
    for(auto &p: cnt) v.emplace_back(p.first, p.second);
    auto cmp = [](const auto &a, const auto &b){
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    };
    if ((size_t)K < v.size()) {
        partial_sort(v.begin(), v.begin()+K, v.end(), cmp);
        v.resize(K);
    } else {
        sort(v.begin(), v.end(), cmp);
    }
    for(auto &p: v) cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}

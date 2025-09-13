C++ STL Examples
----------------
This archive contains example C++ files demonstrating STL patterns:

Files:
- sliding_window_median.cpp : Sliding Window Median (multiset approach) + demo
- top_k.cpp                : Top-K frequent words
- lru_cache.cpp            : LRU cache using list + unordered_map
- k_way_merge.cpp          : Merge K sorted lists using min-heap
- autocomplete.cpp         : Prefix search using sorted vector + lower_bound

Build:
  g++ -std=c++17 sliding_window_median.cpp -O2 -o sliding
  g++ -std=c++17 top_k.cpp -O2 -o top_k
  g++ -std=c++17 lru_cache.cpp -O2 -o lru_cache
  g++ -std=c++17 k_way_merge.cpp -O2 -o k_way_merge
  g++ -std=c++17 autocomplete.cpp -O2 -o autocomplete

Usage:
- Run compiled binaries. sliding_window_median prints a demo by default.
- For interactive testing of sliding_window_median, uncomment the interactive section in the file.

License: MIT

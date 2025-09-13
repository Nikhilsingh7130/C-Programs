#include <bits/stdc++.h>
using namespace std;

/*
 Sliding Window Median (using two multisets)
 - lo: max-side (multiset where we access rbegin() as median candidate)
 - hi: min-side (multiset where we access begin() as median candidate)
 We keep sizes balanced: |lo| >= |hi| and |lo|-|hi| <= 1
 Removal by value is O(log n) using multiset::erase(iterator) but to erase by value we use find() which removes one occurrence.
 Complexity: O(n log k) where k = window size
*/

class SlidingMedian {
    multiset<long long> lo; // max side (lower half)
    multiset<long long> hi; // min side (upper half)

    void balance() {
        // Ensure sizes: lo.size() == hi.size() or lo.size() == hi.size()+1
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }
        while (lo.size() < hi.size()) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }

public:
    void insert(long long x) {
        if (lo.empty() || x <= *prev(lo.end())) lo.insert(x);
        else hi.insert(x);
        balance();
    }

    void erase(long long x) {
        // Try to find in lo first
        auto it = lo.find(x);
        if (it != lo.end()) {
            lo.erase(it);
        } else {
            it = hi.find(x);
            if (it != hi.end()) hi.erase(it);
            else {
                // value not found (shouldn't happen with correct usage)
            }
        }
        balance();
    }

    double median() const {
        if (lo.empty() && hi.empty()) return 0;
        if (lo.size() > hi.size()) return double(*prev(lo.end()));
        // even
        long long a = *prev(lo.end());
        long long b = *hi.begin();
        return (double(a) + double(b)) / 2.0;
    }
};

// Simple test driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Sliding Window Median - Demo\n";
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    cout << "Input: ";
    for (int x : nums) cout << x << ' ';
    cout << "\nWindow size k = " << k << "\n";

    SlidingMedian win;
    vector<double> medians;
    for (int i = 0; i < (int)nums.size(); ++i) {
        win.insert(nums[i]);
        if (i >= k - 1) {
            medians.push_back(win.median());
            win.erase(nums[i - k + 1]);
        }
    }
    cout << "Medians: ";
    for (double m : medians) {
        // print with .5 for halves
        if (floor(m) == m) cout << (long long)m << ' ';
        else cout << m << ' ';
    }
    cout << "\n\n";

    // More interactive test: read n,k then array
    /*
    int n;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SlidingMedian sw;
    for (int i = 0; i < n; ++i) {
        sw.insert(a[i]);
        if (i >= k-1) {
            cout << sw.median() << ' ';
            sw.erase(a[i-k+1]);
        }
    }
    cout << '\n';
    */

    return 0;
}

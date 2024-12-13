#include <vector>
#include <algorithm>
using namespace std;

class RandomizedSet {
    vector<int> v;
    
    // Binary search helper function to check if a value exists
    bool search(int val) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid] == val) return true;
            else if (v[mid] > val) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (search(val)) return false; // Check if the value already exists
        v.push_back(val);             // Add the value
        sort(v.begin(), v.end());     // Sort the vector
        return true;
    }

    bool remove(int val) {
        if (!search(val)) return false; // Check if the value exists
        auto it = lower_bound(v.begin(), v.end(), val); // Find the element
        if (it != v.end() && *it == val) {
            v.erase(it);               // Erase the element
        }
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];   // Return a random element
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

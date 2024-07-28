#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(const vector<int>& nums) {
  // Store the elements within the vector into a unordered map
  unordered_map<int, bool> dataMap;
  // Create a new vector to store repeated entry keys
  vector<int> result_vec;
  // For repeated entries, check if the key is the same
  for (auto i : nums) {
    // res is type pair<unordered_map<int, bool>::iterator, bool>
    auto res = dataMap.insert({i, true});
    if (!res.second) {  // Failed to insert element
        result_vec.push_back(res.first->first);
    }
  }
  return result_vec;
}

void test() {
    auto printVector = [](const vector<int>& v) {
        cout << "(";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << ", ";
        }
        cout << ")";
    };

    {
        cout << "\n----- Test: No Duplicates -----\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> expected = {};
        vector<int> result = findDuplicates(nums);
        cout << "EXPECTED: No Duplicates\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Some Duplicates -----\n";
        vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5};
        vector<int> expected = {1, 2, 5};
        vector<int> result = findDuplicates(nums);
        sort(result.begin(), result.end());
        cout << "EXPECTED: Has Duplicates: ";
        printVector(expected);
        cout << "\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: All Duplicates -----\n";
        vector<int> nums = {1, 1, 2, 2, 3, 3};
        vector<int> expected = {1, 2, 3};
        vector<int> result = findDuplicates(nums);
        sort(result.begin(), result.end());
        cout << "EXPECTED: Has Duplicates: (1, 2, 3)\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Empty Vector -----\n";
        vector<int> nums = {};
        vector<int> expected = {};
        vector<int> result = findDuplicates(nums);
        cout << "EXPECTED: No Duplicates\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
    return 0; 
    
}
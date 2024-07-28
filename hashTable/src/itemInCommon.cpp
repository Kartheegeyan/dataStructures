#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool itemInCommon(vector<int> vec1, vector<int> vec2)
{
    // std::unordered_map<int, bool> * newMap = new std::unordered_map<int, bool>(vec1.size());
    unordered_map<int, bool> newMap;
    for (auto i : vec1)
    {
        newMap.insert({i, true});
    }
    for (auto j : vec2)
    {
        if (newMap.find(j) != newMap.end())
        {
            return true;
        }
    }
    return false;
    
}

void test() {
    {
        cout << "\n----- Test: Has Items In Common -----\n";
        vector<int> vect1 = {1, 2, 3, 4, 5};
        vector<int> vect2 = {5, 6, 7, 8, 9};
        cout << "EXPECTED: True\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: No Items In Common -----\n";
        vector<int> vect1 = {1, 2, 3, 4, 5};
        vector<int> vect2 = {6, 7, 8, 9, 10};
        cout << "EXPECTED: False\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (!itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Both Vectors Empty -----\n";
        vector<int> vect1 = {};
        vector<int> vect2 = {};
        cout << "EXPECTED: False\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (!itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: One Vector Empty -----\n";
        vector<int> vect1 = {1, 2, 3, 4, 5};
        vector<int> vect2 = {};
        cout << "EXPECTED: False\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (!itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }
    
}



int main()
{
    vector<int> vect1 = {1, 2, 3, 4, 5};
    vector<int> vect2 =  {6, 7, 8, 9, 10};

    bool result = itemInCommon(vect1, vect2);
    cout << "Result: " << (result == true ? "True" : "False") << endl;

    cout << "\n-------- Running Test --------\n" << endl;
    test();

    return 0;
}
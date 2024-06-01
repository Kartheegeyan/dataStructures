#include <vector>
#include <unordered_map>


bool itemsInCommon(std::vector<int> vec1, std::vector<int> vec2)
{
    // std::unordered_map<int, bool> * newMap = new std::unordered_map<int, bool>(vec1.size());
    std::unordered_map<int, bool> newMap;
    for (auto i : vec1)
    {
        newMap.insert({i, true});
    }
    for (auto j : vec2)
    {
        if (newMap[j])
        {
            return true;
        }
    }
    return false;
    
}



int main()
{
    return 0;
}
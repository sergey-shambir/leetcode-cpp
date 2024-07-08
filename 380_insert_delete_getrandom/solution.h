#pragma once

#include <random>
#include <unordered_map>
#include <vector>

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet
{
public:
    RandomizedSet()
        : generator(std::random_device()())
    {
    }

    bool insert(int val)
    {
        if (indexMap.contains(val))
        {
            return false;
        }
        values.push_back(val);
        indexMap[val] = values.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        const auto it = indexMap.find(val);
        if (it != indexMap.end())
        {
            const size_t foundIndex = it->second;
            const size_t lastIndex = values.size() - 1;

            std::swap(values[foundIndex], values[lastIndex]);
            indexMap[values[foundIndex]] = foundIndex;

            indexMap.erase(val);
            values.pop_back();

            return true;
        }
        return false;
    }

    int getRandom()
    {
        std::uniform_int_distribution<size_t> distribution(0, values.size() - 1);
        return values[distribution(generator)];
    }

private:
    std::unordered_map<int, size_t> indexMap;
    std::vector<int> values;
    std::mt19937 generator;
};

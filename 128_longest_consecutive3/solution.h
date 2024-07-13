#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Использует алгоритм Find-Union (т.е. Disjoin Set Union или "Система непересекающихся множеств")
 * Модификации:
 *   1) Сжатие пути
 *   2) Хранение веса
 * См. https://ru.algorithmica.org/cs/set-structures/dsu/ 
 */
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        for (int num : nums)
        {
            if (!parent.contains(num))
            {
                add(num, num);
                int prev = num - 1;
                if (parent.contains(prev))
                {
                    unite(prev, num);
                }
                int next = num + 1;
                if (parent.contains(next))
                {
                    unite(next, num);
                }
            }
        }
        
        int maxWeight = 0;
        for (const auto& kv : leaderWeight)
        {
            if (kv.second > maxWeight)
            {
                maxWeight = kv.second;
            }
        }
        return maxWeight;
    }

private:
    int leader(int num)
    {
        int numParent = parent[num];
        if (numParent == num)
        {
            return num;
        }
        int result = leader(numParent);
        parent[num] = result; // Сжатие пути
        return result;
    }
    
    void add(int num, int numParent)
    {
        parent[num] = numParent;
        leaderWeight[numParent] += 1;
    }
    
    void unite(int a, int b)
    {
        a = leader(a);
        b = leader(b);
        if (leaderWeight[a] > leaderWeight[b])
        {
            swap(a, b);
        }
        leaderWeight[b] += leaderWeight[a];
        parent[a] = b;
    }

    unordered_map<int,int> parent;
    unordered_map<int,int> leaderWeight;
};

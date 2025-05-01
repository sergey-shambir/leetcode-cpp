#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if (nums.size() <= 1)
            {
                return;
            }
    
            // Ищем индекс элемента, который меньше соседа справа
            size_t left = nums.size() - 2;
            while (left < nums.size() && nums[left] >= nums[left + 1])
            {
                --left;
            }
            // Если нет такого элемента, то возвращаем начальную перестановку.
            if (left > nums.size())
            {
                reverseSlice(nums, 0, nums.size() - 1);
                return;
            }
    
            // Ищем элемент справа, который больше чем nums[left]
            size_t right = nums.size() - 1;
            while (nums[left] >= nums[right])
            {
                --right;
            }
    
            // Меняем местами найденные элементы
            std::swap(nums[left], nums[right]);
    
            reverseSlice(nums, left + 1, nums.size() - 1);
        }
    
    private:
        // Переворачивает подсписок от first до last включительно
        void reverseSlice(vector<int>& nums, size_t first, size_t last)
        {
            while (first < last)
            {
                std::swap(nums[first], nums[last]);
                ++first;
                --last;
            }
        }
    };
    
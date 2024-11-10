#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <functional>
#include <deque>
#include <chrono>
#include <list>

namespace Solutions
{
    namespace Backtracking
    {
        // [1,2,3] -> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        //
        // [1, 2] -> 
        std::vector<int> _permute(  const std::vector<int> &nums,
                                    std::vector<std::vector<int>> &results,
                                    std::list<int> _data,
                                    size_t currentIdx, 
                                    bool bFirstStart = true)
        {
            size_t T = 0;
            while (T < _data.size()) {
                int currentElement = INT32_MAX;
                if (!bFirstStart) {
                    auto it = _data.begin();
                    std::advance(it, currentIdx);
                    currentElement = *it;
                    _data.erase(it);
                }

                std::vector<int> returnResult;
                if (_data.empty()) {
                    std::vector<int> result;
                    result.emplace_back(currentElement);
                    return result;
                }
                else {
                     returnResult = _permute(nums, results, _data, T, true);
                     returnResult.push_back(currentElement);
                }
            }
        }

        std::vector<std::vector<int>> permute(std::vector<int> &nums)
        {
            std::vector<std::vector<int>> results;
            std::list<int> _data(nums.begin(), nums.end());
            size_t T = 0;
            _permute(nums, results, _data, T);
            return results;
        }

        void test () {
            std::vector<int> nums = {1,2,3};
            auto result = permute(nums);
        }
    }
}

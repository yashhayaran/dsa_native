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
        // [1,2,3] => [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        // ([1, 2, 3], k = 0)  
        /*
        K = 0, 1, 2
        ([1, 2, 3], K = 0)      ([1, 2, 3], K = 1)      ([1, 2, 3], K = 2)
        ([2, 3], K = 0) -> 1, ([2, 3], K = 0) -> 1
        ([3], K = 0) -> 2, ([2], K = 1) -> 3
        ([], K = 0) -> 3, ([], K = 0) -> 2
        std::vector<std::vector<int>>::iterator 
        __permute(std::vector<std::vector<int>>& results, std::list<int> data, int K = -1) 
        {
            int currElement = INT32_MIN;
            
            if (K != -1) {
                std::list<int>::iterator itr = data.begin();
                if (K) {
                    std::advance(itr, K);
                }
                currElement = *itr;
                data.erase(itr);
            }
            
            if (data.empty()) {
                std::vector<int> result = {currElement};
                auto retItr = results.insert(results.end(), result);
                return retItr;
            }
            else {
                auto retItr = results.end();
                for (size_t T = 0; T < data.size(); T++) {
                     retItr = __permute(results, data, T);
                    if (currElement != INT32_MIN) {
                        retItr->push_back(currElement);
                    }
                }
                return retItr;
            }

            return results.end();
        }
        */

        /*
        void
        __permute_(std::vector<std::vector<int>>& results, std::vector<int> currentResult, std::list<int> data) 
        {
            auto retItr = results.end();
            int currElement = INT32_MIN;

            for (size_t T = 0; T < data.size(); T++) {
                // get the current value!
                std::list<int>::iterator itr = data.begin();
                if (T) {
                    std::advance(itr, T);
                }
                currElement = *itr;
                data.erase(itr);

                std::vector<int> newResult;
                if (!currentResult.empty()) {
                    newResult = currentResult;
                }
                newResult.push_back(currElement);
                results.push_back(newResult);

                if (!data.empty()) {
                    __permute(results, newResult, data);
                }
            }
        }
        */

        std::vector<std::vector<int>> 
        __permute(std::list<int> data, int K = -1) 
        {
            std::vector<std::vector<int>> results;
            int currElement = INT32_MIN;
            
            if (K != -1) {
                std::list<int>::iterator itr = data.begin();
                if (K) {
                    std::advance(itr, K);
                }
                currElement = *itr;
                data.erase(itr);
            }
            
            // submit
            // if (data.empty()) {
            //     std::vector<int> result = {*data.begin()};
            //     results.push_back(result);
            // }
            if (data.size() == 1) {
                std::vector<int> result = {*data.begin(), currElement};
                results.push_back(result);
            }
            else {
                for (size_t T = 0; T < data.size(); T++) {
                    auto vecRet = __permute(data, T);

                    for (auto& e: vecRet){
                        if (currElement != INT32_MIN) {
                            e.push_back(currElement);
                        }
                        results.push_back(e);
                    }
                }
            }

            return results;
        }

        std::vector<std::vector<int>> permute(std::vector<int>& nums) 
        {
            std::vector<std::vector<int>> results;
            std::vector<int> d;
            std::list<int> data(nums.begin(), nums.end());
            results = __permute(data);
            return results;
        }

        void test () {
            std::vector<int> nums = {1,2,3};
            //std::vector<int> nums = {5,4,6,2};
            auto result = permute(nums);
        }
    }
}

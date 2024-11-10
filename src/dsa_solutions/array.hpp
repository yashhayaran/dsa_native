#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <functional>
#include <deque>
#include <chrono>

namespace Solutions
{
    namespace Array
    {
        // https://leetcode.com/problems/two-sum/description/
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::vector<int> resultVec(2, 0);
            std::unordered_map<int, size_t> tempStore;
            size_t M = 0;
            int X = -1;

            for (M = 0; M < nums.size(); M++)
            {
                X = target - nums[M];
                auto itr = tempStore.find(X);
                
                if (itr == tempStore.end())
                {
                    tempStore.emplace(nums[M], M);
                }
                else
                {
                    resultVec[0] = M;
                    resultVec[1] = (*itr).second;
                    break;
                }
            }

            return resultVec;
        }

        // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
        int maxProfit(std::vector<int>& prices) 
        {
            int maxProfit = INT32_MIN;
            int minVal = INT32_MAX;
            int maxVal = INT32_MIN;

            for (int N = 0; N < prices.size(); N++)
            {
                if (minVal > prices[N])
                {
                    minVal = prices[N];
                    maxVal = INT32_MIN;
                }
                
                if (maxVal < prices[N])
                {
                    maxVal = prices[N];
                    maxProfit = maxVal - minVal > maxProfit ? maxVal - minVal : maxProfit;
                }
            }

            return maxProfit;
        }

        // https://leetcode.com/problems/container-with-most-water/
        int maxArea(std::vector<int>& height) 
        {   
            size_t X = 0; 
            size_t Y = height.size() - 1;
            unsigned maxArea = 0;
            int tempMin = 0;
            bool moveLeftOrRight = false; // false = left, true = right
             
            while (X < Y)
            {
                if (height[X] <= height[Y])
                {
                    moveLeftOrRight = false; 
                    tempMin = height[X];
                }
                else
                {
                    moveLeftOrRight = true; 
                    tempMin = height[Y];
                }

                maxArea = maxArea < (tempMin * (Y-X)) ? (tempMin * (Y-X)) : maxArea;

                if (moveLeftOrRight)
                {
                    Y--;
                }
                else 
                {
                    X++;
                }
            }

            return maxArea;
        }
    
        /*
        @link
            https://leetcode.com/problems/sliding-window-maximum/
        @test
            std::cout << "--------------------------------------------------------------------" << std::endl;
            typedef std::tuple<std::vector<int>, int, std::vector<int>> TUPLE;

            std::vector<TUPLE> data {
                TUPLE({-95,92,-85,59,-59,-14,88,-39,2,92,94,79,78,-58,37,48,63,-91,91,74,-28,39,90,-9,-72,-88,-72,93,38,14,-83,-2,21,4,-75,-65,3,63,100,59,-48,43,35,-49,48,-36,-64,-13,-7,-29,87,34,56,-39,-5,-27,-28,10,-57,100,-43,-98,19,-59,78,-28,-91,67,41,-64,76,5,-58,-89,83,26,-7,-82,-32,-76,86,52,-6,84,20,51,-86,26,46,35,-23,30,-51,54,19,30,27,80,45,22}, 10, {92,94,94,94,94,94,94,94,94,94,94,91,91,91,91,91,91,91,93,93,93,93,93,93,93,93,93,93,63,100,100,100,100,100,100,100,100,100,100,59,48,87,87,87,87,87,87,87,87,87,100,100,100,100,100,100,100,100,100,100,78,78,78,78,78,83,83,83,83,83,83,86,86,86,86,86,86,86,86,86,86,84,84,84,54,54,54,54,80,80,80}),
                TUPLE({9,10,9,-7,-4,-8,2,-6}, 5, {10,10,9,2}),
                TUPLE({-7,-8,7,5,7,1,6,0}, 4, {7,7,7,7,7}),
                TUPLE({1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7}),
                TUPLE({1}, 1, {1}),
                TUPLE({7,2,4}, 2, {7, 4}),
                TUPLE({1,-1}, 1, {1,-1}),
            };

            for (auto& e: data)
            {
                const auto result = Solutions::Array::maxSlidingWindow(std::get<0>(e), std::get<1>(e));
                std::cout << formatVector(std::get<0>(e)) << ": '" << std::get<1>(e) << "' Result: " << formatVector(result) << " == " << formatVector(std::get<2>(e)) << std::endl;
                assert(result == std::get<2>(e));
            }
            std::cout << "--------------------------------------------------------------------" << std::endl;
        */
        std::vector<int> _maxSlidingWindow(std::vector<int>& nums, int k)
        {
            std::deque<int> dq;
            std::vector<int> ans;
            for (int i=0; i<nums.size(); i++) 
            {
                if (!dq.empty() && dq.front() == i-k) 
                {
                    dq.pop_front();
                }
                while (!dq.empty() && nums[dq.back()] < nums[i])
                {    
                    dq.pop_back();
                }
                
                dq.push_back(i);
                
                if (i>=k-1) 
                {
                    ans.push_back(nums[dq.front()]);
                }
            }
            return ans;

            std::vector<int> result;
            bool skipErase = false;
            int M = 0; 
            int N = 0;
            std::map<int, size_t, std::greater<int>> sortedWindow;
        
            while (N < k)
            {
                if (sortedWindow.find(nums[N]) != sortedWindow.end())
                {
                    sortedWindow[nums[N]] = N;
                }
                else
                {   
                    sortedWindow.insert(std::make_pair(nums[N], N));
                }
                N++;
            }
            
            // push the calculated max of the first window in the result
            result.push_back((*sortedWindow.begin()).first);

            for (; N < nums.size(); M++, N++)
            {
                if (sortedWindow.find(nums[N]) != sortedWindow.end())
                {
                    sortedWindow[nums[N]] = N;
                    skipErase = true;
                }
                if (sortedWindow.find(nums[M]) != sortedWindow.end())
                {
                    skipErase = M != sortedWindow[nums[M]];
                }
                
                if (skipErase)
                {   
                    skipErase = false;
                }
                else
                {
                    sortedWindow.erase(nums[M]);
                }

                sortedWindow.insert(std::make_pair(nums[N], N));
                result.push_back((*sortedWindow.begin()).first);
            }
            
            return result;
        }

        /*
        @link
            https://leetcode.com/problems/sliding-window-maximum/
        @test
            std::cout << "--------------------------------------------------------------------" << std::endl;
            typedef std::tuple<std::vector<int>, int, std::vector<int>> TUPLE;

            std::vector<TUPLE> data {
                TUPLE({-95,92,-85,59,-59,-14,88,-39,2,92,94,79,78,-58,37,48,63,-91,91,74,-28,39,90,-9,-72,-88,-72,93,38,14,-83,-2,21,4,-75,-65,3,63,100,59,-48,43,35,-49,48,-36,-64,-13,-7,-29,87,34,56,-39,-5,-27,-28,10,-57,100,-43,-98,19,-59,78,-28,-91,67,41,-64,76,5,-58,-89,83,26,-7,-82,-32,-76,86,52,-6,84,20,51,-86,26,46,35,-23,30,-51,54,19,30,27,80,45,22}, 10, {92,94,94,94,94,94,94,94,94,94,94,91,91,91,91,91,91,91,93,93,93,93,93,93,93,93,93,93,63,100,100,100,100,100,100,100,100,100,100,59,48,87,87,87,87,87,87,87,87,87,100,100,100,100,100,100,100,100,100,100,78,78,78,78,78,83,83,83,83,83,83,86,86,86,86,86,86,86,86,86,86,84,84,84,54,54,54,54,80,80,80}),
                TUPLE({9,10,9,-7,-4,-8,2,-6}, 5, {10,10,9,2}),
                TUPLE({-7,-8,7,5,7,1,6,0}, 4, {7,7,7,7,7}),
                TUPLE({1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7}),
                TUPLE({1}, 1, {1}),
                TUPLE({7,2,4}, 2, {7, 4}),
                TUPLE({1,-1}, 1, {1,-1}),
            };

            for (auto& e: data)
            {
                const auto result = Solutions::Array::maxSlidingWindow(std::get<0>(e), std::get<1>(e));
                std::cout << formatVector(std::get<0>(e)) << ": '" << std::get<1>(e) << "' Result: " << formatVector(result) << " == " << formatVector(std::get<2>(e)) << std::endl;
                assert(result == std::get<2>(e));
            }
            std::cout << "--------------------------------------------------------------------" << std::endl;
        */
        inline void queue_insert(   std::deque<std::pair<int, size_t>>& _queue, 
                                    const int& element, 
                                    const size_t& pos)
        {
            bool stop = false;
            while(!stop)
            {
                if (_queue.empty())
                {
                    _queue.push_back(std::make_pair(element, pos));
                    stop = true;
                }
                else 
                {
                    if (_queue.back().first <= element)
                    {
                        _queue.pop_back();
                    }
                    else
                    {
                        _queue.push_back(std::make_pair(element, pos));
                        stop = true;
                    }
                }
            }
        }

        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
        {
            if (k == 1)
                return nums;
            
            std::vector<int> result;
            std::deque<std::pair<int, size_t>> _queue;
            size_t M = 0, N = 0;

            while(N < k)
            {
                queue_insert(_queue, nums[N], N);
                N++;
            }
            result.push_back(_queue.front().first);

            while(N < nums.size())
            {
                if (++M > _queue.front().second)
                {
                    _queue.pop_front();
                }

                queue_insert(_queue, nums[N], N);

                // first just copy the biggest element in the queue to result
                result.push_back(_queue.front().first);
                N++;               
            }

            return result;
        }
        
        std::vector<int> findMinJumps(const std::vector<int>& vecInput)
        {
            int nStartPos = 0;
            int nReacherPos = 0;
            int nCurrentJumps = vecInput[nStartPos];
            int nMaxJumpVal = -1;
            int nMaxJumpPos = 0;
            int nNumElRemaining = 0;
            std::vector<int> result;
            bool doCheck = false;

            // {2, 0, 3, 1, 3, 0, 3}
            // {0, 1, 2, 3, 4, 5, 6}

            while (nReacherPos < vecInput.size())
            {
                nNumElRemaining = vecInput.size() - nReacherPos - 1;

                if (nStartPos != nReacherPos)               
                {
                    nCurrentJumps--;
                    if (nCurrentJumps >= 0)
                    {
                        if (nNumElRemaining >= vecInput[nReacherPos])
                            // set the max jump value
                            if (vecInput[nReacherPos] > nMaxJumpVal)
                            {
                                nMaxJumpVal = vecInput[nReacherPos];
                                nMaxJumpPos = nReacherPos;
                            }
                        doCheck = false;
                    }
                    else
                    {
                        doCheck = true;
                    }

                    if (doCheck || nReacherPos == vecInput.size() - 1)
                    {                
                        result.push_back(nMaxJumpPos - nStartPos);
                        nStartPos = nMaxJumpPos;
                        nReacherPos = nMaxJumpPos;
                        
                        nCurrentJumps = vecInput[nStartPos];
                        
                        if (nCurrentJumps > vecInput.size() - nStartPos - 1)
                        {
                            nCurrentJumps = vecInput.size() - nStartPos - 1;
                        }

                        nMaxJumpVal = -1;
                        nMaxJumpPos = 0;

                        doCheck= false;
                    }
                }

                nReacherPos++;
            }

            return result;
        }
    }   
}
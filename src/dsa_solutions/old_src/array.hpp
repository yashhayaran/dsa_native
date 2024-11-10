#include <vector>
#include <set>
#include <memory>
#include <array>

using namespace std;

namespace Array
{
    //https://leetcode.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<int> result(2, 0);
        std::set<int> temp_set;
        int X = 0;

        for (int N = 0; N < nums.size(); N++)
        {
            X = target - nums[N];
            if (temp_set.find(X) == temp_set.end())
            {
                temp_set.insert(nums[N]);
            }
            else
            {
                result[1] = N;
                break;
            }
        }

        for (int N = 0; N < nums.size(); N++)
        {
            if(nums[N] == X)
            {
                result[0] = N;
                break;
            }
        }

        return result;
    }

    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(vector<int>& prices) 
    {
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        int max_profit = 0;
        int profit = 0;

        for (int M = 0; M < prices.size(); M++)
        {
            for (int N = M + 1; N < prices.size(); N++)
            {
                if (prices[N] > prices[M])
                {
                    profit =  prices[N] - prices[M];
                    if (profit > max_profit)
                    {
                        max_profit = profit;
                    }
                }
                else
                {
                    M = N;
                }

            }
        }

        return max_profit;
    }

    //https://leetcode.com/problems/contains-duplicate/
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> _uniqueSet;

        for (auto& e: nums)
        {
            if (_uniqueSet.find(e) == _uniqueSet.end())
            {
                _uniqueSet.insert(e);
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    //https://leetcode.com/problems/product-of-array-except-self/
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> outArray(nums.size());
        outArray[0] = 1;
        
        for (int T = 1; T < outArray.size(); T++)
        {
            outArray[T] = outArray[T-1] * nums[T-1];
        }

        ///////////////////////////////////////////////////////////////////////
        int last1 = nums[nums.size() - 1];
        int last2 = nums[nums.size() - 1];
        nums[nums.size() - 1] = 1;
        for (int T = nums.size() - 2; T >= 0; T--)
        {
            last1 = nums[T];
            nums[T] = nums[T+1] * last2;
            last2 = last1;
        }
        ///////////////////////////////////////////////////////////////////////

        for (int T = 0; T < nums.size(); T++)
        {
            outArray[T] = outArray[T] * nums[T];
        }

        return outArray;
    }

    //https://leetcode.com/problems/maximum-subarray/
    int maxSubArray(vector<int>& nums) 
    {
        int nMaxSum = INT_MIN;
        int nTempSum = 0;

        for (int N = 0; N < nums.size(); N++)
        {
            nTempSum += nums[N];
            
            if(nTempSum <= 0)
            {
                nTempSum = 0;
            }

            if(nMaxSum < nTempSum)
            {
                nMaxSum = nTempSum;
            }
        }

        return nMaxSum;
    }

    //https://leetcode.com/problems/maximum-product-subarray/
    int maxProduct(vector<int>& nums) 
    {
        int num1 = 1;
        int num2 = 1;
        int max_ = INT_MIN;

        for (int t = 0; t < nums.size(); t++)
        {
            num1 *= nums[t];

            if (num1 == 0 && nums[t] > 0)
            {
                num1 = nums[t];
            }
            
            if(num1 > max_)
            {
                max_ = num1;
            }
            
            if(nums[t] > num1)
            {
                max_ = nums[t];
            }
        }

        return max_;
    }

    //https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    int findMin(vector<int>& nums) 
    {
        int min = nums[0];
        if(nums.size() > 1)
        {
            int prevNum = nums[0];
            int currentNum = nums[1];
            
            for(int N = 1; N < nums.size(); N++)
            {
                currentNum = nums[N];

                if(prevNum > currentNum)
                {
                    min = currentNum;
                    break;
                }

                prevNum = nums[N];
            }
        }

        return min;
    }

    //https://leetcode.com/problems/search-in-rotated-sorted-array/
    
    //https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
    int minDeletions(string s) 
    {
        int numDeletions = 0;
        int* pFreq = new int[26];
        int maxFreq(0);

        for (auto& each : s)
        {
            auto p = &pFreq[each - 'a'];
            (*p)++;

            if(maxFreq < (*p))
            {
                maxFreq = (*p);
            }
        }

        int* pFreqCounts = new int[maxFreq];
        std::set<int> uniqFreq;

        for(int T = 0; T < 26; T++)
        {
            auto p = &pFreq[T];
            auto res = uniqFreq.find((*p));

            if (res == uniqFreq.end())
            {
                uniqFreq.insert(pFreq[T]);
            }
            else
            {
                numDeletions += pFreq[T];
            }

        }


        return numDeletions;
    }

    //https://leetcode.com/problems/3sum/

    //https://leetcode.com/problems/container-with-most-water/
    void getArea(vector<int>& height, int& M, int& N, int& maxArea)
    {
        int area = min(height[M], height[N]) * (N - M);
        if(maxArea < area)
        {
            maxArea = area;
        }

        int X = M + 1;
        int Y = N - 1;

        if (X <= Y)
        {
            if (height[M] > height[N])
            {
                getArea(height, X, N, maxArea);
            }
            else
            {
                getArea(height, M, Y, maxArea);
            }
        }
    }

    int maxArea(vector<int>& height) 
    {
        int M = 0;
        int N = height.size() - 1;
        int maxArea = INT16_MIN;

        if (height.size() > 2)
        {
            getArea(height, M, N, maxArea);
        }
        else
        {
            return min(height[M], height[N]);
        }

        return maxArea;
    }

}
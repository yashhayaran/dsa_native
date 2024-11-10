#include <iostream>
#include <vector>
#include <math.h>

namespace Solutions
{
    namespace Dynamic
    {
        /*
            @link
            https://leetcode.com/problems/climbing-stairs/

            @test
            std::cout << "--------------------------------------------------------------------" << std::endl;
            typedef std::tuple<int, int> TUPLE;

            std::vector<TUPLE> data {
                TUPLE(2, 2),
                TUPLE(3, 3),
            };

            for (auto& e: data)
            {
                const auto result = Solutions::Dynamic::climbStairs(std::get<0>(e));
                std::cout << std::get<0>(e) << ": Result: " << result << " == " << std::get<1>(e) << std::endl;
                assert(result == std::get<1>(e));
            }
            std::cout << "--------------------------------------------------------------------" << std::endl;
        */

        int climbStairs(const int& n)
        {
            int array[n+1];
            int result = 0;

            array[0] = 0;
            array[1] = 1;
            array[2] = 2;

            for (int T = 3; T <= n; T++)
            {
                array[T] = array[T-2] + array[T-1];
            }

            return array[n];
        }
        
        /*
        @link
        https://leetcode.com/problems/frog-jump-ii/description/

        @test
        std::cout << "--------------------------------------------------------------------" << std::endl;
        typedef std::tuple<std::vector<int>, int> TUPLE;

        std::vector<TUPLE> data {
            TUPLE({0,2,5,6,7}, 5),
        };

        for (auto& e: data)
        {
            const auto result = Solutions::Dynamic::maxJump(std::get<0>(e));
            std::cout << formatVector(std::get<0>(e)) << ": Result: " << result << " == " << std::get<1>(e) << std::endl;
            assert(result == std::get<1>(e));
        }
        std::cout << "--------------------------------------------------------------------" << std::endl;
        */
        int maxJump(std::vector<int>& stones)
        {
            int result = 0;
            int max = stones[1] - stones[0];

            for (int T = 2; T < stones.size(); T++)
            {
                max = max > (stones[T] - stones[T-2]) ? max : (stones[T] - stones[T-2]);
            }
            
            return max;
        }
        
        /*
        @link
        https://leetcode.com/problems/house-robber/description/

        @test
        std::cout << "--------------------------------------------------------------------" << std::endl;
        typedef std::tuple<std::vector<int>, int> TUPLE;

        std::vector<TUPLE> data {
            TUPLE({1,2,3,1}, 4),
            TUPLE({2,7,9,3,1}, 12)
        };

        for (auto& e: data)
        {
            const auto result = Solutions::Dynamic::rob(std::get<0>(e));
            std::cout << formatVector(std::get<0>(e)) << ": Result: " << result << " == " << std::get<1>(e) << std::endl;
            assert(result == std::get<1>(e));
        }
        std::cout << "--------------------------------------------------------------------" << std::endl;
        */
        int rob(const std::vector<int>& nums)
        {
            //nums: 2, 7, 3, 1, 4, 2, 1, 8
            // = 19
            //dp:   0, 2, 
            auto dp = std::vector<int>(nums.size()+1);

            dp[0] = 0;
            dp[1] = nums[0];
            
            for (int t = 2; t <= nums.size(); t++)
            {
                dp[t] = std::max(dp[t-2] + nums[t-1], nums[t-2]);
            }

            return std::max(dp[nums.size()], dp[nums.size()-1]);
        }
    }
}
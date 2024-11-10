#include <iostream>
#include <vector>

namespace Solutions
{
    namespace BitManipulation
    {
        // https://leetcode.com/problems/counting-bits/
        int getBitSetCount(int n)
        {
            int count = 0;
            while (n)
            {
                n = n & (n - 1);
                count++;
            }

            return count;
        }

        std::vector<int> countBits(int n)
        {
            if (n >= 8)
            {
                std::vector<int> result;

                // 0
                result.push_back(0);
                // 1
                result.push_back(1);
                // 2
                result.push_back(1);
                // 3
                result.push_back(2);
                // 4
                result.push_back(1);
                // 5
                result.push_back(2);
                // 6
                result.push_back(2);
                // 7
                result.push_back(3);

                int X = 1 << 3;
                std::vector<int> tempStore({2, 2, 3});

                for (int N = X; N <= n; N++)
                {
                    if (N == n)
                    {
                        result.push_back(getBitSetCount(N));
                        break;
                    }

                    if (N == X)
                    {
                        // great reset
                        result.push_back(1);

                        if ((N + tempStore.size()) > n)
                        {
                            int M = n - (N);
                            result.insert(result.end(), tempStore.begin(), tempStore.begin() + M);
                            break;
                        }
                        else
                        {
                            result.insert(result.end(), tempStore.begin(), tempStore.end());
                            N += tempStore.size();
                        }

                        X <<= 1;
                    }
                    else
                    {
                        int val = getBitSetCount(N);
                        result.push_back(val);
                        tempStore.push_back(val);
                    }
                }

                return result;
            }
            else
            {
                std::vector<int> result;

                for (int N = 0; N <= n; N++)
                {
                    result.push_back(getBitSetCount(N));
                }

                return result;
            }
        }

        // https://leetcode.com/problems/missing-number/
        int missingNumber(std::vector<int> &nums)
        {
            size_t T = nums.size();
            int X = nums[0];
            int Y = 1;

            for (size_t N = 1; N < T; N++)
            {
                X = X ^ nums[N];
            }

            for (size_t N = 2; N <= T; N++)
            {
                Y = Y ^ N;
            }

            return X ^ Y;
        }

        // https://leetcode.com/problems/reverse-bits/
        uint32_t reverseBits(uint32_t n)
        {
            return 0;
        }
    }
}
        // https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
        int lengthOfLongestSubstring(std::string s) 
        {
            if (s.empty())
            {
                return 0;
            }
            else if (s == " ")
            {    
                return 1;
            }
            else if (s.length() == 1)
            {    
                return 1;
            }

            /* Actual logic begins here
             */
            size_t maxCount = 0;

            size_t M = 0;
            size_t N = 0;

            std::unordered_map<char, size_t> uniqueCharsMap;
            //uniqueCharsMap.insert(std::make_pair(s[M], M));

            while (N < s.length())
            {
                // tried to find the element in map, finding Nth s's char, but found nothing!
                if (uniqueCharsMap.find(s[N]) == uniqueCharsMap.end())
                {
                    // first you insert the element at Nth location
                    uniqueCharsMap.insert(std::make_pair(s[N], N));
                    if (maxCount < ((N-M)))
                    {
                        maxCount = ((N-M));
                    }
                    N++;
                }
                // hey, you found the Nth-s char in the map
                else 
                {
                    // update the location of the already inserted key!
                    M = uniqueCharsMap[s[N]];
                    
                    /*
                    while (s[M] == s[N] && M < N)
                    {
                        M++;
                    }
                    
                    
                    if (M == N)
                    {
                        uniqueCharsMap.clear();
                        uniqueCharsMap.insert(std::make_pair(s[N], N));
                    }
                    else
                    {
                        uniqueCharsMap[s[N]] = N;
                    }
                    */
                    std::vector<char> toDelete;
                    for (auto& e: uniqueCharsMap)
                    {
                        if (e.second <= M)
                        {
                            toDelete.push_back(e.first);
                        }
                    }
                    for (auto& e: toDelete)
                    {
                        uniqueCharsMap.erase(e);
                    }

                    /*
                    if (maxCount < ((N-M)))
                    {
                        maxCount = ((N-M));
                    }
                    */
                    //N++;
                }
            }

            return maxCount;
        }




        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
        {
            std::vector<int> result;
            
            int M = 0; 
            int N = 0;
            int nMax = INT32_MIN;
            int nMaxIdx = 0;
            int nPrevSum = 0;
            int nCurrSum = 0;
            int nPopped = INT32_MIN;
            int nPushed = INT32_MIN;
            
            // first step is tp calculate the intial magic numbers like 
            // - total sum of the window
            // - max number in the window
            while (N < k)
            {
                if (nMax < nums[N])
                {    
                    nMax = nums[N];
                    nMaxIdx = N;
                }
                
                nCurrSum += nums[N];
                N++;
            }
            
            // push the calculated max of the first window in the result
            result.push_back(nMax);

            for (M++; N < nums.size(); M++, N++)
            {
                nPopped = nums[M-1];
                nPushed = nums[N];

                nPrevSum = nCurrSum;
                nCurrSum += (nPushed - nPopped);

                if (nCurrSum > nPrevSum)
                {
                    if (nCurrSum > nMax)
                    {
                        nMax = nPushed;
                    } 
                    else
                    {
                        if (nMaxIdx == M-1)
                        {
                            nMax = nPushed;
                            nMaxIdx = N;
                        }
                    }
                }

                result.push_back(nMax);
            }
            
            
            return nums;
        }
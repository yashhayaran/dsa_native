#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

namespace Solutions
{
    namespace String
    {
        /*
        @link 
            https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
        
        @test
            std::cout << "-----------------------------" << std::endl;
            std::vector<std::pair<std::string, size_t>> data {
                std::pair<std::string, size_t>("abcabcbb", 3),
                std::pair<std::string, size_t>("bbbbb", 1),
                std::pair<std::string, size_t>("pwwkew", 3),
                std::pair<std::string, size_t>("abba", 2),
                std::pair<std::string, size_t>("tmmzuxt", 5),
                std::pair<std::string, size_t>("wobgrovw", 6),
                std::pair<std::string, size_t>("ggububgvfk", 6),
                std::pair<std::string, size_t>("au", 2)
            };

            for (auto& e: data)
            {
                const auto r = Solutions::String::lengthOfLongestSubstring(e.first);
                std::cout << e.first << " - " << r << " == " << e.second << std::endl;
                assert(r == e.second);
            }
            std::cout << "-----------------------------" << std::endl;
        */
        int lengthOfLongestSubstring(std::string s)
        {
            if (s.empty())
                return 0;
            else if (s == " ")
                return 1;
            else if (s.length() == 1)
                return 1;

            /* Actual logic begins here */
            size_t maxCount = 0;

            size_t M = 0;
            size_t N = 1;

            std::unordered_map<char, size_t> uniqueCharsMap;
            uniqueCharsMap.insert(std::make_pair(s[M], M));

            while (N < s.length())
            {
                // tried to find the element in map, finding Nth s's char, but found nothing!
                if (uniqueCharsMap.find(s[N]) == uniqueCharsMap.end())
                {
                    // first you insert the element at Nth location
                    uniqueCharsMap.insert(std::make_pair(s[N], N));
                    if (maxCount < ((N - M) + 1))
                    {
                        maxCount = ((N - M) + 1);
                    }
                    N++;
                }
                // hey, you found the Nth-s char in the map
                else
                {
                    // update the location of the already inserted key!
                    M = uniqueCharsMap[s[N]];
                    std::vector<char> toDelete;
                    for (auto &e : uniqueCharsMap)
                    {
                        if (e.second <= M)
                        {
                            toDelete.push_back(e.first);
                        }
                    }
                    
                    for (auto &e : toDelete)
                    {
                        uniqueCharsMap.erase(e);
                    }
                    
                    M++;
                }
            }

            return maxCount;
        }
        
        /*
        @link 
            https://leetcode.com/problems/longest-repeating-character-replacement/
        
        @test
            std::cout << "-----------------------------" << std::endl;
            std::vector<std::tuple<std::string, int, int>> data {
                std::tuple<std::string, int, int>("ABBB", 2, 4),
                std::tuple<std::string, int, int>("AAAB", 0, 3),
                std::tuple<std::string, int, int>("ABAB", 2, 4),
                std::tuple<std::string, int, int>("AABABBA", 1, 4),
                std::tuple<std::string, int, int>("BAAAB", 2, 5)
            };

            for (auto& e: data)
            {
                const auto result = Solutions::String::characterReplacement(std::get<0>(e), std::get<1>(e));
                std::cout << std::get<0>(e) << ":" << std::get<1>(e) << " - " << result << " == " << std::get<2>(e) << std::endl;
                assert(result == std::get<2>(e));
            }
            std::cout << "-----------------------------" << std::endl;
        */
        int characterReplacement(std::string s, int k)
        {
            if (s.empty())
                return 0;
            else if (s == " ")
                return 1;
            else if (s.length() == 1)
                return 1;

            /* Actual logic begins here */
            int maxCount = 1;
            int nChances = k + 1;
            int M = 0;
            int N = 1;
            //int temp = -1;
            char mainChar = s[0];
            std::pair<int, int> firstDiffOccur;
            firstDiffOccur.first = -1;
            firstDiffOccur.second = -1;
            // std::vector<int> whereDiffCharFound;

            while (N < s.length())
            {
                if (s[N] != mainChar)
                {
                    if (--nChances)
                    {
                        if (nChances == k)
                        {
                            firstDiffOccur.first = N;
                            firstDiffOccur.second = N - M;
                        }
                    }
                    else
                    {
                        if (firstDiffOccur.first > 0)
                        {
                            M = firstDiffOccur.first;
                            firstDiffOccur.first = -1;
                            N = M;
                        }
                        else
                        {
                            M = N;
                        }

                        mainChar = s[M];
                        nChances = k + 1;
                    }
                }

                if (maxCount < ((N - M) + 1))
                {
                    maxCount = ((N - M) + 1);
                }
                N++;
            }

            // little backtrack to remaining
            if (maxCount < s.size() && firstDiffOccur.second > 0 && --nChances)
            {    
                if (nChances >= firstDiffOccur.second)
                {
                    maxCount += firstDiffOccur.second;
                }
                else
                {
                    maxCount += nChances;
                }
            }

            return maxCount;
        }

        /*
        @link 
            https://leetcode.com/problems/minimum-window-substring/description/
        @test
            std::cout << "-----------------------------" << std::endl;
            std::vector<std::tuple<std::string, std::string, std::string>> data {
                //std::tuple<std::string, std::string, std::string>("ADOBECODEBANC", "ABC", "BANC"),
                std::tuple<std::string, std::string, std::string>("a", "a", "a"),
                std::tuple<std::string, std::string, std::string>("a", "aa", "")
            };

            for (auto& e: data)
            {
                const auto result = Solutions::String::minWindow(std::get<0>(e), std::get<1>(e));
                std::cout << std::get<0>(e) << ":" << std::get<1>(e) << " - " << result << " == " << std::get<2>(e) << std::endl;
                assert(result == std::get<2>(e));
            }
            std::cout << "-----------------------------" << std::endl;
        */
        std::string minWindow(std::string s, std::string t)
        {
            std::string strResult = "";
            
            if (t.size() == s.size())
            {
                if (t == s)
                {
                    return t;
                }
            }
            else if (t.size() > s.size())
            {
                return "";
            }
            else if (t.size() == 1) 
            {
                if (s.find(t[0]) == std::string::npos) {
                    return "";
                }
                return t;
            }

            // Actual logic starts here!
            // "ADOBECODEBANC"  "ABC" > "BANC"
            size_t M(0), N(0), currResCount(0);

            N = t.size();

            // fill your buffers 
            std::list<char> spillFillContainer;
            std::list<char> spillFillContainerBackup;
            std::map<char, size_t> firstPosMap;
            while ((int)N--) {
                spillFillContainer.push_back(t[N]);
                spillFillContainerBackup.push_back(t[N]);
            }
            
            // set your sliding window to scan data 
            M = 0;
            N = 0;
            bool run = true;
            char nextFoundCharPos = 0;

            // first avoid duplicate first occurence of the t's char in s string 
            while (N < s.size()) {
                if (t.find(s[N]) != std::string::npos) {
                    if (firstPosMap.find(s[N]) == firstPosMap.end()) {
                        firstPosMap.insert(std::make_pair(s[N], N));
                        spillFillContainer.remove(s[N]);
                        if (firstPosMap.size() == 2) {
                            nextFoundCharPos = s[N];
                        }
                    }
                    else {
                        firstPosMap[s[N]] = N;
                        if (firstPosMap.size() == 1) {
                            M = N;
                        }
                    }
                }
                else if (firstPosMap.empty()) {
                    M = N + 1;
                }
                
                // now time reset the M, N 
                if (spillFillContainer.empty()) {
                     if (currResCount <= strResult.size()) {
                        strResult = std::string(s.begin() + M, s.begin() + N + 1);
                        currResCount = strResult.size();
                     }

                     M = firstPosMap[nextFoundCharPos];
                     N = M;

                     firstPosMap.clear();
                     spillFillContainer = spillFillContainerBackup;

                     firstPosMap.insert(std::make_pair(s[M], M));
                     spillFillContainer.remove(s[M]);

                     nextFoundCharPos = 0;
                }
                N++;
            }

            return strResult;
        }

        void test()
        {
            std::cout << "-----------------------------" << std::endl;
            std::vector<std::tuple<std::string, std::string, std::string>> data 
            {
                std::tuple<std::string, std::string, std::string>("bba", "ba", "ba"),
                std::tuple<std::string, std::string, std::string>("abc", "cba", "abc"),
                std::tuple<std::string, std::string, std::string>("abc", "bc", "bc"),
                std::tuple<std::string, std::string, std::string>("ADOBECODEBANC", "ABC", "BANC"),
                std::tuple<std::string, std::string, std::string>("a", "a", "a"),
                std::tuple<std::string, std::string, std::string>("a", "aa", "")
            };

            for (auto& e: data)
            {
                const auto result = Solutions::String::minWindow(std::get<0>(e), std::get<1>(e));
                std::cout << std::get<0>(e) << ":" << std::get<1>(e) << " - " << result << " == " << std::get<2>(e) << std::endl;
                assert(result == std::get<2>(e));
            }
            std::cout << "-----------------------------" << std::endl;
        }
    }
}
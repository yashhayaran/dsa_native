#include <iostream>
#include <vector>
/*
[Coding2]:
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

// Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

// Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

// Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4 
*/

// [1,3,5,6], 2, 0, 3, -1
// [1,3,5,6], 2, 1, 2, 1
int search_helper(const std::vector<int>& data, const int& itemToSearch, int minIndex, int maxIndex, int& possibleIndex)
{
    int currMidIndex = (minIndex + maxIndex) / 2;
    
    if (data[currMidIndex] == itemToSearch) // 3 < 7
    {
        return currMidIndex;
    }
    
    if (minIndex >= maxIndex)
    {
        if (data[minIndex] < itemToSearch && data[maxIndex] < itemToSearch)
            possibleIndex = maxIndex + 1;

        return -1;
    }

    if(data[currMidIndex] > itemToSearch)
    {
        possibleIndex = currMidIndex;           
        return search_helper(data, itemToSearch, minIndex, currMidIndex - 1, possibleIndex);
    }
    else
    {
        possibleIndex = currMidIndex;
        // [1,3,5,6], 7, 2, 3, -1
        return search_helper(data, itemToSearch, currMidIndex + 1, maxIndex, possibleIndex);
    }
}

int search(const std::vector<int>& data,  const int& itemToSearch)
{
    int possibleIndex = -1;

    // [1,3,5,6], 7, 0, 3, -1
    auto searchedIndex = search_helper(data, itemToSearch, 0, data.size() - 1, possibleIndex); 

    if (searchedIndex != -1)
    {
        return searchedIndex;
    }
    else 
    {
        return possibleIndex;
    }
}

void test0_()
{
    std::vector<int> data = {1, 3, 5, 6};

    std::cout << "Search: 2, Index: " << search(data, 2) << std::endl;
    std::cout << "Search: 5, Index: " << search(data, 5) << std::endl;
    std::cout << "Search: 7, Index: " << search(data, 7) << std::endl;
}

int main()
{
    return 0;
}


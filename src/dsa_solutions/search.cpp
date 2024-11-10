#include <iostream>
#include <vector>

namespace Solutions
{
    namespace Search
    {
        size_t binary_search_helper(const std::vector<int>& store, 
                                    const int& itemToSearch, 
                                    size_t& start, 
                                    size_t& end, 
                                    size_t& possibleMiddleIndex)
        {
            std::cout << "Start: " << start << ", End: " << end << ", PossibleMiddle: " <<  possibleMiddleIndex << std::endl;
            if (store[possibleMiddleIndex] == itemToSearch)
            {
                return possibleMiddleIndex;
            }

            if (itemToSearch < store[possibleMiddleIndex])
            {
                end = possibleMiddleIndex - 1;
            }
            else if (itemToSearch > store[possibleMiddleIndex])
            {
                start = possibleMiddleIndex;
            }
            
            if (end > start)
            {
                possibleMiddleIndex = start + (end - start) / 2;
                
                return binary_search_helper (
                            store,
                            itemToSearch,
                            start,
                            end,
                            possibleMiddleIndex
                        );
            }
            else 
            {
                return 999;
            }
        }

        size_t binary_search(std::vector<int>& store, const int& itemToSearch)
        {
            if (store.size())
            {
                size_t start = 0;
                size_t end = store.size() - 1;
                size_t possibleIdx = end / 2;
                
                return binary_search_helper (
                            store,
                            itemToSearch,
                            start,
                            end,
                            possibleIdx
                        );
            }

            return -1;
        }
    }
}
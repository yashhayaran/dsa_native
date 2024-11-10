#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

#ifndef _HEAP_HPP_
#define _HEAP_HPP_

namespace Solutions
{
    namespace Heap
    {
        template <typename Ttype>
        size_t adjustHeap(std::vector<Ttype> &data, const size_t &nSize, const size_t currPos, bool isMaxHeap)
        {
            size_t currLeft = (2 * currPos) + 1;
            size_t currRight = (2 * currPos) + 2;
            size_t pivotPos = -1;

            if (currRight < nSize)
            {
                if (isMaxHeap)
                {
                    if (data[currLeft] > data[currRight])
                    {
                        pivotPos = currLeft;
                    }
                    else
                    {
                        pivotPos = currRight;
                    }

                    if (data[pivotPos] > data[currPos])
                    {
                        Ttype temp = data[currPos];
                        data[currPos] = data[pivotPos];
                        data[pivotPos] = temp;

                        return pivotPos;
                    }
                }
                else
                {
                    if (data[currLeft] < data[currRight])
                    {
                        pivotPos = currLeft;
                    }
                    else
                    {
                        pivotPos = currRight;
                    }

                    if (data[pivotPos] < data[currPos])
                    {
                        Ttype temp = data[currPos];
                        data[currPos] = data[pivotPos];
                        data[pivotPos] = temp;

                        return pivotPos;
                    }
                }
            }
            else if (currLeft < nSize)
            {
                pivotPos = currLeft;
                if (isMaxHeap)
                {
                    if (data[pivotPos] > data[currPos])
                    {
                        Ttype temp = data[currPos];
                        data[currPos] = data[pivotPos];
                        data[pivotPos] = temp;

                        return pivotPos;
                    }
                }
                else
                {
                    if (data[pivotPos] < data[currPos])
                    {
                        Ttype temp = data[currPos];
                        data[currPos] = data[pivotPos];
                        data[pivotPos] = temp;

                        return pivotPos;
                    }
                }
            }

            return 0;
        }

        /*
        @brief
        Heapify: Turns any data of values into a max or min heap.
        Heap have following properties:
        - STRUCTURE: Complete binary tree
        - NOTE: - 2 * n - 1 (n = number of levels)
        */
        template <typename Ttype>
        void heapify(std::vector<Ttype> &data, const size_t &nSize, bool isMaxHeap)
        {
            size_t pivotLoc = 0;
            Ttype temp = 0;
            bool doAdjust = true;
            for (int M = nSize - 1; M >= 0; M--)
            {
                pivotLoc = M;
                doAdjust = true;
                while (doAdjust)
                {
                    pivotLoc = adjustHeap(data, nSize, pivotLoc, isMaxHeap);
                    doAdjust = (bool)pivotLoc;
                }
            }
        }

        template <typename Ttype>
        std::vector<Ttype> createHeap(const std::vector<Ttype> &data, bool isMaxHeap)
        {
            std::vector<Ttype> result;
            size_t currPos = 0;

            for (size_t M = 0; M < data.size(); M++)
            {
                result.push_back(data[M]);
                currPos = M;

                while (currPos)
                {
                    size_t rootPos = currPos / 2;
                    if (isMaxHeap)
                    {
                        if ((isMaxHeap && result[rootPos] < result[currPos]) || (!isMaxHeap && result[rootPos] > result[currPos]))
                        {
                            Ttype temp = result[currPos];
                            result[currPos] = result[rootPos];
                            result[rootPos] = temp;

                            currPos = rootPos;
                        }
                        else
                        {
                            currPos = 0;
                        }
                    }
                }
            }

            return result;
        }

        template <typename Ttype>
        std::vector<Ttype> heapSort(std::vector<Ttype> &actualData, const size_t &nSize, bool isMaxHeap)
        {
            std::vector<Ttype> data;

            // Lets's heapify the data
            // heapify(data, nSize, isMaxHeap);

            data = createHeap<Ttype>(actualData, isMaxHeap);

            std::cout << "Data: ";
            for (auto &e : data)
            {
                std::cout << e << ", ";
            }
            std::cout << std::endl;

            // Then delete each element one by one to get the sorting in order
            size_t pivotLoc = 0;
            Ttype temp = 0;
            bool doAdjust = true;

            for (size_t M = nSize - 1; M >= 1; M--)
            {
                pivotLoc = 0;
                doAdjust = true;
                temp = data[M];
                data[M] = data[pivotLoc];
                data[pivotLoc] = temp;
                while (doAdjust)
                {
                    pivotLoc = adjustHeap(data, M, pivotLoc, isMaxHeap);
                    doAdjust = (bool)pivotLoc;
                }
            }

            return data;
        }
    }

    // + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + * + *
    // create a class for heap access

    namespace HeapOOPS
    {
        template <typename Ttype, typename TCompare>
        class Heap
        {
        private:
            TCompare _compareFuncObj;
            std::vector<Ttype> _vecData;
            size_t _nMaxHeapSize;

            void swap(const size_t &pos1, const size_t &pos2)
            {
                Ttype temp = _vecData[pos1];
                _vecData[pos1] = _vecData[pos2];
                _vecData[pos2] = temp;
            }

            size_t tryPromotElement(const size_t rootPos)
            {
                auto &currPos = rootPos;
                auto &data = _vecData;
                const auto nSize = Size();

                size_t currLeft = (2 * currPos) + 1;
                size_t currRight = (2 * currPos) + 2;
                size_t pivotPos = -1;

                // do we have a right child?
                if (currRight < nSize)
                {
                    // compare left child vs. right child,
                    // to find the pivot guy
                    if (_compareFuncObj(data[currLeft], data[currRight]))
                    {
                        pivotPos = currLeft;
                    }
                    else
                    {
                        pivotPos = currRight;
                    }
                }
                // in case if root element dont have any right child
                else if (currLeft < nSize)
                {
                    pivotPos = currLeft;
                }

                // then compare pivot guy with main root guy
                // pivot is big (max heap) or small (min heap)
                // then swap the elements, and return pivot guy pos!
                // if (data[pivotPos] > data[currPos])
                if (pivotPos != -1)
                {
                    if (_compareFuncObj(data[pivotPos], data[currPos]))
                    {
                        swap(pivotPos, currPos);
                        return pivotPos;
                    }
                }

                return 0;
            }

            void remove_top()
            {
                auto &data = _vecData;
                const auto nSize = Size();
                size_t pivotLoc = 0;
                bool doAdjust = true;

                swap(0, nSize - 1);
                _vecData.pop_back();
                Heapify();
            }

        public:
            Heap()
            {
                _vecData = std::vector<Ttype>();
            }

            Heap(std::initializer_list<Ttype> data) : _vecData(data)
            {
                Heapify();
            }

            Heap(const std::vector<Ttype> &data, TCompare compareFunc) : _compareFuncObj(compareFunc)
            {
                _vecData = data;
                Heapify();
            }

            constexpr std::vector<Ttype> Data()
            {
                return _vecData;
            }

            constexpr size_t Size()
            {
                return _vecData.size();
            }

            /*
            @brief
            Heapify: Turns a list into heap
            */
            void Heapify()
            {
                auto &data = _vecData;
                const auto nSize = Size();
                size_t pivotLoc = 0;
                bool doAdjust = true;
                for (int M = nSize - 1; M >= 0; M--)
                {
                    pivotLoc = M;
                    bool bAdjust = true;
                    while (bAdjust)
                    {
                        pivotLoc = tryPromotElement(pivotLoc);
                        bAdjust = (bool)pivotLoc;
                    }
                }
            }

            void Push(const Ttype &data)
            {
                if (_vecData.size() < _nMaxHeapSize)
                {
                    _vecData.push_back(data);
                    Heapify();
                }
            }

            Ttype Pop()
            {
                Ttype pop_element = _vecData[0];
                remove_top();
                return pop_element;
            }

            void Show()
            {
                for (auto &e : _vecData)
                {
                    std::cout << e << ", ";
                }
                std::cout << std::endl;
            }

            std::vector<Ttype> HeapSort()
            {
                std::vector<Ttype> orignal_heap = _vecData;
                std::vector<Ttype> sorted;

                while (Size())
                {
                    Ttype top_element = _vecData[0];
                    sorted.push_back(top_element);
                    swap(0, Size() - 1);
                    _vecData.pop_back();
                    Heapify();
                }

                _vecData = orignal_heap;
                return sorted;
            }
        };

        void tester()
        {
            std::greater<int> comp;

            Heap<int, std::greater<int>> heapo1 = {1, 2, 3, 4, 5, 6};
            Heap<int, std::greater<int>> heapo2 = {6, 5, 4, 3, 2, 1};

            std::vector<int> datax1 = {1, 2, 3, 4, 5, 6};
            Heap<int, std::greater<int>> heapx1;
            for (auto &e : datax1)
            {
                heapx1.Push(e);
            }
            heapx1.Show();

            std::vector<int> datax2 = {6, 5, 4, 3, 2, 1};
            Heap<int, std::greater<int>> heapx2;
            for (auto &e : datax2)
            {
                heapx2.Push(e);
            }

            heapx2.Show();

            auto max_element = heapx1.Pop();

            heapx1.Push(7);
            auto sorted = std::move(heapx1.HeapSort());
        }

        // @link https://leetcode.com/problems/top-k-frequent-elements/
        std::vector<int> topKFrequent(std::vector<int> &nums, int k)
        {
            std::map<int, size_t> _map;
            typedef std::pair<size_t, int> _pairType;
            struct typerComp
            {
                bool operator()(const _pairType& left, const _pairType& right)
                {
                    return left.first < right.first;
                }
            };

            size_t size = nums.size();
            bool run = true;
            while (run)
            {
                run = static_cast<bool>(--size);
                auto found = _map.find(nums[size]);
                if (found == _map.end())
                {
                    _map.emplace(nums[size], 1);
                }
                else
                {
                    found->second++;
                }
            }


            std::priority_queue<_pairType, std::vector<_pairType>, typerComp> _heap;
            size = nums.size();
            run = true;
            for (auto& [key, value] : _map)
            {
                _heap.push(std::make_pair(value, (int)key));
            }

            run = true;
            std::vector<int> results;
            while (run)
            {
                run = static_cast<bool>(--k) && !_heap.empty();
                auto data = _heap.top();
                results.push_back(data.second);
                _heap.pop();
            }

            return results;
        }

        void test()
        {
            std::vector<int> data = {1, 1, 1, 2, 2, 3};
            int k = 2;
            auto result = topKFrequent(data, k);
        }

    } // namespace name

}

#endif
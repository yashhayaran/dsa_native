#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "heap.hpp"

namespace Solutions
{
    namespace LinkedList
    {
        struct ListNode
        {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}

            void construct(int elementToInsert, ListNode *node = nullptr)
            {
                ListNode *pCurrentHead = node;
                if (pCurrentHead == nullptr)
                {
                    pCurrentHead = this;
                }

                if (pCurrentHead->next == nullptr)
                {
                    if (pCurrentHead->val == 0)
                    {
                        pCurrentHead->val = elementToInsert;
                    }
                    else
                    {
                        pCurrentHead->next = new ListNode();
                        construct(elementToInsert, pCurrentHead->next);
                    }
                }
                else
                {
                    construct(elementToInsert, pCurrentHead->next);
                }
            }

            void print()
            {
                ListNode *pCurrentHead = this;

                while (pCurrentHead != nullptr)
                {
                    std::cout << pCurrentHead->val << ", ";
                    pCurrentHead = pCurrentHead->next;
                }
            }
        };

        /* @link https://leetcode.com/problems/merge-k-sorted-lists/
         */
        ListNode *mergeKLists(std::vector<ListNode *> &lists)
        {
            // 1. create a min heap
            // 2. there are K sorted list
            // 3. put all first K list first element in the min heap
            // 4. loop over
            //     1. take root eleement
            //     2. put in new list
            //     3. put the removed list's root element in the min heap again
            //     4. repeat again till min heap is empty

            class ListNodeCompare
            {
                public: 
                bool operator() (const ListNode* left, const ListNode* right)
                {
                    return left->val < right->val;
                }
            };
            
            ListNode* mergedListHead = new ListNode();
            bool run = true;

            // just intialize some values:
            size_t count = lists.size();
            Solutions::HeapOOPS::Heap<ListNode*, ListNodeCompare> _heap;
            while(count--) {
                _heap.Push(lists[count]);
            }

            while(_heap.Size())
            {
                auto poppedItem = _heap.Pop();
                mergedListHead->construct(poppedItem->val);

                if (poppedItem->next) {
                    _heap.Push(poppedItem->next);
                }
            }
            
            return mergedListHead;
        }

        void test_solution()
        {
            /*
                Input: lists = [[1,4,5],[1,3,4],[2,6]]
                Output: [1,1,2,3,4,4,5,6]
            */

            std::vector<ListNode *> vecOfListNodeHeads;

            vecOfListNodeHeads.push_back(new ListNode);
            vecOfListNodeHeads.back()->construct(1);
            vecOfListNodeHeads.back()->construct(4);
            vecOfListNodeHeads.back()->construct(5);
            vecOfListNodeHeads.back()->print();

            vecOfListNodeHeads.push_back(new ListNode);
            vecOfListNodeHeads.back()->construct(1);
            vecOfListNodeHeads.back()->construct(3);
            vecOfListNodeHeads.back()->construct(4);
            vecOfListNodeHeads.back()->print();

            vecOfListNodeHeads.push_back(new ListNode);
            vecOfListNodeHeads.back()->construct(2);
            vecOfListNodeHeads.back()->construct(6);
            vecOfListNodeHeads.back()->print();

            std::cout << "-----------------------------" << std::endl;
            std::cout << "[1,1,2,3,4,4,5,6]" << std::endl;
            mergeKLists(vecOfListNodeHeads)->print();
            std::cout << "-----------------------------" << std::endl;
        }
    }
}
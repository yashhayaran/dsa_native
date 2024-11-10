#include <vector>
#include <set>
#include <memory>
#include <array>
#include <iostream>

namespace LinkedList
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
        void Print()
        {
            ListNode* currNode = this;
            std::cout << "[";
            while(currNode != nullptr)
            {
                std::cout << currNode->val << ", ";
                currNode = currNode->next;
            }
            std::cout << "]" << std::endl;
        }
    };

    ListNode* reverseList_itr(ListNode* head) 
    {
        ListNode* newListHead = nullptr;
        if (head != nullptr)
        {
            if (head->next != nullptr)
            {
                ListNode* prevNode = nullptr;
                ListNode* currHead = head;

                while(currHead != nullptr)
                {
                    ListNode* nextNode = currHead->next;
                    currHead->next = prevNode;
                    prevNode = currHead;
                    currHead = nextNode;
                }

                return prevNode;
            }
        }

        return head;
    }

    ListNode* reverseList_rec_helper(ListNode* currNode, ListNode* preNode)
    {
        if (currNode != nullptr)
        {
            ListNode* newCurrNode = currNode->next;
            currNode->next = preNode;
            if (newCurrNode != nullptr)
            {
                return reverseList_rec_helper(newCurrNode, currNode);
            }
        }
        return currNode;
    }

    ListNode* reverseList_rec(ListNode* head) 
    {
        return reverseList_rec_helper(head, nullptr);
    }

    ListNode* reverseList(ListNode* head) 
    {
        return reverseList_rec(head);
    }

    bool hasCycle(ListNode *head) {
        if (head)
        {
            if (head->next)
            {
                auto* pSlowPointer = head;
                auto* pFastPointer = head->next;
                while (pSlowPointer != nullptr)
                {
                    if (pSlowPointer == pFastPointer)
                    {
                        return true;
                    }
                    
                    pSlowPointer = pSlowPointer->next;
                    if (pFastPointer->next)
                    {
                        if (pFastPointer->next->next)
                        {
                            pFastPointer = pFastPointer->next->next;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else 
                    {
                        break;
                    }
                }
            }
        }

        return false;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* result_node = nullptr;
        ListNode* curr_node = nullptr;
        ListNode* input_node_1 = list1;
        ListNode* input_node_2 = list2;

        return nullptr;
        bool run = true;
        while (run)
        {
            if (input_node_1 && input_node_2)
            {

            }
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {   
        if (head)
        {
            size_t size = 0;
            // Count the number of nodes:
            for (auto* pNode = head; pNode != nullptr; pNode = pNode->next, ++size) {}

            if (size > 1 && n < size)
            {
                size -= n; 
                ListNode* pNode = head->next;       
                ListNode* pNodePrev = head;         
                
                while (--size && pNode)                      
                {
                    pNodePrev = pNode;              
                    pNode = pNode->next;                               
                }
                
                pNodePrev->next = pNode->next;
                delete pNode;
                
            }
            else if (n == size)
            {
                ListNode* pNode = head->next;
                delete head;
                head = pNode;
            }
            else if (n == 1)
            {
                delete head;
                head = nullptr;
            }
        }

        return head;
    }

    void reorderList_rec(ListNode* currNode, ListNode* resListLastNode)
    {
        if (currNode && currNode->next && currNode->next->next)
        {
            ListNode *prevLastCurrNode = currNode->next;
            ListNode *lastCurrNode = currNode->next->next;
            bool trap(false), set(false);
            while(lastCurrNode->next) 
            {   
                prevLastCurrNode = lastCurrNode;
                lastCurrNode = lastCurrNode->next;
                trap = true;
            }
            
            ListNode* newCurrNextNode = currNode->next;

            if (!resListLastNode)
            {
                resListLastNode = currNode;
                resListLastNode->next = lastCurrNode;
                set = true;
            }
            else 
            {
                resListLastNode->next = currNode;
                resListLastNode->next->next = lastCurrNode;
            }

            prevLastCurrNode->next = nullptr;

            if (trap)
            {    
                reorderList_rec(newCurrNextNode, lastCurrNode);
            }
            else
            {
                if (set)
                    resListLastNode->next->next = prevLastCurrNode;
                else
                    resListLastNode->next->next->next = prevLastCurrNode;
                    
            }
        }
        else if (currNode && currNode->next)
        {
            resListLastNode->next = currNode;
        }
    }

    // [1, 2, 3, 4, 5]
    // [1, 5, 2, 4, 3]
    void reorderList(ListNode* head) 
    {
        if (head && head->next && head->next->next)
        {
            ListNode* newListHead = nullptr;
            reorderList_rec(head, newListHead);
            head = newListHead;
        }
    }
}
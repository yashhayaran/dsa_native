#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <__algorithm/max.h>

#define null 0

namespace Solutions
{
    namespace Tree
    {
        namespace BinaryTree
        {
            class TreeNode
            {
                public:
                    int val;
                    TreeNode* left;
                    TreeNode* right;
                    TreeNode() : val(0), left(nullptr), right(nullptr) {}
                    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
                    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
            };

            /*
            @brief 
            Constructs a binary tree node of type TreeNode, takes vector as input. 
            Assumes vector in level order format. 
            */
            TreeNode* construct(std::vector<int>& data, size_t idx = 0)
            {
                TreeNode* root = nullptr;
                if (data[idx] != 0)
                {    
                    TreeNode* root = new TreeNode(data[idx]);
                    root->left = construct(data, 2 * idx + 1);
                    root->right = construct(data, 2 * idx + 2);
                }

                return root;
            }

            // https://leetcode.com/problems/maximum-depth-of-binary-tree/
            int maxDepth(TreeNode* root) 
            {
                //if(root == nullptr) return 0;
                //return std::max(maxDepth(root->left), maxDepth(root->right))+1;
                return 1;
            }
        }
    }
}
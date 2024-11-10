#include <iostream>
#include <list>

namespace Tree
{
    struct TreeNode 
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode* buildTree(std::list<std::string> data)
    {
        TreeNode* root = nullptr;
        if(data.size())
        {
            auto strRootVal = data.front();
            data.pop_front();
            if (!strRootVal.empty() && strRootVal != "null")
            {
                root = new TreeNode(std::atoi(strRootVal.c_str()));
                
                TreeNode* prevRoot = root;
                TreeNode* currNode = root->left;

                for (auto &&strVal : data)
                {
                    if (strVal != "null")
                    {
                        currNode = new TreeNode(std::atoi(strVal.c_str()));
                    }
                    else
                    {
                        
                    }
                }
            }
        }

        return root;
    }

    

    int maxDepth(TreeNode* root) 
    {
        TreeNode* pNode = root;
        
        std::list<TreeNode*> nodes;
        int count = 0;
        nodes.push_front(root);

        while (nodes.size())
        {
            count++;
            auto* node = nodes.front();
            nodes.pop_front();
            if(node)
            {
                nodes.push_back(node->left);
                nodes.push_back(node->right);
            }
        }
    }
}
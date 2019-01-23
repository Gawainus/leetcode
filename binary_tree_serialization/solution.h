#define once

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <assert.h>

//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root)
            return "";

        std::stack<TreeNode*> node_stack;
        std::stringstream ss;

        node_stack.push(root);

        while (!node_stack.empty()) {
            TreeNode * node = node_stack.top();
            node_stack.pop();

            if (!node) {
                ss << "~,";
                continue;
            }

            ss << node->val << ',';

            if (node->right) {
                node_stack.push(node->right);
            }
            else {
                node_stack.push(nullptr);
            }

            if (node->left) {
                ss << node->left->val << ',';
                node_stack.push(node->left->right);
                node_stack.push(node->left->left);
            }
            else {
                ss << "~,";
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.empty())
            return nullptr;

        // assert(data[0] != '~'); // the root should be a number

        TreeNode * curr {nullptr};

        std::stack<TreeNode*> node_stack;

        auto it = data.crbegin();
        while (it != data.crend()) {
            it++;

            if (*it == '~') {
                node_stack.push(nullptr);
                it++; // skip the comma
            }
            else {
                int num = 0;
                int power = 1;
                while(it != data.crend() && *it != ',') {

                    if (*it == '-') {
                        num *= -1;
                        it++;
                        continue;
                    }

                    num += (*it - '0') * power;
                    power *= 10;
                    it++;
                }


                curr = new TreeNode(num);

                curr->left = node_stack.top();
                node_stack.pop();

                curr->right = node_stack.top();
                node_stack.pop();

                node_stack.push(curr);
            }
        }

        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

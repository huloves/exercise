#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return create_max_tree(nums, 0, nums.size() - 1);   // 3, 2, 1, 6, 0, 5
    }
    TreeNode* create_max_tree(vector<int> &nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int max_num = nums[left];
        unsigned int max_index = left;
        for(int i = left; i <= right; i++) {
            if(nums[i] > max_num) {
                max_num = nums[i];
                max_index = i;
            }
        }
        TreeNode *root = new TreeNode(max_num);
        root->left = create_max_tree(nums, left, max_index - 1);
        root->right = create_max_tree(nums, max_index + 1, right);
        return root;
    }
};

int main()
{
	vector<int> nums = {3,2,1,6,0,5};
	Solution sol;
	TreeNode *root = sol.constructMaximumBinaryTree(nums);
	return 0;
}
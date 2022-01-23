#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* create_tree_pre(struct TreeNode **root);
void in_order(struct TreeNode *root);
void inorder(struct TreeNode* root, int* res, int* resSize);
void in_traversal(struct TreeNode* root, int *answer, int *returnSize);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
 
int input[100];
int index = 0;
int n = 0;

int main(int argc, char **argv)
{
	// struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	struct TreeNode *root;
	root = create_tree_pre(&root);
	in_order(root);
	printf("\n");
	int returnSize;
	int *answer = inorderTraversal(root, &returnSize);
	for(int i = 0; i < returnSize; i++) {
		printf("%d", answer[i]);
	}
	printf("\n");
	return 0;
}

struct TreeNode* create_tree_pre(struct TreeNode **root) {
	if(input[index] == 0) {
		return NULL;
	}
	*root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	(*root)->val = input[index++];
	(*root)->left = create_tree_pre(&((*root)->left));
	if((*root)->left == NULL) { index++; }
	(*root)->right = create_tree_pre(&((*root)->right));
	if((*root)->right == NULL) { index++; }
	return *root;
}

void in_order(struct TreeNode *root) {
	if(root != NULL) {
		// printf("%d", root->val);
		in_order(root->left);
		printf("%d", root->val);
		in_order(root->right);
	}
}

void inorder(struct TreeNode* root, int* res, int* resSize) {
    if (!root) {
        return;
    }
    inorder(root->left, res, resSize);
    res[(*resSize)++] = root->val;
    inorder(root->right, res, resSize);
}

int* inorderTraversal_(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * 501);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}

void in_traversal(struct TreeNode* root, int *answer, int *returnSize) {
    if(root == NULL) {
        return;
    }
    in_traversal(root->left, answer, returnSize);
    answer[(*returnSize)++] = root->val;
    in_traversal(root->right, answer, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *answer = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    in_traversal(root, answer, returnSize);
    return answer;
}

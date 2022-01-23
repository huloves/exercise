#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* create_tree_pre(struct TreeNode **root);
struct TreeNode* invertTree(struct TreeNode* root);
void in_order(struct TreeNode *root);

int input[100];
int index = 0;
int n = 0;

int main(int argc, char **argv)
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	struct TreeNode *root;
	root = create_tree_pre(&root);
	root = invertTree(root);
	in_order(root);
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

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL) {
        return NULL;
    }
    struct TreeNode *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void in_order(struct TreeNode *root) {
	if(root != NULL) {
		// printf("%d", root->val);
		in_order(root->left);
		printf("%d", root->val);
		in_order(root->right);
	}
}

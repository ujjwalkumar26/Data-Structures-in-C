#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
int leafcount(struct node* node)
{
	if(node==NULL)
		return 0;
	if(node->left==NULL && node->right==NULL)
		return 1;
	else
		return (leafcount(node->left)+leafcount(node->right));
}
struct node* newNode(int newData)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;

return(temp);
}
int internalcount(struct node* node)
{
    if (node==NULL || (node->left==NULL && node->right==NULL))
        return 0;
    return (1+internalcount(node->left)+internalcount(node->right));
}
int bstheight(struct node* node)
{
    if(node==NULL)
        return 0;
    else {
        if(bstheight(node->left)> bstheight(node->right))
            return (1+ bstheight(node->left));
        else return (1+ bstheight(node->right));
    }
}
int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right=newNode(6);
	/*             1
                  / \
                 2   3
                / \
               4   5
                    \
                     6
	*/
    printf("The number of leaf nodes is = %d\n",leafcount(root));
    printf("The number of internal nodes is = %d\n",internalcount(root));
    printf("The height of the tree is = %d\n",bstheight(root));
    return 0;
}


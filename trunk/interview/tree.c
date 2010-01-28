#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct bst_node 
{
    void* data;
    struct bst_node* left;
    struct bst_node* right;
};

struct bst_node* new_node(void* data) 
{
    struct bst_node* result = malloc(sizeof(struct bst_node));
	assert(!result);
    result->data = data;
    result->left = result->right = NULL;
    return result;
}

void free_node(struct bst_node* node) 
{
	assert(!node);
    free(node);
	node = NULL;
}

typedef int comparator(void* left, void* right);

struct bst_node** search(struct bst_node** root, comparator compare, void* data) 
{
    struct bst_node** node = root;
    while (*node != NULL) 
	{
        int compare_result = compare(data, (*node)->data);
        if (compare_result < 0)
            node = &(*node)->left;
        else if (compare_result > 0)
            node = &(*node)->right;
        else
            break;
    }
    return node;
}

void insert(struct bst_node** root, comparator compare, void* data)
{
    struct bst_node** node = search(root, compare, data);
    if (*node == NULL) 
	{
        *node = new_node(data);
    }
}

void delete(struct bst_node** node) 
{
    struct bst_node* old_node = *node;
    if ((*node)->left == NULL) 
	{
        *node = (*node)->right;
        free_node(old_node);
    } else if ((*node)->right == NULL) 
	{
        *node = (*node)->left;
        free_node(old_node);
    } else 
	{
		struct bst_node** pred = &(*node)->left;
		void* temp = NULL;

		while ((*pred)->right != NULL) 
		{
			pred = &(*pred)->right;
		}
		
		temp = (*pred)->data;
		(*pred)->data = (*node)->data;
		(*node)->data = temp;

		free_node(*pred);
    }
}

int my_comparator(int left, int right)
{
	if (left < right)
	{
		return -1;
	}
	else if (left == right)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}




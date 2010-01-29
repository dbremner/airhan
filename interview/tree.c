#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>

#include "queue.h"

struct bst_node 
{
    int data;
    struct bst_node* left;
    struct bst_node* right;
};

struct bst_node* new_node(int data) 
{
    struct bst_node* result = malloc(sizeof(struct bst_node));
	assert(result);

    result->data = data;
    result->left = result->right = NULL;
    return result;
}

void free_node(struct bst_node* node) 
{
	assert(node);
    free(node);
	node = NULL;
}

typedef int comparator(int left, int right);

struct bst_node** search(struct bst_node** root, comparator compare, int data) 
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

void insert(struct bst_node** root, comparator compare, int data)
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
		int temp;

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

void visit(struct bst_node* node)
{
    printf("%d\n", node->data);
}

void visit_level(struct bst_node* node, int level)
{
    int i = 0;
    for (; i < level; i ++) printf("  ");

    visit(node);
}

void preorder_traverse(struct bst_node* root)
{
    if (!root) return;
    
    visit(root);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void inorder_traverse(struct bst_node* root)
{
    if (!root) return;
    
    inorder_traverse(root->left);
    visit(root);
    inorder_traverse(root->right);
}

void postorder_traverse(struct bst_node* root)
{
    if (!root) return;

    postorder_traverse(root->left);
    postorder_traverse(root->right);
    visit(root);
}

void delete_tree(struct bst_node* root)
{
    if (!root) return;

    delete_tree(root->left);
    delete_tree(root->right);

    free_node(root);
}

void pretty_print_layered(struct bst_node* root)
{
    Queue* queue = queue_new();
    struct bst_node* node = NULL;
    assert(root);
    
    queue_push_head(queue, root);
    while (!queue_is_empty(queue))
    {
        node = (struct bst_node*)queue_pop_tail(queue);
        visit(node);

        if (node->left) queue_push_head(queue, node->left);
        if (node->right) queue_push_head(queue, node->right);
    }

    queue_free(queue);
}

void c_tree_suite()
{
    int a = 25;
    struct bst_node* root = new_node(a);
    int i = 0;

    for (i = 15; i < 30; i ++)
    {
        insert(&root, my_comparator, i);
    }

    preorder_traverse(root);

    printf("tree pretty print in layers: \n\n\n\n\n");

    pretty_print_layered(root);

    delete_tree(root);
}


int main()
{
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );

    c_tree_suite();

     _CrtDumpMemoryLeaks(); 
    return 0;
}

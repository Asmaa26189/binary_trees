#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * struct binary_tree_struct - binary_tree_struct
 * @n: n
 * @parent: parent
 * @right: right
 * @left: left
 */
struct binary_tree_struct
{
	int n;
	struct binary_tree_struct *parent;
	struct binary_tree_struct *right;
    struct binary_tree_struct *left;
};

typedef struct binary_tree_struct binary_tree_s;
typedef struct binary_tree_struct b_s;
typedef struct binary_tree_struct a_s;
typedef struct binary_tree_struct h_s;

/**
 * struct link_struct - link_struct
 * @n: n
 * @node: node
 * @next: next
 */
typedef struct link_struct
{
	size_t n;
	struct binary_tree_struct const *node;
	struct link_struct *next;
} link_t;

void binary_tree_print(const binary_tree_s *);
binary_tree_s *binary_tree_node(binary_tree_s *parent, int value);
binary_tree_s *binary_tree_insert_left(binary_tree_s *parent, int value);
binary_tree_s *binary_tree_insert_right(binary_tree_s *parent, int value);
void binary_tree_delete(binary_tree_s *tree);
int binary_tree_is_leaf(const binary_tree_s *node);
int binary_tree_is_root(const binary_tree_s *node);
void binary_tree_preorder(const binary_tree_s *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_s *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_s *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_s *tree);
size_t binary_tree_depth(const binary_tree_s *tree);
size_t binary_tree_size(const binary_tree_s *tree);
size_t binary_tree_leaves(const binary_tree_s *tree);
size_t binary_tree_nodes(const binary_tree_s *tree);
int binary_tree_balance(const binary_tree_s *tree);
int binary_tree_is_full(const binary_tree_s *tree);
int binary_tree_is_perfect(const binary_tree_s *tree);
binary_tree_s *binary_tree_sibling(binary_tree_s *node);
binary_tree_s *binary_tree_uncle(binary_tree_s *node);
binary_tree_s *binary_trees_ancestor(const binary_tree_s *first,
const binary_tree_s *second);
void binary_tree_levelorder(const binary_tree_s *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_s *tree);
binary_tree_s *binary_tree_rotate_left(binary_tree_s *tree);
binary_tree_s *binary_tree_rotate_right(binary_tree_s *tree);
int binary_tree_is_bst(const binary_tree_s *tree);
b_s *bst_insert(b_s **tree, int value);
b_s *array_to_bst(int *array, size_t size);
b_s *bst_search(const b_s *tree, int value);
b_s *bst_remove(b_s *root, int value);
int binary_tree_is_avl(const binary_tree_s *tree);
a_s *avl_insert(a_s **tree, int value);
a_s *array_to_avl(int *array, size_t size);
a_s *avl_remove(a_s *root, int value);
a_s *sorted_array_to_avl(int *array, size_t size);
int binary_tree_is_heap(const binary_tree_s *tree);
h_s *heap_insert(h_s **root, int value);
h_s *array_to_heap(int *array, size_t size);
int heap_extract(h_s **root);
int *heap_to_sorted_array(h_s *heap, size_t *size);

#endif

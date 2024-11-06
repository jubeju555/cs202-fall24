#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "bstree.hpp"
// #include "../include/bstree.hpp"
using namespace std;
using CS140::BSTNode;
using CS140::BSTree;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

int BSTree::Depth(const string &key) const
{
  (void)key;
  if (key.empty()) return -1;

  int depth = 0;
  const BSTNode *n = sentinel->right;  
  const BSTNode *parent = sentinel;
  const BSTNode *child = sentinel;
  

  while (n != sentinel)
  {
    if (key == n->key)
    {
      return depth;
    }
    else if (key < n->key)
    {
      n = n->left;
    }
    else
    {
      n = n->right;
    }
    depth++;
  }
  return -1;

  // if ((dist = Depth(sentinel, x)) >= 0)
  // {
  //   return dist + 1;
  // }
  // else if ((dist = Depth(sentinel, x)) >= 0)
  // {
  //   return dist + 1;
  // }
  // else
  // {
  //   return ;
  // }
}

int BSTree::Height() const
{
  // do i start from 0 or the root or are they the same thing?
  // if (sentinel->right == NULL)
  // {
  //   return 0;
  // }
  // if (sentinel->right->left == NULL && sentinel->right->right == NULL)
  // {
  //   return 1;
  // }
  while (sentinel->right != sentinel)
  {
    return recursive_find_height(sentinel->right, 0);
  }
  
  return 0;
  }

vector<string> BSTree::Ordered_Keys() const
{
  vector<string> rv;
  make_key_vector(sentinel->right, rv);
  return rv;
}

BSTree::BSTree(const BSTree &t)
{
  (void)t;
  sentinel = new BSTNode();
  sentinel->parent = NULL;
  sentinel->left = NULL;
  sentinel->right = sentinel;
  sentinel->key = "";
  sentinel->val = NULL;

  size = 0;
}

BSTree &BSTree::operator=(const BSTree &t)
{
  (void)t;
  if (this != &t)
  {
    Clear();
  }

  return *this;
}

int BSTree::recursive_find_height(const BSTNode *n, int x) const
{
  (void)n;

  int left = recursive_find_height(n->left, x);
  int right = recursive_find_height(n->right, x);

  return 1 + max(left, right);
}

void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  (void)n;
  (void)v;
  if (n != sentinel)
  {
    make_key_vector(n->left, v);
    v.push_back(n->key);
    make_key_vector(n->right, v);
  }
}

BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys,
                                    const vector<void *> &vals,
                                    size_t first_index,
                                    size_t num_indices) const
{
  (void)sorted_keys;
  (void)vals;
  (void)first_index;
  (void)num_indices;
  return NULL;

  if (num_indices == 0)
  {
    return NULL;
  }
  size_t mid = first_index + num_indices / 2;

  BSTNode *node = new BSTNode();
  node->key = sorted_keys[mid];
  node->val = vals[mid];

  node->left = make_balanced_tree(sorted_keys, vals, first_index, mid);
  node->right = make_balanced_tree(sorted_keys, vals, mid + 1, num_indices - mid - 1);
}

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include "bstree.hpp"
// #include "../include/bstree.hpp"
using namespace std;
using CS140::BSTNode;
using CS140::BSTree;
// judah benjamin 
// 2/26/2021
// lab 9
// jbenjam7

// sources: ria helped with finishing balanced trees, 
// jackson: helped with hwo to keep trand and coutn depth and hights
/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

// calculate the depth of the tree, set at 0
int BSTree::Depth(const string &key) const
{
  (void)key;
  if (key.empty())
    return -1;

  int depth = 0;
  const BSTNode *n = sentinel->right;
// while the node isnt sentnal, if its not the current one, go down, if less its left if more its right. 
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

}

int BSTree::Height() const
{
// recursive function, if setinel send back -1
  if (sentinel->right == sentinel)
  {
    return -1;
  }
  return recursive_find_height(sentinel->right);
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

  size = t.size;

  if (t.sentinel->right != t.sentinel)
  {
    vector<string> sorted_keys = t.Ordered_Keys();
    vector<void *> vals = t.Ordered_Vals();
    sentinel->right = make_balanced_tree(sorted_keys, vals, 0, sorted_keys.size());
  }
}
// clear the tree out, then start calling funcitons to start adding nodes
BSTree &BSTree::operator=(const BSTree &t)
{
  if (this != &t)
  {
    Clear();
    size = t.size;

    if (t.sentinel->right != t.sentinel)
    {
      vector<string> sorted_keys = t.Ordered_Keys();
      vector<void *> vals = t.Ordered_Vals();
      sentinel->right = make_balanced_tree(sorted_keys, vals, 0, sorted_keys.size());
      
    }

  }

  return *this;
}
// set setinel to 0
int BSTree::recursive_find_height(const BSTNode *n) const
{
  if (n == sentinel)
  {
    return 0;
  }

  int right = recursive_find_height(n->right);
  int left = recursive_find_height(n->left);

  return 1 + max(left, right);
}
// create keys 
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
// if no leafs your at setinel 
  if (num_indices == 0)
  {
    return sentinel;
  }

  size_t mid = first_index + num_indices / 2;

  BSTNode *node = new BSTNode();
  BSTNode *left;
  BSTNode *right;

// call make balanced tree for left and right

  left = make_balanced_tree(sorted_keys, vals, first_index, mid - first_index);
  right = make_balanced_tree(sorted_keys, vals, mid + 1, num_indices - (mid + 1 - first_index));
 
// stores ne left and right to parent, then registers ikds to parent
 left->parent = node;
 right->parent = node;
 node->left = left;
 node->right = right;
// calls the other functions to continue. 
node->key = sorted_keys[mid];
  node->val = vals[mid];
  

  return node;
}

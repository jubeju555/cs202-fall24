#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "../include/bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

int BSTree::Depth(const string &key) const
{
  (void) key;
  if (key.empty()) return -1;


  int depth = 0;
const BSTNode *n = sentinel->right;
  
    while (n != NULL)
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
  return recursive_find_height(sentinel->right, 0);
}

vector <string> BSTree::Ordered_Keys() const
{
  vector <string> rv;
  return rv;
}
    
BSTree::BSTree(const BSTree &t)        
{
  (void) t;
}

BSTree& BSTree::operator= (const BSTree &t) 
{
  (void) t;
  return *this;
}

int BSTree::recursive_find_height(const BSTNode *n, int x) const
{
  (void) n;
  if (n == NULL)
  {
    return -1;
  }
  int left = recursive_find_height(n->left, x);
  int right = recursive_find_height(n->right, x);

  return 1 + max(left, right);
}

void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  (void) n;
  (void) v;
}

BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
                            const vector<void *> &vals,
                            size_t first_index,
                            size_t num_indices) const
{
  (void) sorted_keys;
  (void) vals;
  (void) first_index;
  (void) num_indices;
  return NULL;
}

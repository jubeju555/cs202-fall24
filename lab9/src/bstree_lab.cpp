#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "bstree.hpp"
#include "../include/bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

int BSTree::Depth(const string &key, int x) const
{
  (void) key;
  if (key.empty()) return -1;

  int dist = 0;

  if (key.empty())
  {
    
    if ((dist = Depth(key->left, x)) >= 0)
    {
      return dist + 1;
    }
    else if ((dist = Depth(key->right, x)) >= 0)
    {
      return dist + 1;
    }
    // else
    // {
    //   return ;
    // }
      return dist;
  }
}


int BSTree::Height(int x) const
{
  int n;
  int h = -1;

  int maxheight = recursive_find_height();

  return h;
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

int BSTree::recursive_find_height(const BSTNode *n) const
{
  (void) n;
  return -1;
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

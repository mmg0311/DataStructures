#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int d)
   {
      data = d;
      left = NULL;
      right = NULL;
   }
};

void preorder_traversal(Node *root)
{
   if (root == NULL)
   {
      return;
   }
   cout << root->data << " ";
   preorder_traversal(root->left);
   preorder_traversal(root->right);
}

void postorder_traversal(Node *root)
{
   if (root == NULL)
   {
      return;
   }
   postorder_traversal(root->left);
   postorder_traversal(root->right);
   cout << root->data << " ";
}

void inorder_traversal(Node *root)
{
   if (root == NULL)
   {
      return;
   }
   inorder_traversal(root->left);
   cout << root->data << " ";
   inorder_traversal(root->right);
}

int height(Node *root)
{
   if (root->left == NULL && root->right == NULL)
   {
      return 0;
   }
   if (root->left == NULL)
   {
      return height(root->right) + 1;
   }
   if (root->right == NULL)
   {
      return height(root->left) + 1;
   }
   return max(height(root->left) + 1, height(root->right) + 1);
}

void topView(Node *root)
{
   Node *t = root;
   cout << t->data << " ";
   t = root->left;
   while (t != NULL)
   {
      cout << t->data << " ";
      t = t->left;
   }
   t = root->right;
   while (t != NULL)
   {
      cout << t->data << " ";
      t = t->right;
   }
}

//find the min and max line number
void findMinMax(Node *root, int *min, int *max, int curr_dist)
{
   if (root == NULL)
   {
      return;
   }
   if (curr_dist < *min)
   {
      *min = curr_dist;
   }
   else if (curr_dist > *max)
   {
      *max = curr_dist;
   }
   findMinMax(root->left, min, max, curr_dist - 1);
   findMinMax(root->right, min, max, curr_dist + 1);
}
//for printing vertical order
void print_vertical_order(Node *root, int line_no, int curr_dist)
{
   if (root == NULL)
   {
      return;
   }
   if (curr_dist == line_no)
   {
      cout << root->data << " ";
   }
   print_vertical_order(root->left, line_no, curr_dist - 1);
   print_vertical_order(root->right, line_no, curr_dist + 1);
}

//traverse through lines to print
void verticalOrder(Node *root)
{
   int min = 0, max = 0;
   findMinMax(root, &min, &max, 0);
   for (int i = min; i <= max; i++)
   {
      print_vertical_order(root, i, 0);
      cout << endl;
   }
}

//******************for top view****************
void getVerticalOrder(Node *root, map<int, pair<int, int>> &m, int l, int d)
{
   if (root == NULL)
      return;

   if (m.count(d) == 0)
   {
      m[d] = make_pair(root->data, l);
   }
   else if (m[d].second > l)
   {
      m[d] = make_pair(root->data, l);
   }

   getVerticalOrder(root->left, m, l + 1, d - 1);
   getVerticalOrder(root->right, m, l + 1, d + 1);
}

void topView(Node *root)
{
   map<int, pair<int, int>> m;
   int curr_dist = 0;
   getVerticalOrder(root, m, 0, curr_dist);
   for (auto it = m.begin(); it != m.end(); it++)
   {
      cout << it->second.first << " ";
   }
}

//*******************************************

//level order traversal
void levelOrder(Node *root)
{
   queue<Node *> s;
   s.emplace(root);
   Node *t;
   while (!s.empty())
   {
      t = s.front();
      s.pop();
      cout << t->data << " ";
      if (t->left != NULL)
      {
         s.emplace(t->left);
      }
      if (t->right != NULL)
      {
         s.emplace(t->right);
      }
   }
}

//insert into binary search tree

int main()
{
}
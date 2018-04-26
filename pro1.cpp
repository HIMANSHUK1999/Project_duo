// Iterative CPP program to convert a Binary
// Tree to its mirror
#include<iostream.h>
using namespace std;
 
/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* newNode(int data)
 
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 
/* Change a tree so that the roles of the  left and
    right pointers are swapped at every node.
 So the tree...
       4
      / \
     2   5
    / \
   1   3
 
 is changed to...
       4
      / \
     5   2
        / \
       3   1
*/
void mirror(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    // Do BFS. While doing BFS, keep swapping
    // left and right children
    while (!q.empty())
    {
        // pop top node from queue
        Node* curr = q.front();
        q.pop();
 
        // swap left child with right child
        swap(curr->left, curr->right);
 
        // push left and right children
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
 

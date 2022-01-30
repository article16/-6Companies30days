class Solution {
public:

  // Convert a given tree to a tree where every node contains sum of values of
  // nodes in left and right subtrees in the original tree
  int sum(Node *node) {
    if (node == NULL)return 0;

    int l = sum(node->left);
    int r = sum(node->right);

    int temp = node->data;
    node->data = l + r;
    return temp + l + r;
  }
  void toSumTree(Node *node)
  {
    int s = sum(node);
  }
};
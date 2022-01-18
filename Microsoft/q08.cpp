class Solution
{
public:
  //Function to connect nodes at same level.
  void connect(Node *root)
  {
    Node* node;
    queue<Node*>q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 1; i <= n; i++) {
        if (i > 1)node->nextRight = q.front();
        node = q.front();
        q.pop();
        if (node->left)q.push(node->left);
        if (node->right)q.push(node->right);
      }
    }
  }

};
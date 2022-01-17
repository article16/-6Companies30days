class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            ans.push_back(node->data);
            if (node->left)q.push(node->left);
            else q.push(NULL);
            if (node->right)q.push(node->right);
            else q.push(NULL);

            while (!q.empty() && q.front() == NULL) {
                ans.push_back(-1);
                q.pop();
            }
        }
        return ans;
    }

    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        queue<Node*>q;
        Node *root = new Node(A[0]);
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (A[i] == -1)node->left = NULL;
            else {
                node->left = new Node(A[i]);
                q.push(node->left);
            }
            i++;

            if (A[i] == -1)node->right = NULL;
            else {
                node->right = new Node(A[i]);
                q.push(node->right);
            }
            i++;

        }
        return root;
    }

};
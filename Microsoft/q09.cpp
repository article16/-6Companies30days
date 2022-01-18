int sum(Node* root, int x, int &cnt) {
    if (root == NULL)return 0;

    int s = root->data + sum(root->left, x, cnt) + sum(root->right, x, cnt);
    if (s == x)cnt++;
    return s;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int cnt = 0;
    int s = sum(root, X, cnt);
    return cnt;
}
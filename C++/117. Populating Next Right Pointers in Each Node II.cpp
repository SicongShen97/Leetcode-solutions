/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            Node* pre;
            Node* node;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    pre = que.front();
                    que.pop();
                    node = pre;
                }
                else {
                    node = que.front();
                    que.pop();
                    pre->next = node;
                    pre = node;
                }
                pre->next = nullptr;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};
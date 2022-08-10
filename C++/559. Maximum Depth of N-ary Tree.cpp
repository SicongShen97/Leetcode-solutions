/*
1.µÝ¹é
2.µü´ú
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Solution {
// public:
//     int maxDepth(Node* root) {
//         if (root == NULL) return 0;
//         int max_ = 0;
//         for (auto child: root->children){
//             max_ = max(max_, maxDepth(child));
//         }
//         return 1 + max_;
//     }
// };

class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        if (root == NULL) return depth;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            depth++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* cur = que.front(); que.pop();
                for (auto child : cur->children) {
                    que.push(child);
                }
            }
        }
        return depth;
    }
};
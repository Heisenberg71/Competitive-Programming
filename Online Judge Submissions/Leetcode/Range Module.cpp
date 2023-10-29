/*

Problem Link: https://leetcode.com/problems/range-module/description/
Time Complexity: O(amount_of_all_function_calls*log(amounts_of_updates))
Space Complexity: O(amount_of_all_updates*log(amount_of_all_updates))

*/
class Node{
    public:
    int l, r;
    bool state;
    Node *left = NULL, *right = NULL;
    Node(int l, int r, bool st) {
        this->l = l;
        this->r = r;
        this->state = st;
    }
};

class RangeModule {
public:
    Node *root;

    RangeModule() {
        root = new Node(0, 1e9, false);
    }

    bool update(int l, int r, bool state, Node* root) {
        if(root->l >= l && root->r <= r) {
            root->state = state;
            root->left = NULL;
            root->right = NULL;
            return state;
        }
        if(l > root->r || r < root->l)return root->state;

        int mid = root->l + (root->r - root->l) / 2;
        if(root->left == NULL) {
            root->left = new Node(root->l, mid, root->state);
            root->right = new Node(mid + 1, root->r, root->state);
        }

        bool left = update(l, r, state, root->left);
        bool right = update(l, r, state, root->right);
        root->state = left & right;
        return root->state;
    }
    
    void addRange(int left, int right) {
        update(left, right - 1, true, root);
    }

    bool q(Node *root, int l, int r) {
        if((root->l > l && root->r < r) || root->left == NULL)return root->state;

        int mid = root->l + (root->r - root->l) / 2;
        if(r <= mid){
            return q(root->left, l, r);
        }else if(l > mid){
            return q(root->right, l, r);
        }else{
            return q(root->left, l, r) && q(root->right, l, r);
        }
    }
    
    bool queryRange(int left, int right) {
        return q(root, left, right - 1);
    }
    
    void removeRange(int left, int right) {
        update(left, right - 1, false, root);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

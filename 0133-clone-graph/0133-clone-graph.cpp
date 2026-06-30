/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   vector<Node*> noderegister;
    void dfs(Node* actual,Node* clone){
        for(auto neighbor:actual->neighbors){
            if(not noderegister[neighbor->val]){
            Node* newNode = new Node(neighbor->val);
            noderegister[newNode->val] = newNode;
            clone->neighbors.push_back(newNode);
            dfs(neighbor,newNode);
        }else{
            clone->neighbors.push_back(noderegister[neighbor->val]);
        }
    }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        noderegister.resize(110,NULL);
        noderegister[clone->val] = clone;
        dfs(node,clone);
        return clone;
        
    }
};
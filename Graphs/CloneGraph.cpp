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
private:
    // void print_adjlist(Node* node){
    //     vector<vector<int>> edges;
    //     for(int i=0; i<)
    // }
    void print_nodes(Node* node){
        Node* temp_node=node->neighbors[0]->neighbors[0];
        vector<Node*> vec=temp_node->neighbors;
        for(int i=0 ; i<vec.size();i++){
            cout<<vec[i]->val<<" ";
        }
    }
    Node* bfs(Node* node){
        queue<Node*> q;
        unordered_map<Node*,Node*> recl;
        Node* newhead=new Node(node->val);
        recl[node]=newhead;
        q.push(node);
        // visited[node]
        while(!q.empty()){
            Node* temp =q.front();
            if(temp!=nullptr){
                vector<Node*> vec=temp->neighbors;
                for(int i=0;i<vec.size();i++){
                if(recl.find(vec[i]) == recl.end()){
                    q.push(vec[i]);
                    Node* temp_node= new Node(vec[i]->val);
                    recl[vec[i]]=temp_node;
                }
                recl[temp]->neighbors.push_back(recl[vec[i]]);
            }
            }
            q.pop();
        }
        return newhead;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        return bfs(node);
    }
};

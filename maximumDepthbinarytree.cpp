#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node (int val){
        this->data = val;
        this->right = NULL;
        this->left = NULL;

    }

};

Node* createTree(){
    cout<<"Enter the value "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* newNode = new Node(data);
    cout<<"left of Node:"<<newNode->data<<endl;

    newNode->left = createTree();

    cout<<"right of Node: "<<newNode->data<<endl;

    newNode->right = createTree();

    return newNode;

}
int maxDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    int height = max(leftHeight,rightHeight)+1;

    return height;

}
int main(){

    Node* root = createTree();

    cout<<root->data<<endl;

    int height = maxDepth(root);
    cout<<"height is : "<<height<<endl;


    return 0;
}
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
int main(){

    Node* root = createTree();

    cout<<root->data<<endl;


    return 0;
}
#include<iostream>
#include<queue>
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
void preOrderTraversal(Node* root){
    if(root == NULL){
        return;

    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;

    }
    
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;

    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
    
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
                    }
    }
}
int main(){

    Node* root = createTree();

    cout<<root->data<<endl;

    cout<<"Printing preOrder: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Printing InOrder: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Printing postOrder: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Printing LevelOrder: ";
    levelOrderTraversal(root);
    cout<<endl;




    return 0;
}
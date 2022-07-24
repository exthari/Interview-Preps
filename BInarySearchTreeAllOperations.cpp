#include<iostream>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};

node *Getnewnode(int data){
  node *newnode = new node();
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

node *insertData(node *root, int data){ 
    if(root == NULL){
        root = Getnewnode(data);
    }

    else if(data <= root->data){
        root->left = insertData(root->left,data);
    }
    
    else{
        root->right = insertData(root->right,data);
    }

    //Common for all
    return root; 
}
    
void searchNode(node *root, int data){
    if(root == NULL)
        cout<<endl<<data<<" is not present in the BST";
    else if (root->data == data)
        cout<<endl<<root->data<<" is present in the BST";
    else if (data <= root->data)
        return searchNode(root->left, data);
    else if (data > root->data)
        return searchNode(root->right,data);
}


node *Findmin(node *root){
    
    if (root == NULL){
        cout<<"error";
    }
    
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

node *Findmax(node *root){
    if (root == NULL){
            cout<<"error";
        }

    while(root->right != NULL){
        root = root->right;
    }

    return root;
    
}

node *deleteNode(node *root , int data){

    // Corner cases : 
    if (root == NULL){
        return root;
    }
    else if (data < root->data){
        //cout<<"debug1 "<<root->data<<endl;
        root->left = deleteNode(root->left , data);
    }

    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }

    else
    {
        //case 1 : No child
        if(root->right == NULL && root->left == NULL){
            //cout<<"debug2 ";
            delete root;
            root = NULL;
        }

        // case 2 : One child 
        else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
        }

        else if(root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
        }

        //Case 3 : 

        else {
            node *temp = Findmin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);

        }
    }

    return root;
}

void inOrderTraversal(node *root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node *root){
    if(root ==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int sumofallNodes(node *root){
    int sum;
    if(root ==NULL){
        return 0;
    }

    return root->data + sumofallNodes(root->left) + sumofallNodes(root->right);
}

void sumofleafNodes(node *root , int *sum){
    
    // Very good technique to get leaves sum
    
    if (root == NULL)
        return ;
    
    if(root->left == NULL && root->right == NULL){
        *sum += root->data;
    }

    sumofleafNodes(root->left, sum);
    sumofleafNodes(root->right , sum);

}

int main(){
    
int o;
  // root node declration to NULL
  int sum;
  node *root = new node();
  root = NULL;
  cin>>o;
  while(o!=-1){
    root = insertData(root,o);
    cin>>o;
  }
 
  sum = 0;  
  sumofleafNodes(root , &sum);
  cout<<"Sum of all leaves nodes are "<<sum;
  return 0;
}
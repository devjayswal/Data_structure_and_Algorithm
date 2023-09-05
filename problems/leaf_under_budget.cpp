/*Given a binary tree and a budget. 
Assume you are at the root of the tree(level 1),
you need to maximise the count of leaf nodes you can visit
in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.*/
/*Input: 
                  10
                /    \
               8      2
             /      /   \
            3      3     6
                    \
                     4
and budget = 8
Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
In budget 8 one can visit Max 2 Leaf Nodes.*/
#include<bits/stdc++.h>

using namespace std;


struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int getcount(node *root , int budget ){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        if(budget >= 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    int leftcount = getcount(root->left, budget - 1);
    int rightcount = getcount(root->right, budget - 1);
    return leftcount + rightcount;
}

int main(){
    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->right->left = new node(3);
    root->right->right = new node(6);
    root->right->left->right = new node(4);
    int budget = 8;
    cout<<getcount(root, budget);
    return 0;
}
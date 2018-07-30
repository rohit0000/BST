#include<iostream>
#include "bst.h"
using namespace std;
bst::bst(){
    root = NULL;
}

int bst::find(int item_i){
    node *currentNode = root;
    if(root == NULL){
        cout << "Nothing is here"<< endl;
    }

    while(currentNode->value_i !=item_i){

        if(item_i < currentNode->value_i){
            currentNode = currentNode->left_p;
        }
        else{
            currentNode = currentNode->right_p;
        }
        if(currentNode == NULL){
            return -1;
        }
    }
    return 0;
}

int bst::insert(int item_i){

    node temp = new node;
    temp->left_p = NULL;
    temp->right_p = NULL;
    temp->parent_p = NULL;
    temp->value_i = item_i;
    if(root == NULL){
        root = temp;
    }
}

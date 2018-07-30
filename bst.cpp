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

    node *temp = new node;
    temp->left_p = NULL;
    temp->right_p = NULL;
    temp->parent_p = NULL;
    temp->value_i = item_i;
    int found = 0;
    if(root == NULL){
        root = temp;
    }
    else{
        node *currentNode = new node;
        currentNode = root;
        currentNode->parent_p = NULL;

        while(found == 0){
            currentNode->parent_p = currentNode;
            if(item_i < currentNode->value_i){
                currentNode = currentNode->left_p;

                if(currentNode == NULL){
                    currentNode->parent_p->left_p = temp;
                    return;
                }
            }
            else{
                currentNode = currentNode->right_p;

                if(currentNode == NULL){
                    currentNode->parent_p->right_p = temp;
                    return;
                }
            }
        }
    }
}

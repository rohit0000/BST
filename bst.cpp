#include<iostream>
#include "bst.h"
#include "queue.h"
using namespace std;

bst::bst(){
    root = NULL;
}

int bst::find(int item_i){
    node *currentNode = root;
    if(root == NULL){
        return -2;
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

    if(root == NULL){
        root = temp;
        return 0;
//        cout << root->value_i << endl;
    }
    else{
        node *currentNode = new node;
        currentNode = root;
        node *prev = new node;
//        currentNode->parent_p = NULL;
        prev = NULL;

        while(1){
//            currentNode->parent_p = currentNode;
                prev = currentNode;
            if(item_i < currentNode->value_i){
                currentNode = currentNode->left_p;

                if(currentNode == NULL){
                    prev->left_p = temp;
                    temp->parent_p = prev;
                    return 0;
                }
            }
            else{
                currentNode = currentNode->right_p;
                if(currentNode == NULL){
                    prev->right_p = temp;
                    temp->parent_p = prev;
                    return 0;
                }
            }
        }
    }
    return -1;
}
int findpredecessor(node* current, int value){
    int pred = -1;
    while(current){
        if(value < current->value_i){
            pred = -1;
            current = current->left_p;
        }
        else if(value > current->value_i){
            pred = current->value_i;
            current = current->right_p;
        }
        else{
            if(current->left_p){
                current = current->left_p;
                while(current->right_p){
                    current = current->right_p;
                }
                pred = current->value_i;
            }
            else{
                return pred;
            }
            break;
        }
    }
    return pred;
}

node* deleteNode(struct node* current, int value)
{
    // base case
    if (current == NULL) return current;

    if (value < current->value_i)
        current->left_p = deleteNode(current->left_p, value);


    else if (value > current->value_i)
        current->right_p = deleteNode(current->right_p, value);

    else
    {
        // node with only one child or no child
        if (current->left_p == NULL)
        {
            struct node *temp = current->right_p;
            return temp;
        }
        else if (current->right_p == NULL)
        {
            struct node *temp = current->left_p;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        int temp = findpredecessor(current, value);

        // Copy the inorder successor's content to this node
//        current->value_i = temp->value_i;
        current->value_i = temp;

        // Delete the inorder successor
        current->left_p = deleteNode(current->left_p, temp);
    }
    return current;
}

int bst::remove(int item_i){

    if(root == NULL){
        return -2;
//        cout << root->value_i << endl;
    }
    if(find(item_i) == -1){
        return -1;
    }
    else{
        node *currentNode = new node;
        currentNode = root;
        currentNode = deleteNode(   currentNode, item_i);
        root = currentNode;
    }
    return 0;
}

int bst::minimum(){
    node *currentNode = new node;
    currentNode = root;
    while(currentNode->left_p != NULL){
        currentNode = currentNode->left_p;
    }
    return currentNode->value_i;
}

int bst::maximum(){
    node *currentNode = new node;
    currentNode = root;
    while(currentNode->right_p != NULL){
        currentNode = currentNode->right_p;
    }
    return currentNode->value_i;
}

int bst::predecessor(int item_i){
    if(root == NULL){
        return -2;
    }
    if(find(item_i) == -1){
        return -3;
    }
    else{
        return findpredecessor(root, item_i);
    }

}

int findsuccessor(node* current, int value){
    int succ = -1;
    while(current){
        if(value < current->value_i){
            succ = current->value_i;
            current = current->left_p;
        }
        else if(value > current->value_i){
            succ = -1;
            current = current->right_p;
        }
        else{
            if(current->right_p){
                current = current->right_p;
                while(current->left_p){
                    current = current->left_p;
                }
                succ = current->value_i;
            }
            else{
                return succ;
            }
            break;
        }
    }
    return succ;
}

int bst::successor(int item_i){
    if(root == NULL){
        return -2;
    }
    if(find(item_i) == -1){
        return -3;
    }
    else{
        return findsuccessor(root, item_i);
    }

}

void traversePre(node *current){

    if(current == NULL){
        return;
    }
    cout << current->value_i << " ";

    traversePre(current->left_p);

    traversePre(current->right_p);

}

void traversePost(node *current){

    if(current == NULL){
        return;
    }
    traversePost(current->left_p);

    traversePost(current->right_p);

    cout << current->value_i << " ";

}

void traverseIn(node *current){

    if(current == NULL){
        return;
    }
    traverseIn(current->left_p);

    cout << current->value_i << " ";

    traverseIn(current->right_p);
}


void bst::preOrder(){

    if(root == NULL){
        cout << "No Contents";
        return;
    }
    else{
        traversePre(root);
    }

}

void bst::postOrder(){

    if(root == NULL){
        cout << "No Contents";
        return;
    }
    else{
        traversePost(root);
    }

}

void bst::inOrder(){

    if(root == NULL){
        cout << "No Contents";
        return;
    }
    else{
        traverseIn(root);
    }

}
int maxDepth(node* current)
{
   if (current==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(current->left_p);
       int rDepth = maxDepth(current->right_p);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout<<root->value_i << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left_p, level-1);
        printGivenLevel(root->right_p, level-1);
    }
}


void bst::levelOrder(){
    int height = maxDepth(root);
    int i;
    for (i=1; i<=height; i++)
    {
        printGivenLevel(root, i);
    }
}




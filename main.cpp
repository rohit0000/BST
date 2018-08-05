#include <iostream>
#include "bst.h"
#include <string>
#include <cstdlib>
using namespace std;

void test(){
    bst binary;
    binary.insert(36);
    binary.insert(72);
    binary.insert(71);
    binary.insert(24);
    binary.insert(25);
    binary.insert(99);

    cout << "Pred:" << binary.predecessor(36)<<endl;
    cout << "Succ:" << binary.successor(36)<<endl;

    binary.preOrder();
    cout << endl;
    binary.postOrder();
    cout << endl;
    binary.inOrder();
    cout << endl;
    binary.levelOrder();
    cout << endl;

    binary.remove(72);
    binary.preOrder();
    cout << endl;
    binary.postOrder();
    cout << endl;
    binary.inOrder();
    cout << endl;
    binary.levelOrder();
    cout << endl;

//    binary.remove(2);

}

int main()
{
//    test();
    bst binary;
    int q = 0;
    string input, next;
    string delimit = " ";

    while(q == 0){

        cout << "prompt> ";
        getline(cin, input);
        if(input.substr(0, input.find(delimit)).compare("find") == 0){
            if(!(input.length() < 6)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
                if(val > 0 ){
                    if(binary.find(val) ==  0){
                        cout << val << " is found in the tree" << endl;
                    }
                    else if(binary.find(val) ==  -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "ERROR: " <<val << " is not found in the tree" << endl;
                    }
                }
                else {
                    cout << "ERROR: Input is invalid" << endl;
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }
        else if(input.substr(0, input.find(delimit)).compare("ins") == 0){
            if(!(input.length() < 5)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
//                cout << val << endl;
                if(val <= 0){
                    cout << "ERROR: Input is invalid"<< endl;
                }
                else{
                    if(binary.find(val) == 0){
                        cout << "ERROR: " << val << " is already added" << endl;
                    }
                    else{
                        binary.insert(val);
                        cout << val << " added" << endl;
                    }
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }
        else if(input.substr(0, input.find(delimit)).compare("rm") == 0){
            if(!(input.length() < 4)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
//                cout << val << endl;
                if(val <= 0){
                    cout << "ERROR: Input is invalid" << endl;
                }
                else{
                    if(binary.find(val) == 0){
                        binary.remove(val);
                        cout << val << " is removed" << endl;
                    }
                    else if(binary.find(val) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "ERROR: "<< val << " is not found" << endl;
                    }
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("min") == 0){
            if((input.length() < 4)){
                int min = binary.minimum();
                if(min == -1){
                    cout << "ERROR: Tree is empty" << endl;
                }
                else{
                    cout << "Minimum is "<< min << endl;
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("max") == 0){
            if((input.length() < 4)){
                int max = binary.maximum();
                if(max == -1){
                    cout << "ERROR: Tree is empty" << endl;
                }
                else{
                    cout << "Maximum is "<< max << endl;
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("pred") == 0){
            if(!(input.length() < 6)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
//                cout << val << endl;
                if(val <= 0){
                    cout << "ERROR: Input is invalid" << endl;
                }
                else{
                    if(binary.predecessor(val) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else if(binary.predecessor(val) == -3){
                        cout << "ERROR: "<< val << " is not found" << endl;
                    }
                    else if(binary.predecessor(val) == -1){
                        cout << "ERROR: Predecessor is not found" << endl;
                    }
                    else{
                        cout << "Predecessor: "<<binary.predecessor(val) << endl;
                    }
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("succ") == 0){
            if(!(input.length() < 6)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
//                cout << val << endl;
                if(val <= 0){
                    cout << "ERROR: Input is invalid" << endl;
                }
                else{
                    if(binary.successor(val) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else if(binary.successor(val) == -3){
                        cout << "ERROR: "<< val << " is not found" << endl;
                    }
                    else if(binary.successor(val) == -1){
                        cout << "ERROR: Successor is not found" << endl;
                    }
                    else{
                        cout << "Successor: "<<binary.successor(val) << endl;
                    }
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("preo") == 0){
            if((input.length() < 5)){
                    if(binary.find(0) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "PreOrder Traversal" << endl;
                        cout << "   ";
                        binary.preOrder();
                        cout << endl;
                    }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("posto") == 0){
            if((input.length() < 6)){
                    if(binary.find(0) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "PostOrder Traversal" << endl;
                        cout << "   ";
                        binary.postOrder();
                        cout << endl;
                    }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("ino") == 0){
            if((input.length() < 4)){
                    if(binary.find(0) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "InOrder Traversal" << endl;
                        cout << "   ";
                        binary.inOrder();
                        cout << endl;
                    }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("levelo") == 0){
            if((input.length() < 7)){
                    if(binary.find(0) == -2){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "LevelOrder Traversal" << endl;
                        cout << "   ";
                        binary.inOrder();
                        cout << endl;
                    }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("bye") == 0){
            if((input.length() < 4)){
                    return 0;
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }


        else{
            cout << "ERROR: Invalid Command" << endl;
        }

    }
    return 0;
}

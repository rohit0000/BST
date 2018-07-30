struct node{
    int value_i;
    struct node *left_p;
    struct node *right_p;
    struct node *parent_p;
};
class bst{
private:
    struct node *root;
public:
    bst();
    int find(int item_i);
    int insert(int item_i);
    int remove(int item_i);
    int minimum();
    int maximum();
    int predecessor(int item_i);
    int successor(int item_i_);
    void preOrder();
    void postOrder();
    void inOrder();
    void levelOrder();

};

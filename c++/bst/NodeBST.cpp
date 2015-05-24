#ifndef NODEBST
#define NODEBST
#include "BST.h"
#include <stdio.h>

struct node {
    int num;
    struct node* next;
};
typedef struct node Node

class NodeBST : public BST {
    Node* root;
    public:
        NodeBST();
        ~NodeBST();
        void insert(int val);
        bool find(int val);
        void print_inorder();
};

NodeBST::NodeBST() {
    printf("Hello ");
}

NodeBST::~NodeBST() {
    printf("leave\n");
}

void NodeBST::insert(int val) {
    if (root == NULL) {

    } else{

    };
}

bool NodeBST::find(int val) {

}

void NodeBST::print_inorder() {

}




#endif

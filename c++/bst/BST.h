#ifndef BST
#define BST

class BST {
    private:
        int num[100];
        int len;
    public:
        virtual ~BST() = 0;
        virtual void insert(int val) = 0;
        virtual bool find(int val) = 0;
        virtual void print_inorder() = 0;
};

#endif

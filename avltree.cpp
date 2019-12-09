#include"avltree.h"

template<typename T>
node<T>::node(T data){
    this->data = data;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

template<typename T>
int height(node<T>* node) {
    if (!node) return 0;
    return node->height;
}

template<typename T>
int balance(node<T>* node){
    if (!node) return 0;
    return height(node->right) - height(node->left);
}


template<typename T>
node<T>* rotateL(node<T>*& n){
    node<T>* r = n->right;
    node<T>* lr = r->left;

    r->left = n;
    n->right = lr;

    n->height = 1 + max(height(n->left),height(n->right));
    r->height = 1 + max(height(r->left),height(r->right));

    return r;
}

template<typename T>
node<T>* rotateR(node<T>*& n){
    node<T>* l = n->left;
    node<T>* rl = l->right;

    l->right = n;
    n->left = rl;
    
    n->height = 1 + max(height(n->left),height(n->right));
    l->height = 1 + max(height(l->left),height(l->right));

    return l;
}

template<typename T>
avltree<T>::avltree(){
    this->root = nullptr;
    this->size = 0;
}

template<typename T>
avltree<T>::~avltree(){
    this->clear();
}

template<typename T>
void avltree<T>::clear(){
    clearH(root);
}

template<typename T>
void avltree<T>::clearH(node<T>*& root){
    if (root){
        clearH(root->left);
        clearH(root->right);
        delete root;
        root = nullptr;
    }
}

template<typename T>
void avltree<T>::insert(T data){
    insertH(root,data);
    this->size++;
}

template<typename T>
void avltree<T>::insertH(node<T>*& root, T data){
    if (!root){
        root = new node<T>(data);
    }
    else {
        if (data >= root->data) insertH(root->right, data);
        else insertH(root->left, data);

        root->height = 1 + max(height(root->left),height(root->right));

        if (balance(root) > 1){
            if (balance(root->right) < 0) root->right = rotateR(root->right);
            root = rotateL(root);
        }
        if (balance(root) < -1){
            if (balance(root->left) > 0) root->left = rotateL(root->left);
            root = rotateR(root);
        }
    }
}

template<typename T>
void avltree<T>::preH(node<T>* root){
    if (root){
        cout << "{ ";
        preH(root->left);
        cout << "|(" << root->data << ")|";
        preH(root->right);
        cout << " }";
    }
}

template<typename T>
void avltree<T>::print(string order){
    if (order == "pre"){
        preH(this->root);
    }
}
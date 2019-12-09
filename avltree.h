#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct node
{
    T data;
    int height;
    node<T>* left;
    node<T>* right;
    node(T data);
};

template<typename T>
int height(node<T>*);

template<typename T>
int balance(node<T>*);

template<typename T>
node<T>* rotateL(node<T>*&);

template<typename T>
node<T>* rotateR(node<T>*&);

template<typename T>
class avltree
{
private:
    // friend height(node<T>*);
    // friend balance(node<T>*);
    node<T>* root;
    int size;
    void clearH(node<T>*&);
    void insertH(node<T>*&, T data);
    void preH(node<T>*);
public:
    avltree();
    ~avltree();
    void clear();
    void insert(T data);
    void print(string);
};

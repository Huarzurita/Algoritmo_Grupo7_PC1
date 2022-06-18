#pragma once
#include "Capp.h"
class TreapNode
{
private:
    int data, priority;
    TreapNode* left, * right;
    TreapNode(int data) :data(data) {
        priority = rand() % 100;
        left = right = nullptr;
    }
    friend class Treap;
};
class Treap
{
private:
    Treap() { }
    void rotateLeft(TreapNode*& root){
        TreapNode* R = root->right;
        TreapNode* X = root->right->left;
        R->left = root;
        root->right = X;
        root = R;
    }
    void rotateRight(TreapNode*& root){
        TreapNode* L = root->left;
        TreapNode* Y = root->left->right;
        L->right = root;
        root->left = Y;
        root = L;
    }
public:
    void insertNode(TreapNode*& root, int data){
    if (root == nullptr) {
        root = new TreapNode(data);
        return;}
    if (data < root->data){
        insertNode(root->left, data);
        if (root->left != nullptr && root->left->priority > root->priority)
            rotateRight(root);
    }
    else {
        insertNode(root->right, data);
        if (root->right != nullptr && root->right->priority > root->priority)
            rotateLeft(root);
    }
}

    bool searchNode(TreapNode* root, int key)
    {
        if (root == nullptr) return false;
        if (root->data == key)return true;
        if (key < root->data) return searchNode(root->left, key);
        return searchNode(root->right, key);
    }
    
    void deleteNode(TreapNode*& root, int key)
    {
        if (root == nullptr) { return; }
        if (key < root->data) { deleteNode(root->left, key);}
        else if (key > root->data) {deleteNode(root->right, key);}
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root; root = nullptr; }
            else if (root->left && root->right){
                if (root->left->priority < root->right->priority)  {
                    rotateLeft(root);
                    deleteNode(root->left, key);
                }
                else {
                    rotateRight(root);
                    deleteNode(root->right, key);
                }
            }
            else {
                TreapNode* child = (root->left) ? root->left : root->right;
                TreapNode* curr = root;
                root = child;
                delete curr;
            }
        }
    }
    void printTreap(TreapNode* root)
    {
        if (root == nullptr) {  return;}
        printTreap(root->right);
        Console::ForegroundColor = ConsoleColor::Magenta;
        cout << "Número del usuario: "<<root->data << "\t Prioridad:" << root->priority << endl;
        printTreap(root->left);
    }
};


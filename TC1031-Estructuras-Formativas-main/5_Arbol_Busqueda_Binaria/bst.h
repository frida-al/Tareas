/*
* bst.h
*
* Frida Arcadia Luna
* 07 de octubre de 2024
*/

#ifndef BST_H
#define BST_H

#include <string>
#include <sstream>


#endif
template <class T> class BST;

template <class T>
class TreeNode {
private:
	T value;
	TreeNode *left, *right;

	TreeNode<T>* succesor();

public:
	TreeNode(T val) :value(val), left(0), right(0){}
	TreeNode(T val, TreeNode<T>* le, TreeNode<T>* ri):value(val), left(le), right(ri){}
	void add(T val){
        if (val < value) {
            if (left != 0) {
                left->add(val);
            } else {
                left = new TreeNode<T>(val);
            }
        } else {
            if (right != 0) {
                right->add(val);
            } else {
                right = new TreeNode<T>(val);
            }
        }
    }
	bool find(T val){
        if (val == value) {
            return true;
        } else if (val < value) {
            return (left != 0 && left->find(val));
        } else if (val > value) {
            return (right != 0 && right->find(val));
        }
        return false;
    }
    int height(){
        int hl = 0;
        int hr = 0;

        if(left != 0){
            hl = left->height();
        }

        if(right != 0){
            hr = right->height();
        }

        if (hl > hr) {
            return 1 + hl; 
        } else {
            return 1 + hr; 
        }
    }

	void remove(T val){
        TreeNode<T> * succ, *old;
        if (val < value) {
            if (left != 0) {
                if (left->value == val) {
                    old = left;
                    succ = left->succesor();
                    if (succ != 0) {
                        succ->left = old->left;
                        succ->right = old->right;
                    }
                    left = succ;
                    delete old;
                } else {
                    left->remove(val);
                }
            }
        } else if (val > value) {
            if (right != 0) {
                if (right->value == val) {
                    old = right;
                    succ = right->succesor();
                    if (succ != 0) {
                        succ->left = old->left;
                        succ->right = old->right;
                    }
                    right = succ;
                    delete old;
                } else {
                    right->remove(val);
                }
            }
        }
    }
	void removeChilds(){
        if (left != 0) {
            left->removeChilds();
            delete left;
            left = 0;
        }
        if (right != 0) {
            right->removeChilds();
            delete right;
            right = 0;
        }
    }
	void preorder(std::stringstream& aux) const{
        aux << value;
        if (left != 0) {
            aux << " ";
            left->preorder(aux);
        }
        if (right != 0) {
            aux << " ";
            right->preorder(aux);
        }
    }
    void inorder(std::stringstream& aux) const{
        if (left != 0){
            left ->inorder(aux);
            aux << " ";
        }
        aux << value;

        if (right != 0){
            aux << " ";
            right -> inorder(aux);
        }
    }
    void postorder(std::stringstream& aux) const{
        if (left != 0){
            left -> postorder(aux);
            aux << " ";
        }
        if (right != 0){
            right -> postorder(aux);
            aux << " ";
        }
        aux << value;
    }
    void lbl(std::stringstream& aux) const{
        aux << value;
        if (left != 0){
            aux << " ";
            left->lbl(aux);
        }
        if(right != 0){
            aux << " ";
            right -> lbl(aux);
        }
    }
    

	friend class BST<T>;
};

template <class T>
class BST {
private:
	TreeNode<T> *root;

public:
	BST(): root(0) {}
	~BST(){
        removeAll();
    }
	bool empty() const{
        return (root == 0);
    }
	void add(T val){
        if (root != 0) {
            if (!root->find(val)) {
                root->add(val);
            }
        } else {
            root = new TreeNode<T>(val);
        }
    }
	bool find(T val) const{
        if (root != 0) {
            return root->find(val);
        } else {
            return false;
        }
        return false;
    }
	void removeAll(){
        if (root != 0) {
            root->removeChilds();
        }
        delete root;
        root = 0;
    }
    std::string visit(){
        std::stringstream aux;
        aux << "[";
        if (!empty()) {
            root->preorder(aux);
        }
        aux << "]";
        aux << "\n";
        aux << "[";
        if (!empty()) {
            root->inorder(aux);
        }
        aux << "]";
        aux << "\n";
        aux << "[";
        if (!empty()) {
            root->postorder(aux);
        }
        aux << "]";
        aux << "\n";
        aux << "[";
        if (!empty()){
            root->lbl(aux);
        }
        aux << "]";
        
        return aux.str();
    }
    int height(){
        if (root) {
            return root->height();
        }
        return 0; 
    }
    std::string ancestors(T val){
        std::stringstream aux2;
        TreeNode<T> *aux = root;
    
        aux2 << "[";
        while (aux != nullptr && val != aux->value) {
            if (aux2.tellp() > 1)
                aux2 << " ";
            aux2 << aux->value;
            if (val < aux->value)
                aux = aux->left;
            else
                aux = aux->right;
        }
        
        if (aux == nullptr)
            return "[]";
        aux2 << "]";
        return aux2.str();
}

    
    int whatlevelamI (T val){
        TreeNode<T> *aux;
        int level = 1;

        aux = root;
        while(val != aux->value){
            if (val < aux->value) {
                level ++;
                aux = aux->left;
            } else if (val > aux->value) {
                level++;
                aux = aux->right;
            }
        }
     return level;

    }

};
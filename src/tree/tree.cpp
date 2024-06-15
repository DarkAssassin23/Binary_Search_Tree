#ifndef TREE_CPP
#define TREE_CPP
#include <iostream>
#include <sstream>
#include <string>

#include "tree.h"

template <class T>
bst<T>::bst(void)
{
    root = nullptr;
}

template <class T>
bst<T>::bst(const bst<T> &original)
{
    copyTree(root, original.root);
}

template <class T>
bst<T>::~bst(void)
{
    destroy(root);
}

/*========================================*/
/*          Operator Overloads            */
/*========================================*/
template <class T>
void bst<T>::operator=(const bst<T> &original)
{
    if (&original == this)
        return; // ignore assigning self to self
    destroy(root);
    copyTree(root, original.root);
}

template <class T>
bool bst<T>::operator==(const bst<T> &t) const
{
    return toString() == t.toString();
}

template <class T>
bool bst<T>::operator!=(const bst<T> &t) const
{
    return toString() != t.toString();
}

template <class T>
std::ostream &operator<<(std::ostream &os, const bst<T> &t)
{
    os << t.toString();
    return os;
}

/*========================================*/
/*           Public Functions             */
/*========================================*/
template <class T>
bool bst<T>::search(T &value) const
{
    return binarySearch(root, value);
}

template <class T>
bool bst<T>::insert(T &item)
{
    return insertItem(root, item);
}

template <class T>
void bst<T>::print(void) const
{
    printTree(root);
}

template <class T>
bool bst<T>::isEmpty(void) const
{
    return root == nullptr;
}

template <class T>
bool bst<T>::deleteItem(T &value)
{
    return Delete(root, value);
}

template <class T>
bool bst<T>::printOne(T &value) const
{
    return printOneNode(root, value);
}

template <class T>
bool bst<T>::update(T &value, T newValue)
{
    return deleteItem(value) ? insert(newValue) : false;
}

template <class T>
std::string bst<T>::toString(void) const
{
    return getString(root);
}

/*========================================*/
/*           Private Functions            */
/*========================================*/
template <class T>
void bst<T>::copyTree(TreeNode<T> *&dst, const TreeNode<T> *src)
{
    if (src != nullptr)
    {
        dst = new TreeNode<T>;
        dst->data = src->data;
        dst->left = nullptr;
        dst->right = nullptr;
        copyTree(dst->left, src->left);
        copyTree(dst->right, src->right);
    }
}

template <class T>
bool bst<T>::binarySearch(TreeNode<T> *root, T &value) const
{
    if (root == nullptr)
        return false;
    else if (root->data == value)
    {
        value = root->data;
        return true;
    }
    else if (root->data <= value)
        return (binarySearch(root->right, value));
    else
        return (binarySearch(root->left, value));
}

template <class T>
bool bst<T>::insertItem(TreeNode<T> *&root, T &value)
{
    if (root == nullptr)
    {
        root = new TreeNode<T>;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    else if (root->data > value)
        return insertItem(root->left, value);
    else if (root->data < value)
        return insertItem(root->right, value);
    else
        return false;
}

template <class T>
void bst<T>::printTree(TreeNode<T> *root) const
{
    if (root != nullptr)
    {
        printTree(root->left);
        std::cout << root->data << " ";
        printTree(root->right);
    }
}

template <class T>
std::string bst<T>::getString(TreeNode<T> *root) const
{
    std::ostringstream os;
    if (root != nullptr)
    {
        os << getString(root->left);
        os << root->data << " ";
        os << getString(root->right);
    }
    return os.str();
}

template <class T>
void bst<T>::destroy(TreeNode<T> *&root)
{
    if (root != nullptr)
    {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

template <class T>
bool bst<T>::printOneNode(TreeNode<T> *root, T &value) const
{
    if (root == nullptr)
        return false;
    else if (root->data == value)
    {
        std::cout << root->data;
        return true;
    }
    else if (root->data >= value)
        return printOneNode(root->left, value);
    else
        return printOneNode(root->right, value);
}

template <class T>
bool bst<T>::Delete(TreeNode<T> *&root, T &value)
{
    if (root != nullptr)
    {
        if (root->data < value)
            return Delete(root->right, value);
        else if (root->data > value)
            return Delete(root->left, value);
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                value = root->data;
                delete root;
                root = nullptr;
                return true;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                TreeNode<T> *temp = root;
                root = root->right;
                value = temp->data;
                delete temp;
                return true;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                TreeNode<T> *temp = root;
                root = root->left;
                value = temp->data;
                delete temp;
                return true;
            }
            else
            {
                value = root->data;
                root->data = findMax(root->left);
                Delete(root->left, root->data);
                return true;
            }
        }
    }
    return false;
}

template <class T>
T bst<T>::findMin(TreeNode<T> *root) const
{
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

template <class T>
T bst<T>::findMax(TreeNode<T> *root) const
{
    while (root->right != nullptr)
        root = root->right;
    return root->data;
}

#endif /* TREE_CPP */

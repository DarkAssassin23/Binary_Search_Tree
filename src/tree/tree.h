#ifndef TREE_H
#define TREE_H
#include "node.h"

/// @class bst
/// @brief A template class for a Binary Search Tree
template <class T>
class bst
{
  public:
    /// @brief Default constructor
    bst(void);

    /// @brief Copy constructor to set a new bst given an existing one
    /// @param original The bst we will use to set our values to equal
    bst(const bst<T> &original);

    /// @brief Destructor
    ~bst(void);

    /// @brief Equals operator overload to set one bst equal to another
    /// @param original The bst we will be set equal to
    void operator=(const bst<T> &original);

    /// @brief Equals equals operator overload to check if two bst's are equal
    /// @param t The bst to compare
    bool operator==(const bst<T> &t) const;

    /// @brief Not equals operator overload to see if two bst's are not equal
    /// @param t The bst to compare
    bool operator!=(const bst<T> &t) const;

    /// @brief Check if the value is in the tree
    /// @param value The thing to search the bst for
    /// @return If the provided value is in the bst
    bool search(T &value) const;

    /// @brief Insert the given value in the bst (if it doesn't already exist)
    /// @param value The value to insert into the bst
    /// @return If successful
    bool insert(T &value);

    /// @brief Print out the contents of the bst in ascending order
    void print(void) const;

    /// @brief Is the bst empty
    /// @return If the bst is empty
    bool isEmpty(void) const;

    /// @brief Remove the given value from the bst
    /// @param value The value to remove from the bst
    /// @return If the value was removed
    bool deleteItem(T &value);

    /// @brief Print a single element from the bst
    /// @param value The value to print
    /// @return If the value was present and printed
    bool printOne(T &value) const;

    /// @brief Update the given value with a new value
    /// @param value The value to be updated
    /// @param newValue The new value to be set
    /// @return If the original value exists and was updated
    bool update(T &value, T newValue);

    /// @brief Get the bst as a string
    /// @return The bst as a string
    std::string toString(void) const;

  private:
    /// @brief Copy the source bst to the destination bst
    /// @param dst Root of the bst to copy the data to
    /// @param src Root of the source bst to copy the data from
    void copyTree(TreeNode<T> *&dst, const TreeNode<T> *src);

    /// @brief Search the tree for the given value
    /// @param root The current root of the tree
    /// @param value The value being searched for
    /// @return If the value is in the tree
    bool binarySearch(TreeNode<T> *root, T &value) const;

    /// @brief Insert a single item into the tree
    /// @param root The current root of the tree
    /// @param value The value to be inserted
    /// @return If successful
    bool insertItem(TreeNode<T> *&root, T &value);

    /// @brief Print the bst based on the current root
    /// @param root The current root of the tree
    void printTree(TreeNode<T> *root) const;

    /// @brief Get the value of the bst from the root as a string
    /// @param root the current root of the tree
    std::string getString(TreeNode<T> *root) const;

    /// @brief Destroy the left and right sides of the bst given the root
    /// @param The current root of the tree
    void destroy(TreeNode<T> *&root);

    /// @brief Print a single element from the bst
    /// @param root The current root of the tree
    /// @param value The value to print
    /// @return If the value was present and printed
    bool printOneNode(TreeNode<T> *root, T &value) const;

    /// @brief Delete the value from the tree
    /// @param root The current root of the tree
    /// @param value The value to be deleted
    bool Delete(TreeNode<T> *&root, T &value);

    /// @brief Get the minimum value in the bst
    /// @return The minimum value in the bst
    T findMin(TreeNode<T> *root) const;

    /// @brief Get the minimum value in the bst
    /// @return The minimum value in the bst
    T findMax(TreeNode<T> *root) const;

    TreeNode<T> *root; //!< The root node of the bst
};

#include "tree.cpp"
#endif /* TREE_H */

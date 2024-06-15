#ifndef NODE_H
#define NODE_H

template <class T>
class TreeNode
{
  public:
    /// @brief Default constructor
    TreeNode(void);

    /// @brief Copy constructor to set a new TreeNode given an existing one
    /// @param value The TreeNode we will use to set our values to equal
    TreeNode(const T &value);

    TreeNode<T> *left;  //!< Pointer to the left side of the tree
    TreeNode<T> *right; //!< Pointer to the right side of the tree
    T data;             //!< Data contained in this node
};

template <class T>
TreeNode<T>::TreeNode(void)
{
    right = nullptr;
    left = nullptr;
}

template <class T>
TreeNode<T>::TreeNode(const T &value)
{
    left = nullptr;
    right = nullptr;
    data = value;
}

#endif /* NODE_H */

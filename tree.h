#ifndef ___________TREE_H
#define ___________TREE_H
#include <iostream>
template <class T>
class Tree
{
    struct Node
    {
        T item;
        Node *son;
        Node *brother;

        Node(T i, Node *s = NULL, Node *b = NULL)
        {
            item = i;
            son = s;
            brother = b;
        }
    };
    Node *root;
public:
    Tree()
    {
        root = NULL;
    }

    ~Tree()
    {
        DeleteSubTree(root);
    }

    int GetHieght()
    {
        return GetHieght(root);
    }

    int GetNodesOnLevel(int level)
    {
        return GetNodesOnLevel(root, level);
    }

    void Add(const T& element)
    {
        Add(root, element);
    }

private:
    int GetHieght(Node *node);
    int GetNodesOnLevel(Node *node, int level);
    void DeleteSubTree(Node *node);
    void Add(Node *&node, const T &element);
};

template <class T>
void Tree<T>::DeleteSubTree(Node *node)
{
    if(node)
    {
        DeleteSubTree(node->son);
        DeleteSubTree(node->brother);
        delete node;
    }
}

template <class T>
int Tree<T>::GetHieght(Node *node)
{
    if(node == NULL) {return 0;}
    int max = 0;
    for (Node *cur = node->son; cur; cur = cur->brother)
    {
        int curHeight = GetHieght(cur);
        if (curHeight > max)
        {
            max = curHeight;
        }
    }
    return max + 1;
}

template <class T>
int Tree<T>::GetNodesOnLevel(Node *node, int level)
{
    if(node == NULL)
    {
        return 0;
    }
    if (level <= 0)
    {
        return 0;
    }

    return GetNodesOnLevel(node->son, level - 1) + (level == 1) + GetNodesOnLevel(node->brother, level);
}

template <class T>
void Tree<T>::Add(Node *&node, const T &element)
{
    if (node == NULL)
    {
        node = new Node(element);
    }
    else if (element < node->item)
    {
        Add(node->son, element);
    }
    else
    {
        Add(node->brother, element);
    }
}
#endif //___________TREE_H

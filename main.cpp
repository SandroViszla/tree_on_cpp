#include "tree.h"

int main() {
    Tree<int> tree;

    tree.Add(12);
    tree.Add(5);
    tree.Add(3);
    tree.Add(10);
    tree.Add(7);
    tree.Add(11);
    tree.Add(6);
    tree.Add(9);

    std::cout<< "Высота дерева " << tree.GetHieght() << std::endl;
    std::cout<< "На третьем уровне находится " << tree.GetNodesOnLevel(3) << " элемента" << std::endl;

    return 0;
}

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "tree.h"

int main(void)
{

    bst<int> tree;
    int number = 0;
    srand(time(NULL));

    assert(tree.isEmpty() == true);
    std::cout << "INSERTING\n";
    for (int i = 0; i < 15; i++)
    {
        number = rand() % 100;
        std::cout << "Atttempting to insert " << number << ". ";
        if (tree.insert(number))
            std::cout << "Success.\n";
        else
            std::cout << number << " already exists\n";
    }
    std::cout << "\nInitial Tree: ";
    tree.print();
    std::cout << "\n";

    int newNum = 81;
    while (tree.search(newNum))
        newNum++;

    std::cout << "Changing ";
    tree.printOne(number);
    std::cout << " to " << newNum << "\n";

    assert(tree.update(number, newNum) == true);
    assert(tree.update(number, 43) == false);
    std::cout << "Updated Tree: " << tree.toString() << "\n\n";

    bst<int> tree2(tree);
    bst<int> tree3 = tree;
    assert(tree2 == tree);
    assert(tree3 == tree);

    int array[16] = { 40, 23, 1,  5,  28, 84, 81, 80,
                      97, 90, 47, 56, 70, 71, 79, 90 };
    for (int i = 0; i < 16; i++)
    {
        printf("%d is%s in the tree", array[i],
               tree.search(array[i]) ? "" : " not");
        if (tree.deleteItem(array[i]))
            std::cout << ". Deleted... ";
        printf("\n");
    }
    assert(tree2 != tree);
    assert(tree2 == tree3);
    assert(tree3 != tree);

    std::cout << "\nFinal Tree: " << tree << "\n";

    return 0;
}

#include <iostream>
#include "Lazy_BST.h"
#include "BST.h"
#include <math.h>
using namespace std;

int main() {
    BST<int> tempBST;
    for (int i = 10; i != 0; i--) {
        tempBST.insert(i);
    }

    tempBST.print2D(tempBST.getRoot(),0);

    return 0;
}

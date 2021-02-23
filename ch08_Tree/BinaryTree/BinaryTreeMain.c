#include <stdio.h>
#include "BinaryTree.h"

int main(void) {

    BTreeNode * bt1 = MakeBTreeNode();      // Node bt1 made
    BTreeNode * bt2 = MakeBTreeNode();      // Node bt2 made
    BTreeNode * bt3 = MakeBTreeNode();      // Node bt3 made
    BTreeNode * bt4 = MakeBTreeNode();      // Node bt4 made

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);

    // bt1�� ���� �ڽ� ����� ������ ���
    printf("%d \n", GetData(GetLeftSubTree(bt1)));

    // bt1�� ���� �ڽ� ����� ���� �ڽ� ����� ������ ���
    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

    return 0;
}
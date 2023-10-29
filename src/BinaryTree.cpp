#include "BinaryTree.h"
void Recursion_DLR(binarynode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->c;
    Recursion_DLR(root->lchild);
    Recursion_DLR(root->rchild);
}
void Recursion_LDR(binarynode *root)
{
    if (root == NULL)
    {
        return;
    }
    Recursion_LDR(root->lchild);
    cout << root->c;
    Recursion_LDR(root->rchild);
}
void Recursion_LRD(binarynode *root)
{
    if (root == NULL)
    {
        return;
    }
    Recursion_LRD(root->lchild);
    Recursion_LRD(root->rchild);
    cout << root->c;
}
void GetTreeLeafNumber(binarynode *root, int &number)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        number++;
    }
    GetTreeLeafNumber(root->lchild, number);
    GetTreeLeafNumber(root->rchild, number);
}
int GetDepth(binarynode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int Ldepth = GetDepth(root->lchild);
    int Rdepth = GetDepth(root->rchild);
    return (Ldepth > Rdepth ? Ldepth + 1 : Rdepth + 1);
}

void BinaryTreeTest(void)
{
    // 创建节点
    binarynode node1 = {'A', NULL, NULL};
    binarynode node2 = {'B', NULL, NULL};
    binarynode node3 = {'C', NULL, NULL};
    binarynode node4 = {'D', NULL, NULL};
    binarynode node5 = {'E', NULL, NULL};
    binarynode node6 = {'F', NULL, NULL};
    binarynode node7 = {'G', NULL, NULL};
    binarynode node8 = {'H', NULL, NULL};
    // 建立节点关系
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    int number = GetDepth(&node1);
    cout << number << endl;
}
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
// 定义二叉树节点
class binarynode
{
public:
    char c;             // 节点数据域
    binarynode *lchild; // 左孩子
    binarynode *rchild; // 右孩子
};
void Recursion_DLR(binarynode *root);
void Recursion_LDR(binarynode *root);
void Recursion_LRD(binarynode *root);
void GetTreeLeafNumber(binarynode *root, int &number);
void BinaryTreeTest(void);
int GetDepth(binarynode *root);
binarynode *BinaryTreeCopy(binarynode *root);
void BinaryTreeRelease(binarynode *root);
#endif
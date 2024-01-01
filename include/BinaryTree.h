#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
// ����������ڵ�
class binarynode
{
public:
    char c;             // �ڵ�������
    binarynode *lchild; // ����
    binarynode *rchild; // �Һ���
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
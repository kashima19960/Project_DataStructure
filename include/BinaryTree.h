#pragma once
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
void BinaryTreeTest(void);
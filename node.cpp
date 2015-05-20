#include <iostream>
#include <cstdlib>
#include "tree.hh"
#include "benchmark.hh"

CNode::~CNode()
{
    if(left)
        delete left;
    left=NULL;

    if(right)
        delete right;
    right=NULL;
}

void CNode::preorder()const
{
    if(this!=NULL)
    {
        std::cout << value << " ";
        left->preorder();
        right->preorder();
    }
}

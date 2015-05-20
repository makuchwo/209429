#include "tree.hh""
#include <iostream>

void CTree::add(int k)
{
  CNode *w=new CNode();
  w->value=k;

  CNode *tmp=root;

  if(!tmp)
    root=w;
  else
    while(1)
      if(k<tmp->value)
      {
        if(!tmp->left)
        {
          tmp->left=w;
          break;
        } else
        tmp=tmp->left;
      } else {
        if(!tmp->right)
        {
          tmp->right=w;
          break;
        } else
        tmp=tmp->right;
      }
  w->up=tmp;
  w->left=NULL;
  w->right=NULL;
}

void CTree::fill_random(int x)
{
   int k;
   start_timer();
    for(int i=0; i<x; i++)
    {
        k = 1 + rand() % 9;
        this->add(k);
    }
    stop_timer();
    put_time_to_file(x);
}

void CTree::preorder()const
{
    if(root!=NULL)
    {
       root->preorder();
    }
}

CNode* CTree::find(int k)
{
    int r=0,l=0;
  CNode *tmp=root;
  while(tmp && tmp->value!=k)
  {
      if(k<tmp->value)
      {
        tmp=tmp->left;
        l++;
      } else {
        tmp=tmp->right;
        r++;
      }
  }
//  std::cout << "Wezel znajduje sie po " << l << " przejsciach w lewo i " << r << " przejsciach w prawo" << std::endl;
  return tmp;
}

CNode* CTree::get_min()
{
   CNode* tmp=new CNode();
   tmp=root;
  if(tmp)
  {
    while(tmp->left)
    tmp = tmp->left;
  }

  return tmp;
}

CNode* CTree::get_max()
{
    CNode* tmp=new CNode();
    tmp=root;
    if(tmp)
    {
        while(tmp->right)
            tmp=tmp->right;
    }
    return tmp;
}


int CTree::benchmark_add()
{
        for(int i=1;i<=10;i++)
        {
            this->fill_random(i);
        }
        for(int i=10;i<100; i=i+10)
        {
            this->fill_random(i);
        }
        for(int i=100;i<1000; i=i+100)
        {
         this->fill_random(i);
        }
        for(int i=1000;i<10000; i=i+1000)
        {
            this->fill_random(i);
        }
}

void CTree::find_random(int quantity)
{
    start_timer();
        for(int i=0; i<quantity; i++)
        {
            find(quantity);
        }
    stop_timer();
    put_time_to_file(quantity);
}


int CTree::benchmark_find()
{

        for(int i=1;i<=10;i++)
        {

            find_random(i);
        }

        for(int i=10;i<100; i=i+10)
        {
            find_random(i);
        }

        for(int i=100;i<1000; i=i+100)
        {
            find_random(i);
        }

        for(int i=1000;i<10000; i=i+1000)
        {
            find_random(i);
        }
         for(int i=10000;i<100000; i=i+10000)
        {
            find_random(i);
        }
        for(int i=100000;i<1000000; i=i+100000)
        {
            find_random(i);
        }
        for(int i=1000000;i<10000000; i=i+1000000)
        {
            find_random(i);
        }

}

    CTree::CTree()
    {
        root=NULL;
    }

    CTree::~CTree()
    {
        if(root!=NULL)
            delete root;
        root=NULL;
    }

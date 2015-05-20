#include <iostream>
#include "Red_black_tree.hh"
#include "Red_black_node.hh"


CRed_Black_Tree::CRed_Black_Tree()
{
  S.color = 'B';
  S.up    = &S;
  S.left  = &S;
  S.right = &S;
  root    = &S;
}

CRed_Black_Tree::~CRed_Black_Tree() {}

CRed_Black_Node* CRed_Black_Tree::find(int k)
{
    int l=0,r=0;
  CRed_Black_Node* tmp=root;

  while((tmp!=&S) && (tmp->value!=k))
    if(k<tmp->value)
    {
        tmp=tmp->left;
        l++;
    } else {
      tmp=tmp->right;
      r++;
    }
  if(tmp==&S)
    return NULL;

  //std::cout << "Wezel znajduje sie po " << l << " przejsciach w lewo i " << r << " przejsciach w prawo" << std::endl;
  return tmp;
}

CRed_Black_Node* CRed_Black_Tree::min(CRed_Black_Node *r)
{
  if(r!= &S)
    while(r->left!=&S)
        r=r->left;
  return r;
}

CRed_Black_Node* CRed_Black_Tree::max(CRed_Black_Node *r)
{
  if(r!= &S)
    while(r->right!=&S)
        r=r->right;
  return r;
}


void CRed_Black_Tree::rotate_left(CRed_Black_Node * prev)
{
  CRed_Black_Node* next=prev->right;
  CRed_Black_Node* tmp;

  if(next!=&S)
  {
    tmp=prev->up;
    prev->right=next->left;

    if(prev->right!=&S)
        prev->right->up=prev;

    next->left=prev;
    next->up=tmp;
    prev->up=next;

    if(tmp!=&S)
    {
      if(tmp->left==prev)
        tmp->left=next;
      else
        tmp->right=next;
    } else
        root=next;
  }
}

void CRed_Black_Tree::rotate_right(CRed_Black_Node * prev)
{
  CRed_Black_Node* next=prev->left;
  CRed_Black_Node* tmp;

  if(next!=&S)
  {
    tmp=prev->up;
    prev->left=next->right;
    if(prev->left!=&S)
        prev->left->up=prev;

    next->right=prev;
    next->up=tmp;
    prev->up=next;

    if(tmp!=&S)
    {
      if(tmp->left==prev)
        tmp->left=next;
      else
        tmp->right=next;
    }
    else
        root=next;
  }
}

void CRed_Black_Tree::add(int k)
{
  CRed_Black_Node *w, *uncle;

  w = new CRed_Black_Node;
  w->left  = &S;
  w->right = &S;
  w->up    = root;
  w->value   = k;

  if(w->up==&S)
    root=w;
  else
  while(1)
  {
    if(k<w->up->value)
    {
      if(w->up->left==&S)
      {
        w->up->left=w;
        break;
      }
      w->up=w->up->left;
    }
    else
    {
      if(w->up->right==&S)
      {
        w->up->right=w;
        break;
      }
      w->up=w->up->right;
    }
  }
  w->color='R';
  while((w != root) && (w->up->color == 'R'))
  {
    if(w->up==w->up->up->left)
    {
      uncle=w->up->up->right;

      if(uncle->color=='R')  // 1)
      {
        w->up->color = 'B';
        uncle->color = 'B';
        w->up->up->color = 'R';
        w = w->up->up;
        continue;
      }

      if(w==w->up->right) // 3)
      {
        w = w->up;
        rotate_left(w);
      }

      w->up->color = 'B'; // 2)
      w->up->up->color ='R';
      rotate_right(w->up->up);
      break;
    }
    else
    {
      uncle = w->up->up->left;

      if(uncle->color == 'R') // 1)
      {
        w->up->color = 'B';
        uncle->color = 'B';
        w->up->up->color = 'R';
        w = w->up->up;
        continue;
      }

      if(w == w->up->left) // 3)
      {
        w = w->up;
        rotate_right(w);
      }

      w->up->color = 'B'; // 2)
      w->up->up->color = 'R';
      rotate_left(w->up->up);
      break;
    }
  }
  root->color = 'B';
}

void CRed_Black_Tree::fill_random(int x)
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

void CRed_Black_Tree::find_random(int quantity)
{
    start_timer();
        for(int i=0; i<quantity; i++)
        {
            find(quantity);
        }
    stop_timer();
    put_time_to_file(quantity);
}


int CRed_Black_Tree::benchmark_add()
{
        for(int i=1;i<=10;i++)
        {
            fill_random(i);
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
         for(int i=10000;i<100000; i=i+10000)
        {
            this->fill_random(i);
        }
        for(int i=100000;i<1000000; i=i+100000)
        {
            this->fill_random(i);
        }
}


int CRed_Black_Tree::benchmark_find()
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

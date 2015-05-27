#include "queue.hh"
#include <iostream>

/*!
 *\file queue.cpp
 *\brief implementuje zdefiniowana klase kolejki
 */

void queue::push(int element)
{
  queue_node *tmp = new queue_node();

  tmp->next=NULL;
  tmp->data=element;

  if(last)
    last->next=tmp;
  else
    first=tmp;
  last=tmp;
}

void queue::pop()
{
  if(first)
  {
    queue_node* tmp=first;
    first=first->next;
    if(!first)
        last = NULL;
    delete tmp;
  }
}

void queue::print()const
{
    queue_node *tmp=first;
    if(!first)
        std::cout << std::endl;
    else
    while(tmp->next!=NULL)
    {
        std::cout << tmp->data << " ";
        tmp=tmp->next;
    }
    std::cout << std::endl;
}

queue::~queue()
{
    while(first)
        pop();
}

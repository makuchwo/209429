#include "list.hh"
#include <iostream>
#include <cstdlib>

CList::CList()
{
    next=NULL;
}

CList::~CList()
{
    while(next!=NULL)
    {
        next=next->next;
        delete next;
    }
}

void CList::push(int element)
{
    CList *tmp=new CList;
    tmp->value=element;
    tmp->next=next;
    next=tmp;
}

int CList::pop()
{
    CList *tmp_list=next;
    int tmp_value;
    if(next==NULL)
        return -1;
        else
            next=tmp_list->next;
            tmp_value=tmp_list->value;
            delete tmp_list;
            return tmp_value;
}

void CList::print()const
{
    CList *tmp=next;
    while(tmp!=NULL)
    {
        std::cout << tmp->value << " ";
        tmp=tmp->next;
    }
    std::cout << std::endl;
}

int CList::get_value(int i)const
{
     CList *tmp=next;
    for(int j=0; j<i; j++)
    {
        tmp=tmp->next;
    }
    if(tmp==NULL) return -1;
    else
    return tmp->value;
}

int& CList::get_value(int i)
{
    int error=-1;
     CList *tmp=next;
    for(int j=0; j<i; j++)
    {
        tmp=tmp->next;
    }
    if(tmp==NULL) return error;
    else
    return tmp->value;
}

void CList::swap(int i, int j)
{
    int tmp_vale_1=get_value(i);
    int tmp_vale_2=get_value(j);
    get_value(i)=tmp_vale_2;
    get_value(j)=tmp_vale_1;
}

bool CList::is_empty()
{
    if(next==NULL) return true;
    else
        return false;
}

int CList::get_size()
{
    CList *tmp=next;
    int i=0;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        i++;
    }
    return i;
}

void CList::pull(int i)
{
    for(int j=0; j<i; j++)
    {
        push(rand()%10);
    }
}

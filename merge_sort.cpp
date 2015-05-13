#include <iostream>
#include "list.hh"
#include "merge_sort.hh"


void CMergeSort::sorting(CList* list, int left, int right)
{
    int middle, iter1, iter2, i;
    int *tmp=new int[list->get_size()+1];

    middle =( left + right + 1 )/2;

    if(middle-left>1) sorting(list,left,middle-1);
    if(right-middle>0) sorting(list,middle,right);

    iter1=left;
    iter2=middle;
    for(i=left;i<=right;i++)
    {
         if((iter1==middle) || ((iter2<=right) && ( list->get_value(iter1)> list->get_value(iter2))))
            tmp[i]=list->get_value(iter2++);
         else
             tmp[i]=list->get_value(iter1++);
    }
    for(i=left;i<=right;i++)
    {
        list->get_value(i)=tmp[i];
    }
    delete [] tmp;
}

    void CMergeSort::sort(CList* list, int left, int right)
    {
        start_timer();
        sorting(list,left,right);
        stop_timer();
        put_time_to_file(list->get_size());
    }

    void CMergeSort::benchmarking(CList *list)
    {
        for(int i=1;i<=10;i++)
        {
            list->pull(1);
            sort(list,0,i-1);
        }
        for(int i=10;i<100; i=i+10)
        {
            list->pull(10);
            sort(list,0,i-1);
        }

        for(int i=100;i<1000; i=i+100)
        {
            list->pull(100);
            sort(list,0,i-1);
        }

        for(int i=1000;i<10000; i=i+1000)
        {
            list->pull(1000);
            sort(list,0,i-1);
        }
    }


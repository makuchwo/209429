#include "quick_sort.hh"

void CQuickSort::sorting(CList *list, int left, int right)
{
    int i=left;
    int j=right;
    int piwot=list->get_value((left+right)/2);
        do
        {
            while(list->get_value(i)<piwot)
                i++;
            while(list->get_value(j)>piwot)
                j--;

            if(i<=j)
            {
                list->swap(i,j);
                i++;
                j--;
            }
        }while(i<=j);
    if(left<j)   sorting(list,left,j);
    if(right>i)  sorting(list,i,right);
}

void CQuickSort::sort(CList *list, int left, int right)
{
    start_timer();
    sorting(list,left,right);
    stop_timer();
    put_time_to_file(list->get_size());
}


   void CQuickSort::benchmarking(CList *list)
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

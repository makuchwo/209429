#include "heap_sort.hh"

 void CHeapSort::build_heap(CList *list,int last)
   {
        for(int i=last/2; i>0; i--)
           down_heap(list,i,last);
   }

    void CHeapSort::down_heap(CList *list,int parent, int last)
    {
        int child=2*parent;
        while(child<=last)
        {
            if(child+1<=last and list->get_value(child+1)>list->get_value(child))
                child++;
            if(list->get_value(child)>list->get_value(parent))
                list->swap(child,parent);
            parent=child;
            child=2*parent;
        }
    }

    void CHeapSort::up_heap(CList *list, int last)
    {
        int parent=1, child=2;
        while(child<=last)
        {
            if(child+1<=last and list->get_value(child)<list->get_value(child+1))
                child++;

                list->swap(parent,child);
                parent=child;
                child=2*parent;
        }
        while(parent>1 and list->get_value(parent)>list->get_value(parent/2))
        {
            list->swap(parent,parent/2);
            parent=parent/2;
        }
    }
    void CHeapSort::sorting(CList *list,int useless,int last)
    {
        build_heap(list,last);
        while(last>1)
        {
            list->swap(1,last);
            last--;
            up_heap(list,last);
        }
    }

    void CHeapSort::sort(CList *list, int useless, int last)
    {
        start_timer();
        sorting(list,useless,last);
        stop_timer();
        put_time_to_file(list->get_size());
    }

 void CHeapSort::benchmarking(CList *list)
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


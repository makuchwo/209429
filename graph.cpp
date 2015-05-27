#include "graph.hh"
#include "queue.hh"
#include "benchmark.hh"
#include <iostream>

/*!
 *\file graph.cpp
 *\brief implementuje zdefiniowana klase grafu
 */


   CGraph::CGraph(int v, int e) : V(v), E(e)
    {
        ListV = new CNode[V];
        ListE = new CEdge[E];

        matrix = new int*[V];
        for(int i=0; i<V; i++)
        {
            matrix[i] = new int[V];
        }

        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                matrix[i][j]=0;

                visited = new bool[v];
    }


    CGraph::~CGraph()
    {
        delete [] ListV;
        delete [] ListE;


        for(int i=0; i<V; i++)
        {
            delete [] matrix[i];
        }
        delete [] matrix;

        delete [] visited;
    }

    void CGraph::set_graph(int edge1, int verticle1, int verticle2)
    {
        ListV[verticle1].value=verticle1;
        ListV[verticle2].value=verticle2;
        ListE[edge1].prev=&ListV[verticle1];
        ListE[edge1].next=&ListV[verticle2];
        matrix[verticle1][verticle2]=1;
       // matrix[verticle2][verticle1]=1;
    }

       void CGraph::print_matrix()const
       {
            for(int i=0; i <V; i++)
            {
                for(int j=0; j<V; j++)
                std::cout <<  matrix[i][j] << " ";
                std::cout << std::endl;
            }
       }

    void CGraph::DFSing(int v)
    {
        visited[v]=1;
        std::cout << v << " ";

        for(int i=0; i<V; i++)
        {
            if(matrix[v][i]==1 and visited[i]==0)
                DFSing(i);
        }
    }

    void CGraph::DFS(int v)
    {
        start_timer();
            DFSing(v);
        stop_timer();
        put_time_to_file(v);
    }

    void CGraph::BFS(int v)
    {
        start_timer();
        int i;
        queue_node *q;
        queue *x=new queue;

        x->push(v);
        visited[v]=true;

        while(x->first)
        {
            v=x->first->data;
            x->pop();
            std::cout << v << " ";
            for(i=0; i<V; i++)
            if((matrix[v][i]==1) && !visited[i])
            {
                x->push(i);
                visited[i]=true;
            }
        }
        x->~queue();
        std::cout << std::endl;
        stop_timer();
        put_time_to_file(v);
    }


    CEdge* CGraph::search(int key)
    {
        CEdge *tmp = new CEdge();

        for(int i=0; i<E; i++)
        {
            if(key!=ListE[i].prev->value && key!=ListE[i].next->value)
            {
                tmp[i]=ListE[i];
                std::cout << tmp[i].next->value << std::endl;
                std::cout << tmp[i].prev->value << std::endl;
            }
            std::cout << std::endl;
        }
        return tmp;
    }



CGraph* CGraph::make_random_graph(int sizeV, int sizeE)
{
    CGraph *G = new CGraph(sizeV,sizeE);
    int k,l;
    for(int i=0; i<sizeV; i++)
    {
        do
        {
            k=rand()%10;
        }while(k>=sizeV);

        do
        {
            l=rand()%10;
        }while(l>=sizeV);
       G->set_graph(i,k,l);
    }
    *this=*G;
    return G;
}



   void CGraph::benchmarking_DFS()
      {
         make_random_graph(10000,10000);

        for(int i=1;i<=10;i++)
        {
            DFS(i);
        }
        for(int i=10;i<100; i=i+10)
        {
            DFS(i);
        }

        for(int i=100;i<1000; i=i+100)
        {
            DFS(i);
        }

        for(int i=1000;i<10000; i=i+1000)
        {
            DFS(i);
        }
    }


 void CGraph::benchmarking_BFS()
      {
         make_random_graph(10000,10000);

        for(int i=1;i<10;i++)
        {
            BFS(i);
        }

        for(int i=10;i<100; i=i+10)
        {
            BFS(i);
        }

        for(int i=100;i<1000; i=i+100)
        {
            BFS(i);
        }

        for(int i=1000;i<10000; i=i+1000)
        {
            BFS(i);
        }
    }

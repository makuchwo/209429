#include "graph.hh"
#include "queue.hh"
#include "stack.hh"
//#include "global.h"
#include <iostream>
#include <fstream>
#include <windows.h>

/*!
 *\file graph.cpp
 *\brief implementuje zdefiniowana klase grafu
 */


   void CGraph::save_matrix(std::fstream& file)const
   {
          for(int i=0; i <V; i++)
            {
                for(int j=0; j<V; j++)
                file <<  matrix[i][j] << " ";
                file << std::endl;
            }
   }

   CGraph::CGraph(int v, int e) : V(v), E(e)
    {
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

        for(int i=0; i<V; i++)
        {
            delete [] matrix[i];
        }
        delete [] matrix;
        delete [] visited;
    }

    void CGraph::set_graph(int verticle1, int verticle2)
    {
        matrix[verticle1][verticle2]=1;
        matrix[verticle2][verticle1]=1;
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

    void CGraph::DFS(int v)
    {
        visited[v]=1;
        std::cout << v << " ";

        for(int i=0; i<V; i++)
        {
            if(matrix[v][i]==1 and visited[i]==0)
             DFS(i);
        }
    }

    void CGraph::BFS(int v)
    {
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
    }




bool CGraph::BFSPath(int start, int meta, Lista<int> *L)
{
    queue k;
    bool found;
    int  v, u, i;

    for(int i=0; i<V; i++)
        visited[i]=0;

        int *P=new int[V];
        P[start]=-1;

        k.push(start);

        visited[start]=true;
        found=false;

    while(!k.is_empty())
    {
        v=k.front();
        k.pop();

        if(v==meta)
        {
            found=true;
            break;
        }


    for(int i=1; i<V; i++)
        if(!visited[i] && matrix[v][i]==1)
        {
            P[i] = v;
            k.push(i);
            visited[i] = true;
        }
    }

    if(!found)
    {
        std::cout << "sciezka nie zostala odnaleziona" << std::endl;
        return false;
//              MessageBox(hwnd,"Sciezka nie zostala odnaleziona","Blad",MB_ICONINFORMATION);
    }
    else
        while(v>-1)
        {
            L->push(v);
           // std::cout << v << " ";
            v=P[v];
        }
        L->wyswietl();
return true;

}

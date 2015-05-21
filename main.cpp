#include <iostream>

using namespace std;

class CNode {
public:
    int value;
};

class CEdge {
public:
    CNode *prev;
    CNode *next;
};

class CGraph {
public:
    int V,E;
    CNode *ListV;
    CEdge *ListE;

public:
    CGraph(int v, int e);
    void set_graph(int edge1, int vertice1, int vertice2);
    CEdge* search(int key);
};

   CGraph::CGraph(int v, int e) : V(v), E(e)
    {
        ListV = new CNode[V];
        ListE = new CEdge[E];
    }

    void CGraph::set_graph(int edge1, int verticle1, int verticle2)
    {
        ListV[verticle1].value=verticle1;
        ListV[verticle2].value=verticle2;
        ListE[edge1].prev=&ListV[verticle1];
        ListE[edge1].next=&ListV[verticle2];
    }

    CEdge* CGraph::search(int key)
    {
        CEdge *tmp = new CEdge();

        for(int i=0; i<E; i++)
        {
            if(key!=ListE[i].prev->value && key!=ListE[i].next->value)
            {
                tmp[i]=ListE[i];
                cout << tmp[i].next->value << endl;
                cout << tmp[i].prev->value << endl;
            }
            cout << endl;
        }
        return tmp;
    }

int main()
{
  CGraph *G1 = new CGraph(9,11);
    G1->set_graph(0,0,1);
    G1->set_graph(1,0,2);
    G1->set_graph(2,1,3);
    G1->set_graph(3,1,4);
    G1->set_graph(4,3,6);
    G1->set_graph(5,4,6);
    G1->set_graph(6,2,4);
    G1->set_graph(7,2,6);
    G1->set_graph(8,2,5);
    G1->set_graph(9,5,7);
    G1->set_graph(10,7,8);
    G1->set_graph(11,3,3); // zapomnialem o tym, niech bedzie to krawedz 11...

// SEARCH WYSWIETLA KRAWEDZIE PRZEZ KTORE PRZESZEDL
    G1->search(8);
    return 0;
}

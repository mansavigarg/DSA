#include <iostream>
#include <list>
using namespace std;

// ( Directed Graph and Undirected Graph ) --> Unweighted

class Graph {
    public:
        unordered_map<int, list<int>> adjList;
        void addEdge(int u, int v, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed
            if(direction == 1){
                // u se v ki trf ek edge hai ==== u -> v
                adjList[u].push_back(v);
            }
            else{
                // u se v  and v se u ki trf ek edge hai ==== u -> v && v -> u
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            cout << endl << "Printing adjList" << endl;
            printadjList();
            cout << endl;
        }

        void printadjList(){
            for(auto i : adjList){
                cout << i.first << " -> {";
                for(auto neightbour : i.second){
                    cout << neightbour << ", ";
                }
                cout << "}" << endl;
            }
        }
};


// ( Directed Graph and Undirected Graph ) --> Weighted Graph

template <typename T>

class Graph2 {
    public:
        unordered_map<T, list<pair<T, int>>> adjList;

        void addEdge(T u, T v, int weight, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed
            if(direction == 1){
                // u se v ki trf ek edge hai ==== u -> v
                adjList[u].push_back({v,weight});
            }
            else{
                // u se v  and v se u ki trf ek edge hai ==== u -> v && v -> u
                adjList[u].push_back({v,weight});
                adjList[v].push_back({u,weight});
            }
            cout << endl << "Printing adjList" << endl;
            printadjList();
            cout << endl;
        }

        void printadjList(){
            for(auto i : adjList){
                cout << i.first << " -> {  ";
                for(auto p : i.second){
                    cout << "{" << p.first << ", " << p.second << "}, ";
                }
                cout << "}" << endl;
            }
        }
};



int main() {

    Graph2<char> g;
    // g.addEdge(0,1,5,1);
    // g.addEdge(1,2,10,1);
    // g.addEdge(1,3,20,1);
    // g.addEdge(2,3,50,1);
    g.addEdge('a','b',5,0);
    g.addEdge('b','c',10,0);
    g.addEdge('b','c',20,0);
    g.addEdge('c','d',50,0);
    return 0;
}

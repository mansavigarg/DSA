#include <iostream>
#include <list>
using namespace std;

// ( Directed Graph and Undirected Graph ) --> Weighted Graph

template <typename T>

class Graph {
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

        void bfsTraversal(T src, unordered_map< T, bool > &vis) {
            // adjList alredy availabe hai data member mein
            // visited array
            // unordered_map< T, bool > vis;


            // queue
            queue < T > q;

            // initial
            q.push(src);
            vis[src] = true;

            while(!q.empty()){
                T frontNode = q.front();
                cout << frontNode << " ";
                q.pop();

                // go to the neighbour 
                for( auto nbr : adjList[frontNode]){
                    T nbrData = nbr.first;

                    if(!vis[nbrData]){
                        q.push(nbrData);
                        vis[nbrData] = true;
                    }
                }
            }

        }
};



int main() {

    Graph<char> g;

    // dis-connectecd graph
    g.addEdge('a','b',5,0);
    g.addEdge('b','c',10,0);

    g.addEdge('d','e',20,0);

    g.addEdge('f','f',50,0);

    unordered_map< char, bool > vis;
    for(char node = 'a'; node <= 'f'; node++){
        if(!vis[node]){
            g.bfsTraversal(node, vis);
        }
    }
    return 0;
}

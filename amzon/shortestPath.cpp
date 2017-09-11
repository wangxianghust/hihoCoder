#include <iostream>
#include <list>
#include <climits>
#include <vector>

using namespace std;

struct GraphNode{
    bool known;
    int dist; //now distance source--->end
    int path;// prev node
};

struct Node{
    int vertex; // self-node.
    int weight; 
    Node(int v, int w):vertex(v), weight(w){}
};

class Graph{
    private:
        int edge_num;
        int vertex_num;
        vector<vector<Node> > graph_list;
        vector<GraphNode> nodeArr;

    public:
        Graph(){}
        ~Graph();
        void dijkstra(int src);
        void constructGraph(vector<vector<int> > &edges);
};

void Graph::dijkstra(int src){
    for(int i=0; i<vertex_num; ++i){
        nodeArr[i].known = false;
        nodeArr[i].dist = INT_MAX;
        nodeArr[i].path = 0;
    }

    nodeArr[src].dist =  0;

    for(;;){
        int v = 0;
        int min = INT_MAX;
        for(int i=0; i<vertex_num; ++i){
            // select the min dist from nodeArr
            if(!nodeArr[i].known && (min > nodeArr[i].dist)){
                min = nodeArr[i].dist;
                v = i;
            } 
        }

        if(min == INT_MAX) break;
        
        nodeArr[v].known = true;

        for(auto it = graph_list[v].begin(); it != graph_list[v].end(); ++it){
            //this node is not visited
            if(!nodeArr[(*it).vertex].known){
                if(nodeArr[v].dist + (*it).weight < nodeArr[(*it).vertex].dist){
                    nodeArr[(*it).vertex].dist = nodeArr[v].dist + (*it).weight;
                    nodeArr[(*it).vertex].path = v;
                }
            }
        }
    }
}

void Graph::constructGraph(vector<vector<int> > &edges){
    for(auto edge : edges){
        int start = edge[0];
        int end = edge[1];
        int weight = edge[2];
        Node node1(end, weight);
        graph_list[start].push_back(node1);
        Node node2(start, weight);
        graph_list[end].push_back(node2);
    }
}

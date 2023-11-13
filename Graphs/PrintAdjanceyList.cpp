/*
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 
0-based indexing is followed everywhere.
*/

#include <bits/stdc++.h>

class Solution{
    public:
        std::vector<std::vector<int>> AdjanceyList (int NumberOfVertices, std::vector<std::pair<int, int>> Edges){
                std::vector<std::vector<int>> List(NumberOfVertices);
                for(int i = 0 ; i < Edges.size() ; i += 1){
                    int U = Edges[i].first, V = Edges[i].second ;
                    List[U].push_back(V) ;
                    List[V].push_back(U) ;
                }
                return List ;
        }
};

int main(){
    int NumberOfVertices, NumberOfEdges ;
    std::cin >> NumberOfVertices >> NumberOfEdges ;

    std::vector<std::pair<int, int>> Edges ;
    for(int i = 0 ; i < NumberOfEdges ; i += 1){
        int U, V ;
        std::cin >> U >> V ;
        Edges.push_back({U, V}) ;
    }

    Solution Object ;
    std::vector<std::vector<int>> AdjanceyList = Object.AdjanceyList(NumberOfVertices, Edges) ;

    for(int i = 0 ; i < NumberOfVertices ; i += 1){

        std::sort(AdjanceyList[i].begin(), AdjanceyList[i].end()) ;

        for(auto ptr : AdjanceyList[i]){
            std::cout << ptr << " " ;       
        }
        std::cout << std::endl ;
    }

    return 0;
}
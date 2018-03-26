// Name: Bananannn
// Sources of Help: http://vlsicad.ucsd.edu/courses/cse101-w18/textbook.pdf
// PAGE 103&97
// https://piazza.com/class/jb8pdrlepuy2ga?cid=320 for the overall algorithm
// Due: 1/26/2018 at 11:59 PM

#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include "Graph.hpp"
//#include "DFS.hpp"

template <class T>
std::list<std::set<T> > scc(Graph<T>& g){
    std::list<std::set<T> > sccs;
    // TODO: Implement SCC
    // the algorithm is inspired by the piazza post in the website mentioned 
    // above
    // reverse the graph to get G^R
    Graph<T> reverse = g.Graph<T>::reverse_graph();

    int flag = 0;
    // get the post numbers of the reverse graph
    reverse.Graph<T>::reset_graph();
    int num = 1;
    for(auto it = reverse.vertices.begin(); it != reverse.vertices.end(); it++){
        //std::cout<<(*it).first<<std::endl;
        // DFS from DFS.cpp
        if( (*it).second->visited == false ){
            //dfs(reverse, (*it).first);
            reverse.vertices[(*it).first]->visited = true;
            reverse.vertices[(*it).first]->pre = num;
            num += 1;
            std::stack<T> mystack;
            mystack.push((*it).first);
            // Check the stack
            while( !mystack.empty() ){
                T vertex = mystack.top();
                bool flag = true;
                Vertex<T>* curr = reverse.vertices[vertex];
                for( auto eit = curr->edges.begin();eit != curr->edges.end(); 
                eit++){
                    if( reverse.vertices[*eit]->visited == false ){
                        mystack.push(*eit);
                        reverse.vertices[*eit]->visited = true;
                        reverse.vertices[*eit]->pre = num;
                        num += 1;
                        flag = false;
                        break;
                    }
                }
                if( flag == true ){
                    mystack.pop();
                    curr->post = num;
                    num += 1;
                }
            }
        }

    }

    // save the post numbers in decreasing order in a priority queue
    std::priority_queue< std::pair<int, T>> pq;
    for(auto it = reverse.vertices.begin(); it != reverse.vertices.end(); it++){
        int postnum = (*it).second->post;
        pq.push(std::make_pair(postnum, (*it).first));
    }
    /*while(pq.size()!=0){
        std::cout<<"print "<<pq.top().first<<std::endl;
        pq.pop();
    }*/
    
    // start finding the SCCs
    int count = 0;
    while( pq.size() != 0 ){
        std::set<T> oneC;
        T cur = pq.top().second;
        pq.pop();
        if( g.vertices[cur]->visited == false ){
            oneC = dfs(g, cur);
            sccs.push_back(oneC);
        }

    }

    return sccs;
}

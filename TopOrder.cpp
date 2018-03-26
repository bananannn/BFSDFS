// Name: bananannn
// Sources of Help:http://www.cplusplus.com/reference/map/map/insert/ 
//                 https://piazza.com/class/jb8pdrlepuy2ga?cid=270
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
// include more libraries as needed
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include <list>

template <class T>
std::list<T> top_order(Graph<T>& g) {
  std::list<T> res;
  // TODO: Implement TopOrder
  std::map<T, int> indegree;
  std::stack<T> mystack;
  // reverse the graph to get the indegrees of each node
  Graph<T> reverse = g.Graph<T>::reverse_graph();
  std::queue<T> myqueue;
  std::map<T, Vertex<T> *> currver = reverse.vertices;
  //std::vector<Vertex<T> &> myvec;
  for(auto it = currver.begin(); it != currver.end(); it++ ){
    int degree = currver[(*it).first]->edges.size();
    indegree.insert(std::pair<T, int>((*it).first, degree));
    if( degree == 0 ){
        myqueue.push((*it).first);
    }
    //std::cout<<"indegree "<< (*it).first<<indegree[(*it).first] << std::endl;
  }
   
  while( !myqueue.empty() ){
      T curr = myqueue.front();
      myqueue.pop();
      res.push_back(curr);
      if( indegree[curr] == 0 ){
          mystack.push(curr);
          std::list<T> edge = g.vertices[curr]->edges;
          for( auto eit = edge.begin(); eit!=edge.end(); eit++ ){
              int orginal = indegree[*eit];
              indegree[*eit] = orginal-1;
              if( indegree[*eit] == 0 ){
                  myqueue.push(*eit);
              }
          }
      }
  }
 
  if( g.vertices.size() != res.size() ){
      res.clear();
  }
  return res;
}


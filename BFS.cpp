// Name: Bananannn
// Sources of Help: 
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
#include <queue>
#include <map>
#include <list>
#include <set>

template <class T>
std::set<T> bfs(Graph<T>& g, T t) {
  std::set<T> res;
  // TODO: Implements BFS
  int currtime = 0;
  std::queue<T> myqueue;
  myqueue.push(t);
  currtime += 1;
  // use a queue to implement
  while( !myqueue.empty() ){
    T vertex = myqueue.front();
    myqueue.pop();
    Vertex<T>* curr = g.vertices[vertex];
    curr->pre = currtime;
    if( curr->visited == false ){
      for( auto it = curr->edges.begin(); it!=curr->edges.end(); it++ ){
        myqueue.push(*it);
        currtime += 1;
        g.vertices[*it]->pre = currtime;
      }
      res.insert(curr->id);
      curr->visited = true;
      currtime += 1;
      curr->post = currtime;
    }
  }
  return res;
}


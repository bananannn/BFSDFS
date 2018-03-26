// Name: Bananannn
// PID: A91107457
// Sources of Help: https://piazza.com/class/jb8pdrlepuy2ga?cid=184
//                  The homework1 solution for question 4 posted by the professor
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
#include <stack>
#include <map>
#include <list>
#include <set>

template <class T>
std::set<T> dfs(Graph<T>& g, T t) {
  std::set<T> res;
  // TODO: Implement DFS
  // The algorithm is inspired by the solution of HW1 question #4
  // The website is posted above
  int num = 1;
  g.vertices[t]->visited = true;
  res.insert(t);
  g.vertices[t]->pre = num;
  num += 1;
  std::stack<T> mystack;
  mystack.push(t);
  // Check the stack
  while( !mystack.empty() ){
    T vertex = mystack.top();
    bool flag = true;
    Vertex<T>* curr = g.vertices[vertex];
    for( auto it = curr->edges.begin();it != curr->edges.end(); it++){
      if( g.vertices[*it]->visited == false ){
        mystack.push(*it);
        g.vertices[*it]->visited = true;
        res.insert(*it);
        g.vertices[*it]->pre = num;
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
      
  return res;
}


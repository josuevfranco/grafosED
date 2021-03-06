#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
const int V=5;
vector< list<int> > a(V);
int BFS(int s)
{
int visited[V]={0};
queue<int> cola;
visited[s]=1;
cola.push(s);
while(!cola.empty())
{
int x = cola.front();
cola.pop();
vector<list<int> >::iterator it1 = a.begin()+x;
list<int> it2 =* it1;
list<int>::iterator iter = it2.begin();
while(iter != it2.end())
{
if(visited[*iter]==0)
{
visited[*iter]=1;
cola.push(*iter);
}
++iter;
}
visited[x]=2; // set visited here.
}
return 0;
}
void addEdge(int i, int j)
{
a[i].push_back(j);
a[j].push_back(i);
}
int main() {
vector<list<int> >::iterator it1=a.begin();
addEdge(0,1);
addEdge(0,3);
addEdge(1,5);
while(it1!=a.end())
{
list<int> it2=*it1;
list<int>::iterator iter=it2.begin();
while(iter!=it2.end())
{
cout<<*iter<<" ";
iter++;
}
cout<<endl;
it1++;
}
cout<<BFS(0);
return 0;
}

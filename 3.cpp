#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> vertice;
class Grafo {
vector<vertice> *adjList;
size_t dimGrafo;
public:
Grafo(size_t dimGrafo){
this->dimGrafo = dimGrafo;
adjList = new vector<vertice>[dimGrafo];
}
void agregaVertice(int origen, int destino, int peso) {
adjList[origen].push_back(make_pair(destino,peso));
}
void printLista() {
for(size_t i = 0 ; i < this->dimGrafo; ++i ) {
cout << i <<" -> ";
for(vector<pair<int,int>>::iterator
j = this->adjList[i].begin();
j != this->adjList[i].end();
++j) {
printAristaVertice(*j);
}
cout << " X"<<endl;
}
}
void busquedaAnchura(){
busquedaAnchura(0);
}
void busquedaProfundidad(){
busquedaProfundidad(0);
}
~Grafo(){
delete [] adjList;
}
private:
inline void printAristaVertice(vertice j){
cout << " (vertice = " << j.first <<" , " << "peso = " << j.second << "
),";
}
void busquedaAnchura(int start){
cout << endl;
cout << "Busqueda en anchura (BFS) : " << endl;
queue <int> cola;
vector<bool> visited (dimGrafo);
visited[start] = true;
cola.push(start);
while(!cola.empty()){
int front = cola.front();
cout << front << " ";
cola.pop();
for(vector<vertice>::iterator i = this->adjList[front].begin();
i != this->adjList[front].end();
++i) {
if(!visited[i->first]){
visited[i->first] = true;
cola.push(i->first);
}
}
}
}
void busquedaProfundidad(int start){
cout << endl;
cout << "Busqueda en profundidad (DFS) :" << endl;
stack<int> pila;
vector<bool> visited(dimGrafo);
pila.push(0);
while(!pila.empty()){
int top = pila.top();
pila.pop();
if(!visited[top]) {
visited[top] = true;
cout << top << " ";
}
for(vector<vertice>::iterator i = this->adjList[top].begin();
i != this->adjList[top].end();
++i) {
if(!visited[i->first]){
pila.push(i->first);
}
}
}
}
};
int main() {
Grafo citiesGrafo(5);
citiesGrafo.agregaVertice(0,1,10);
citiesGrafo.agregaVertice(1,2,21);
citiesGrafo.agregaVertice(2,0,32);
citiesGrafo.agregaVertice(2,4,41);
citiesGrafo.agregaVertice(0,3,59);
citiesGrafo.printLista();
citiesGrafo.busquedaAnchura();
citiesGrafo.busquedaProfundidad();
}

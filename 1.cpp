#include<iostream>
using namespace std;
#include <queue>
#include <stack>
class Grafo {
private:
int vertice, arista;
int **adyMatrix;
int *visitado;
public:
Grafo(int ver,int arc) : vertice (ver), arista (arc)
{
adyMatrix = new int * [ver];
for (int i = 0; i < vertice; i++) {
adyMatrix[i] = new int[vertice];
for(int j = 0; j < vertice; j++)
adyMatrix[i][j] = 0;
}
visitado = new int [vertice];
}
void visitados(){
for(int i = 0; i < vertice; i++) {
visitado[i] = 0;
//cout << visitado[i];
}
}
~Grafo() {
for (int i = 0; i < vertice; i++)
delete[] adyMatrix[i];
delete[] adyMatrix;
}
void crear_grafo() {
for(int i = 0; i < vertice; i++)
for(int j = 0; j < vertice; j++)
cin >> adyMatrix[i][j];
}
void agregarArista(int i, int j) {
if (i >= 0 && i < vertice && j > 0 && j < vertice) {
adyMatrix[i][j] = 1;
}
}
void removerArista(int i, int j) {
if (i >= 0 && i < vertice && j > 0 && j < vertice) {
adyMatrix[i][j] = 0;
}
}
bool esArista(int i, int j) {
if (i >= 0 && i < vertice && j > 0 && j < vertice)
return adyMatrix[i][j];
else
return false;
}
void profundidad(int nodo)
{
visitado[nodo] = 1;
cout << nodo << " ";
for(int i = 0; i < vertice; i++){
if(adyMatrix[nodo][i] && !visitado[i]){
profundidad(i);
}
}
}
void profundidadI(int nodo)
{
visitados();
stack<int> pila;
pila.push(nodo);
visitado[nodo] = 1;
while( !pila.empty() ){
int elemento = pila.top();
pila.pop();
cout << elemento << " ";
for(int i=0; i < vertice; i++ ){
if( adyMatrix[elemento][i] ){
if ( !visitado[i] )
pila.push(i);
visitado[i] = 1;
}
}
}
}
void anchura(int nodo)
{
visitados();
visitado[nodo] = 1;
queue<int> cola;
cola.push(nodo);
while( !cola.empty() ){
int elemento = cola.front();
cola.pop();
cout << elemento << " ";
for(int i=0; i < vertice; i++ ){
if( adyMatrix[elemento][i] && !visitado[i] ){
cola.push(i);
visitado[i] = 1;
}
}
}
}
};
int main()
{
int ver, arc;
cout << "Numero de vertices ";
cin >> ver;
cout << "Numero de arcos ";
cin >> arc;
Grafo gh(ver, arc);
cout << "creacion del grafo\n";
gh.crear_grafo();
cout << "busqueda en anchura \n";
gh.anchura(0);
cout << endl;
cout << "busqueda en profundidad\n";
gh.visitados();
gh.profundidad(0);
cout << endl;
gh.profundidadI(0);
cout << endl;
}

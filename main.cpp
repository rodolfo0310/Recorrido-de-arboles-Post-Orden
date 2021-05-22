#include <iostream>

int main() {
    std::cout << "RECORRIDOS POSTORDEN\n";
}
struct nodo {
   int dato;
   struct nodo *arbol;
   struct arbol;
};

//Recorrido PostOrden: En este tipo de recorrido, el valor del nodo se procesa después de recorrer todas las ramas:
//Para recorrer en PostOrden se hace> izquierdo-derecho-raiz

void PostOrden(nodo*arbol) {
   if(arbol == NULL) return;
   }
  else{ 

     PostOrden(arbol->izq);// recorre todo el lado izquierdo
     PostOrden(arbol->der);//recorre todo el lado derecho
     cout<<arbol->dato<<"-"; //identifica la raiz 
    
    
}
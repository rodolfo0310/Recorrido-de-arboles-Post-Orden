/*
Pasos para poder mostrar todos los elementos de un árbol.
1. Definir la función.
   Aquí tenemos que comprobar algunas cosas.
   Si el árbol está vacío.
   Si el árbol está lleno.
*/

struct Nodo{
  
  int dato;
  Nodo *izquierda;
  Nodo *derecha;

};

//Prototipos.
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *arbol, int);
void PostOrden(Nodo *);

#include <iostream>
using namespace std;

int main() {
  
   menu();


}

void menu(){
  
  Nodo *arbol = NULL;
  int dato, opcion, conteo = 0; //Inicializada en 0 porque no quiero que me deje un espacio cuando se imprima la raíz.

  do{

    cout << "----Menú_árboles----" << endl;
    cout << "1. Insertar un nodo\n";
    cout << "2. Mostrar todo el árbol\n";
    cout << "3. Recorrido PostOrden\n";
    cout << "4. Salir\n";
    cout << "Opción: ";
    cin  >> opcion;

    switch(opcion){

      case 1: 
      cout << "Digite un número para el árbol: ";
      cin  >> dato;
      insertarNodo(arbol, dato);
      cout << "Dato insertado\n";
      cout << "\n";
     
      break;

     
      case 2: 

      cout << "Este es su árbol:\n ";
      mostrarArbol(arbol, conteo);
      cout << "\n";

      
      break;
      case 3:
      cout << "Recorrido en Post Orden" << endl;
      PostOrden(arbol);
      cout << "\n\n";
      break;
      case 4: break;

    }
      
       cout << "Presione la tecla enter para continuar...";
       
      cin.ignore().get();
      system("clear");
      

  }while(opcion != 3);
}

Nodo *crearNodo(int numero){
     
     //Creamos el nuevo y le reservamos memoria.
     Nodo *nuevo_nodo = new Nodo();
     nuevo_nodo -> dato = numero;
     nuevo_nodo -> izquierda = NULL;
     nuevo_nodo -> derecha = NULL;

     return nuevo_nodo;

}

//Esta función nos va a permitir insertar nodos en el árbol binario de búsqueda de la forma que ya se ha hablado.
void insertarNodo(Nodo *&arbol, int numero){
   
   //Comprobamos si el árbol está vacío.
   if(arbol == NULL){
     Nodo *nuevoNodo = crearNodo(numero); //Crea un nuevo nodo con la función encargada de realizar esta acción.
     arbol = nuevoNodo; //Almacenamos el nodo en la raíz del árbol.
   }

   //El árbol no está vacío y tiene uno o más nodos.
   else{
    
      int valorRaiz = arbol->dato; //Obtenemos el valor de la raíz del árbol.
      //Comprobamos si los elementos a insertar son mayores o menores que los elementos de la raíz
      if(numero < valorRaiz){

        insertarNodo(arbol->izquierda, numero);

      }

      else{
         
         insertarNodo(arbol->derecha, numero);

      }

   }

}

void mostrarArbol(Nodo *arbol, int contador){
     //Si el árbol está vacío.
     if(arbol == NULL){
       
      return;

     }

     else{
       
       mostrarArbol(arbol->derecha, contador + 1);
       for(int i = 0; i < contador; i++){
         cout << "    ";
       }

       //Imprimimos los datos.
       cout << arbol -> dato << endl;//Imprimimos la raíz.
       mostrarArbol(arbol->izquierda, contador + 1);

     }


}

void PostOrden(Nodo *arbol){
  if(arbol == NULL){
    return;
  }
  else{
    PostOrden(arbol->izquierda);
    PostOrden(arbol-> derecha);
    cout << arbol -> dato << "-";
  }
}

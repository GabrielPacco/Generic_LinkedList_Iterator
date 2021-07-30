#include <iostream>
#include <chrono> 
#include <vector>
#include "LinkedList.h"

using namespace std::chrono; 
using namespace std;

int main() {

    auto start = high_resolution_clock::now(); 

	LinkedList<string> L1;

    L1.add_front("Hola"); 
    L1.add_front("Amigo"); 
    L1.add_front("Como"); 
    L1.add_front("Estas");

    L1.print();
    cout << endl;

    L1.insertpos("Elliot",3);
    L1.add_back("Alderson");

    L1.print();
    cout << endl;

    L1.popBack();

    L1.print();
    cout << endl;

    L1.popFront();
    //L1.popBack(); 

    L1.print();
    cout << endl;

    L1.remove(1);

    L1.print();
    cout << endl;

    LinkedList<double> list;

    list.add_front(23.45); 
    list.add_front(12.45); 
    list.add_front(64.64); 

    LinkedList<int> L2;

    L2.add_front(2);
    L2.add_front(5);
    L2.add_front(4);
    L2.add_front(24);
    

    //Llama al constructor de copia
	LinkedList<int> L3 = L2;
    cout<<"\nConstruida la lista L3 para que sea = a L2: " << endl;
	
    cout<<"Lista L2:\n";
    L2.print();
    cout<<"Lista L3:\n";
    L3.print();

    cout<<"\nConstruida la lista L4 para que sea = a L3: " << endl;
    LinkedList<int> L4;
    L4 = L3;
    cout<<"Lista L3:\n";
    L3.print();
    cout<<"\nImprimiendo L4: "<<endl;
    L4.print();
    
    
    /*
    //Llama al constructor de movimiento
    LinkedList<int> L5 = std::move(L2);
    cout << "Construida la lista L5 con los recursos movidos de la lista L2: " << endl;

    cout<<"Lista L5:\n";
    L5.print();
    cout<<"Lista L2:\n";
    L2.print();
    */

    //Llama al operador de movimiento de asignación sobrecargado
    LinkedList<int> L6;
	L6 = std::move(L2);
    cout << "Mover los recursos de la L2 a la L6: " << endl;
    cout<<"Lista L6:\n";
    L6.print();
    cout<<"\nImprimiendo L2: "<<endl;
    L2.print();

    //Iterando L4
    cout<<"\nIterando L4:\n";
    for (Iterator<int> it = L4.begin(); it != L4.end(); it++)
    {
        std::cout << *it << endl;
    }

    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    
    cout << "Tiempo de ejecucion en microseconds: ";
    cout << duration.count() << endl;

    return 0;
}


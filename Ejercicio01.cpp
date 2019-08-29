/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Mauricio Pacheco
 *
 * Created on 26 de agosto de 2019, 4:10 p.m.
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
struct Nodo{
    int dato;
    Nodo *sig;
} *inicio, *fin;

class ListaEnlazada{
    public: 
    
    Nodo* crearNodo(int valor){
        Nodo *n = new Nodo;
        n->dato = valor;
        n->sig = nullptr;
        return n;
    }
    
    void agregarElemento(int valor){
        Nodo *n = crearNodo(valor), *temp;
        if(!inicio){
            inicio = n;
            fin = n;
        }
        else{
            for(temp = inicio; temp->sig; temp = temp->sig);
            temp->sig = n;
        }
    }
    
    void mostrarLista(){
        Nodo *temp = inicio;
        if(!inicio){
            cout << "La lista no tiene datos";
        }
        else{
            while(temp){
                cout << temp->dato << ", ";
                temp = temp->sig;
            }
            cout << endl;
        }
    }
    
    int cant(){
        Nodo *temp = inicio;
        int cont = 0;
        if(!inicio){
            cout << "La lista no tiene datos";
        }
        else{
            while(temp){
                cont++;
                temp = temp->sig;
            }
        }
        return cont;
    }
    
    ListaEnlazada newList(){
        float media = promedio();
        Nodo *temp = inicio;
        int aux[cant()], cont = 0;
        while(temp){
            if(temp->dato > media){
                aux[cont] = temp->dato;
                cont++;
            }
            temp = temp->sig;
        }
        ListaEnlazada nueva;
        for(int i = 0; i < cont; i++){
            nueva.agregarElemento(aux[i]);
        }
        return nueva;
    }
    
    float promedio(){
        if(!inicio){
            cout << "La lista no tiene datos";
        }
        else{
            float acum, cont = 0;
            Nodo *temp = inicio;
            while(temp){
                acum = acum + temp->dato;
                cont += 1;
                temp = temp->sig;
            }
            float media = acum/cont;
            cout << endl << "El promedio es " << media << endl;
            return media;
        }
    }
    
    ListaEnlazada(){
        inicio = nullptr;
        fin = nullptr;
    }
};

int main(int argc, char** argv) {
    ListaEnlazada list01, list02;
    list01.agregarElemento(10);
    list01.agregarElemento(20);
    list01.agregarElemento(20);
    list01.agregarElemento(30);
    list01.agregarElemento(40);
    list01.agregarElemento(50);
    list01.mostrarLista();
    
    list02 = list01.newList();
    cout << endl << "La nueva lista es " << endl;
    list02.mostrarLista();
    
    return 0;
}
/*
 * ========================================================================
 *
 *
 *       Filename: main.cpp
 *
 *       Description: Program that creates a server that can handle 
 *                    multiple connections.
 *
 *       Version: 1.0
 *       Created: 19/01/17
 *       Revision: none
 *       Compiler: g++
 *
 *       Author: Daniel Monzalvo, danielmonr@gmail.com
 *
 * ========================================================================
*/

#include <stdlib.h>
#include <iostream>
#include "doubleList.h"

int main(int argc, char* argv[]){

    DList<int>* lista = new DList<int>();
    lista->Add(1);
    lista->Add(3);
    //lista->Add(2);

    delete lista;
    return 1;
}

#include <stdlib.h>
#include <iostream>
#pragma once

template <class T>
class Node{
    public:
        Node(){
            std::cout << "Value: ";
            std::cin>> value;
            prev = nullptr;
            next = nullptr;
        }
        Node(T v, Node<T>* p, Node<T>* n){
            std::cout << "Node::Constructor()\n";
            value = v;
            prev = p;
            next = n;
        }
        ~Node(){
            prev = nullptr;
            if (next)
                delete next;
            next = nullptr;
        }

        T getValue(){
            return value;
        }

        Node<T>* getNext(){
            return next;
        }
        Node<T>* getPrev(){
            return prev;
        }
        void setValue(T v){
            value = v;
        }
        void setNext(Node<T>* n){
            next = n;
        }
        void setPrev(Node<T>* p){
            prev = p;
        }

    private:
        T value;
        Node<T>* prev;
        Node<T>* next;
};

template <class T>
class DList{
    public:
        DList(){
            length = 0;
            first = nullptr;
        }
        ~DList(){
            if (first)
                delete first;
            first = nullptr;
        }

        Node<T>* Last(){
            std::cout << "DList::Last()\n";
            Node<T>* temp = first;
            while(temp->getNext())
                temp = temp->getNext();
            return temp;
        }

        void Add(T v){
            std::cout << "DList::Add()\n";
            Node<T>* n;
            if(length != 0){
                std::cout << "DList::Add()::Not First\n";
                n = new Node<T>(v, Last(), nullptr);
                Last()->setNext(n);
            }
            else{
                std::cout <<"DList::Add()::First\n";
                n = new Node<T>(v, nullptr, nullptr);
                first = n;
            }
            length++;
            std::cout << "DList::Add()::end\n";
        }

        bool Delete(int pos){
            Node<T>* temp = At(pos);
            if(!temp)
                return false;

            temp->getNext()->setPrev(temp->getPrev());

            if (pos == 0)
                first = temp->getNext();
            else
                temp->getPrev()->setNext(temp->getNext());

            temp->setPrev(nullptr);
            temp->setNext(nullptr);
            delete temp;
            length--;
            return true;

        }

        Node<T>* At(int pos){
            if (length <= pos)
                return nullptr;

            Node<T>* n = first;
            int i = 1;
            for (i; i <= pos; ++i){
                n = n->getNext();
            }

            return n;
        }

        int Length(){
            return length;
        }

        int Search(T v){
            int cont = 0;
            Node<T>* temp = first;
            while(temp){
                if(temp->getValue() == v)
                    return cont;
                temp = temp->getNext();
                cont++;
            }
            return -1;
        }

    private:
        int length;
        Node<T>* first;
};

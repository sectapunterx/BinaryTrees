//
// Created by Fin on 25.10.2022.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace N
{
    class BinaryTreeElements
    {
        //friend class BinaryTree;
    private:
        int year, price;
        string name, country, model;

        BinaryTreeElements* left;
        BinaryTreeElements* right;
        BinaryTreeElements* parent;
        BinaryTreeElements* root;
        BinaryTreeElements* current;

        void DeleteNode(BinaryTreeElements* q);
    public:
        void InsertElement();

        BinaryTreeElements()
        {
            root = nullptr;
            current = nullptr;
            year = 0;
            price = 0;
            name = "";
            country = "";
            model = "";
            cout << "Constructor BinaryTreeElements" << endl;
        }
        BinaryTreeElements(BinaryTreeElements* q)
        {
            year = q->year;
            price = q->price;
            name = q->name;
            country = q->country;
            model = q->model;
            cout << "Copy constructor" << endl;
        }
        //parametric constructor
        BinaryTreeElements(int year, int price, string name, string country, string model)
        {
            this->year = year;
            this->price = price;
            this->name = name;
            this->country = country;
            this->model = model;
            cout << "Parametric constructor" << endl;
        }
        //destructor
        ~BinaryTreeElements()
        {
            cout << "Destructor" << endl;
        }

        int Size();
        void AddElement();
        void InsertingChildElementForCurrentElement();
        BinaryTreeElements* DeleteCurrentNode();
        BinaryTreeElements* MoveInStructure();
        void DisplayTree(BinaryTreeElements* q);
        void CleanTheStructure();


    };
}

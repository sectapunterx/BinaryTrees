//
// Created by Fin on 25.10.2022.
//
#include "header.h"
using namespace N;



void BinaryTreeElements::DeleteNode(BinaryTreeElements* q)
{
    if(current == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if(this->parent == NULL)
    {
        cout << "Parent is empty" << endl;
        return;
    }
    else
    {
        DeleteNode(this->left);
        DeleteNode(this->right);
    }
    delete this;
}

int BinaryTreeElements::Size()
{
    int size = 1;

    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        size++;
        BinaryTreeElements* q = this->left;
        while(q != nullptr)
        {
            size++;
            q = this->left;
        }
        BinaryTreeElements* w = this->right;
        while(w != nullptr)
        {
            size++;
            w = this->right;
        }
    }
    return size;
}
void BinaryTreeElements::InsertElement()
{
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter country: ";
    cin >> country;
    cout << "Enter model: ";
    cin >> model;

}

void BinaryTreeElements::AddElement()
{
    BinaryTreeElements* q = new BinaryTreeElements();
    cout << "Enter 1 to add element to the left, 2 to add element to the right: ";
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        this->left = new BinaryTreeElements(q);
        this->left->parent = this;
        this->left->left = nullptr;
        this->left->right = nullptr;
        q->InsertElement();
        current = this->left;
    }
    else if(choice == 2)
    {
        this->right = new BinaryTreeElements(q);
        this->right->parent = this;
        this->right->left = nullptr;
        this->right->right = nullptr;
        q->InsertElement();
        current = this->right;
    }
    else
    {
        cout << "Wrong choice" << endl;
        return;
    }
}
void BinaryTreeElements::InsertingChildElementForCurrentElement()
{
    cout << "Enter 1 to add element to the left, 2 to add element to the right: ";
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        if(this->left == nullptr)
        {
            this->left = new BinaryTreeElements();
            this->left->InsertElement();
            this->left->parent = this;
            this->left->left = nullptr;
            this->left->right = nullptr;
            current = this->left;
            return;
        }
        else
        {
            cout << "Left element is not empty" << endl;
        }
    }
    else if(choice == 2)
    {
        if(this->right == nullptr)
        {
            this->right = new BinaryTreeElements();
            this->right->InsertElement();
            this->right->parent = this;
            this->right->left = nullptr;
            this->right->right = nullptr;
            current = this->right;
            return;
        }
        else
        {
            cout << "Right element is not empty" << endl;
        }
    }
    else
    {
        cout << "Wrong choice" << endl;
        return;
    }
}
BinaryTreeElements* BinaryTreeElements::DeleteCurrentNode()
{
    if(current == nullptr)
    {
        cout << "Tree is empty" << endl;
        return nullptr;
    }
    if(current->parent == nullptr)
    {
        cout << "Parent is empty" << endl;
        return nullptr;
    }
    else
    {
        BinaryTreeElements* q = current -> parent;
        delete current;
        return q;
    }
    return 0;
}
BinaryTreeElements* BinaryTreeElements::MoveInStructure()
{
    cout << "Enter 1 to move to the left, 2 to move to the right, 3 to move to the parent: ";
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        if(this->left == nullptr)
        {
            cout << "Left element is empty" << endl;
            return nullptr;
        }
        else
        {
            cout << "Prev address: " << this << endl;
            current = this->left;
            cout << "Current address: " << current << endl;
            return current;
        }
    }
    else if(choice == 2)
    {
        if(this->right == nullptr)
        {
            cout << "Right element is empty" << endl;
            return nullptr;
        }
        else
        {
            cout << "Prev address: " << this << endl;
            current = this->right;
            cout << "Current address: " << current << endl;
            return current;
        }
    }
    else if(choice == 3)
    {
        if(this->parent == nullptr)
        {
            cout << "Parent element is empty" << endl;
            return nullptr;
        }
        else
        {
            cout << "Prev address: " << this << endl;
            current = this->parent;
            cout << "Current address: " << current << endl;
            return current;
        }
    }
    else
    {
        cout << "Wrong choice" << endl;
        return nullptr;
    }
}
void BinaryTreeElements::DisplayTree(BinaryTreeElements* q)
{
    cout << "Address: " << q << endl;
    cout << "Year: " << q->year << endl;
    cout << "Price: " << q->price << endl;
    cout << "Name: " << q->name << endl;
    cout << "Country: " << q->country << endl;
    cout << "Model: " << q->model << endl;
    cout << endl;
}
void BinaryTreeElements::CleanTheStructure()
{
    root->DeleteNode(root);
    root = nullptr;
    current = nullptr;
    return;
}
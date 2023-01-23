#include <iostream>
#include <windows.h>
using namespace std;

struct car {
    int year;
    int price;
    string mark;
    string model;
    string color;
    car* left;
    car* right;
    car* parent;
};

int CountElements(car* root)
{
    if (root == NULL)
        return 0;
    else
        return CountElements(root->left) + CountElements(root->right) + 1;
}

void Input(car* root)
{
    cout << "Enter year: ";
    cin >> root->year;
    cout << "Enter price: ";
    cin >> root->price;
    cout << "Enter mark: ";
    cin >> root->mark;
    cout << "Enter model: ";
    cin >> root->model;
    cout << "Enter color: ";
    cin >> root->color;
}
void AddElement(car* root)
{
    cout << "Выберите потомка: 1 - левый, 2 - правый: " << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        if (root->left == NULL)
        {
            root->left = new car;
            root->left->parent = root;
            Input(root->left);
        }
        else
        {
            AddElement(root->left);
        }
    }
    else if (choice == 2)
    {
        if (root->right == NULL)
        {
            root->right = new car;
            root->right->parent = root;
            Input(root->right);
        }
        else
        {
            AddElement(root->right);
        }
    }
    else
    {
        cout << "Неверный ввод" << endl;
    }
}

void InputElForCurrent(car* root)
{
    cout << "Введите потомка, для которого хотите ввести данные: 1 - левый, 2 - правый: " << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        if (root->left == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            Input(root->left);
        }
    }
    else if (choice == 2)
    {
        if (root->right == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            Input(root->right);
        }
    }
    else
    {
        cout << "Неверный ввод" << endl;
    }
}
void DeleteCurrentElement(car* root)
{
    cout << "Введите потомка, который хотите удалить: 1 - левый, 2 - правый: " << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        if (root->left == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            root->left = NULL;
        }
    }
    else if (choice == 2)
    {
        if (root->right == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            root->right = NULL;
        }
    }
    else
    {
        cout << "Неверный ввод" << endl;
    }
}
void CleanStructure(car* root)
{
    if (root->left != NULL)
    {
        CleanStructure(root->left);
    }
    if (root->right != NULL)
    {
        CleanStructure(root->right);
    }
    delete root;
}
void MovementInStructure(car* root)
{
    cout << " 1 - к левому потомку, 2 - к правому потомку, 3 - к родителю: " << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        if (root->left == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            root = root->left;
        }
    }
    else if (choice == 2)
    {
        if (root->right == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            root = root->right;
        }
    }
    else if (choice == 3)
    {
        if (root->parent == NULL)
        {
            cout << "Нет элемента" << endl;
        }
        else
        {
            root = root->parent;
        }
    }
    else
    {
        cout << "Неверный ввод" << endl;
    }
}
void PrintInfoAboutEveryElement(car* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "Year: " << root->year << endl;
    cout << "Price: " << root->price << endl;
    cout << "Mark: " << root->mark << endl;
    cout << "Model: " << root->model << endl;
    cout << "Color: " << root->color << endl;
    cout << endl;
    PrintInfoAboutEveryElement(root->left);
    PrintInfoAboutEveryElement(root->right);
}




int main()
{
    SetConsoleOutputCP(CP_UTF8);
    car* root = new car;
    Input(root);
    int choice;
    do
    {
        cout << "1 - добавить элемент" << endl;
        cout << "2 - удалить элемент" << endl;
        cout << "3 - ввести данные для элемента" << endl;
        cout << "4 - очистить структуру" << endl;
        cout << "5 - переместиться по структуре" << endl;
        cout << "6 - вывести информацию о каждом элементе" << endl;
        cout << "7 - вывести количество элементов" << endl;
        cout << "8 - выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            AddElement(root);
            break;
        case 2:
            DeleteCurrentElement(root);
            break;
        case 3:
            InputElForCurrent(root);
            break;
        case 4:
            CleanStructure(root);
            break;
        case 5:
            MovementInStructure(root);
            break;
        case 6:
            PrintInfoAboutEveryElement(root);
            break;
        case 7:
            cout << "Количество элементов: " << CountElements(root) << endl;
            break;
        case 8:
            break;
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    } while (choice != 8);
}

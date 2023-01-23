#include <iostream>
#include <windows.h>
#include <string>
#include "headerrr.h"
using namespace header;

int main() {


    SetConsoleOutputCP(CP_UTF8);
    Tree *tree = new Tree();
    Tree *tree1 = new Tree();
    while(1) {
        cout << "Введите 1 для создания перого дерева, 2 - для создания второго, 3 - чтобы войти в меню для сравнения элементов." << endl;
        int a;
        cin >> a;
        if (a == 1) {
            int command = 0;
            while (1) {
                if (command != 8) {
                    int size = 0;
                    cout << "Введите команду для вызова функции: " << endl;
                    cout << "1 - Посчитать количество элементов в дереве" << endl;
                    cout << "2 - Для добавления элемента в дерево" << endl;
                    cout << "3 - Для вставки дочернего элемента в структуру данных" << endl;
                    cout << "4 - Для удаления текущего элемента из структуры данных" << endl;
                    cout << "5 - Для удаления всей структуры данных" << endl;
                    cout << "6 - Для перемещения по структуре данных" << endl;
                    cout << "7 - Для вывода информации о текущем элементе" << endl;
                    cout << "8 - Для возвращения к выбору дерева" << endl;
                    cin >> command;
                    if (command == 1) {
                        cout << "Количество элементов: " << tree->treesize() << endl;
                    }
                    if (command == 2) {
                        tree->AddElement();
                    }
                    if (command == 3) {
                        tree->InsertChild();
                    }
                    if (command == 4) {
                        tree->DeleteCurrentNode();
                    }
                    if (command == 5) {
                        tree->CleanTree();
                    }
                    if (command == 6) {
                        tree->MoveInStructure();
                    }
                    if (command == 7) {
                        tree->DisplayTree();
                    }
                    if (command == 8) {
                        break;
                    }

                }
            }
        }
        if (a == 2) {
            int command = 0;
            while (1) {
                if (command != 8) {
                    int size = 0;
                    cout << "Введите команду для вызова функции: " << endl;
                    cout << "1 - Посчитать количество элементов в дереве" << endl;
                    cout << "2 - Для добавления элемента в дерево" << endl;
                    cout << "3 - Для вставки дочернего элемента в структуру данных" << endl;
                    cout << "4 - Для удаления текущего элемента из структуры данных" << endl;
                    cout << "5 - Для удаления всей структуры данных" << endl;
                    cout << "6 - Для перемещения по структуре данных" << endl;
                    cout << "7 - Для вывода информации о текущем элементе" << endl;
                    cout << "8 - Для возвращения к выбору дерева" << endl;
                    cin >> command;
                    if (command == 1) {
                        cout << "Количество элементов: " << tree1->treesize() << endl;
                    }
                    if (command == 2) {
                        tree1->AddElement();
                    }
                    if (command == 3) {
                        tree1->InsertChild();
                    }
                    if (command == 4) {
                        tree1->DeleteCurrentNode();
                    }
                    if (command == 5) {
                        tree1->CleanTree();
                    }
                    if (command == 6) {
                        tree1->MoveInStructure();
                    }
                    if (command == 7) {
                        tree1->DisplayTree();
                    }
                    if (command == 8) {
                        break;
                    }

                }
            }
        }
        if (a == 3) {
            cout << "1. Сравнить по году" << endl;
            cout << "2. Сравнить по цене" << endl;
            cout << "3. Выйти" << endl;
            cout << "Выберите пункт меню: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:

                    if (tree->CompareYear() > tree1->CompareYear()) {
                        cout << "Год больше" << endl;
                    } else {
                        cout << "Год меньше" << endl;
                    }
                    break;
                case 2:
                    if (tree->ComparePrice() > tree1->ComparePrice()) {
                        cout << "Цена больше" << endl;
                    } else {
                        cout << "Цена меньше" << endl;
                    }
                    break;
                case 3:
                    break;
                default:
                    cout << "Неверный пункт меню" << endl;
                    break;
            }
        }
    }
}

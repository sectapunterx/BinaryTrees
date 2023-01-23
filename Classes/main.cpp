#include <iostream>
#include <windows.h>
#include "header.h"
using namespace std;
using namespace N;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    BinaryTreeElements zxc;
    BinaryTreeElements* treeRoot = new BinaryTreeElements();
    BinaryTreeElements* treeCurrent;

    cout << "Если вы хотите создать бинарное дерево выбирите 'y', если нет, нажмите 'n'" << endl;
    char choice;
    cin >> choice;
    if(choice == 'y')
    {
        int command;
        cout << "Введите информацию о корне дерева" << endl;
        zxc.InsertElement();
        treeCurrent = treeRoot;
        cout << "Корневой элемент создан, его адрес: " << treeRoot << endl;
        while(1) {
            cout << "Введите команду для вызова функции: " << endl;
            cout << "1 - Посчитать количество элементов в дереве" << endl;
            cout << "2 - Для добавления элемента в дерево" << endl;
            cout << "3 - Для вставки дочернего элемента в структуру данных" << endl;
            cout << "4 - Для удаления текущего элемента из структуры данных" << endl;
            cout << "5 - Для удаления всей структуры данных" << endl;
            cout << "6 - Для перемещения по структуре данных" << endl;
            cout << "7 - Для вывода информации о текущем элементе" << endl;
            cout << "9 - Для выхода из программы" << endl;
            cin >> command;
            if (command == 1) {
                int s = zxc.Size();
                cout << s << endl;
            }
            if (command == 2) {
                zxc.AddElement();
            }
            if (command == 3) {
                zxc.InsertingChildElementForCurrentElement();
            }
            if (command == 4) {
                if(treeCurrent == treeRoot)
                {
                    cout << "Нельзя удалить корневой элемент" << endl;
                }
                else
                {
                    cout << "Удаленный адрес: " << treeCurrent << endl;
                    treeCurrent = zxc.DeleteCurrentNode();
                    cout << "Текущий адрес: " << treeCurrent << endl;
                }
            }
            if (command == 5) {
                zxc.CleanTheStructure();
            }
            if (command == 6) {
                treeCurrent = zxc.MoveInStructure();
            }
            if (command == 7) {
                zxc.DisplayTree(treeCurrent);
            }
            if (command == 8) {
                cout << "Выход из программы" << endl;
                return 0;
            }
        }
    }
    else
    {
        cout << "Программа завершила работу" << endl;
        return 0;
    }

    return 0;
}

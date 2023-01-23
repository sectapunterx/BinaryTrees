#include "headerrr.h"

using namespace std;
using namespace header;

void Tree::Insert()
{
    Auto* asd = new Auto();
    if (root == NULL)
    {
        root = asd;
        cout << "Корень: " << root << endl;
        now = root;
    }
}


bool Auto::EmptyLeft()
{
    return this->left == nullptr;
}

bool Auto::EmptyRight()
{
	return this->right == nullptr;
}

Auto* Auto::GetLeft()
{
	return left;
}
Auto* Auto::GetRight()
{
	 return right;
}
Auto* Auto::GetParent()
{
    return parent;
}

Auto * Auto::AddLeft(Auto *asd)
{
    this->left = asd;
	asd->parent=this;
    return this->left;
}
Auto * Auto::AddRight(Auto *asd)
{
    this->right = asd;
	asd->parent=this;
    return this->right;
}

string Auto::CheckYear() {
    return this->year;
}
string Auto::CheckPrice() {
    return this->price;
}

string Tree::ComparePrice() {
    return this->now->CheckPrice();
}
string Tree::CompareYear() {
    return this->now->CheckYear();
}

/*void Tree::ShowCompareMenu() {
    cout << "1. Сравнить по цене" << endl;
    cout << "2. Сравнить по году" << endl;
    cout << "3. Выйти" << endl;
    cout << "Выберите пункт меню: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        if () {
            cout << "Цена больше" << endl;
        }
        else {
            cout << "Цена меньше" << endl;
        }
        break;
    case 2:
        if (tree->ComparePrice() > tree1->ComparePrice()) {
            cout << "Год больше" << endl;
        }
        else {
            cout << "Год меньше" << endl;
        }
        break;
    case 3:
        break;
    default:
        cout << "Неверный пункт меню" << endl;
        break;
    }
}*/

void Tree::ShowMenu() {
    int command = 0;
    while(1) {
        if (command != 8) {
            int size = 0;
            cout << "Введите команду для вызова функции: " << endl;
            cout << "1 - Посчитать количество элементов в дереве" << endl;
            cout << "2 - Для добавления элемента в дерево" << endl;
            cout << "3 - Для вставки дочернего элемента в структуру данных" << endl;
            cout << "4 - Для удаления текущего элемента из структуры данных" << endl;
            cout << "5 - Для удаления всей структуры данных " << endl;
            cout << "6 - Для перемещения по структуре данных" << endl;
            cout << "7 - Для вывода информации о текущем элементе" << endl;
            cout << "8 - Для возвращения к выбору дерева" << endl;
            cin >> command;
            if (command == 1) {
                cout << "Количество элементов: " << Size() << endl;
            }
            if (command == 2) {
                AddElement();
            }
            if (command == 3) {
                InsertChild();
            }
            if (command == 4) {
                DeleteCurrentNode();
            }
            if (command == 5) {
                CleanTree();
            }
            if (command == 6) {
                MoveInStructure();
            }
            if (command == 7) {
                DisplayTree();
            }
            /*if (command == 8) {
                ShowCompareMenu();
            }*/

        }
    }
}

void Tree::AddElement()
{
    Auto* auto1 = new Auto();
    if (root == NULL)
    {
        root = auto1;
        cout << root << endl;
        now = root;
    }
    else
    {
        now = root;
        cout << "Введите 'l' для добавления элемента слева, 'r' для добавления элемента справа: ";
        char side;
        cin >> side;
        if (side == 'l')
        {
            if (this->now->EmptyLeft())
            {
                //now = this->now->AddLeft(auto1);
				this->now->AddLeft(auto1);
            }
            else
            {
                cout << "Элемент уже существует" << endl;
            }
        }
        else if (side == 'r')
        {
            if (this->now->EmptyRight())
            {
                //now = this->now->AddRight(auto1);
				this->now->AddRight(auto1);
            }
            else
            {
                cout << "Элемент уже существует" << endl;
            }
        }
        }
}
void Tree::InsertChild()
{
    cout << "Введите 'l' для добавления элемента слева, 'r' для добавления элемента справа: ";
    char side;
    cin >> side;
    Auto * auto1 = new Auto();

    if(root == nullptr)
    {
        root = auto1;
        cout << "Корень: " << root << endl;
        now = root;
    }
    else
    {
        if (side == 'l')
        {
            if (this->now->EmptyLeft()) {
                this->now->AddLeft(auto1);
            }
            else
            {
                cout << "Элемент уже существует" << endl;
            }
        }
        else if (side == 'r')
        {
            if (this->now->EmptyRight()) {
                this->now->AddRight(auto1);
            }
            else
            {
                cout << "Элемент уже существует" << endl;
            }
        }
    }
}


int Tree::Size()
{
    int size = 0;
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        size++;
        if (this->now->GetLeft() != nullptr)
        {
            this->now = this->now->GetLeft();
            size += Size();
        }
        if (this->now->GetRight() != nullptr)
        {
            this->now = this->now->GetRight();
            size += Size();
        }
    }
    return size;
}

int Auto::treesize() {
    int size = 0;
    if (this->left != nullptr) {
        size += this->left->treesize();
    }
    if (this->right != nullptr) {
        size += this->right->treesize();
    }
    return size + 1;
}

int Tree::treesize() {
    return this->root->treesize();
}

Auto* Auto::ChangeLeft(Auto *tmp)
{
    ChangeLeft(tmp);
    this->left = tmp;
    return this->left;
}
Auto* Auto::ChangeRight(Auto *tmp)
{
    ChangeRight(tmp);
    this->right = tmp;
    return this->right;
}
//????????
void Tree::DeleteNode(Auto* f)
{
    if(now == nullptr)
        return;
	if(this->now->GetLeft())
    DeleteNode(this->now->GetLeft());
	if(this->now->GetRight())
    DeleteNode(this->now->GetRight());
    delete this->now;

}
//???????????
void Tree::DeleteCurrentNode()
{
   // if(this->now->GetParent() == nullptr)
   // {
        //DeleteNode(this->now);
	Auto *tmp = this->now->GetParent();	
	delete this->now;
     //   cout << "Удаление корня" << endl;
       // return nullptr;
  //  }
  //  else
   /* {
        if(this->now->GetParent()->GetLeft() == this->now)
        {
            //null pointer to member
            this->now->GetParent()->ChangeLeft(nullptr);
            DeleteNode(this->now);
            cout << "Удаление левого элемента с адресом: " << this << endl;
            this->now = this->now->GetParent();
            return this->now;
        }
        else
         {
            this->now->GetParent()->ChangeRight(nullptr);
            cout << "Удаление правого элемента с адресом " << this << endl;
             DeleteNode(this->now);
             this->now = this->now->GetParent();
            return this->now;
        }
    }*/

	now=tmp;
	root=tmp;
    //return  tmp;

}

void Tree::MoveInStructure()
{
    Auto* tmp = this->now;
	cout << "Введите 'l' для перехода в левый элемент, 'r' для перехода в правый элемент: ";
    char side;
    cin >> side;
    if (side == 'l')
    {
        if (!this->now->EmptyLeft())
        {
            now = this->now->GetLeft();
        }
        else
        {
            cout << "Элемент не существует" << endl;
        }
    }
    else if (side == 'r')
    {
        if (!this->now->EmptyRight())
        {
            now = this->now->GetRight();
        }
        else
        {
            cout << "Элемент не существует" << endl;
        }
    }
    cout << "Предыдущий элемент: " << tmp << "Текущий элемент: " << now << endl;
}

void Auto::DisplayTree()
{
    //print info about current node
    cout << this << endl;
    /*cout << "Автомобиль: " << this->name << endl;
    cout << "Цвет: " << this->color << endl;
    cout << "Цена: " << this->price << endl;
    cout << "Адрес: " << this << endl;
    cout << "Родитель: " << this->parent << endl;
    cout << "Левый элемент: " << this->left << endl;
    cout << "Правый элемент: " << this->right << endl;
    cout << endl;*/
}

void Tree::DisplayTree()
{
    //print info about current node
    this->now->DisplayTree();
}

void Tree::CleanTree()
{
    DeleteNode(root);
    root = nullptr;
    now = nullptr;
    cout << "Дерево очищено" << endl;
}
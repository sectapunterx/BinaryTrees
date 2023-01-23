#pragma once

#include <iostream>
#include <string>
using namespace std;


//Класс с переменными автомобиля и функциями с ними
namespace header {
    class Auto {

    protected:
        string name;
        string color;
        string year;
        string mileage;
        string price;
	private:
		 Auto* left;
        Auto* right;
        Auto* parent;

    public:

        //перегрузить оператор >
        const bool operator > (Auto* asd) {
            return this->year > asd->year && this->price > asd->price;
        }
        //перегрузить оператор <
        const bool operator < (Auto* asd) {
            return this->year < asd->year && this->price < asd->price;
        }
        //перегрузить оператор >=
        const bool operator >= (Auto* asd) {
            return this->price >= asd->price && this->year >= asd->year;
        }
        //перегрузить оператор <=
        const bool operator <= (Auto* asd) {
            return this->price <= asd->price && this->year >= asd->year;
        }
        //перегрузить оператор ==
        const bool operator == (Auto* asd) {
            return this->year == asd->year && this->price == asd->price ;
        }
        //перегрузить оператор <<
        friend ostream& operator << (ostream& out, Auto* asd) {
            out << "Название: " << asd->name << endl;
            out << "Цвет: " << asd->color << endl;
            out << "Год выпуска: " << asd->year << endl;
            out << "Пробег: " << asd->mileage << endl;
            out << "Цена: " << asd->price << endl;
            return out;
        }
        //перегрузить оператор >>
        friend istream& operator >> (istream& in, Auto* asd) {
            in >> asd->name >> asd->color >> asd->year >> asd->mileage >> asd->price;
            return in;
        }

        void DisplayTree();
         Auto * AddLeft(Auto* auto1);
		 Auto * AddRight(Auto* auto1);
		 Auto * GetLeft();
		 Auto * GetRight();
         Auto * GetParent();

         int treesize();

         string CheckYear();
         string CheckPrice();

         Auto* ChangeLeft(Auto* tmp);
         Auto* ChangeRight(Auto* tmp);
		 bool EmptyLeft();
		  bool EmptyRight();
        Auto()
        {
            cout << "Конструктор автомобиля" << endl;
            cout << "Введите название автомобиля: ";
            cin >> this->name;
            cout << "Введите цвет автомобиля: ";
            cin >> this->color;
            cout << "Введите год выпуска автомобиля: ";
            cin >> this->year;
            cout << "Введите пробег автомобиля: ";
            cin >> this->mileage;
            cout << "Введите цену автомобиля: ";
            cin >> this->price;
            //cout << "Корень: " << this << endl;
            /*name = "No name";
            color = "No color";
            year = "No year";
            mileage = "No mileage";
            price = "No price";*/
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
        Auto(string name, string color, int year, int mileage, int price)
        {
            cout << "Параметрический конструктор автомобиля" << endl;
            this->name = name;
            this->color = color;
            this->year = year;
            this->mileage = mileage;
            this->price = price;
            //cout << "Корень: " << this << endl;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
        Auto(Auto* auto1)
        {
            cout << "Конструктор копирования автомобиля" << endl;

            cout << "Введите название автомобиля: ";
            cin >> this->name;
            this->name = auto1->name;
            cout << "Введите цвет автомобиля: ";
            cin >> this->color;
            this->color = auto1->color;
            cout << "Введите год выпуска автомобиля: ";
            cin >> this->year;
            this->year = auto1->year;
            cout << "Введите пробег автомобиля: ";
            cin >> this->mileage;
            this->mileage = auto1->mileage;
            cout << "Введите цену автомобиля: ";
            cin >> this->price;
            this->price = auto1->price;
            //cout << "Корень: " << this << endl;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
        ~Auto()
        {
			if(this->parent != nullptr)
				if (this->parent->left==this)
				{
					this->parent->left=NULL;
					cout << "Удаление левого элемента с адресом: " << this << endl;
				}
				else 
				{
						this->parent->right=NULL;
						cout << "Удаление правого элемента с адресом: " << this << endl;
				}
			else  cout << "Удаление корня" << endl;
			
			if(this->left != nullptr)
			{
				delete this->left;
			}
			if(this->right != nullptr)
			{
				delete this->right;
			}
            cout << "Destructor for " <<  this << endl;
        }
    };
//Класс с переменными дерева и функциями с ними
    class Tree {
protected:
        Auto* Auto1;
		 
        Auto* root;
        Auto* now;
        void DeleteNode(Auto* f);
public:
        Tree()
        {
            root = nullptr;
            now = nullptr;
        }
        /*bool isLeft(Tree* q);
        bool isRight(Tree* q);
        bool isRoot(Tree* q);*/



        string CompareYear();
        string ComparePrice();

        int treesize();

        void ShowMenu();
        void ShowCompareMenu();

        void Insert();
        int Size();
        void AddElement();
        void InsertChild();
        void DeleteCurrentNode();
        void MoveInStructure();
        void CleanTree();
		void DisplayTree();

    };
}

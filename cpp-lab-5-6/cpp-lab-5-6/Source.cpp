#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include <iostream>
#include <cstring>


using namespace std;

class Smartphone {
private:
	char* manufacturer;
	char* model;
	int cores;
	double memorycapacity;
	double cost;

public:
	//Определение конструктора без параметров
	Smartphone() {
		manufacturer = nullptr;
		model = nullptr;
		cores = 0;
		memorycapacity = 0;
		cost = 0;
	}
	//Определение конструктора с параметрами
	Smartphone(const char* manufacturerValue, const char* modelValue, int coresValue, double memorycapacityValue, double costValue) {
		manufacturer = new char[strlen(manufacturerValue) + 1];
		strcpy(manufacturer, manufacturerValue);
		model = new char[strlen(modelValue) + 1];
		strcpy(model, modelValue);
		cores = coresValue;
		memorycapacity = memorycapacityValue;
		cost = costValue;
	}
	//Определение конструктора копирования
	Smartphone(Smartphone& other) {
		manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy(manufacturer, other.manufacturer);
		model = new char[strlen(other.model) + 1];
		strcpy(model, other.model);
		cores = other.cores;
		memorycapacity = other.memorycapacity;
		cost = other.cost;
	}
	//Определение деструктора
	~Smartphone() {
		delete[] manufacturer;
		delete[] model;
	}
	//Функции для вывода 
	void printmanufacturer()const {
		cout << "Производитель:" << manufacturer << endl;
	}
	void printmodel()const {
		cout << "Модель:" << model << endl;
	}
	void printcores()const {
		cout << "Количество ядер:" << cores << endl;
	}
	void printmemorycapacity()const {
		cout << "Объём памяти:" << memorycapacity << endl;
	}
	void printcost()const {
		cout << "Цена:" << cost << endl;
	}
	void printAll()const {
		cout << "Производитель:" << manufacturer << endl;
		cout << "Модель:" << model << endl;
		cout << "Количество ядер:" << cores << endl;
		cout << "Объём памяти:" << memorycapacity << endl;
		cout << "Цена:" << cost << endl;
	}
	//Функции для редактирования полей
	void setmanufacturer(const char* manufacturerValue) {
		delete[] manufacturer;
		manufacturer = new char[strlen(manufacturerValue) + 1];
		strcpy(manufacturer, manufacturerValue);
	}
	void setmodel(const char* modelValue) {
		delete[] model;
		model = new char[strlen(modelValue) + 1];
		strcpy(model, modelValue);
	}
	void setcores(int coresValue) {
		cores = coresValue;
	}
	void setmemorycapacity(double memorycapacityValue) {
		memorycapacity = memorycapacityValue;
	}
	void setcost(double costValue) {
		cost = costValue;
	}
	//Функции для возвращения значений
	char* getmanufacturer() const {
		return manufacturer;
	}
	char* getmodel() const {
		return model;
	}
	int getcores() const {
		return cores;
	}
	double getmemorycapacity() const {
		return memorycapacity;
	}
	double getcost() const {
		return cost;
	}
	//Функция для вывода списка всех смартфонов производителя Х
	static void List1(Smartphone** smartphone, int n, const char* manufacturer) {
		for (int i = 0; i < n; i++) {
			if (strcmp(smartphone[i]->manufacturer, manufacturer) == 0) {//Сравнение текущего производителя и данного
				cout << smartphone[i]->manufacturer << endl;
				cout << smartphone[i]->model << endl;
				cout << smartphone[i]->cores << endl;
				cout << smartphone[i]->memorycapacity << endl;
				cout << smartphone[i]->cost << endl;

			}
		}
	}
	//Функция для вывода списка смартфонов, у которых количество ядер больше N
	static void List2(Smartphone** smartphone, int n, int N) {
		for (int i = 0; i < n; i++) {
			if ((smartphone[i]->cores) > N) {
				cout << smartphone[i]->manufacturer << endl;
				cout << smartphone[i]->model << endl;
				cout << smartphone[i]->cores << endl;
				cout << smartphone[i]->memorycapacity << endl;
				cout << smartphone[i]->cost << endl;

			}
		}
	}

	//Функция для вывода средних стоимостей смартфонов для всех производителей
	static void List3(Smartphone** smartphones, int n) {
		// Перебираем все смартфоны и вычисляем среднюю стоимость для каждого производителя
		for (int i = 0; i < n; i++) {
			char currentManufacturer[50];
			float totalCost = 0;
			int count = 0;

			// Проверяем, есть ли уже данные для текущего производителя
			bool flag = false;
			for (int j = 0; j < i; j++) {
				if (strcmp(smartphones[i]->manufacturer, smartphones[j]->manufacturer) == 0) {
					flag = true;
					break;
				}
			}

			// Если данные для текущего производителя уже собраны, переходим к следующему смартфону 
			if (flag) {
				continue;
			}

			// Иначе проходим по всем смартфонам и находим все смартфоны с текущим производителем
			strcpy(currentManufacturer, smartphones[i]->manufacturer);
			for (int j = 0; j < n; j++) {
				if (strcmp(smartphones[j]->manufacturer, currentManufacturer) == 0) {
					totalCost += smartphones[j]->cost;
					count++;
				}
			}

			// Вычисляем среднюю стоимость
			float averageCost = totalCost / count;

			// Выводим результат
			cout << "Средняя стоимость смартфонов производителя " << currentManufacturer << ": " << averageCost << endl;

		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	Smartphone one("Apple", "X", 6, 256, 100000);
	one.printAll();

	Smartphone two;
	two.setmanufacturer("Samsung");
	two.setmodel("Galaxy S23");
	two.setcores(8);
	two.setmemorycapacity(512);
	two.setcost(70000);
	two.printmanufacturer();
	two.printmodel();
	two.printcores();
	two.printmemorycapacity();
	two.printcost();

	Smartphone three(one);
	three.setmodel("XI");
	three.setcores(7);
	three.setmemorycapacity(128);
	three.setcost(120000);
	three.printAll();

	Smartphone* smartphone[3] = { &one, &two , &three };
	cout << "List of all smartphones from manufacturer X:" << endl;
	Smartphone::List1(smartphone, 3, "Apple");
	cout << "List of all models with more than N cores:" << endl;
	Smartphone::List2(smartphone, 3, 5);
	cout << "List of average smartphone prices for all manufacturers:" << endl;
	Smartphone::List3(smartphone, 3);

	return 0;
}

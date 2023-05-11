#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

struct arr {
	int* pointer = nullptr;
	int length = 0;
};

struct route {
	int routeNumber;
	float price;
	char firstStation[50]{};
	char lastStation[50]{};
};

void init(arr& arr, int length);

void show(arr& arr);

void app(arr& arr);

int& el(arr& arr, int index);

void clear(arr& arr);

void changeSymbol(std::string& str, char ch1, char ch2);

void routeShow(route& r);

float calculationOfTheFare(float price, int numPassenger, uint8_t procentKids);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	// Задача 1.
	std::cout << "Задача 1.\n";
	/*
		Создайте структуру arr, в которой содержатся поля:
	 int* pointer – указатель на динамический массив. 
	По умолчанию содержит значение nullptr;
	 int length – размер массива. По умолчанию равен 
	нулю.
	Создайте следующие функции для работы с данной 
	структурой:
	 init – инициализация массива и его длины. Массив 
	должен состоять из нулей. Работает только в том случае, 
	если в указателе pointer содержится значение nullptr;
	 show – вывод в цикле содержимого всего массива 
	на экран;
	 app – увеличение размера массива на один 
	элемент, в который записывается переданное значение;
	 el – обращение к элементу массива под 
	переданным в функцию индексом;
	 clear – освобождение памяти, выделенной под 
	массив, хранящийся в объекте, а также обнуление его 
	длины. В указатель должно записываться значение 
	nullptr.
	*/

	arr massive;

	init(massive, 10);

	show(massive);

	app(massive);

	show(massive);
	for (int i = 0; i < 10; ++i) {
		el(massive, i) = i + 1;
	}

	show(massive);

	clear(massive);

	show(massive);

	// Задача 2.
	std::cout << "\n\n\nЗадача 2.\n";
	/*
		Напишите функцию, которая принимает строку и 
	символы ch1 и ch2. Функция ищет в переданной строке 
	все символы ch1 и меняет их на символы ch2. Учтите, 
	что строка должна передаваться по ссылке.
	*/
	std::string str = "C:/Users/Maksim/Downloads/Домашнее задание";
	std::cout << "Исходная строка:\n";
	std::cout << str << std::endl;
	changeSymbol(str, '/', '\\');
	std::cout << "Конечная строка:\n";
	std::cout << str << std::endl;


	// Задача 3.
	std::cout << "\n\n\nЗадача 3.\n";
	/*
		Создайте структуру route, которая описывает 
	транспортный маршрут и содержит следующие поля:
	 номер маршрута;
	 цена за проезд;
	 остановка начала маршрута;
	 конечная остановка.
	Создайте следующие функции для работы с данной 
	структуры:
	 функция, выводящая информацию об объекте;
	 функция, которая вычисляет стоимость проезда 
	для определённого количества человек, которое 
	передаётся в функцию. Также в функцию передаётся
	процент детей (от 0 до 100) среди этих пассажиров. Для 
	детей проезд в два раза дешевле.
	*/
	
	route r1{77, 32.5, "Театр \"Ироничная компания\"", "Кислотные дачи"};

	routeShow(r1);
	std::cout << "Введите количество пассажиров -> ";
	int numPass = 0;
	std::cin >> numPass;
	int kidsProcent = 0;
	std::cout << "Введите процент детей -> ";
	std::cin >> kidsProcent;
	std::cout << "Общая стоимость проезда - ";
	std::cout << calculationOfTheFare(r1.price, numPass, kidsProcent) << std::endl;

	return 0;
}

void init(arr& arr, int length) {
	if (arr.pointer == nullptr) {
		arr.length = length;
		arr.pointer = new int[arr.length] {};
	}
}

void show(arr& arr) {
	if (arr.pointer != nullptr) {
		for (int i = 0; i < arr.length; ++i) {
			std::cout << arr.pointer[i] << '\t';
		}
		std::cout << std::endl;
	}
}

void app(arr& arr) {
	int* tmp = new int[arr.length + 1] {};
	for (int i = 0; i < arr.length; ++i) {
		tmp[i] = arr.pointer[i];
	}
	delete[] arr.pointer;
	arr.pointer = tmp;
	arr.length++;
}

int& el(arr& arr, int index) {
	return arr.pointer[index];
}

void clear(arr& arr) {
	if (arr.pointer != nullptr) {
		delete[] arr.pointer;
		arr.pointer = nullptr;
		arr.length = 0;
	}

}

void changeSymbol(std::string& str, char ch1, char ch2) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ch1) {
			str[i] = ch2;
		}
	}
}


void routeShow(route& r) {
	std::cout << "Номер маршрута: " << r.routeNumber << std::endl;
	std::cout << "Цена за проезд: " << r.price << std::endl;
	std::cout << "Остановка начала маршрута: " << r.firstStation << std::endl;
	std::cout << "Конечная остановка маршрута: " << r.lastStation << std::endl;
}

float calculationOfTheFare(float price, int numPassenger, uint8_t procentKids) {
	int numAdult = (int)(numPassenger - numPassenger * procentKids / 100.0);
	int numKids = numPassenger - numAdult;
	return price * numAdult + price/2 * numKids;
}
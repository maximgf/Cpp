// Geometryfigure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "GeometryFigure.h"
#include <iostream>

int main() {
    std::vector <GeometricFigure<double>*> figures;

    Circle<double> circle(Point<double>(0, 0), 5.0);
    Ellipse<double> ellipse(Point<double>(0, 0), 3.0, 2.0);
    Triangle<double> triangle(Point<double>(0, 0), Point<double>(3, 0), Point<double>(0, 4));
    Rectangle<double> rectangle(Point<double>(0, 0), Point<double>(3, 0), Point<double>(3, 4), Point<double>(0, 4));
    Polygon<double> polygon("granitsy-uchastka2.txt");
    figures.push_back(&circle);
    figures.push_back(&ellipse);
    figures.push_back(&triangle);
    figures.push_back(&rectangle);
    figures.push_back(&polygon);

    for (const auto& figure : figures) {
        figure->name();
        std::cout << "Area: " << figure->calc_area() << std::endl;
        std::cout << "Perimeter: " << figure->calc_perimeter() << std::endl << "\n";
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

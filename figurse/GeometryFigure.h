#pragma once
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
#include <vector>
#include <fstream>


//Заготовки


template<class T>
class Point {
public:
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
};

template<class T>
class GeometricFigure {
public:
    virtual T calc_area() = 0;
    virtual T calc_perimeter() = 0;
    virtual void name() = 0;
};


//Circle

//Заголовки
template<class T> class Circle : public GeometricFigure<T> {
private:
    Point<T> center;
    T radius;

public:
    Circle(Point<T> c, T r) : center(c), radius(r) {} // Определение конструктора здесь

    T calc_area() override;
    T calc_perimeter() override;
    void name() override;
};

//Определение
template<class T>
T Circle<T>::calc_area() {
    return M_PI * radius * radius;
}

template<class T>
T Circle<T>::calc_perimeter() {
    return 2 * M_PI * radius;
}

template<class T>
void Circle<T>::name() {
    std::cout << "Circle" << std::endl;
}


//Ellipse

//Заголовки
template<class T>
class Ellipse : public GeometricFigure<T> {
private:
    Point<T> center;
    T a, b;

public:
    Ellipse(Point<T> c, T a, T b) : center(c), a(a), b(b) {}

    T calc_area() override;
    T calc_perimeter() override;
    void name() override;
};

//Определения
template<class T>
T Ellipse<T>::calc_area() {
    return M_PI * a * b;
}

template<class T>
T Ellipse<T>::calc_perimeter() {
    return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

template<class T>
void Ellipse<T>::name() {
    std::cout << "Ellipse" << std::endl;
}


//Triangle

//Заголовки
template<class T>
class Triangle : public GeometricFigure<T> {
private:
    Point<T> vertices[3];

public:
    Triangle(Point<T> a, Point<T> b, Point<T> c) : vertices{ a, b, c } {}

    T calc_area() override;
    T calc_perimeter() override;
    void name() override;
};

//Определения
template<class T>
T Triangle<T>::calc_area() {
    T a = sqrt((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x) + (vertices[1].y - vertices[0].y)) *(vertices[1].y - vertices[0].y));
    T b = sqrt((vertices[2].x - vertices[1].x) *(vertices[2].x - vertices[1].x) + (vertices[2].y - vertices[1].y)* (vertices[2].y - vertices[1].y));
    T c = sqrt((vertices[0].x - vertices[2].x)*(vertices[0].x - vertices[2].x) + (vertices[0].y - vertices[2].y)*(vertices[0].y - vertices[2].y));
    T s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

template<class T>
T Triangle<T>::calc_perimeter() {
    T a = sqrt((vertices[1].x - vertices[0].x) * (vertices[1].x - vertices[0].x) + (vertices[1].y - vertices[0].y) * (vertices[1].y - vertices[0].y));
    T b = sqrt((vertices[2].x - vertices[1].x) * (vertices[2].x - vertices[1].x) + (vertices[2].y - vertices[1].y) * (vertices[2].y - vertices[1].y));
    T c = sqrt((vertices[0].x - vertices[2].x) * (vertices[0].x - vertices[2].x) + (vertices[0].y - vertices[2].y) * (vertices[0].y - vertices[2].y));
    return a + b + c;
}

template<class T>
void Triangle<T>::name() {
    std::cout << "Triangle" << std::endl;
}


//Rectangle

//Заголовки
template<class T>
class Rectangle : public GeometricFigure<T> {
private:
    Point<T> vertices[4];

public:
    Rectangle(Point<T> a, Point<T> b, Point<T> c, Point<T> d) : vertices{ a, b, c, d } {}

    T calc_area() override;
    T calc_perimeter() override;
    void name() override;
};

//Определения
template<class T>
T Rectangle<T>::calc_area() {
    T width = sqrt((vertices[1].x - vertices[0].x) * (vertices[1].x - vertices[0].x) + (vertices[1].y - vertices[0].y) * (vertices[1].y - vertices[0].y));
    T height = sqrt((vertices[2].x - vertices[1].x) * (vertices[2].x - vertices[1].x) + (vertices[2].y - vertices[1].y) * (vertices[2].y - vertices[1].y));
    return width * height;
}

template<class T>
T Rectangle<T>::calc_perimeter() {
    T width = sqrt((vertices[1].x - vertices[0].x) * (vertices[1].x - vertices[0].x) + (vertices[1].y - vertices[0].y) * (vertices[1].y - vertices[0].y));
    T height = sqrt((vertices[2].x - vertices[1].x) * (vertices[2].x - vertices[1].x) + (vertices[2].y - vertices[1].y) * (vertices[2].y - vertices[1].y));
    return 2 * (width + height);
}

template<class T>
void Rectangle<T>::name() {
    std::cout << "Rectangle" << std::endl;
}


//Polygon

//Заголовки
template<class T>
class Polygon : public GeometricFigure<T> {
private:
    std::vector<Point<T>> vertices;

public:
    Polygon(const std::string& filename);

    T calc_area() override;
    T calc_perimeter() override;
    void name() override;
};

//Определения
template<class T>
//Конструктор по заданному файлу
Polygon<T>::Polygon(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    int numVertices;
    file >> numVertices;
    for (int i = 0; i < numVertices; ++i) {
        T x, y;
        file >> x >> y;
        vertices.emplace_back(x, y);
    }
    file.close();
}

template<class T>
T Polygon<T>::calc_area() {
    T area = 0.0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        area += (vertices[i].x * vertices[(i + 1) % n].y) - (vertices[(i + 1) % n].x * vertices[i].y);
    }
    return 0.5 * std::abs(area);
}

template<class T>
T Polygon<T>::calc_perimeter() {
    T perimeter = 0.0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        perimeter += sqrt((vertices[(i + 1) % n].x - vertices[i].x) * (vertices[(i + 1) % n].x - vertices[i].x) + (vertices[(i + 1) % n].y - vertices[i].y) * (vertices[(i + 1) % n].y - vertices[i].y));
    }
    return perimeter;
}

template<class T>
void Polygon<T>::name() {
    std::cout << "Polygon" << std::endl;
}



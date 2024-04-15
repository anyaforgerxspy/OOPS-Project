#include <iostream>
#include <cmath>


const double PI = 3.14159265358979323846;


class Shape {
public:
    
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};


class Circle : public Shape {
private:
    double radius;
public:
   
    Circle(double r) : radius(r) {}

    
    double area() const override {
        return PI * radius * radius;
    }

    
    double perimeter() const override {
        return 2 * PI * radius;
    }
};


class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    
    Rectangle(double l, double w) : length(l), width(w) {}

   
    double area() const override {
        return length * width;
    }

   
    double perimeter() const override {
        return 2 * (length + width);
    }
};


class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
   
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

   
    double area() const override {
       
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    
    double perimeter() const override {
        return side1 + side2 + side3;
    }
};


int main() {
    
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 4, 5);

    std::cout << "Circle: Area = " << circle.area() << ", Perimeter = " << circle.perimeter() << std::endl;
    std::cout << "Rectangle: Area = " << rectangle.area() << ", Perimeter = " << rectangle.perimeter() << std::endl;
    std::cout << "Triangle: Area = " << triangle.area() << ", Perimeter = " << triangle.perimeter() << std::endl;

    return 0;
}

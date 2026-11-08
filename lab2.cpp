#include<iostream>
using namespace std;
class shape
{
    public:
         virtual float area() = 0; // pure virtual function
};
    class Circle : public shape
    {
    private:
        float radius;   
    public:
       Circle(float r)
        {
            radius = r;
        
        }
        float area()
        {
            return 3.14 * radius * radius;
        }
    };    
        class Rectangle : public shape
        {
        private:
            float length,breadth;
            
    
        public:
              Rectangle(float l, float b) 
            {   
                length = l;
                breadth = b;
            }
            float area()
            {
                return length * breadth;
            }
        };
    class Triangle : public shape
    {
    private:
        float base;
        float height;
    public:
        //constructor
        Triangle(float b, float h)
        {
            base = b;
            height = h;
        }
        float area()
        {
            return 0.5 * base * height;
        }
    };
    int main()
    {
        Circle c(5);
        Rectangle r(4,6);
        Triangle t(3,4);
        shape*ptr;
        ptr=&c;

        cout << "Area of circle: " << ptr->area() << endl;
        ptr=&r;
        cout << "Area of rectangle: " << ptr->area() << endl;
        ptr=&t;
        cout << "Area of triangle: " << ptr->area() << endl;
        return 0;
    };
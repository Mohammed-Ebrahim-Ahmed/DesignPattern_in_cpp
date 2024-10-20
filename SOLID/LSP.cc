#include <iostream>


class Rectangle
{
protected:
    int width;
    int height;

public:
    Rectangle(int width, int height): width{width}, height{height}{}

    int getHeight() {

    	return this->height;

    }

    virtual void setHeight(int height) {

    	this->height = height;

    }

    int getWidth() {
    	return this->width;
    }
    virtual void setWidth(int width) {
    	this->width = width;
    }

    int area() const {
        return width * height;
    }
};

class Square : public Rectangle {

public:
    Square(int size) : Rectangle(size, size) {}

    void setWidth(int width) override{
        this->width = this->height = width;
    }

    void setHeight(int height) override{
        this->width = this->height = height;
    }

};
void process(Rectangle& r)
{
    int w = r.getWidth();
    r.setHeight(10);

    std::cout << "Expected area = " << w*10 << ", got " << r.area() << std::endl;
}


int main(){

    Rectangle Rect{2,3};

    process(Rect);

    Square sq{5};
    process(sq);
    return 0;
}
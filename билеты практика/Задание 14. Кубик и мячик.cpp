#include <iostream>

class Body {
protected:
    int x = 0, y = 0, z = 0;
    float jumpable;
public:
    Body() {
        jumpable = rand() % 6 + 1;
    }
    virtual int dropIt(int force) = 0;
};

class Dice : public Body {
    int num = 1;
public:
    int dropIt(int force) override {
        int total = force * jumpable * y;
        num = (total % 6) + 1;
        return num;
    }
};

class Ball : public Body {
    int jump_height = 0;
public:
    int dropIt(int force) override {
        if (y == 0) jump_height = 0;
        else if (force == 0) jump_height = y * jumpable;
        else jump_height = y * jumpable * force;
        return jump_height;
    }
};

int main() {
    srand(time(NULL));
    Dice dice;
    Ball ball;
    std::cout << dice.dropIt(10) << std::endl;
    std::cout << ball.dropIt(10);
}

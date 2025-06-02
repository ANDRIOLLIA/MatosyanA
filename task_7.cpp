#include <iostream>

class MyArr {
private:
    int* data;
    size_t size;
public:
    MyArr() : data(nullptr), size(0) {}
    MyArr(size_t n) : data(new int[n] {}), size(n) {}
    ~MyArr() { std::cout << "yaica"; }
    MyArr(MyArr&& other) : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    MyArr& operator=(MyArr&& a) {
        if (this != &a) {
            delete[] data;
            data = a.data;
            size = a.size;
            a.data = nullptr;
            a.size = 0;
        }
        return *this;
    }
    MyArr(const MyArr&) = delete;
    MyArr& operator=(const MyArr&) = delete;
    int& operator[](size_t index) {
        return data[index];
    }

    const int& operator[](size_t index) const {
        return data[index];
    }
    
    friend std::ostream& operator<<(std::ostream& out, const MyArr& arr) {
        for (size_t i = 0; i < arr.size; ++i) {
            out << arr.data[i] << " ";
        }
        return out;
    }

    int getSize() const { return size; }
};

MyArr createArr() {
    MyArr arr(5);
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = rand() % 10;
    }
    return arr;
}

int main() {
    MyArr a;
    a = createArr();

    std::cout << "arr: " << a << std::endl;
    return 0;
}
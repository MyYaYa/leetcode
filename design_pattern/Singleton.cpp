#include <iostream>

class Singleton {
private:
    /* Here will be the instance stored. */
    static Singleton* instance;
    /* Private constructor to prevent instancing. */
    Singleton();

public:
    /* Static access method. */
    static Singleton* getInstance();
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance() {
    if (instance == 0) {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton() {}

int main() {
    // new Singleton(); //Won't work
    Singleton* s = Singleton::getInstance();
    Singleton* r = Singleton::getInstance();

    /* The address will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
}
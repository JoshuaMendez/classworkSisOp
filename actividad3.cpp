#include <iostream>

void memoria() {
    int stackVar = 111;
    int* heapVar = new int(222);
    static int staticVar = 333;

    std::cout << "\n=== Segmentos de memoria ===\n";
    std::cout << "stackVar (Stack): " << &stackVar << " Valor: " << stackVar << "\n";
    std::cout << "heapVar (Heap):  " << heapVar << " Valor: " << *heapVar << "\n";
    std::cout << "staticVar (Code/Data): " << &staticVar << " Valor: " << staticVar << "\n";

    delete heapVar;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    int* p = a;
    for (int i = 0; i < 5; ++i) {
        *(p + i) *= 10;
    }

    std::cout << "Contenido del array:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "a[" << i << "] = " << *(p + i) << "\n";
    }

    std::cout << "\n--- Direcciones ---\n";
    std::cout << "Direccion de a (decay)    : " << a << "   (== &a[0])\n";
    std::cout << "Direccion de a[0]         : " << &a[0] << "\n";
    std::cout << "Direccion del puntero p   : " << &p << "   (direccion propia de p)\n";
    std::cout << "Contenido de p            : " << p << "   (apunta a &a[0])\n";
    std::cout << "Direccion de todo el array: " << &a << "   (mismo valor que &a[0] pero tipo distinto)\n";

    std::cout << "\nsizeof(a)   = " << sizeof(a) << " bytes\n";
    std::cout << "sizeof(*p)  = " << sizeof(*p) << " bytes (tamanio de un int)\n";

    memoria();

    return 0;
}
#include <iostream>

void memoria() {
    int stackVar = 10;
    int* heapVar = new int(20);
    static int staticVar = 30;

    std::cout << "\n=== Segmentos de memoria ===\n";
    std::cout << "stackVar (Stack): " << &stackVar << " Valor: " << stackVar << "\n";
    std::cout << "heapVar (Heap): "  << heapVar << " Valor: " << *heapVar << "\n";
    std::cout << "staticVar (Code/Data): " << &staticVar << " Valor: " << staticVar << "\n";

    delete heapVar;
}

int main() {
    int x = 42;
    std::cout << "Valor inicial de x: " << x << "\n";
    std::cout << "Direccion de x: " << &x << "\n";

    int* p = &x;
    *p = 99;

    std::cout << "Nuevo valor de x (via puntero): " << x << "\n";
    std::cout << "Direccion de x (igual que antes): " << &x << "\n";

    memoria();

    return 0;
}
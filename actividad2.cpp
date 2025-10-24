#include <iostream>

void memoria() {
    int stackVar = 100;
    int* heapVar = new int(200);
    static int staticVar = 300;

    std::cout << "\n=== Segmentos de memoria ===\n";
    std::cout << "stackVar (Stack): " << &stackVar << " Valor: " << stackVar << "\n";
    std::cout << "heapVar (Heap): " << heapVar << " Valor: " << *heapVar << "\n";
    std::cout << "staticVar (Code/Data): " << &staticVar << " Valor: " << staticVar << "\n";

    delete heapVar;
}

int main() {
    int x = 10;
    std::cout << "Valor inicial de x: " << x << "\n";

    int* ptr = &x;

    std::cout << "Valor via *ptr: " << *ptr << "\n";
    *ptr = 20;
    std::cout << "Nuevo valor de x tras *ptr=20: " << x << "\n";

    int& ref = x;
    ref = 30;
    std::cout << "Nuevo valor de x tras ref=30: " << x << "\n";

    std::cout << "\n--- Direcciones ---\n";
    std::cout << "Direccion de x (&x):        " << &x << "\n";
    std::cout << "Contenido de ptr (direccion de x): " << ptr << "\n";
    std::cout << "Direccion del puntero (&ptr): " << &ptr << "\n";
    std::cout << "Direccion de la referencia (&ref): " << &ref << " (igual a &x)\n";

    memoria();

    return 0;
}
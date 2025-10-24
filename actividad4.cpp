#include <iostream>
#include <memory>

using namespace std;

void memoria(int** A, int filas, int cols) {
    int stackVar = 111;
    static int staticVar = 222;
    int* heapVar = new int(333);

    cout << "\n=== Segmentos de memoria ===\n";
    cout << "Direccion de funcion memoria (CODE): " << (void*)&memoria << '\n';
    cout << "staticVar (DATA): " << &staticVar << "  Valor: " << staticVar << '\n';
    cout << "stackVar  (STACK): " << &stackVar  << "  Valor: " << stackVar  << '\n';
    cout << "heapVar   (HEAP):  " << heapVar    << "  Valor: " << *heapVar  << '\n';

    if (A && filas > 0 && cols > 0) {
        cout << "\n--- Matriz 2D dinamica (new) ---\n";
        cout << "A (arreglo de punteros en HEAP): " << A << '\n';
        cout << "&A[0] (dir del primer puntero):  " << &A[0] << '\n';
        cout << "A[0] (dir de la fila 0 en HEAP): " << A[0] << '\n';
        cout << "&A[0][0] (primer entero):        " << &A[0][0] << '\n';

        if (filas > 1) {
            cout << "A[1] (dir de la fila 1 en HEAP): " << A[1] << "  (puede no ser contigua a A[0])\n";
        }
    }

    delete heapVar;
}

int main() {
    int filas, cols;
    cout << "Filas: ";  if (!(cin >> filas) || filas <= 0) return 0;
    cout << "Columnas: "; if (!(cin >> cols) || cols <= 0) return 0;

    unique_ptr<int[]> data(new int[filas * cols]);

    unique_ptr<int*[]> A(new int*[filas]);
    for (int i = 0; i < filas; ++i) A[i] = data.get() + i * cols;

    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < cols; ++j)
            A[i][j] = i * cols + j;

    cout << "\nMatriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) cout << A[i][j] << ' ';
        cout << '\n';
    }

    cout << "\n=== Direcciones (contiguo) ===\n";
    cout << "data (bloque contiguo):    " << data.get() << '\n';
    cout << "A (punteros a filas):      " << A.get() << '\n';
    cout << "A[0]:                      " << A[0] << '\n';
    cout << "&A[0][0]:                  " << &A[0][0] << '\n';

    memoria(A.get(), filas, cols);
    for (int i = 0; i < filas; ++i) delete[] A[i];
        delete[] A.get();
    return 0;
}

#include <iostream>

using namespace std;

int main() {

    int numCorretores;
    std::cin >> numCorretores;

    for (int i = 0; i < numCorretores; i++) {
        cout << "Corretor " << i << ": ";   
    }

    return 0;
}
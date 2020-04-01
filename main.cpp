#include <iostream>
#include <queue>
#include <fstream>

using namespace std;



int main() {

    queue<string> q;
    string st;
    ifstream inFile("../test02.txt");
    int ctr = 1;

    if (!inFile.is_open()) {
        cout << "No pude abrir el file\n";
        exit(1);
    }

    // q ["fase completa"]

    while (inFile >> st) {
        if (st != "{") {
            cout << st << " ";
        }
        else  {
            string tmp;
            // leer cada string hasta encontrar }
            while( inFile >> st && st !=  "}") {
                tmp = tmp + st + " ";
            }
            cout << "[" << ctr << "] ";
            ctr++;
            q.push(tmp);
        }
    }
    cout << endl;

    // imprimir el contenido de cada elemento del queue
    ctr = 1;
    while(!q.empty()) {
        cout << "[" << ctr << "] " << q.front() << endl;
        ctr++;
        q.pop();
    }

    return 0;
}


int stackLL
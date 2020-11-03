
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "funkcje.h"
using namespace std;


int main(int argc, char* argv[])
{
    string sourceFile, targetFile;
    vecpair edges;
    vector <double> queue;
    if (argc == 2) {
        for (int i = 0; i < 2; i++) {
            string arg = argv[i];
            if (arg == "-h") {
                cout << "Sposob uzywania: [nazwa pliku] [-g <plik do odczytu>] [-d <plik do zapisu>]";
                break;
            }
            else {
                cout << "Niepoprawne dane." << endl << "Sposob uzywania: [nazwa pliku] [-g <plik do odczytu>] [-d <plik do zapisu>]" << endl;
                break;
            }
        }
    }
    else if(argc == 5){
        int counter = 0;
        for (int i = 0; i < 5; ++i) {
            string arg = argv[i];
            if (arg == "-g") {
                sourceFile = argv[i + 1];
            }
            else if (arg == "-d") {
                targetFile = argv[i + 1];
            }
            else {
                if (counter++ == 3) {
                    cout << "Nieporawne dane." << endl << "Sposob uzywania: [nazwa pliku] [-g <plik do odczytu>] [-d <plik do zapisu>]";
                }
            }
        }
        if (counter == 3) {
            edges = edgesRead(sourceFile);
            kruskal(edges, queue);
            
        }
        }

    else {
        cout << "Niepoprawne dane." << endl << "Sposob uzywania: [nazwa pliku] [-g <plik do odczytu>] [-d <plik do zapisu>]" << endl;
    }

    return 0;
}

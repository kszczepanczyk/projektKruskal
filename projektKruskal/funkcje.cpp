#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "funkcje.h"

using namespace std;

void obetnij(string& napis)
{
    size_t poczatek = napis.find_first_not_of("(),");
    size_t koniec = napis.find_last_not_of("(),");

    if (poczatek != std::string::npos and koniec != std::string::npos)
        napis = napis.substr(poczatek, koniec - poczatek + 1);
    else
        napis = "";
}

vecpair edgesRead(string sourceFile)
{
    string word;
    vector<double> tempVector;
    vecpair edges;
    ifstream iStream(sourceFile);
    if (iStream) {
        cout << "Udalo sie otworzyc pliczek\n";
        while (iStream >> word)
        {
            obetnij(word);
            float i = stof(word);
            tempVector.push_back(i);
        }
        iStream.close();
        for (int i = 0; i < tempVector.size(); i += 3) {
            edges.push_back({ tempVector[i + 2],{tempVector[i],tempVector[i + 1]} });
        }
        sort(edges.begin(), edges.end());
        for (int i = 0; i < edges.size(); i++) {
            cout << edges[i].first << "  " << edges[i].second.first << "  " << edges[i].second.second << endl;
        }
    }
    else {
        cout << "Nie udalo sie otworzyc pliczku";
    }
    return edges;
}

double maxi(vecpair edges) {
    double max = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].second.first < edges[i].second.second)
            max = edges[i].second.second;
        else
            max = edges[i].second.first;
       }
    return max;
}

int isInQueue(vecpair edges, vector<double> queue, int j) {
    vector<double>::iterator it,it2;
   
    for (int i = 0; i < maxi(edges); i++) {
        it = find(queue.begin(), queue.end(), edges[j].second.first);
        it2 = find(queue.begin(), queue.end(), edges[j].second.second);
        if (it == queue.end() and it2 == queue.end())
            return 1;
        else if (it != queue.end() and it2 != queue.end())
            return 2;
        else if (it != queue.end() and it2 == queue.end())
            return 3;
        else if (it == queue.end() and it2 != queue.end())
            return 4;
        else
            return 0;
    }
}

void kruskal(vecpair edges, vector<double> queue) {
    int i = 0;
    double weight = 0;
    vecpair output;
    queue.push_back(edges[i].second.first);
    queue.push_back(edges[i].second.second);
    weight += edges[i].first;
    output.push_back({ edges[i].second.first,{edges[i].second.second,edges[i].first} });
    while (queue.size() != (maxi(edges) + 1)) {
        i++;
       
        if (isInQueue(edges, queue, i) == 1) {
            queue.push_back(edges[i].second.first);
            queue.push_back(edges[i].second.second);
            output.push_back({ edges[i].second.first,{edges[i].second.second,edges[i].first} });
            weight += edges[i].first;
        }
        else if (isInQueue(edges, queue, i) == 2) {
            cout << "sa" << endl;
        }
        else if (isInQueue(edges, queue, i) == 3) {
            queue.push_back(edges[i].second.second);
            output.push_back({ edges[i].second.first,{edges[i].second.second,edges[i].first} });
            weight += edges[i].first;
        }
        else if (isInQueue(edges, queue, i) == 4) {
            queue.push_back(edges[i].second.first);
            output.push_back({ edges[i].second.first,{edges[i].second.second,edges[i].first} });
            weight += edges[i].first;
        }
        else
            break;

    }
    cout << "przebieg: " << i << endl;
    cout << "\nPRZEBIEG OUTPUT" << output.size() << endl;
    for (int i = 0; i < output.size(); i++) {
        cout << output[i].first << " " << output[i].second.first << " " << output[i].second.second << endl;
    }
    cout << queue.size() << endl;
    cout << weight;
}
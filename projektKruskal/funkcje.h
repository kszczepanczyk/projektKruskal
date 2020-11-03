#pragma once
using namespace std;
typedef vector<pair<double, pair<double, double>>> vecpair;

void obetnij(string&);
vecpair edgesRead(string);
double maxi(vecpair);
void kruskal(vecpair, vector<double>);

#pragma once
#include <string>
using namespace std;

class Mahasiswa {
public:
    string nama, nrp;
    int idkelas;
    Mahasiswa ();
    Mahasiswa (string, string, int);
    ~Mahasiswa ();
};
#pragma once
#include <string>
using namespace std;

class Dosen {
public:
    string nama, nip;
    int idkelas;
    Dosen ();
    Dosen (string, string, int);
    ~Dosen ();
};
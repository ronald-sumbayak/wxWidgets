#pragma once
#include <vector>
#include "Mahasiswa.h"
#include "Dosen.h"
#include "Kelas.h"

class Data {
public:
    std::vector<vector<Mahasiswa>> students;
    std::vector<Dosen> teachers;
    std::vector<Kelas> classes;
    Data ();
    void loadData ();
    void loadMahasiswa ();
    void loadDosen ();
    void loadKelas ();
    ~Data ();
};
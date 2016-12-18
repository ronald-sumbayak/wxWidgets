#include "Data.h"
#include <fstream>
#include "wx/wx.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"
#include <iostream>

Data::Data () {

}

Data::~Data () {

}

void Data::loadData () {
    loadMahasiswa ();
    loadDosen ();
    loadKelas ();
}

void Data::loadMahasiswa () {
    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = wxFileName (stdPaths.GetExecutablePath ()).GetPath () + wxT ("\\mahasiswa.txt");
    std::ifstream input;
    input.open (std::string (src));

    int i = 0;
    Mahasiswa insert;
    students.push_back (vector<Mahasiswa> ());

    while (getline (input, insert.nrp)) {
        if (insert.nrp.c_str ()[0] == '-') {
            students.push_back (vector<Mahasiswa> ());
            i++;
            continue;
        }

        getline (input, insert.nama);
        insert.idkelas = i;
        students[i].push_back (insert);
    }

    input.close ();
}

void Data::loadDosen () {
    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = wxFileName (stdPaths.GetExecutablePath ()).GetPath () + wxT ("\\dosen.txt");
    std::ifstream input;
    input.open (std::string (src));

    int i = 0;
    Dosen insert;
    while (input >> insert.nip) {
        getline (input, insert.nama);
        insert.idkelas = i++;
        teachers.push_back (insert);
    }
}

void Data::loadKelas () {
    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = wxFileName (stdPaths.GetExecutablePath ()).GetPath () + wxT ("\\kelas.txt");
    std::ifstream input;
    input.open (std::string (src));

    int i = 0;
    Kelas insert;
    while (input >> insert.nama >> insert.ruang >> insert.hari >> insert.mulai >> insert.selesai) {
        insert.id = i++;
        classes.push_back (insert);
    }
}
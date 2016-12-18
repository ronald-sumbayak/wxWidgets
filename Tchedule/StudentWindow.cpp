#include "StudentWindow.h"
#include "Mahasiswa.h"

StudentWindow::StudentWindow (wxFrame *frame) : wxWindow (frame, wxID_ANY, wxPoint (400, 0), wxSize (400, 600)) {
    //studentList = new wxGrid (this, wxID_ANY, wxDefaultPosition, GetSize ());
    //studentList->HideRowLabels ();
}

void StudentWindow::setData (Data data) {
    this->data = data;
}

void StudentWindow::onGridClick (int row, int col) {
    int id = (row * 2) + col;
    delete studentList;
    studentList = new wxGrid (this, wxID_ANY, wxPoint (0, 100), GetSize ());
    studentList->CreateGrid (data.students[id].size (), 2);
    studentList->HideRowLabels ();
    studentList->EnableEditing (false);
    studentList->SetColLabelValue (0, "NRP");
    studentList->SetColLabelValue (1, "Nama");
    studentList->SetColSize (0, 100);
    studentList->SetColSize (1, 300);

    for (int i = 0; i < data.students[id].size (); i++) {
        studentList->SetCellValue (i, 0, data.students[id][i].nrp);
        studentList->SetCellValue (i, 1, data.students[id][i].nama);
    }

    delete dosen;
    dosen = new wxGrid (this, wxID_ANY, wxDefaultPosition, wxSize (400, 100));
    dosen->CreateGrid (1, 2);
    dosen->EnableEditing (false);
    dosen->HideRowLabels ();
    dosen->SetColLabelValue (0, "NIP");
    dosen->SetColLabelValue (1, "Dosen");
    dosen->SetColSize (0, 100);
    dosen->SetColSize (1, 300);
    dosen->SetCellValue (0, 0, data.teachers[id].nip);
    dosen->SetCellValue (0, 1, data.teachers[id].nama);

    wxBoxSizer *sizer = new wxBoxSizer (wxVERTICAL);
    //sizer->Add (dosen);
    //sizer->Add (studentList);
    //SetSizer (sizer);
}

StudentWindow::~StudentWindow () {

}
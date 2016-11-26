#include "MainFrame.h"
#include "MainWindow.h"

MainFrame::MainFrame (const wxString& title) : wxFrame (NULL, wxID_ANY, title) {
	window = new MainWindow (this);
}
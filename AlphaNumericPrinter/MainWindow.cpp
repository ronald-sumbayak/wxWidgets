#include "wx/stdpaths.h"
#include "wx/filename.h"
#include "MainWindow.h"
#include "MainFrame.h"

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
    EVT_KEY_DOWN (MainWindow::onKeyDown)
    EVT_KEY_UP (MainWindow::onKeyUp)
    EVT_CHAR (MainWindow::onChar)
    EVT_PAINT (MainWindow::onPaint)
END_EVENT_TABLE ()

MainWindow::MainWindow (MainFrame* parent) : wxWindow (parent, wxID_ANY) {
    SetBackgroundColour (wxColour (*wxWHITE));
    imageSize = 100;
    bitmap = nullptr;
    wxImageHandler *imageLoader = new wxPNGHandler ();
    wxImage::AddHandler (imageLoader);
}

void MainWindow::onKeyDown (wxKeyEvent& event) {
    event.Skip ();
}

void MainWindow::onKeyUp (wxKeyEvent& event) {
}

void MainWindow::onChar (wxKeyEvent& event) {
    if (!isAlphaNumeric (event.GetKeyCode ())) return;
    loadImage (wxString ((char) event.GetKeyCode ()));
}

bool MainWindow::isAlphaNumeric (int numb) {
    if (numb>='0' && numb<='9') return true;
    if (numb>='a' && numb<='z') return true;
    return false;
}

void MainWindow::onPaint (wxPaintEvent &event) {
    wxPaintDC pdc (this);
    
    if (bitmap != nullptr) {
        int xx, yy;
        xx = rand () % (GetSize ().GetWidth () - imageSize);
        yy = rand () % (GetSize ().GetHeight () - imageSize);
        pdc.DrawBitmap (*bitmap, wxPoint (xx, yy), true);
    }
}

void MainWindow::loadImage (wxString keyCode) {
    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = stdPaths.GetExecutablePath ();
    src = wxFileName (src).GetPath () + wxT ("\\") + keyCode + wxT (".png");
    
    wxImage image (src, wxBITMAP_TYPE_PNG);
    image.Rescale (imageSize, imageSize);
    bitmap = new wxBitmap (image);
    Refresh ();
}
#include "wx/filename.h"
#include "wx/stdpaths.h"
#include "MainWindow.h"
#define random(x) rand () % (x)

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
    EVT_CHAR (MainWindow::loadImage)
    EVT_PAINT (MainWindow::onPaint)
END_EVENT_TABLE ()

MainWindow::MainWindow (MainFrame *frame) : wxWindow (frame, wxID_ANY) {
    imageSize = 100;
    wxImage::AddHandler (new wxPNGHandler ());
}

void MainWindow::loadImage (wxKeyEvent &event) {
    if (!isAlphaNumeric (event.GetKeyCode ())) return;
    wxString keyCode = (char) event.GetKeyCode ();
    
    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = stdPaths.GetExecutablePath ();
    src = wxFileName (src).GetPath () + wxT ("\\") + keyCode + wxT (".png");
    
    wxImage image (src, wxBITMAP_TYPE_PNG);
    image.Rescale (imageSize, imageSize);
    bitmap = new wxBitmap (image);
    Refresh ();
}

bool MainWindow::isAlphaNumeric (int numb) {
    if (numb >= '0' && numb <= '9') return true;
    if (numb >= 'a' && numb <= 'z') return true;
    if (numb >= 'A' && numb <= 'Z') return true;
    return false;
}

void MainWindow::onPaint (wxPaintEvent &event) {
    if (bitmap == nullptr) return;
    wxPaintDC pdc (this);
    int x, y;
    x = random (GetClientSize ().GetWidth () - imageSize);
    y = random (GetClientSize ().GetHeight () - imageSize);
    pdc.DrawBitmap (*bitmap, wxPoint (x, y), true);
}

MainWindow::~MainWindow () {
    delete bitmap;
}
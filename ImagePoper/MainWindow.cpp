#include "wx/filename.h"
#include "wx/stdpaths.h"
#include "MainWindow.h"

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
    EVT_LEFT_DOWN (MainWindow::loadImage)
    EVT_PAINT (MainWindow::onPaint)
END_EVENT_TABLE ()
    
MainWindow::MainWindow (wxFrame *frame) : wxWindow (frame, wxID_ANY) {
    imageCount = 10;
    imageSize = 100;
    wxImage::AddHandler (new wxPNGHandler ());
}

void MainWindow::loadImage (wxMouseEvent &event) {
    wxString imageCode = wxString::Format (wxT ("%d"), rand () % imageCount);

    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = stdPaths.GetExecutablePath ();
    src = wxFileName (src).GetPath () + wxT ("\\") + imageCode  + wxT (".png");

    wxImage image (src, wxBITMAP_TYPE_PNG);
    image.Rescale (imageSize, imageSize);
    bitmap = new wxBitmap (image);
    Refresh ();
}

void MainWindow::onPaint (wxPaintEvent &event) {
    if (bitmap == nullptr) return;
    wxPaintDC pdc (this);
    int x, y;
    x = wxGetMousePosition ().x - imageSize;
    y = wxGetMousePosition ().y - imageSize;
    pdc.DrawBitmap (*bitmap, wxPoint (x, y), true);
}

MainWindow::~MainWindow () {
    delete bitmap;
}
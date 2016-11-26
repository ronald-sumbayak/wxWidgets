#include "MainWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
    EVT_LEFT_DOWN (MainWindow::loadImage)
    EVT_PAINT (MainWindow::onPaint)
END_EVENT_TABLE ()
    
MainWindow::MainWindow (wxFrame *parent) : wxWindow (parent, wxID_ANY) {
    SetBackgroundColour (wxColour (*wxWHITE));
    mImageCount = 10;
    mImageSize = 100;
    
    wxImageHandler *imageLoader = new wxPNGHandler ();
    wxImage::AddHandler (imageLoader);
}

void MainWindow::loadImage (wxMouseEvent &event) {
    wxString imageCode = wxString::Format (wxT ("%d"), rand () % mImageCount);

    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = stdPaths.GetExecutablePath ();
    src = wxFileName (src).GetPath () + wxT ("\\") + imageCode  + wxT (".png");

    wxImage image (src, wxBITMAP_TYPE_PNG);
    image.Rescale (mImageSize, mImageSize);
    mBitmap = new wxBitmap (image);
    Refresh ();
}

void MainWindow::onPaint (wxPaintEvent &event) {
    wxPaintDC pdc (this);

    if (mBitmap != nullptr) {
        int xx, yy;
        xx = wxGetMousePosition ().x - mImageSize;
        yy = wxGetMousePosition ().y - mImageSize;
        pdc.DrawBitmap (*mBitmap, wxPoint (xx, yy), true);
    }
}
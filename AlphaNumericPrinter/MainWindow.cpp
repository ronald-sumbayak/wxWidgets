#include "wx/filename.h"
#include "wx/stdpaths.h"
#include "MainWindow.h"
#include "MainFrame.h"

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
    EVT_CHAR (MainWindow::loadImage)
    EVT_PAINT (MainWindow::onPaint)
END_EVENT_TABLE ()

MainWindow::MainWindow (MainFrame *parent) : wxWindow (parent, wxID_ANY) {
    SetBackgroundColour (wxColour (*wxWHITE));
    mImageSize = 100;
    mBitmap = nullptr;
    wxImageHandler *imageLoader = new wxPNGHandler ();
    wxImage::AddHandler (imageLoader);
}

void MainWindow::loadImage (wxKeyEvent &event) {
    if (!isAlphaNumeric (event.GetKeyCode ())) return;
    wxString keyCode = (char) event.GetKeyCode();
    
    wxStandardPaths &stdPaths = wxStandardPaths::Get ();
    wxString src = stdPaths.GetExecutablePath ();
    src = wxFileName (src).GetPath () + wxT ("\\") + keyCode + wxT (".png");
    
    wxImage image (src, wxBITMAP_TYPE_PNG);
    image.Rescale (mImageSize, mImageSize);
    mBitmap = new wxBitmap (image);
    Refresh ();
}

bool MainWindow::isAlphaNumeric (int numb) {
    if (numb>='0' && numb<='9') return true;
    if (numb>='a' && numb<='z') return true;
    return false;
}

void MainWindow::onPaint (wxPaintEvent &event) {
    wxPaintDC pdc (this);
    
    if (mBitmap != nullptr) {
        int xx, yy;
        xx = rand () % (GetSize ().GetWidth () - mImageSize);
        yy = rand () % (GetSize ().GetHeight () - mImageSize);
        pdc.DrawBitmap (*mBitmap, wxPoint (xx, yy), true);
    }
}
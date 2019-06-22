#include "BanknoteRecognitionApp.h"
#include "BanknoteRecognitionFrm.h"

IMPLEMENT_APP(BanknoteRecognitionFrmApp)

bool BanknoteRecognitionFrmApp::OnInit()
{
    BanknoteRecognitionFrm* frame = new BanknoteRecognitionFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}


int BanknoteRecognitionFrmApp::OnExit()
{
    return 0;
}

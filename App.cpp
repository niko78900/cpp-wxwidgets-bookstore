#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{

    MainFrame* MainWindow = new MainFrame("BookStore");
    MainWindow->SetClientSize(900, 675);
    MainWindow->Show();
    MainWindow->Center();
    return true;
}
//
// Created by Giada on 17/01/2024.
//

#include "MyApp.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MainFrame *mainFrame = new MainFrame("ToDo List");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}
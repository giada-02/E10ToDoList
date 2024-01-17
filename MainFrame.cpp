//
// Created by Giada on 17/01/2024.
//

#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    createControls();
}

void MainFrame::createControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 22)));

    panel = new wxPanel(this);
    panel->SetFont(mainFont);
    panel->SetBackgroundColour(*wxLIGHT_GREY);

    headlineText = new wxStaticText(panel, wxID_ANY, "ToDo List",
                                    wxPoint(8, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
    headlineText->SetFont(headlineFont);

    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(495, 35));
    addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(600, 80), wxSize(100, 35));
    checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));
    removeButton = new wxButton(panel, wxID_ANY, "Remove", wxPoint(100, 525), wxSize(100, 35));
    clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(600, 525), wxSize(100, 35));

}
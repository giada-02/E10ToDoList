//
// Created by Giada on 17/01/2024.
//

#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    createControls();
    bindEventHandlers();
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

    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(495, 35), wxTE_PROCESS_ENTER);
    addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(600, 80), wxSize(100, 35));
    checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));
    removeButton = new wxButton(panel, wxID_ANY, "Remove", wxPoint(100, 525), wxSize(100, 35));
    clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(600, 525), wxSize(100, 35));
}

void MainFrame::bindEventHandlers() {
    addButton->Bind(wxEVT_BUTTON, &MainFrame::onAddButtonClicked, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::onInputEnter, this);
    removeButton->Bind(wxEVT_BUTTON, &MainFrame::onRemoveButtonClicked, this);
    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::onKeyCanc, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::onClearButtonClicked, this);
}

void MainFrame::onAddButtonClicked(wxCommandEvent &evt) {
    addTaskFromInput();
}

void MainFrame::onInputEnter(wxCommandEvent &evt) {
    addTaskFromInput();
}

void MainFrame::addTaskFromInput() {
    wxString description = inputField->GetValue();
    if (!description.empty()) {
        checkListBox->Insert(description, checkListBox->GetCount());
        inputField->Clear();
    }
    inputField->SetFocus();
}

void MainFrame::onRemoveButtonClicked(wxCommandEvent &evt) {
    deleteSelectedTask();
}

void MainFrame::onKeyCanc(wxKeyEvent &evt) {
    if (evt.GetKeyCode() == WXK_DELETE) {
        deleteSelectedTask();
    }
}

void MainFrame::deleteSelectedTask() {
    int selectedIndex = checkListBox->GetSelection();
    if (selectedIndex != wxNOT_FOUND) {
        checkListBox->Delete(selectedIndex);
    }
}

void MainFrame::onClearButtonClicked(wxCommandEvent &evt) {
    if (!checkListBox->IsEmpty()) {
        wxMessageDialog dialog(this, "Are you sure you want to clear all tasks?", "Clear", wxYES_NO | wxCANCEL);
        int result = dialog.ShowModal();
        if (result == wxID_YES) {
            checkListBox->Clear();
        }
    }
}
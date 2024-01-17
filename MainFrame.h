//
// Created by Giada on 17/01/2024.
//

#ifndef E10TODOLIST_MAINFRAME_H
#define E10TODOLIST_MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString &title);

private:
    wxPanel *panel;
    wxStaticText *headlineText;
    wxTextCtrl *inputField;
    wxButton *addButton;
    wxCheckListBox *checkListBox;
    wxButton *removeButton;
    wxButton *clearButton;

    void createControls();

    void bindEventHandlers();

    void onAddButtonClicked(wxCommandEvent &evt);

    void onRemoveButtonClicked(wxCommandEvent &evt);

    void onClearButtonClicked(wxCommandEvent &evt);

};


#endif //E10TODOLIST_MAINFRAME_H

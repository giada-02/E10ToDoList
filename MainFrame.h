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

    //add task
    void onAddButtonClicked(wxCommandEvent &evt);
    void onInputEnter(wxCommandEvent &evt); //key 'Enter' to add task
    void addTaskFromInput();

    //remove selected task
    void onRemoveButtonClicked(wxCommandEvent &evt);
    void onKeyCanc(wxKeyEvent &evt); //key 'Canc' to remove selected task
    void deleteSelectedTask();

    void onClearButtonClicked(wxCommandEvent &evt);

};


#endif //E10TODOLIST_MAINFRAME_H

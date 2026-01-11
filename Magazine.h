#pragma once
#include "Book.h"
#include<wx/wx.h>

class Magazine : public Book
{
	wxString publisher;
	wxString issue;
public:
	Magazine(wxString title = "NULL", wxString author = "NULL", wxString genre = "NULL", 
		wxString publisher = "NULL", wxString issue = "NULL", double price = 0.0, int stock = 0);
	wxString get_publisher();
	wxString get_issue();
	void set_publisher(wxString x);
	void set_issue(wxString x);
	wxString combine_details();
	wxString get_type();
};
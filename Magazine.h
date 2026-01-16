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
	Magazine* clone() const override;
	wxString get_publisher() const;
	wxString get_issue() const;
	void set_publisher(wxString x);
	void set_issue(wxString x);
	wxString combine_details() const override;
	wxString combine_details_with_stock(int stockOverride) const override;
	wxString get_type() const override;
};

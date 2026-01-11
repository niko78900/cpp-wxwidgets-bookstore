#pragma once
#include<vector>
#include<wx/wx.h>
class Book
{
protected:
	wxString title;
	wxString author;
	wxString genre;
	double price;
	int stock;
	wxString combination;
	wxString bare_combination;
public:
	Book(wxString title = "NULL", wxString author = "NULL", wxString genre = "NULL", double price = 0.0, int stock = 0);
	virtual ~Book() = default;
	virtual Book* clone() const;
	virtual wxString combine_details(); //combines strings to be placed in the main table
	virtual wxString get_type();
	wxString combine_bare_details(); //combines bare strings that make each and every book different for searching/matching purposes
	wxString get_title();
	wxString get_author();
	wxString get_genre();
	double get_price();
	int get_stock();
	void decrement_stock();
	void set_stock(int x);
	void set_title(wxString x);
	void set_author(wxString x);
	void set_genre(wxString x); 
	void set_price(double x);
};


#pragma once
#include<vector>
#include<wx/wx.h>
class Book
{
protected:
	static int next_id;
	int id;
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
	virtual wxString combine_details() const; //combines strings to be placed in the main table
	virtual wxString combine_details_with_stock(int stockOverride) const;
	virtual wxString get_type() const;
	wxString combine_bare_details() const; //combines bare strings that make each and every book different for searching/matching purposes
	int get_id() const;
	wxString get_title() const;
	wxString get_author() const;
	wxString get_genre() const;
	double get_price() const;
	int get_stock() const;
	void decrement_stock();
	void set_stock(int x);
	void set_title(wxString x);
	void set_author(wxString x);
	void set_genre(wxString x); 
	void set_price(double x);
};


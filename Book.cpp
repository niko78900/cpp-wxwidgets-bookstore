#include "Book.h"
#include<iomanip>

int Book::next_id = 1;

Book::Book(wxString title, wxString author, wxString genre, double price , int stock)
{
	this->id = next_id++;
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->price = price;
	this->stock = stock;
	combination = combine_details();
}

Book* Book::clone() const
{
	return new Book(*this);
}

wxString Book::combine_details() const
{
	return combine_details_with_stock(stock);
}

wxString Book::combine_details_with_stock(int stockOverride) const
{
	wxString Sstock = wxString::Format("%d", stockOverride);
	wxString Sprice = wxString::Format("%.2f", price);
	return title + ", " + author + ", " + genre + ", " + Sstock + ", " + Sprice;
}

wxString Book::combine_bare_details() const
{
	return title + ", " + author + ", " + genre;
}

int Book::get_id() const
{
	return id;
}

wxString Book::get_title() const
{
	return title;
}

wxString Book::get_author() const
{
	return author;
}

wxString Book::get_genre() const
{
	return genre;
}

double Book::get_price() const
{
	return price;
}

int Book::get_stock() const
{
	return stock;
}

void Book::decrement_stock()
{
	
	stock = stock - 1;
	
}

void Book::set_stock(int x)
{
	stock = x;
}

void Book::set_title(wxString x)
{
	title = x;
}

void Book::set_author(wxString x)
{
	author = x;
}

void Book::set_genre(wxString x)
{
	genre = x;
}

void Book::set_price(double x)
{
	price = x;
}


wxString Book::get_type() const
{
	return "Book";
}

#include "Book.h"
#include<iomanip>

Book::Book(wxString title, wxString author, wxString genre, double price , int stock)
{
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->price = price;
	this->stock = stock;
	combination = combine_details();
}

wxString Book::combine_details()
{
	wxString Sstock = wxString::Format("%d", stock);
	wxString Sprice = wxString::Format("%.2f",price);
	return title + ", " + author + ", " + genre + ", " + Sstock + ", " + Sprice;
}

wxString Book::combine_bare_details()
{
	return title + ", " + author + ", " + genre;
}

wxString Book::get_title()
{
	return title;
}

wxString Book::get_author()
{
	return author;
}

wxString Book::get_genre()
{
	return genre;
}

double Book::get_price()
{
	return price;
}

int Book::get_stock()
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


wxString Book::get_type()
{
	return "Book";
}

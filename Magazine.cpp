#include "Magazine.h"

Magazine::Magazine(wxString title, wxString author, wxString genre, wxString publisher, wxString issue, double price, int stock)
{
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->publisher = publisher; 
	this->issue = issue;
	this->price = price;
	this->stock = stock;
	combination = combine_details();
}

Magazine* Magazine::clone() const
{
	return new Magazine(*this);
}

wxString Magazine::get_publisher()
{
	return publisher;
}

wxString Magazine::get_issue()
{
	return issue;
}

void Magazine::set_publisher(wxString x)
{
	publisher = x;
}

void Magazine::set_issue(wxString x)
{
	issue = x;
}

wxString Magazine::combine_details()
{
	wxString Sstock = wxString::Format("%d", stock); //converts wxString to int number
	wxString Sprice = wxString::Format("%.2f", price); // converts wxString to double number
	return title + ", " + publisher + ", " + issue + ", " + genre + ", " + Sstock + ", " + Sprice;
}

wxString Magazine::get_type()
{
	return "Magazine";
}

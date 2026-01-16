#include "Magazine.h"

Magazine::Magazine(wxString title, wxString author, wxString genre, wxString publisher, wxString issue, double price, int stock)
	: Book(title, author, genre, price, stock),
	publisher(publisher),
	issue(issue)
{
	combination = combine_details();
}

Magazine* Magazine::clone() const
{
	return new Magazine(*this);
}

wxString Magazine::get_publisher() const
{
	return publisher;
}

wxString Magazine::get_issue() const
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

wxString Magazine::combine_details() const
{
	return combine_details_with_stock(stock);
}

wxString Magazine::combine_details_with_stock(int stockOverride) const
{
	wxString Sstock = wxString::Format("%d", stockOverride); //converts wxString to int number
	wxString Sprice = wxString::Format("%.2f", price); // converts wxString to double number
	return title + ", " + publisher + ", " + issue + ", " + genre + ", " + Sstock + ", " + Sprice;
}

wxString Magazine::get_type() const
{
	return "Magazine";
}

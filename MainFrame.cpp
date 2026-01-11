#include "MainFrame.h"
#include<wx/wx.h>
#include <wx/valnum.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	tempPanel = new wxPanel(this);
	Title = new wxStaticText(tempPanel, wxID_ANY, "BookStore", wxPoint(374, 22), wxSize(152, 30));
	Title2 = new wxStaticText(tempPanel, wxID_ANY, "Written in C++ using the wxWidgets library", wxPoint(187, 63), wxSize(527, 30));
	wxFont HeadlineFont(wxFontInfo(wxSize(0, 28)).Bold());
	wxFont HeadlineFont2(wxFontInfo(wxSize(0, 26)));
	Title->SetFont(HeadlineFont);
	Title2->SetFont(HeadlineFont2);
	AddButton = new wxButton(tempPanel, wxID_ANY, "Add", wxPoint(352, 164), wxSize(80, 23));
	RemoveButton = new wxButton(tempPanel, wxID_ANY, "Remove", wxPoint(352, 197), wxSize(80, 23));
	lefthandText = new wxStaticText(tempPanel, wxID_ANY, "Available books", wxPoint(123, 136), wxSize(90, 15));

	wxArrayString TypeChoices;
	TypeChoices.Add("Book");
	TypeChoices.Add("Magazine");
	SelectionOfBookType = new wxChoice(tempPanel, wxID_ANY, wxPoint(450, 164), wxSize(100, 23), TypeChoices);

	Book test1("A Tale of Two Cities", "Charles Dickens", "Historical Fiction", 69.99, 200);
	Book test2("The Little Prince", "Antoine de Saint-Exupéry", "Children's fiction", 69.99, 200);
	Book test3("Harry Potter and the Philosopher's Stone", "J. K. Rowling", "Fantasy", 69.99, 200);
	Magazine test4("Why Are Movies so Bad at Making Civil War Look Scary?", 
		"Ismail Muhammad", "Political", "The New York Times", "5.1.24 Issue", 13.99, 200);
	AvailableBooksSectionVector.push_back(new Book(test1));
	AvailableBooksSectionVector.push_back(new Book(test2));
	AvailableBooksSectionVector.push_back(new Book(test3));
	AvailableBooksSectionVector.push_back(new Magazine(test4));
	wxArrayString AvailableBooksArray;
	for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
	{
		AvailableBooksArray.Add(AvailableBooksSectionVector[i]->combine_details());
	}

	//Available Books Section
	BookList = new wxListBox(tempPanel, wxID_ANY, wxPoint(23, 164), wxSize(290, 463), AvailableBooksArray);

	//Moving between Cart and Storage buttons
	PutInCart = new wxButton(tempPanel, wxID_ANY, ">>", wxPoint(437, 382), wxSize(27, 25));
	ClearCart = new wxButton(tempPanel, wxID_ANY, "Clear", wxPoint(430, 426), wxSize(41, 25));

	//Edit Button
	EditButton = new wxButton(tempPanel, wxID_ANY, "Edit", wxPoint(425, 470), wxSize(50, 23));

	//Status buttons
	NameOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(351, 504), wxSize(198, 23));
	GenreOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(351, 537), wxSize(85, 23));
	AuthorOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(464, 537), wxSize(85, 23));
	StockOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(351, 570), wxSize(85, 23));
	PriceOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(464, 570), wxSize(85, 23));
	IssueOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(351, 603), wxSize(85, 23));
	PublisherOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, " ", wxPoint(464, 603), wxSize(85, 23));

	//Cart Section
	righthandText = new wxStaticText(tempPanel, wxID_ANY, "Shopping Cart", wxPoint(690, 139), wxSize(83, 15));
	ShoppingCartList = new wxListBox(tempPanel, wxID_ANY, wxPoint(587, 164), wxSize(290, 463));
	CheckOut = new wxButton(tempPanel, wxID_ANY, "Checkout", wxPoint(747, 633), wxSize(62, 23));
	TotalPrice = "0.00";
	TotalPriceIN_CART = new wxStaticText(tempPanel, wxID_ANY, "Total: " + TotalPrice, wxPoint(811, 636), wxSize(70, 23));
	
	//Adding a book/magazine section
	ADDText = new wxStaticText(tempPanel, wxID_ANY, "Add a Book/Magazine", wxPoint(388, 228), wxSize(125, 15));
	NameOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Title of the book/magazine", wxPoint(351, 251), wxSize(198, 23));
	GenreOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Genre of the book/magazine", wxPoint(351, 284), wxSize(85, 23));
	AuthorOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Author of the book/magazine", wxPoint(464, 284), wxSize(85, 23));
	StockOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Stock of the book/magazine", wxPoint(351, 317), wxSize(85, 23));
	PriceOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Price of the book/magazine", wxPoint(464, 317), wxSize(85, 23));
	IssueOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Issue of the magazine", wxPoint(351, 350), wxSize(85, 23));
	PublisherOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Publisher of the magazine", wxPoint(464, 350), wxSize(85, 23));

	wxIntegerValidator<int> stockValidator;
	stockValidator.SetMin(0);

	wxFloatingPointValidator<double> priceValidator(2);
	priceValidator.SetMin(0.0);

	StockOfSelectedBookSTATUS->SetValidator(stockValidator);
	StockOfSelectedBookADD->SetValidator(stockValidator);
	PriceOfSelectedBookSTATUS->SetValidator(priceValidator);
	PriceOfSelectedBookADD->SetValidator(priceValidator);

	wxTextCtrl* textCtrls[] = {
		NameOfSelectedBookSTATUS,
		GenreOfSelectedBookSTATUS,
		AuthorOfSelectedBookSTATUS,
		StockOfSelectedBookSTATUS,
		PriceOfSelectedBookSTATUS,
		IssueOfSelectedBookSTATUS,
		PublisherOfSelectedBookSTATUS,
		NameOfSelectedBookADD,
		GenreOfSelectedBookADD,
		AuthorOfSelectedBookADD,
		StockOfSelectedBookADD,
		PriceOfSelectedBookADD,
		IssueOfSelectedBookADD,
		PublisherOfSelectedBookADD
	};
	for (wxTextCtrl* ctrl : textCtrls)
	{
		ctrl->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnTextKeyDown, this);
	}

	AddButtonsAtBegin();
	AddButton->Disable();
	
	//Event handling
	BookList->Bind(wxEVT_LISTBOX, &MainFrame::OnLeftListBoxSelect, this);
	PutInCart->Bind(wxEVT_BUTTON, &MainFrame::OnMoveButtonToCartClick, this);
	ClearCart->Bind(wxEVT_BUTTON, &MainFrame::OnMoveButtonToSelectionClick, this);
	CheckOut->Bind(wxEVT_BUTTON, &MainFrame::OnCheckoutButtonClicked, this);
	EditButton->Bind(wxEVT_BUTTON, &MainFrame::OnEditButtonClicked, this);
	RemoveButton->Bind(wxEVT_BUTTON, &MainFrame::OnRemoveButtonClicked, this);
	SelectionOfBookType->Bind(wxEVT_CHOICE, &MainFrame::OnChoiceMade, this);
	AddButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
}

MainFrame::~MainFrame()
{
	ClearBookVector(CartBooksSectionVector);
	ClearBookVector(AvailableBooksSectionVector);
}

void MainFrame::ClearBookVector(std::vector<Book*>& items)
{
	for (Book* item : items)
	{
		delete item;
	}
	items.clear();
}

void MainFrame::OnTextKeyDown(wxKeyEvent& evt)
{
	wxTextCtrl* text = wxDynamicCast(evt.GetEventObject(), wxTextCtrl);
	if (!text)
	{
		evt.Skip();
		return;
	}

	if (evt.CmdDown())
	{
		switch (evt.GetKeyCode())
		{
		case 'A':
			text->SelectAll();
			return;
		case 'C':
			text->Copy();
			return;
		case 'V':
			if (text->IsEditable())
			{
				text->Paste();
			}
			return;
		case 'X':
			if (text->IsEditable())
			{
				text->Cut();
			}
			return;
		default:
			break;
		}
	}

	evt.Skip();
}

void MainFrame::OnLeftListBoxSelect(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex != wxNOT_FOUND) {
		//set buttons to white and working
		IssueOfSelectedBookSTATUS->SetBackgroundColour(*wxWHITE);
		IssueOfSelectedBookSTATUS->SetEditable(true);
		IssueOfSelectedBookSTATUS->Enable(true);
		PublisherOfSelectedBookSTATUS->SetBackgroundColour(*wxWHITE);
		PublisherOfSelectedBookSTATUS->SetEditable(true);
		PublisherOfSelectedBookSTATUS->Enable(true);
		
		Book* selectedItemptr = AvailableBooksSectionVector[selectedIndex];
		Book selectedItem = *selectedItemptr;
		NameOfSelectedBookSTATUS->SetValue(selectedItem.get_title());
		GenreOfSelectedBookSTATUS->SetValue(selectedItem.get_genre());
		AuthorOfSelectedBookSTATUS->SetValue(selectedItem.get_author());;
		StockOfSelectedBookSTATUS->SetValue(wxString::Format("%d", selectedItem.get_stock()));;
		PriceOfSelectedBookSTATUS->SetValue(wxString::Format("%.2f", selectedItem.get_price()));;
		
		if (Magazine* Mtemp = dynamic_cast<Magazine*>(selectedItemptr))
		{
			IssueOfSelectedBookSTATUS->SetValue(Mtemp->get_issue());
			PublisherOfSelectedBookSTATUS->SetValue(Mtemp->get_publisher());
		}
		else
		{
			IssueOfSelectedBookSTATUS->SetBackgroundColour(wxColour(240, 240, 240));
			IssueOfSelectedBookSTATUS->SetEditable(false);
			IssueOfSelectedBookSTATUS->Enable(false);
			IssueOfSelectedBookSTATUS->Clear();
			PublisherOfSelectedBookSTATUS->SetBackgroundColour(wxColour(240, 240, 240));
			PublisherOfSelectedBookSTATUS->SetEditable(false);
			PublisherOfSelectedBookSTATUS->Enable(false);
			PublisherOfSelectedBookSTATUS->Clear();
		}
	}
}

void MainFrame::OnMoveButtonToCartClick(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex != wxNOT_FOUND)
	{
		if (selectedIndex != wxNOT_FOUND)
		{

			if (AvailableBooksSectionVector[selectedIndex]->get_stock() > 0)
			{
				AvailableBooksSectionVector[selectedIndex]->decrement_stock();
				Book* tempptr = AvailableBooksSectionVector[selectedIndex];
				Book* cartItem = tempptr->clone();
				cartItem->set_stock(1);
				CartBooksSectionVector.push_back(cartItem);
				ShoppingCartList->Append(cartItem->combine_details());
				BookList->SetString(selectedIndex, AvailableBooksSectionVector[selectedIndex]->combine_details());
			}
			else
			{
				wxMessageBox("No stock available.", "Error", wxOK | wxICON_ERROR);
			}
		}
		else
		{
			wxMessageBox("Please select a single item.", "Error", wxOK | wxICON_ERROR);
		}
	}
	else
	{
		wxMessageBox("Please select a single item.", "Error", wxOK | wxICON_ERROR);
	}
	
	updateCheckoutPrice();
}

void MainFrame::OnMoveButtonToSelectionClick(wxCommandEvent& evt) //clear button event handler
{
	//CartBooksSectionVector
	//AvailableBooksSectionVector;
	for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
	{
		for (int j = 0; j < CartBooksSectionVector.size(); j++)
		{
			if (AvailableBooksSectionVector[i]->combine_bare_details() == CartBooksSectionVector[j]->combine_bare_details())
			{
				AvailableBooksSectionVector[i]->set_stock(AvailableBooksSectionVector[i]->get_stock() + 1);
			}
		}
	}
	// Update changes
	ClearBookVector(CartBooksSectionVector);
	ShoppingCartList->Clear();
	AvailableBooksArray.Clear();
	for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
	{
		AvailableBooksArray.Add(AvailableBooksSectionVector[i]->combine_details());
	}
	BookList->Clear();
	BookList->Append(AvailableBooksArray);
	updateCheckoutPrice();
}

void MainFrame::OnCheckoutButtonClicked(wxCommandEvent& evt)
{
	ClearBookVector(CartBooksSectionVector);
	ShoppingCartList->Clear();
	updateCheckoutPrice();
}

void MainFrame::OnEditButtonClicked(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex != wxNOT_FOUND)
	{
		Book* selectedItemptr = AvailableBooksSectionVector[selectedIndex];
		if (Magazine* Mtemp = dynamic_cast<Magazine*>(selectedItemptr))
		{
			double tempPrice;
			PriceOfSelectedBookSTATUS->GetValue().ToDouble(&tempPrice);
			int tempStock;
			StockOfSelectedBookSTATUS->GetValue().ToInt(&tempStock);
			Mtemp->set_author(AuthorOfSelectedBookSTATUS->GetValue());
			Mtemp->set_genre(GenreOfSelectedBookSTATUS->GetValue());
			Mtemp->set_price(tempPrice);
			Mtemp->set_stock(tempStock);
			Mtemp->set_title(NameOfSelectedBookSTATUS->GetValue());
			Mtemp->set_publisher(PublisherOfSelectedBookSTATUS->GetValue());
			Mtemp->set_issue(IssueOfSelectedBookSTATUS->GetValue());
			AvailableBooksSectionVector[selectedIndex] = Mtemp;
		}
		else
		{
			double tempPrice;
			PriceOfSelectedBookSTATUS->GetValue().ToDouble(&tempPrice);
			int tempStock;
			StockOfSelectedBookSTATUS->GetValue().ToInt(&tempStock);
			AvailableBooksSectionVector[selectedIndex]->set_author(AuthorOfSelectedBookSTATUS->GetValue());
			AvailableBooksSectionVector[selectedIndex]->set_genre(GenreOfSelectedBookSTATUS->GetValue());
			AvailableBooksSectionVector[selectedIndex]->set_price(tempPrice);
			AvailableBooksSectionVector[selectedIndex]->set_stock(tempStock);
			AvailableBooksSectionVector[selectedIndex]->set_title(NameOfSelectedBookSTATUS->GetValue());
		}

		//Update ListBox
		AvailableBooksArray.Clear();
		for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
		{
			AvailableBooksArray.Add(AvailableBooksSectionVector[i]->combine_details());
		}
		BookList->Clear();
		BookList->Append(AvailableBooksArray);
	}
	else
	{
		wxMessageBox("Please select an item.", "Error", wxOK | wxICON_ERROR);
	}


}

void MainFrame::OnRemoveButtonClicked(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex != wxNOT_FOUND)
	{
		delete AvailableBooksSectionVector[selectedIndex];
		AvailableBooksSectionVector.erase(AvailableBooksSectionVector.begin() + selectedIndex);
		
		//Update ListBox
		AvailableBooksArray.Clear();
		for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
		{
			AvailableBooksArray.Add(AvailableBooksSectionVector[i]->combine_details());
		}
		BookList->Clear();
		BookList->Append(AvailableBooksArray);
	}
	else
	{
		wxMessageBox("Please select an item.", "Error", wxOK | wxICON_ERROR);
	}
}

void MainFrame::updateCheckoutPrice()
{
	double temp1 = 0;
	for (int i = 0; i < CartBooksSectionVector.size(); i++)
	{
		temp1 += CartBooksSectionVector[i]->get_price();
	}
	TotalPrice = wxString::Format(wxT("%.2f"), temp1);
	TotalPriceIN_CART->SetLabel(wxT("Total: " + TotalPrice));
}

void MainFrame::OnChoiceMade(wxCommandEvent& evt)
{
	AddButtonsAtEvent();
	AddButton->Enable();
	
	if (SelectionOfBookType->GetStringSelection() == "Book")
	{
		IssueOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
		IssueOfSelectedBookADD->SetEditable(false);
		IssueOfSelectedBookADD->Enable(false);
		IssueOfSelectedBookADD->Clear();
		PublisherOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
		PublisherOfSelectedBookADD->SetEditable(false);
		PublisherOfSelectedBookADD->Enable(false);
		PublisherOfSelectedBookADD->Clear();
	}
	else if (SelectionOfBookType->GetStringSelection() == "Magazine")
	{
		IssueOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
		IssueOfSelectedBookADD->SetEditable(true);
		IssueOfSelectedBookADD->Enable(true);
		IssueOfSelectedBookADD->SetValue("Issue of the magazine");
		PublisherOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
		PublisherOfSelectedBookADD->SetEditable(true);
		PublisherOfSelectedBookADD->Enable(true);
		PublisherOfSelectedBookADD->SetValue("Publisher of the magazine");
	}
}

void MainFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
	double tempPrice;
	int tempStock;
	PriceOfSelectedBookADD->GetValue().ToDouble(&tempPrice);
	StockOfSelectedBookADD->GetValue().ToInt(&tempStock);
	if (SelectionOfBookType->GetStringSelection() == "Book")
	{
		Book T1(NameOfSelectedBookADD->GetValue(), AuthorOfSelectedBookADD->GetValue(), GenreOfSelectedBookADD->GetValue(),	tempPrice, tempStock);
		AvailableBooksSectionVector.push_back(new Book(T1));
		AvailableBooksArray.Clear();
		for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
		{
			AvailableBooksArray.Add(AvailableBooksSectionVector[i]->combine_details());
		}
		BookList->Clear();
		BookList->Append(AvailableBooksArray);
	}
	else if (SelectionOfBookType->GetStringSelection() == "Magazine")
	{	
		Magazine T2(NameOfSelectedBookADD->GetValue(), AuthorOfSelectedBookADD->GetValue(), GenreOfSelectedBookADD->GetValue(), 
			PublisherOfSelectedBookADD->GetValue(), IssueOfSelectedBookADD->GetValue(),tempPrice, tempStock);
		AvailableBooksSectionVector.push_back(new Magazine(T2));
		AvailableBooksArray.Clear();
		for (int i = 0; i < AvailableBooksSectionVector.size(); i++)
		{
			AvailableBooksArray.Add(AvailableBooksSectionVector[i]->combine_details());
		}
		BookList->Clear();
		BookList->Append(AvailableBooksArray);
	}
	AddButtonsAtBegin();
}

void MainFrame::AddButtonsAtBegin()
{
	NameOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	NameOfSelectedBookADD->SetEditable(false);
	NameOfSelectedBookADD->Enable(false);
	NameOfSelectedBookADD->SetValue("Title of the book/magazine");

	GenreOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	GenreOfSelectedBookADD->SetEditable(false);
	GenreOfSelectedBookADD->Enable(false);
	GenreOfSelectedBookADD->SetValue("Genre of the book/magazine");

	AuthorOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	AuthorOfSelectedBookADD->SetEditable(false);
	AuthorOfSelectedBookADD->Enable(false);
	AuthorOfSelectedBookADD->SetValue("Author of the book/magazine");

	StockOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	StockOfSelectedBookADD->SetEditable(false);
	StockOfSelectedBookADD->Enable(false);
	StockOfSelectedBookADD->SetValue("Stock of the book/magazine");

	PriceOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	PriceOfSelectedBookADD->SetEditable(false);
	PriceOfSelectedBookADD->Enable(false);
	PriceOfSelectedBookADD->SetValue("Price of the book/magazine");

	IssueOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	IssueOfSelectedBookADD->SetEditable(false);
	IssueOfSelectedBookADD->Enable(false);
	IssueOfSelectedBookADD->SetValue("Issue of the magazine");

	PublisherOfSelectedBookADD->SetBackgroundColour(wxColour(240, 240, 240));
	PublisherOfSelectedBookADD->SetEditable(false);
	PublisherOfSelectedBookADD->Enable(false);
	PublisherOfSelectedBookADD->SetValue("Publisher of the magazine");
}

void MainFrame::AddButtonsAtEvent()
{
	NameOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	NameOfSelectedBookADD->SetEditable(true);
	NameOfSelectedBookADD->Enable(true);

	GenreOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	GenreOfSelectedBookADD->SetEditable(true);
	GenreOfSelectedBookADD->Enable(true);

	AuthorOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	AuthorOfSelectedBookADD->SetEditable(true);
	AuthorOfSelectedBookADD->Enable(true);

	StockOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	StockOfSelectedBookADD->SetEditable(true);
	StockOfSelectedBookADD->Enable(true);

	PriceOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	PriceOfSelectedBookADD->SetEditable(true);
	PriceOfSelectedBookADD->Enable(true);

	IssueOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	IssueOfSelectedBookADD->SetEditable(true);
	IssueOfSelectedBookADD->Enable(true);
	
	PublisherOfSelectedBookADD->SetBackgroundColour(*wxWHITE);
	PublisherOfSelectedBookADD->SetEditable(true);
	PublisherOfSelectedBookADD->Enable(true);
}


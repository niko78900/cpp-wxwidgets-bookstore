#include "MainFrame.h"
#include<wx/wx.h>
#include <wx/valnum.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	tempPanel = new wxPanel(this);

	Title = new wxStaticText(tempPanel, wxID_ANY, "BookStore");
	Title2 = new wxStaticText(tempPanel, wxID_ANY, "Written in C++ using the wxWidgets library");
	wxFont HeadlineFont(wxFontInfo(wxSize(0, 28)).Bold());
	wxFont HeadlineFont2(wxFontInfo(wxSize(0, 26)));
	Title->SetFont(HeadlineFont);
	Title2->SetFont(HeadlineFont2);

	AddButton = new wxButton(tempPanel, wxID_ANY, "Add");
	RemoveButton = new wxButton(tempPanel, wxID_ANY, "Remove");
	lefthandText = new wxStaticText(tempPanel, wxID_ANY, "Available books");

	wxArrayString TypeChoices;
	TypeChoices.Add("Book");
	TypeChoices.Add("Magazine");
	SelectionOfBookType = new wxChoice(tempPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, TypeChoices);

	Book test1("A Tale of Two Cities", "Charles Dickens", "Historical Fiction", 69.99, 200);
	Book test2("The Little Prince", "Antoine de Saint-Exupéry", "Children's fiction", 69.99, 200);
	Book test3("Harry Potter and the Philosopher's Stone", "J. K. Rowling", "Fantasy", 69.99, 200);
	Magazine test4("Why Are Movies so Bad at Making Civil War Look Scary?", 
		"Ismail Muhammad", "Political", "The New York Times", "5.1.24 Issue", 13.99, 200);
	AvailableBooksSectionVector.push_back(new Book(test1));
	AvailableBooksSectionVector.push_back(new Book(test2));
	AvailableBooksSectionVector.push_back(new Book(test3));
	AvailableBooksSectionVector.push_back(new Magazine(test4));
	//Available Books Section
	BookList = new wxListBox(tempPanel, wxID_ANY);
	BookList->SetMinSize(wxSize(0, -1));

	//Moving between Cart and Storage buttons
	PutInCart = new wxButton(tempPanel, wxID_ANY, ">>");
	ClearCart = new wxButton(tempPanel, wxID_ANY, "Clear");

	//Edit Button
	EditButton = new wxButton(tempPanel, wxID_ANY, "Edit");

	//Status buttons
	NameOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");
	GenreOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");
	AuthorOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");
	StockOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");
	PriceOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");
	IssueOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");
	PublisherOfSelectedBookSTATUS = new wxTextCtrl(tempPanel, wxID_ANY, "");

	//Cart Section
	righthandText = new wxStaticText(tempPanel, wxID_ANY, "Shopping Cart");
	ShoppingCartList = new wxListBox(tempPanel, wxID_ANY);
	ShoppingCartList->SetMinSize(wxSize(0, -1));
	CheckOut = new wxButton(tempPanel, wxID_ANY, "Checkout");
	TotalPrice = "0.00";
	TotalPriceIN_CART = new wxStaticText(tempPanel, wxID_ANY, "Total: " + TotalPrice);

	//Adding a book/magazine section
	ADDText = new wxStaticText(tempPanel, wxID_ANY, "Add a Book/Magazine");
	NameOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Title of the book/magazine");
	GenreOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Genre of the book/magazine");
	AuthorOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Author of the book/magazine");
	StockOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Stock of the book/magazine");
	PriceOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Price of the book/magazine");
	IssueOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Issue of the magazine");
	PublisherOfSelectedBookADD = new wxTextCtrl(tempPanel, wxID_ANY, "Publisher of the magazine");

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
		ctrl->SetMinSize(wxSize(0, -1));
		ctrl->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnTextKeyDown, this);
	}

	wxBoxSizer* rootSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* titleSizer = new wxBoxSizer(wxVERTICAL);
	titleSizer->Add(Title, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 10);
	titleSizer->Add(Title2, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
	rootSizer->Add(titleSizer, 0, wxEXPAND);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
	leftSizer->Add(lefthandText, 0, wxBOTTOM, 5);
	leftSizer->Add(BookList, 1, wxEXPAND);

	wxBoxSizer* centerSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* topActionsSizer = new wxBoxSizer(wxHORIZONTAL);
	topActionsSizer->Add(AddButton, 0, wxRIGHT, 5);
	topActionsSizer->Add(RemoveButton, 0, wxRIGHT, 5);
	topActionsSizer->Add(SelectionOfBookType, 1, wxEXPAND);
	centerSizer->Add(topActionsSizer, 0, wxEXPAND | wxBOTTOM, 8);

	centerSizer->Add(ADDText, 0, wxBOTTOM, 4);
	wxFlexGridSizer* addGrid = new wxFlexGridSizer(2, 6, 6);
	addGrid->Add(NameOfSelectedBookADD, 1, wxEXPAND);
	addGrid->Add(GenreOfSelectedBookADD, 1, wxEXPAND);
	addGrid->Add(AuthorOfSelectedBookADD, 1, wxEXPAND);
	addGrid->Add(StockOfSelectedBookADD, 1, wxEXPAND);
	addGrid->Add(PriceOfSelectedBookADD, 1, wxEXPAND);
	addGrid->Add(IssueOfSelectedBookADD, 1, wxEXPAND);
	addGrid->Add(PublisherOfSelectedBookADD, 1, wxEXPAND);
	addGrid->AddSpacer(0);
	addGrid->AddGrowableCol(0, 1);
	addGrid->AddGrowableCol(1, 1);
	centerSizer->Add(addGrid, 0, wxEXPAND | wxBOTTOM, 10);

	wxBoxSizer* cartButtonsSizer = new wxBoxSizer(wxHORIZONTAL);
	cartButtonsSizer->Add(PutInCart, 0, wxRIGHT, 5);
	cartButtonsSizer->Add(ClearCart, 0);
	centerSizer->Add(cartButtonsSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);

	centerSizer->Add(EditButton, 0, wxALIGN_RIGHT | wxBOTTOM, 4);

	wxFlexGridSizer* statusGrid = new wxFlexGridSizer(2, 6, 6);
	statusGrid->Add(NameOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->Add(GenreOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->Add(AuthorOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->Add(StockOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->Add(PriceOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->Add(IssueOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->Add(PublisherOfSelectedBookSTATUS, 1, wxEXPAND);
	statusGrid->AddSpacer(0);
	statusGrid->AddGrowableCol(0, 1);
	statusGrid->AddGrowableCol(1, 1);
	centerSizer->Add(statusGrid, 0, wxEXPAND);

	wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
	rightSizer->Add(righthandText, 0, wxBOTTOM, 5);
	rightSizer->Add(ShoppingCartList, 1, wxEXPAND);
	wxBoxSizer* checkoutSizer = new wxBoxSizer(wxHORIZONTAL);
	checkoutSizer->Add(CheckOut, 0, wxRIGHT, 6);
	checkoutSizer->AddStretchSpacer(1);
	checkoutSizer->Add(TotalPriceIN_CART, 0, wxALIGN_CENTER_VERTICAL);
	rightSizer->Add(checkoutSizer, 0, wxEXPAND | wxTOP, 6);

	mainSizer->Add(leftSizer, 1, wxEXPAND | wxALL, 10);
	mainSizer->Add(centerSizer, 1, wxEXPAND | wxALL, 10);
	mainSizer->Add(rightSizer, 1, wxEXPAND | wxALL, 10);

	rootSizer->Add(mainSizer, 1, wxEXPAND);

	tempPanel->SetSizer(rootSizer);
	rootSizer->SetSizeHints(this);
	RefreshAvailableList();
	RefreshCartList();

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

bool MainFrame::TryParsePriceStock(wxTextCtrl* priceCtrl, wxTextCtrl* stockCtrl, double& priceOut, int& stockOut)
{
	if (!priceCtrl->GetValue().ToDouble(&priceOut) || !stockCtrl->GetValue().ToInt(&stockOut))
	{
		wxMessageBox("Please enter numeric values for price and stock.", "Invalid input", wxOK | wxICON_ERROR);
		return false;
	}
	if (priceOut < 0.0 || stockOut < 0)
	{
		wxMessageBox("Price and stock must be zero or greater.", "Invalid input", wxOK | wxICON_ERROR);
		return false;
	}
	return true;
}

void MainFrame::RefreshAvailableList()
{
	BookList->Freeze();
	BookList->Clear();
	for (Book* item : AvailableBooksSectionVector)
	{
		int availableStock = GetAvailableStock(item);
		BookList->Append(item->combine_details_with_stock(availableStock));
	}
	BookList->Thaw();
}

void MainFrame::RefreshCartList()
{
	ShoppingCartList->Freeze();
	ShoppingCartList->Clear();
	for (Book* item : CartBooksSectionVector)
	{
		ShoppingCartList->Append(item->combine_details());
	}
	ShoppingCartList->Thaw();
	updateCheckoutPrice();
}

int MainFrame::CountCartItemsById(int id) const
{
	int count = 0;
	for (const Book* item : CartBooksSectionVector)
	{
		if (item->get_id() == id)
		{
			++count;
		}
	}
	return count;
}

int MainFrame::GetAvailableStock(const Book* item) const
{
	int available = item->get_stock() - CountCartItemsById(item->get_id());
	return available < 0 ? 0 : available;
}

int MainFrame::RemoveCartItemsById(int id, int countToRemove)
{
	int removed = 0;
	for (auto it = CartBooksSectionVector.begin(); it != CartBooksSectionVector.end(); )
	{
		if ((*it)->get_id() == id && (countToRemove < 0 || removed < countToRemove))
		{
			delete *it;
			it = CartBooksSectionVector.erase(it);
			++removed;
			if (countToRemove >= 0 && removed >= countToRemove)
			{
				break;
			}
			continue;
		}
		++it;
	}
	return removed;
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
	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}

	//set fields to active
	IssueOfSelectedBookSTATUS->SetBackgroundColour(*wxWHITE);
	IssueOfSelectedBookSTATUS->SetEditable(true);
	IssueOfSelectedBookSTATUS->Enable(true);
	PublisherOfSelectedBookSTATUS->SetBackgroundColour(*wxWHITE);
	PublisherOfSelectedBookSTATUS->SetEditable(true);
	PublisherOfSelectedBookSTATUS->Enable(true);

	Book* selectedItem = AvailableBooksSectionVector[selectedIndex];
	NameOfSelectedBookSTATUS->SetValue(selectedItem->get_title());
	GenreOfSelectedBookSTATUS->SetValue(selectedItem->get_genre());
	AuthorOfSelectedBookSTATUS->SetValue(selectedItem->get_author());
	StockOfSelectedBookSTATUS->SetValue(wxString::Format("%d", selectedItem->get_stock()));
	PriceOfSelectedBookSTATUS->SetValue(wxString::Format("%.2f", selectedItem->get_price()));

	if (Magazine* Mtemp = dynamic_cast<Magazine*>(selectedItem))
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


void MainFrame::OnMoveButtonToCartClick(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex == wxNOT_FOUND)
	{
		wxMessageBox("Please select an item.", "Error", wxOK | wxICON_ERROR);
		return;
	}

	Book* selectedItem = AvailableBooksSectionVector[selectedIndex];
	int availableStock = GetAvailableStock(selectedItem);
	if (availableStock <= 0)
	{
		wxMessageBox("No stock available.", "Error", wxOK | wxICON_ERROR);
		return;
	}

	Book* cartItem = selectedItem->clone();
	cartItem->set_stock(1);
	CartBooksSectionVector.push_back(cartItem);
	RefreshAvailableList();
	RefreshCartList();
}


void MainFrame::OnMoveButtonToSelectionClick(wxCommandEvent& evt) //clear button event handler
{
	ClearBookVector(CartBooksSectionVector);
	RefreshCartList();
	RefreshAvailableList();
}


void MainFrame::OnCheckoutButtonClicked(wxCommandEvent& evt)
{
	for (Book* item : AvailableBooksSectionVector)
	{
		int cartCount = CountCartItemsById(item->get_id());
		if (cartCount > 0)
		{
			int newTotal = item->get_stock() - cartCount;
			if (newTotal < 0)
			{
				newTotal = 0;
			}
			item->set_stock(newTotal);
		}
	}
	ClearBookVector(CartBooksSectionVector);
	RefreshCartList();
	RefreshAvailableList();
}



void MainFrame::OnEditButtonClicked(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex == wxNOT_FOUND)
	{
		wxMessageBox("Please select an item.", "Error", wxOK | wxICON_ERROR);
		return;
	}

	Book* selectedItemptr = AvailableBooksSectionVector[selectedIndex];
	int selectedId = selectedItemptr->get_id();
	double tempPrice = 0.0;
	int tempStock = 0;
	if (!TryParsePriceStock(PriceOfSelectedBookSTATUS, StockOfSelectedBookSTATUS, tempPrice, tempStock))
	{
		return;
	}

	int cartCount = CountCartItemsById(selectedId);
	if (tempStock < cartCount)
	{
		int removed = RemoveCartItemsById(selectedId, cartCount - tempStock);
		if (removed > 0)
		{
			wxMessageBox(wxString::Format("Stock is lower than the cart quantity. Removed %d item(s) from the cart.", removed), "Cart adjusted", wxOK | wxICON_INFORMATION);
		}
	}

	if (Magazine* Mtemp = dynamic_cast<Magazine*>(selectedItemptr))
	{
		Mtemp->set_author(AuthorOfSelectedBookSTATUS->GetValue());
		Mtemp->set_genre(GenreOfSelectedBookSTATUS->GetValue());
		Mtemp->set_price(tempPrice);
		Mtemp->set_stock(tempStock);
		Mtemp->set_title(NameOfSelectedBookSTATUS->GetValue());
		Mtemp->set_publisher(PublisherOfSelectedBookSTATUS->GetValue());
		Mtemp->set_issue(IssueOfSelectedBookSTATUS->GetValue());
	}
	else
	{
		selectedItemptr->set_author(AuthorOfSelectedBookSTATUS->GetValue());
		selectedItemptr->set_genre(GenreOfSelectedBookSTATUS->GetValue());
		selectedItemptr->set_price(tempPrice);
		selectedItemptr->set_stock(tempStock);
		selectedItemptr->set_title(NameOfSelectedBookSTATUS->GetValue());
	}
	for (Book* cartItem : CartBooksSectionVector)
	{
		if (cartItem->get_id() != selectedId)
		{
			continue;
		}
		cartItem->set_author(AuthorOfSelectedBookSTATUS->GetValue());
		cartItem->set_genre(GenreOfSelectedBookSTATUS->GetValue());
		cartItem->set_price(tempPrice);
		cartItem->set_title(NameOfSelectedBookSTATUS->GetValue());
		if (Magazine* cartMag = dynamic_cast<Magazine*>(cartItem))
		{
			cartMag->set_publisher(PublisherOfSelectedBookSTATUS->GetValue());
			cartMag->set_issue(IssueOfSelectedBookSTATUS->GetValue());
		}
	}
	RefreshAvailableList();
	RefreshCartList();
}


void MainFrame::OnRemoveButtonClicked(wxCommandEvent& evt)
{
	int selectedIndex = BookList->GetSelection();
	if (selectedIndex == wxNOT_FOUND)
	{
		wxMessageBox("Please select an item.", "Error", wxOK | wxICON_ERROR);
		return;
	}

	int removedId = AvailableBooksSectionVector[selectedIndex]->get_id();
	delete AvailableBooksSectionVector[selectedIndex];
	AvailableBooksSectionVector.erase(AvailableBooksSectionVector.begin() + selectedIndex);
	RemoveCartItemsById(removedId);
	RefreshAvailableList();
	RefreshCartList();
}


void MainFrame::updateCheckoutPrice()
{
	double total = 0.0;
	for (const Book* item : CartBooksSectionVector)
	{
		total += item->get_price();
	}
	TotalPrice = wxString::Format("%.2f", total);
	TotalPriceIN_CART->SetLabel("Total: " + TotalPrice);
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
	double tempPrice = 0.0;
	int tempStock = 0;
	if (!TryParsePriceStock(PriceOfSelectedBookADD, StockOfSelectedBookADD, tempPrice, tempStock))
	{
		return;
	}
	if (SelectionOfBookType->GetStringSelection() == "Book")
	{
		Book T1(NameOfSelectedBookADD->GetValue(), AuthorOfSelectedBookADD->GetValue(), GenreOfSelectedBookADD->GetValue(),	tempPrice, tempStock);
		AvailableBooksSectionVector.push_back(new Book(T1));
	}
	else if (SelectionOfBookType->GetStringSelection() == "Magazine")
	{	
		Magazine T2(NameOfSelectedBookADD->GetValue(), AuthorOfSelectedBookADD->GetValue(), GenreOfSelectedBookADD->GetValue(), 
			PublisherOfSelectedBookADD->GetValue(), IssueOfSelectedBookADD->GetValue(),tempPrice, tempStock);
		AvailableBooksSectionVector.push_back(new Magazine(T2));
	}
	RefreshAvailableList();
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


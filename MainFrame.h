#pragma once
#include<wx/wx.h>
#include<vector>
#include "Book.h"
#include "Magazine.h"


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame();
private:
	void ClearBookVector(std::vector<Book*>& items);
	bool TryParsePriceStock(wxTextCtrl* priceCtrl, wxTextCtrl* stockCtrl, double& priceOut, int& stockOut);
	void RefreshAvailableList();
	void RefreshCartList();
	int CountCartItemsById(int id) const;
	int GetAvailableStock(const Book* item) const;
	int RemoveCartItemsById(int id, int countToRemove = -1);
	void OnTextKeyDown(wxKeyEvent& evt);
	void OnLeftListBoxSelect(wxCommandEvent& evt);
	void OnMoveButtonToCartClick(wxCommandEvent& evt);
	void OnMoveButtonToSelectionClick(wxCommandEvent& evt);
	void OnCheckoutButtonClicked(wxCommandEvent& evt);
	void OnEditButtonClicked(wxCommandEvent& evt);
	void OnRemoveButtonClicked(wxCommandEvent& evt);
	void updateCheckoutPrice();
	void OnChoiceMade(wxCommandEvent& evt);
	void OnAddButtonClicked(wxCommandEvent& evt);
	void AddButtonsAtBegin();
	void AddButtonsAtEvent();
	wxPanel* tempPanel;
	wxStaticText* Title;
	wxStaticText* Title2;
	std::vector<Book*> AvailableBooksSectionVector;
	std::vector<Book*> CartBooksSectionVector;
	wxButton* AddButton;
	wxButton* RemoveButton;
	wxStaticText* lefthandText;
	wxChoice* SelectionOfBookType;
	wxButton* PutInCart;
	wxButton* ClearCart;
	wxTextCtrl* NameOfSelectedBookSTATUS;
	wxTextCtrl* GenreOfSelectedBookSTATUS;
	wxTextCtrl* AuthorOfSelectedBookSTATUS;
	wxTextCtrl* StockOfSelectedBookSTATUS;
	wxTextCtrl* PriceOfSelectedBookSTATUS;
	wxTextCtrl* IssueOfSelectedBookSTATUS;
	wxTextCtrl* PublisherOfSelectedBookSTATUS;
	wxButton* EditButton;
	wxStaticText* righthandText;
	wxButton* CheckOut;
	wxString TotalPrice;
	wxStaticText* TotalPriceIN_CART;
	wxListBox* BookList;
	wxListBox* ShoppingCartList;
	wxStaticText* ADDText;
	wxTextCtrl* NameOfSelectedBookADD;
	wxTextCtrl* GenreOfSelectedBookADD;
	wxTextCtrl* AuthorOfSelectedBookADD;
	wxTextCtrl* StockOfSelectedBookADD;
	wxTextCtrl* PriceOfSelectedBookADD;
	wxTextCtrl* IssueOfSelectedBookADD;
	wxTextCtrl* PublisherOfSelectedBookADD;
};


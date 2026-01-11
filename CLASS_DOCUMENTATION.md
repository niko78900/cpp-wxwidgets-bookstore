# Class Documentation

## App (App.h / App.cpp)
Role: wxApp subclass; initializes wxWidgets and shows MainFrame.
Key behavior: OnInit creates MainFrame, sets size, shows, centers.

## MainFrame (MainFrame.h / MainFrame.cpp)
Role: wxFrame subclass; owns UI controls and in-memory data.
Data:
- AvailableBooksSectionVector: list of available items (Book* / Magazine*)
- CartBooksSectionVector: cart items (cloned from available)
- wx controls for lists, forms, and buttons
Behavior:
- Constructor builds UI, seeds sample data, configures validators, binds events, and sets sizers.
- OnLeftListBoxSelect populates edit fields based on selected item; enables magazine fields if needed.
- OnMoveButtonToCartClick decrements stock, clones item into cart, updates list and total.
- OnMoveButtonToSelectionClick clears cart and restores stock.
- OnCheckoutButtonClicked clears cart and total.
- OnEditButtonClicked updates the selected item in-place.
- OnRemoveButtonClicked deletes and removes the selected item.
- OnAddButtonClicked creates a new Book or Magazine from form input.
- updateCheckoutPrice sums cart item prices.
- Destructor deletes heap-allocated items; ClearBookVector handles cleanup.

## Book (Book.h / Book.cpp)
Role: Base class for inventory items.
Fields: title, author, genre, price, stock.
Behavior:
- combine_details formats display string (for list box).
- combine_bare_details used for matching items.
- clone returns a heap copy of the concrete type (base implementation returns Book).

## Magazine (Magazine.h / Magazine.cpp)
Role: Specialized Book with publisher and issue.
Behavior:
- Overrides combine_details for magazine display.
- Overrides clone to preserve Magazine type.

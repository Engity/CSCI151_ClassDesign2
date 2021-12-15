#include "SectionC.h"

//---Section C Item -----
Item::Item(std::string name, long id, double price, int quantity){
    _id = id;
    setName(name);
    setPrice(price);
    setQuantity(quantity);
}

std::string Item::getName() const{
    return _name;
}
long Item::getId() const{
    return _id;
}
double Item::getPrice() const{
    return _price;
}
int Item::getQuantity() const{
    return _quantity;
}

void Item::setQuantity(int number){
    if (number >= 0){
        _quantity = number;
    }
    else {
        std::cout << "Quantity cannot be below zero\n";
    }
    
}

void Item::setName(std::string name){
    _name = name;
}

void Item::setPrice(double amount){
    if (amount >= 0){
         _price = amount;
    }
    else {
        std::cout << "Price cannot be below zero\n";
    }
}

void Item::setId(long id){
    if (id >= 0){
        _id = id;
    }
    else {
        std::cout << "ID cannot be below zero\n";
    }
}

void printItemInfo(const Item &item){
    std::cout << "Item: " << item.getName()
        << "\n\tID: " << item.getId()
        << "\n\tPrice: " << item.getPrice()
        << "\n\tQuantity: " << item.getQuantity();
}
//Non-member output stream overload function for Item
std::ostream& operator << (std::ostream& out, const Item &item){
    out << "Item: " << item.getName()
        << "\n\tID: " << item.getId()
        << "\n\tPrice: " << item.getPrice()
        << "\n\tQuantity: " << item.getQuantity();
    return out;
}

//-----Section C Store-----

Store::Store(){}

//Adding item to the shop
void Store::addItem(Item item){
    _items.push_back(item);
}

int Store::getTotal() const{
    return _items.size();
}

bool Store::removeItem(long id, int quantity){
    for (Item &item : _items){
        if (item.getId() == id){
            int new_amount = item.getQuantity() - quantity;

            if (new_amount < 0){
                std::cout << "Cannot remove more than the quantity in the store\n";
                return false;//Removing failed
            }

            item.setQuantity (new_amount);
            return true;//Removing successfully
        }
    }
}

Item Store::getItem(long id) const{
    for (Item item : _items){
        if (item.getId() == id){
            return item;
        }
    }
    std::cout << "Could not find the item with the id " << id << "\n";
    Item blank("",0,0,0);
    //return a blank item
    return blank;
}

void Store::printStoreInfo(){
    std::cout << "The shop's current inventory is:\n";
    for (Item item : _items){
        printItemInfo(item);
        std::cout << "\n";
    }
}

//Non-member output stream overload function for Store
std::ostream& operator << (std::ostream& out, const Store &shop){
    out << "The shop's current inventory is:\n";
    for (int i = 0; i < shop.getTotal(); i++){
        out << shop.getItem(i + 1) << "\n";
    }
    return out;
}

//Process order function
bool Store::processOrder(const Order &order){
    std::vector <std::pair <long, int>> extractedOrder = order.getOrder();
    bool res = true;
    for (std::pair <long, int> item : extractedOrder){
        res |= removeItem( item.first, item.second);
        if (!res){
            std::cout <<"Order failed at item " << item.first << "\n";
            return res;
        }
    }

    std::cout << "Order successfully processed with the total of $" << order.getTotalPrice() << "\n";
    return res;
}

//-----Section C Order-----

 Order::Order(){
    _cost = 0;
 }
void Order::addItem(Item item){
    _cart.push_back(item);
    _cost += item.getPrice();
}
bool Order::removeItem(long id, int quantity){//Remove certain amounts from the cart, based on id
    for (Item &item : _cart){
        if (item.getId() == id){
            int new_amount = item.getQuantity() - quantity;

            if (new_amount < 0){
                std::cout << "Cannot remove more than the quantity in the cart\n";
                return false;//Removing failed
            }
            double new_balence = _cost - quantity * item.getPrice();
            
            _cost = new_balence;
            item.setQuantity (new_amount);
            return true;//Removing successfully
        }
    }
}
double Order::getTotalPrice() const{
    return _cost;
}

Item Order::getItem(long id) const{
    for (Item item : _cart){
        if (item.getId() == id){
            return item;
        }
    }
    std::cout << "Could not find the item with the id " << id << "\n";
    Item blank("",0,0,0);
    //return a blank item
    return blank;
}
int Order::getTotal() const{
    return _cart.size();
}

std::vector <std::pair<long,int>> Order::getOrder() const{//Extract id and quantity of items currently in the order
    std::vector <std::pair <long, int>> res;
    for (Item item : _cart){
        res.push_back(std::make_pair(item.getId(), item.getQuantity()));
    }
    return res;
}

void Order::displayOder(){
    std::cout << "The current order has:\n";
    for (Item item : _cart){
        printItemInfo(item);
        std::cout << "\n";
    }
}



#include <string>
#include <iostream>
#include <vector>

class Item{
	public:
	        Item(std::string name, long id, double price, int quantity);
	
                std::string getName() const;
                long getId() const;
                double getPrice() const;
                int getQuantity() const;
	    
                void setQuantity(int number);
                void setName(std::string name);
                void setPrice(double amount);
                void setId(long id);
	
	private:
                //Default values
                long _id = 0;
                double _price = 0;
                int _quantity = 0;

                std::string _name;
};

void printItemInfo(const Item&);
std::ostream& operator << (std::ostream& out, const Item &item);//Non-member output stream overload function for Item

class Order{
	public:
                Order();
                void addItem(Item item);
                bool removeItem(long id, int quantity);//Remove certain amounts from the cart, based on id
                double getTotalPrice() const;
                void displayOder();
                Item getItem(long id) const;
                int getTotal() const;
                std::vector <std::pair<long,int>> getOrder() const;//Extract id and quantity of items currently in the order
	private:
                double _cost;
                std::vector <Item> _cart;
};

class Store{
	public:
	        Store();
                int getTotal() const;
                void printStoreInfo();
                void addItem(Item);
                Item getItem(long id) const;
                bool removeItem(long id, int quantity);//Remove certain amounts from the shop, based on id
                bool processOrder(const Order &order);
	private:
                std::vector <Item> _items;
};

//Non-member output stream overload function for Store
std::ostream& operator << (std::ostream& out, const Store &shop);



#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Global{
		int x;
		int stored_x[10];	
};
Global global;

class Product{
	private: 
	int prod_id;
	
	public:
	float price;
	string name;

	Product(int x, float y, string z){
		prod_id = x;
		price = y;
		name = z;
	}
	
	void showProd(){
	cout<<prod_id<<"\t\t"<<name<<"\t\t"<<price<<endl;
	}
	
	int showID(){
		return prod_id;
	}
};

class Cart{
	public:
		Product* products[10];
	string name[10];
	float price[10];
	int quantity[10];
	int id[10];
	
	void chooseProduct(){
	bool notFinished = true;
	bool notDuplicate = true;
	int input[10];
	
	while(notFinished = true){
		
	cout<<"Enter the ID of the product you want to add in the shopping cart[0 to exit]: ";
	cin>>input[global.x];	
			while(input[global.x] != products[global.x]->showID() && input[global.x] != 0){
				cin.clear();
				cin.ignore();
				cout<<"Error Input. Try Again: ";
				cin>>input[global.x];
			}	


	notFinished = true;
	}
	

}

	};
		
class Order: public Cart{
	public:
	float totalAmount[10];
	int orderID[10];
	int orderNum;
};

	Product paper(101,10,"Paper");
	Product eraser(102,15,"Eraser");
	Product pencil(103,20,"Pencil");
	Product* products[] = {&paper, &eraser, &pencil};


	Order order[10];
	Cart cart[10];
	void printOrder();
	void printCart();
	void chooseProduct();
	void showProducts();
	void askCheckout();
	void menu();
	void banner();
	void miniBanner();
	
void banner(){
	cout<<endl<<"===================================="<<endl;
}

void miniBanner(){
	cout<<endl<<"------------"<<endl;
}
void showProducts(){
	cout<<"Product ID\tName\t\tPrice\t"<<endl;
	paper.showProd();
	eraser.showProd();
	pencil.showProd();
	
chooseProduct();
}

void loadOrder(){
	cout<<"hi";
}
void viewCart(){
	cout<<"hi";
}
void printOrder(){
	cout<<"hi";
}
void askCheckout(){
	char input;

	cout<<"Do you want to checkout all the products?[Y/N]";
	cin>>input;
	//ADD CONDITIONAL LOOP TO CATCH ERROR
	
	if(input == 'Y' || input == 'y'){
		loadOrder();
		cout<<"Checkout Successful"<<endl;
		global.x = 0;
		menu();
	}
	else{
		menu();
	}
}





void chooseProduct(){
	bool notFinished = true;
	bool notDuplicate = true;
	int input[10];
	
	while(notFinished = true){
		
	cout<<"Enter the ID of the product you want to add in the shopping cart[0 to exit]: ";
	cin>>input[global.x];	
			while(input[global.x] != paper.showID() && input[global.x] != eraser.showID() && input[global.x] != pencil.showID() && input[global.x] != 0){
				cin.clear();
				cin.ignore();
				cout<<"Error Input. Try Again: ";
				cin>>input[global.x];
			}	


	notFinished = true;
menu();
}
}


void menu(){
banner();
int input;
	cout<<"View Products[1]"<<endl;
	cout<<"View Shopping Cart[2]"<<endl;
	cout<<"View Order[3]"<<endl;
	cout<<"Exit[0]"<<endl;
	cout<<": ";

	cin>>input;
	while(input != 1 && input != 2 && input != 3 && input != 0){
		cout<<"Error Input. Try Again: ";
		cin>>input;
	}
	
	switch(input){
		case 1:showProducts();
		break;
		case 2:viewCart();
		break;
		case 3:printOrder();
		break;
		case 0:return;
	}

}

int main(){
	
	
	menu();
	
	
	return 0;
	
}
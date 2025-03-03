#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Global{
	public:
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

	int showID(){
		return prod_id;
	}

	void setID(int x){
		prod_id = x;
	}

	void setPrice(int x){
		price = x;
	}
	
	void setName(string x){
		name = x;
	}
	
	void showProd(){
	cout<<prod_id<<"\t\t"<<name<<"\t\t"<<price<<endl;
	}
	
	
};

class Cart{
	public:
	string name[10][10];
	float price[10][10];
	int quantity[10][10];
	int id[10][10];
	};
		
class Order: public Cart{
	public:
	float totalAmount[10];
	int orderID[10];
	int orderNum;
};

	Product paper;
	Product eraser;
	Product pencil;


	Order order;
	Cart cart;
	void printOrder();
	void printCart();
	void chooseProduct();
	void showProducts();
	void loadOrder();
	void viewCart();
	void askCheckout();
	void menu();
	void addCart();
	void addQuantity();
	void getAmount();
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


void viewCart(){
	banner();
	cout<<"Name\tPrice\tQuantity"<<endl;
	printCart();
	askCheckout();
}
void printCart(){

		for(int i=0;i<global.x;i++){
			cout<<cart.name[order.orderNum][i]<<"\t"<<cart.price[order.orderNum][i]<<"\t"<<cart.quantity[order.orderNum][i]<<endl;
		}
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

void printOrder(){
banner();
	for(int i=0;i<order.orderNum;i++){
	cout<<"Order ID: "<<order.orderID[i]<<endl;
	cout<<"Total Amount: "<<order.totalAmount[i]<<endl;
	cout<<"Name\tPrice\tQuantity"<<endl;
		for(int x=0;x<global.stored_x[i];x++){

			cout<<order.name[i][x]<<"\t"<<order.price[i][x]<<"\t"<<order.quantity[i][x]<<endl;
			
		}
	miniBanner();
	}
	
menu();
}

void loadOrder(){
	order.orderID[order.orderNum] = order.orderNum;
	global.stored_x[order.orderNum] = global.x;
	
	for(int i=0;i<global.stored_x[order.orderNum];i++){
		order.name[order.orderNum][i] = cart.name[order.orderNum][i];
		order.price[order.orderNum][i] = cart.price[order.orderNum][i];
		order.quantity[order.orderNum][i] = cart.quantity[order.orderNum][i];
	}
	
getAmount();
	
}	

void getAmount(){
	for(int i=0;i<global.stored_x[order.orderNum];i++){
		order.totalAmount[order.orderNum] += order.price[order.orderNum][i]*order.quantity[order.orderNum][i];
	}
	
	
order.orderNum++;
}

void addCart(string x, float y, int z){
	cart.name[order.orderNum][global.x] = x;
	cart.price[order.orderNum][global.x] = y;
	cart.id[order.orderNum][global.x] = z;
}

void chooseProduct(){
	bool notFinished = true;
	bool notDuplicate = true;
	int input[10];
	
	while(notFinished = true){
		
	cout<<"Enter the ID of the product you want to add in the shopping cart[0 to exit]: ";
	cin>>input[global.x];	
			//ADD CONDITIONAL LOOP TO CATCH ERROR
			while(input[global.x] != paper.showID() && input[global.x] != eraser.showID() && input[global.x] != pencil.showID() && input[global.x] != 0){
				cin.clear();
				cin.ignore();
				cout<<"Error Input. Try Again: ";
				cin>>input[global.x];
			}	
		
	for(int i=0;i<global.x;i++){
			if(input[global.x] == cart.id[order.orderNum][i]){
				cart.quantity[order.orderNum][i]++;
				cout<<"Product Added Successfully"<<endl;
				notDuplicate = false;
				break;
			}
		}
			
	if(input[global.x] == paper.showID() && notDuplicate == true ){	 
				addCart(paper.name,paper.price,paper.showID());
				cart.quantity[order.orderNum][global.x]++;
				cout<<"Product Added Successfully"<<endl;
			}
				
				if(input[global.x] == eraser.showID() && notDuplicate == true){
				addCart(eraser.name,eraser.price,eraser.showID());
				cart.quantity[order.orderNum][global.x]++;
				cout<<"Product Added Successfully"<<endl;
			}
			
				if(input[global.x] == pencil.showID() && notDuplicate == true){
				addCart(pencil.name,pencil.price,pencil.showID());
				cart.quantity[order.orderNum][global.x]++;
				cout<<"Product Added Successfully"<<endl;
			}
			
				else if(input[global.x] == 0){

				notFinished = false;
				break;
				}
			
			if(notDuplicate == true){
				global.x++;
			}			
	
	notDuplicate = true;
	}

	notFinished = true;
menu();
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
	paper.setID(101);
	paper.setPrice(10);
	paper.setName("Paper");
	

	eraser.setID(102);
	eraser.setPrice(15);
	eraser.setName("Eraser");
	
	
	pencil.setID(103);
	pencil.setPrice(12);
	pencil.setName("Pencil");
	
	menu();
	
	
	return 0;
	
}
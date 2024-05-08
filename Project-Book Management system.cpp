using namespace std;
#include<iostream>
struct book                               // Structure to represent a book                       
{						
    int bookID;
    char bookName[100];
    char authorName[100];
    double price;
    float rating;
    
    void setBookID(int a)
    {
    	this->bookID=a;
	}
	void setBookName(char*str)
	{
		strcpy(this->bookName,str);
	}
	void setAuthorName(char*str1)
	{
		strcpy(this->authorName,str1);
	}   
	void setPrice(double p)
	{
		this->price=p;
	}
	void setRating(float r)
	{
		this->rating=r;
	} 
	int getBookID()
	{
		return this->bookID;
	}
	char*getBookName()
	{
		return this->bookName;
	}
	char*getAuthorName()
	{
		return this->authorName;
	}
	double getPrice()
	{
		return this->price;
	}
	float getRating()
	{
		return this->rating;
	}
};
#define MAX_BOOKS 100					            // Maximum number of books
void addBook(struct book *b, int);
void displayAllBooks(struct book *b, int);
void removeBook(struct book *b, int*);
void searchBook(struct book *b, int);
void updateBookData(struct book *b, int);
void displayTop3BooksByPrice(struct book *b, int);

int main() 
{
    int choice;
    int num_books;
    cout<<"How many books you want to print: ";
    cin>>num_books;
    
    book *b=new book[num_books];
    
    while (1) 
	{
		cout<<"\n"<<"*** Book Management System Menu ***"<<"\n";
        cout<<"1. Add Book"<<"\n";
        cout<<"2. Display All Books"<<"\n";
        cout<<"3. Remove Book"<<"\n";
        cout<<"4. Search Book"<<"\n";
        cout<<"5. Update Book Data"<<"\n";
        cout<<"6. Display Top 3 Books by Price"<<"\n";
        cout<<"\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";
        switch (choice) 
		{
            case 1:
            	addBook(b, num_books);
                break;
            case 2:
            	displayAllBooks(b, num_books);
                break;
            case 3:
            	removeBook(b, &num_books);
                break;
            case 4:
            	searchBook(b, num_books);
                break;
            case 5:
                updateBookData(b, num_books);
                break;
            case 6:
            	displayTop3BooksByPrice(b, num_books);
                break;
            default:
            	cout<<"Invalid choice. Please select a valid option."<<"\n";
            
        }
    }
}
void addBook(struct book *b, int num_books) 
{
	cout<<"------------Add Books-------------"<<"\n";
 	for(int i=0;i<num_books;i++)
	{
		cout<<"Enter book Id: ";
		cin>>b[i].bookID;
		cout<<"The Book name is: ";
		cin>>b[i].bookName;
		cout<<"The Author name is: ";
		cin>>b[i].authorName;
		cout<<"The price of book is: ";
		cin>>b[i].price;
		cout<<"The ratings is: ";
		cin>>b[i].rating;
		cout<<"\n";
	}
	cout<<"Book added successfully!"<<"\n";
   /* if(*num_books < MAX_BOOKS)
	 {
        struct book b1;
        cout<<"---------------------------------------------------------"<<"\n";
        cout<<"Enter Book ID: ";
        cin>>b1.bookID;
        cout<<"Enter Book Name: ";
        cin>>b1.bookName;
        cout<<"Enter Author name: ";
        cin>>b1.authorName;
        cout<<"Enter price: ";
        cin>>b1.price;
        cout<<"Enter ratings: ";
        cin>>b1.rating;
		cout<<"---------------------------------------------------------"<<"\n";

        b[*num_books] = b1;
        (*num_books)++;
        cout<<"Book added successfully!"<<"\n";
    } 
	else 
		cout<<"Maximum book limit reached. Cannot add more books."<<"\n";*/
}
void displayAllBooks(struct book *b, int num_books) 
{
    if(num_books == 0) 
	{
		cout<<"No books in the database."<<"\n";
    }
	else
	{
	 	cout<<"All Books:"<<"\n";
        cout<<"--------------------------------------------------------------"<<"\n";
        for(int i = 0; i < num_books; i++) 
		{
			cout<<"Book : "<<i + 1<<"\n";
            cout<<"Book ID: "<<b[i].bookID<<"\n";
            cout<<"Name: "<<b[i].bookName<<"\n";
            cout<<"Author name: "<<b[i].authorName<<"\n";
            cout<<"Price: "<<b[i].price<<"\n";
            cout<<"Ratings: "<<b[i].rating<<"\n";
            cout<<"--------------------------------------------------------------"<<"\n";
        }
    }
}
void removeBook(struct book *b, int *num_books) 
{
    int removebook;
    cout<<"Enter the Book ID to remove: ";
    cin>>removebook;
    int found = 0;
    
    for(int i = 0; i < *num_books; i++) 
	{
        if(b[i].bookID == removebook) 
		{
            found = 1;
            
            for(int j = i; j < *num_books - 1; j++) 
			{
                b[j] = b[j + 1];
            }
            (*num_books)--;
            cout<<"Book removed successfully!"<<"\n";
            break;
        }
    }
    if (!found)
	{
		cout<<"Book not found."<<removebook ;
    }
}
void searchBook(struct book *b, int num_books)
 {
    int searchbookID;
    char searchName[100];
    cout<<"Enter 1 to search by BookID or 2 to search by Book Name: ";
    int searchOption;
    cin>>searchOption;
    if (searchOption == 1)
	 {
	 	cout<<"Enter BookID to search: ";
        cin>>searchbookID;
        int found = 0;
        for (int i = 0; i <=num_books; i++) 
		{
            if (b[i].bookID == searchbookID) 
			{
				cout<<"Book found:"<<"\n";
				cout<<"---------------------------------------------------------"<<"\n";
                cout<<"Book ID: "<<b[i].bookID<<"\n";
                cout<<"Name: "<< b[i].bookName<<"\n";
                cout<<"Author name: "<<b[i].authorName<<"\n";
                cout<<"Price: "<<b[i].price<<"\n";
                cout<<"Ratings: "<<b[i].rating<<"\n";
                cout<<"---------------------------------------------------------"<<"\n";
                found= 1;
            }
		}
		if(!found)
		{
			cout<<"Book with BookID"<<searchbookID<<" not found."<<"\n";
    	}
	}
	else if (searchOption == 2)
	{
	 	cout<<"Enter Book Name to search: ";
        cin>>searchName;
        int found = 0;
        for (int i = 0; i < num_books; i++) 
		{
            if (strcmp(b[i].bookName, searchName) == 0) 
			{
				cout<<"Book found:"<<"\n";
				cout<<"---------------------------------------------------------------"<<"\n";
                cout<<"Book ID: "<<b[i].bookID<<"\n";
                cout<<"Name: "<<b[i].bookName<<"\n";
                cout<<"Author name: "<<b[i].authorName<<"\n";
                cout<<"Price: "<<b[i].price<<"\n";
                cout<<"Ratings: "<<b[i].rating<<"\n";
                cout<<"---------------------------------------------------------------"<<"\n";
                found = 1;
            }
        }
        if (!found)
		 {
		 	cout<<"Book with Name "<<searchName<< " not found."<<"\n"; 
         }
    } 
	else
		cout<<"Invalid search option."<<"\n";
}
void updateBookData(struct book *b, int num_books)
 {
    int updatebookID;
    cout<<"Enter Book ID of the Book to update: ";
    cin>>updatebookID;
    int found = 0;
    for (int i = 0; i < num_books; i++) 
	{
        if (b[i].bookID == updatebookID) 
		{
			cout<<"Enter updated price: ";
            cin>>b[i].price;
            cout<<"Enter updated ratings: ";
            cin>>b[i].rating;
        
        	cout<<"Book data updated successfully!"<<"\n";
            found = 1;
        }
    }
    if (!found) 
    	cout<<"Book with BookID "<<updatebookID<< " not found."<<"\n";
}
void displayTop3BooksByPrice(struct book *b, int num_books)
 {
    if (num_books < 3) 
	{
		cout<<"There are fewer than 3 books in the database. Cannot display top 3 books."<<"\n";
    }
    for (int i = 0; i < num_books - 1; i++) 
	{
        for (int j = 0; j <num_books - i - 1; j++)
		 {
            if (b[j].price < b[j + 1].price)
			{
                book temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    } 
    cout<<"Top 3 Books by price:"<<"\n";
   	cout<<"-------------------------------------------------------------"<<"\n";
    for (int i = 0; i < 3; i++)
	{
	 	cout<<"Book ID: "<<b[i].bookID<<"\n";
        cout<<"Name: "<<b[i].bookName<<"\n";
        cout<<"Author name: "<<b[i].authorName<<"\n";
        cout<<"Price: "<<b[i].price<<"\n";
        cout<<"Ratings: "<<b[i].rating<<"\n";
        cout<<"------------------------------------------------------------"<<"\n";
    }
}



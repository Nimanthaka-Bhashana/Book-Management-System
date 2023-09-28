#include<iostream>
#include <string>
using namespace std;

class Node
{



    public:
        void displayDetails();
         int id;
         string title, author, category;

        Node* next;
        Node(string pTitle,string pAuthor,string pCategory,int pId)
        {
            title=pTitle;
            author=pAuthor;
            category=pCategory;
            id=pId;
            next=NULL;
        }


};
void Node::displayDetails()
{
       cout<<"\nBook ID:"<<id;
       cout<<"\nBook Title:"<<title;
       cout<<"\nBook Author:"<<author<<endl;


}
class  BookManagement{


public:
    Node* first= NULL;
    void inserBook();
    void menu();
    void updateBook();
    void searchBook();
    void deleteBook();
    void showBooks();
    void searchByCategory();
};

void BookManagement::menu(){
int choice;
while(true){
    cout<< "\n \t_____Book Mamagent System___";
    cout<< "\n\nS.No     Functions\t\t\t   Description"<<endl;
    cout<< "\n1\tAdd    Book\t\t\tInsert New Book";
    cout<< "\n2\tSearch Book\t\t\tSearch Book by ID";
    cout<< "\n3\tUpdate Book\t\t\tInsert New Book";
    cout<< "\n4\tDelete Book\t\t\tDelete Book by ID";
    cout<< "\n5\tShow   Books\t\t\tShow All Books";
    cout<< "\n6\tSearch by category\t\tSearch Books by Category";
    cout<< "\n7\tExit" <<endl;;

    cout<<"Enter Your Choice:";
    cin>>choice;

    switch(choice){
   case 1:
    inserBook();
    break;
    case 2:
    searchBook();
    break;
    case 3:
    updateBook();
    break;
    case 4:
    deleteBook();
    break;
    case 5:
    showBooks();
    break;
    case 6:
    searchByCategory();
    break;
     case 7:
    return;
     default :
    cout<<"\n\nInvalid Choice"<<endl;





    }




}
}
void BookManagement::inserBook()
{
    string title, author, category;
    int id;

    cout<<"Enter Book ID: ";
    cin >>id;
    cout<<"Enter Book Title: ";
    cin >>title;
    cout<<"Enter Book Author: ";
    cin >>author;
    cout<<"Enter Book Category: ";
    cin >>category;

     Node *newBook=new Node(title, author, category,id);
     Node *current=first;
     if(first==NULL)
     {
         newBook->next=NULL;
        first=newBook;


     }
     else if(current->id==id)
             {

               cout<<"\n\n___This Book Already Added___"<<endl;
               return;

             }
          else
          {
              newBook->next=first;
              first=newBook;

          }




cout<<"\n____New Book Inserted Successfully___"<<endl;
}
void BookManagement::searchBook()
{
  int sId;
  cout<<"Enter Book Id:";
  cin>>sId;
  Node *current=first;
 while(current!=NULL)
 {
     if(current->id==sId)
     {
         current->displayDetails();
         return;
     }
     current=current->next;
 }
  cout<<"Book Not Found"<<endl;
}
void BookManagement::updateBook()
{
    int bookId;
    cout<<"Enter Book ID:";
    cin>>bookId;

    Node*current=first;
    while(current!=NULL)
    {
        if(bookId==current->id)
        {
            cout<<"Book ID:"<<current->id<<endl;
            cout<<"Enter Updated Book Title:";
            cin.ignore(); //Ignore any remaining newline characters
            getline(cin,current->title);
            cout<<"Enter Updated Book Author:";
            getline(cin,current->author);
            cout<<"Enter Updated Category:";
            getline(cin,current->category);



         cout<<"\n\n______Book Details Updated Successfully_______"<<endl;
          return;
        }
        current=current->next;

    }
    cout<<"___Book Not Found___";


}
void BookManagement::deleteBook()
{
 int bookId;
     cout<<"Enter Book ID:";
     cin>>bookId;
     Node *current=first;
      Node *previous=current;


    while(current!=NULL)
    {
        if(bookId==current->id)
        {
            previous->next=current->next;
            current->displayDetails();
            delete current;

            cout<<"\n___Book Delete Successfully___\n";
            return;

        }
       else
       {
           previous=current;
           current=current->next;
       }
    }
     cout<<"___Book Not Found___";

}
void BookManagement::showBooks()
{
    Node *current=first;
    while(current!=NULL)
    {
       current->displayDetails();
       current=current->next;

    }

   cout<<"___Books Empty___";
}
void BookManagement::searchByCategory()

{
    string  bookCategory;
     cout<<"Enter Book Category:";
     cin>>bookCategory;
     bool found=false;
     Node *current=first;
     while(current!=NULL)
    {
        if(bookCategory==current->category)
        {
            if(!found)
            {
                cout<<"Book Category:"<<bookCategory<<endl;
                found=true;
            }

            cout<<"Book Id:"<<current->id<<endl;
            cout<<" Book Title:"<<current->title<<endl;
            cout<<" Book Author:"<<current->author<<endl;

           return;

        }
        current=current->next;
    }
    cout<<"Books Not Found in Category:"<<endl;



}
int main()
{

    BookManagement book;
    book.menu();
    return 0;

}

#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string id,name,author,search;
    fstream file;
    public:
    void showbooks();
    void selectbooks();
    void addbooks();
}obj;

int main(){
   char choise;
   cout<<"1- Show all Books"<<endl;
   cout<<"2- Select a book"<<endl;
   cout<<"3- Add books (Admin section)"<<endl;
   cout<<"4- Exit option"<<endl;
   cout<<"------------------------\n";
   cout<<"enter your chiose\n";
   cin>>choise;
   switch(choise){
    case '1':
     cin.ignore();
     obj.showbooks();
    break;
    case '2':
    cin.ignore();
    obj.selectbooks();
    break;
    case '3':
    cin.ignore();
    obj.addbooks();
    break;
    case '4':
    return 0;
    break;
    default:
    cout<<"Enter a valid option";
   }
   return 0;
}
 void temp:: addbooks(){
    cout<<"\nEnter Book ID:";
    getline(cin,id);

    cout<<"\n Enter Book Name:";
    getline(cin,name);

    cout<<"\n Enter Book Author:";
    getline(cin,author);

    file.open("booksData.txt",ios::out|ios::app);
    file<<id<<"*"<<name<<"*"<<author;
    file.close();
 }
 void temp::showbooks(){
   file.open("bookData.txt",ios :: in);
   getline(file,id,'*');
   getline(file,name,'*');
   getline(file,author,'\n');
       cout<<"\n\n";
       cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
   while(!file.eof()){
       cout<<"\t\t "<<id<<" \t\t\t\t "<<name<<" \t\t\t "<<author<<endl;

   getline(file,id,'*');
   getline(file,name,'*');
   getline(file,author,'\n');
   }
   file.close();
    
 }
 void temp::selectbooks(){
   showbooks();
   cout<<"Enter Book Id :: ";
   getline(cin,search);

   file.open("bookData.txt",ios :: in);
   getline(file,id,'*');
   getline(file,name,'*');
   getline(file,author,'\n');

   cout<<"\n\n";
   cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
   while(!file.eof()){
       if(search == id){
           cout<<"\t\t "<<id<<" \t\t\t "<<name<<" \t\t\t "<<author<<endl;
           cout<<"Book Extracted Successfully...!";
       }
   getline(file,id,'*');
   getline(file,name,'*');
   getline(file,author,'\n');
   }
   file.close();
 }
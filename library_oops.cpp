#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int availableCopies;

    Book(int id, string title, string author, int availableCopies) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->availableCopies = availableCopies;
    }

    void DisplayBook() {
        cout << id << " " << title << " " << author << " " << availableCopies << endl;
    }
};

class Member {
public:
    int id;
    string name;
    long long phoneNumber;
    vector<int> infoBook;

    Member(int id, string name, long long phoneNumber) {
        this->id = id;
        this->name = name;
        this->phoneNumber = phoneNumber;
    }
    void borrowBook(int bookId) {
        infoBook.push_back(bookId);
    }

    void returnBook(int bookId) {
        auto it = find(infoBook.begin(), infoBook.end(), bookId);
        if(it != infoBook.end()){
            infoBook.erase(it);
        }
    }
};

class Library {
public:
    vector<Book> books;
    vector<Member> members;

    void addBook(Book b) {
        books.push_back(b);
    }
    void addMember(Member m) {
        members.push_back(m);
    }
    void display_data(int member_id){
        for(auto &it:members){
            if(it.id==member_id){
                cout << "Books borrowed by : "<<it.name << endl;
                if(it.infoBook.empty()){
                    cout << " no books are borrowed.." << endl;
                    return ;
                }
                
                for(int i: it.infoBook){
                    for(auto &j : books){
                        if(i==j.id){
                            cout << j.title << endl;
                        }
                    }
                }
                return ;
            }
        }
        cout << "Member Not Found.."<< endl;
    }
    void findavaib(int book_id){
        for(auto &i:books){
            if(i.id==book_id){
                cout << i.availableCopies << endl;
            }
        }
    }

    void borrowBook(int memberId, int bookId) {
        bool f = 0;
        for(auto &b : books) {
            if(b.id == bookId && b.availableCopies > 0) {
                for(auto &m : members) {
                    if(m.id == memberId) {
                        m.borrowBook(bookId);
                        b.availableCopies--;
                        f = 1;
                        cout << m.name << " borrowed " << b.title << endl;
                        cout << "Remained Books :" << b.availableCopies << endl;
                        return;
                    }
                }
            }
        }
        if(f == 0) cout << "book is not available\n";
    }

    void returnBook(int memberId, int bookId) {
        for(auto &b : books) {
            if(b.id == bookId) {
                for(auto &m : members) {
                    if(m.id == memberId) {
                        m.returnBook(bookId);
                        b.availableCopies++;
                        cout << m.name << " returned " << b.title << endl;
                        cout << "Remained Books :" << b.availableCopies << endl;
                        return;
                    }
                }
            }
        }
        cout << "Invalid return" << endl;
    }
};

int main() {
    Library lib;
    Book b1(1, "The MindSet", "Surya Garapati", 2);
    Member m1(1, "Chintu", 987654321);
    Book b2(2,"Pursuit of happiness","someone",4);
    Member m2(2,"surya",123456789);

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addMember(m1);
    lib.addMember(m2);

    cout << "Copies before borrow: " << b1.availableCopies << endl;
    lib.borrowBook(m1.id, b1.id);
    lib.borrowBook(m1.id, b2.id);
    lib.borrowBook(m2.id, b2.id);
    lib.findavaib(b2.id);
    lib.returnBook(m1.id,b2.id);
    lib.findavaib(b2.id);
}

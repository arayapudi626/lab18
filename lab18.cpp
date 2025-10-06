//COMSC 210 | Lab 18 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node *next;
};

void addHead(Node *&head, double rating, string comment);
void addTail(Node *&head, double rating, string comment);
void print(Node *hd);
void getReview(double &rating, string &comment);


int main(){
    Node *head = nullptr;

    cout << "Which linked list method should we use?\n"
    << " [1] New nodes are added at the head of the linked list\n"
    << " [2] New Nodes are added at the tail of the linked list\n"
    << " Choice: ";
    int choice = 0;
    cin >> choice;
    while (choice !=1 && choice !=2){
        cout << "Enter 1 or 2";
        cin >> choice;
    }

    char again = 'y';
    while (again == 'y' || again == 'Y'){
        double rating;
        string comment;
        getReview(rating, comment);

        if (choice == 1){
            addHead(head, rating, comment);
        }
        else {
            addTail(head, rating, comment);
        }
        cout << "Enter another review? Y/N: ";
        cin >> again;
    }

    print(head);

    return 0;
    
}
//gets review
//argument: double rating and string comment
//return: none
void getReview(double &rating, string &comment){
    cout << "Enter review rating 0-5: ";
    cin >> rating;
    cin.ignore();
    cout << "Enter review comments: ";
    getline(cin, comment);
}

//adds node to head of linked list
//argument: linked list, double rating and string comment
//return: none
void addHead(Node *&head, double rating, string comment){
    Node *n = new Node;
    if (!head){
        head = n;
        n->next = nullptr;
        n->rating = rating;
        n->comment = comment;
    }
    else {
        n->next = head;
        n->rating = rating;
        n->comment = comment;
        head = n;
    }
}

//adds node to back of linked list
//argument: linked list, double rating and string comment
//return: none
void addTail(Node *&head, double rating, string comment){
    Node *n = new Node;
    n->rating = rating;
    n->comment = comment;
    n->next = nullptr;
    if (!head){
        head = n;
    }
    else {
        Node *current = head;
        while (current->next){
            current = current->next;
        }
        current->next = n;
    }
}
//prints in format and averages review
//argument: linked list
//return: none
void print(Node *hd){
    int count = 0;
    int sum = 0;
    Node *current = hd;
    cout << "Outputting all reviews: \n";
    while (current) {
        cout << "   > Review #" << (count++) << ": "
        << current->rating << ": " << current->comment << endl;
        sum += current->rating;
        current = current->next;
    }
    cout << "   > Average: " << (sum/count) << endl;
}
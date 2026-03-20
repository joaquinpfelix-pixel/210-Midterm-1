// COMSC 210 | Midterm 1 | Joaquin Felix
#include <iostream>
using namespace std;

// Constants 
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    // Node for the doubly linked list
    struct Node {
        int data;    // stores the value
        Node* prev;  // pointer to previous node
        Node* next;  // pointer to next node

        // Constructor that initalixes the node with value
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;    // assign value
            prev = p;      // set previous pointer
            next = n;      // set next pointer
        }
    };

    Node* head; // points to first node in the list
    Node* tail; // points to last node in the list

public:

    // Constuctor intializes an empty lis
    DoublyLinkedList() { 
        head = nullptr; // no first node yet
        tail = nullptr; // no last node yet 
    }

    // Insert a new node after a given position
    void insert_after(int value, int position) {
        
        // Reject invalid negative postions
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        // Allocate memory for new node
        Node* newNode = new Node(value);

        // If list is empty, new node becomes both head and tail
        if (!head) {
            head = tail = newNode;
            return;
        }

        // Start traversal from head
        Node* temp = head;

        // Move temp pointer forward "position" times
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        // If temp became null, position is out of bounds
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        // Link new node into list

        newNode->next = temp->next; // new node points to node after temp
        newNode->prev = temp;       // new node point back to temp
        
        // Fix backward pointer of the next node
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // if inserting at end, update tail
        temp->next = newNode; // temp now points forwards to new node
    }

    // Delete first node containing given value
    void delete_val(int value) {
        if (!head) return;  // empty list

        Node* temp = head;  // start at head
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // value not found

        //Fix previous node's next pointer
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; //removing head

        // Fix next node's prev pointer
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; // removing tail 

        delete temp; // free memory
    }

    //Delete node at position
    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        // If deleting first node
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
        
        // Traverse to the desired position
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
        
        // If delteing last node
        if (!temp->next) {
            pop_back();
            return;
        }
        
        // Re-link nodees around temp
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    //Insert at end
    void push_back(int v) {
        Node* newNode = new Node(v);  // create new node


        if (!tail)
            head = tail = newNode; // empty list case
        else {
            tail->next = newNode; // old tail points forward
            newNode->prev = tail; // new node points backward
            tail = newNode; // update tail pointer
        }
    }
    
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void every_other_element(){

    }
};

int main() {
    DoublyLinkedList;

    
    return 0;
}
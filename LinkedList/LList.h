#ifndef LLIST_H
#define LLIST_H

/*
    Linked List class that store integers, with [] operator.
    Uses head pointer.
    Paul Talaga
    September 2015
*/
#include <ostream>
#include <stdexcept>

#define int int

using namespace std;

struct node_t 
{
    int data;
    node_t* next;
};

// This implementation will use a head pointer,
// allowing O(1) insertion on the front,
// and O(n) on the end.
class LList 
{

    public:
    LList()
    {
        head = NULL;
    }

    ~LList()
    {
        clear();
    }

    LList(const LList& other)
    {
        // Do the same as the default constructor
        head = NULL;
        // Check if the other LList is empty
        if(other.head == NULL)
        {
            return;
        }
        // Not empty?  Iterate through the other list
        // and push_back on myself.
        node_t* temp = other.head;
        while(temp)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    // Similar to copy constructor, but check for self
    // assignment, if not, clear and copy all data.
    LList& operator=(const LList& other)
    {
        if(this == &other)
        {
            return *this;
        }
        clear();
        if(other.head == NULL)
        {
            return *this;
        }
        node_t* temp = other.head;
        while(temp)
        {
            push_back(temp->data);
            temp = temp->next;
        }
        return *this;
    }

    //checks if the linked list is empty
    bool empty() const 
    {
        return head == NULL;
    }

    //returns the size of the linked list
    unsigned int size() const 
    {
        // TODO: Fill me in
        return length;
    }

    //adds value to the end of the linked list
    void push_back(int value)
    {
        // TODO: Fill me in
        if(head == NULL) //if list is empty
        {
            head = new node_t;
            head->data = value;
            head->next = NULL;
        }
        else //list already has values
        {
            node_t* n = new node_t();
            n->data = value;
            n->next = NULL;
            
            node_t* temp = head;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            
            temp->next = n;
        }
        
        length++;
    }

    void push_front(int value)
    {
        // Empty list?
        if(head == NULL)
        {
            head = new node_t;
            head->data = value;
            head->next = NULL;
        }
        else
        { // Not empty
            node_t* temp = new node_t;
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        
        length++;
    }

    void pop_front()
    {
        if(head == NULL) return;
        node_t* temp = head;
        head = head->next;
        delete temp;
        
        length--;
    }

    //removes the value at the end of the linked list
    void pop_back()
    {
        // TODO: Fill me in
        node_t* temp = head;
        
        //if the list is empty
        if(temp == NULL)
        {
            return;
        }
        
        //if there is only one node in the list
        if(temp->next == NULL)
        {
            delete temp;
            head == NULL;
            length--;
        }
        else
        {
            node_t* prev;
            
            do
            {
                if(temp->next == NULL)
                {
                    break;
                }
                prev = temp;
                temp = temp->next;
            } while (temp != NULL);
            
            prev->next = temp->next;
            delete temp;
            length--;
        }
    }


    // Overload [] operator
    // Return logic error if index out of bounds
    int& operator[](unsigned pos)
    {
        node_t* temp = head;
        while(temp != NULL && pos > 0)
        {
            temp = temp->next;
            pos--;
        }
        // As long as I don't have a null pointer, assign.
        if(pos == 0 && temp != NULL)
        {
            return temp->data;
        }
        throw logic_error("Index invalid");
    }

    //reverses the current linked list
    LList reverse() const 
    {
        // TODO: Fill me in
        LList rev;
        
        if(head == NULL)
        {
            return rev;
        }
        else
        {
            node_t* temp = head;
            
            for(int i = 0; i < length; i++)
            {
                rev.push_front(temp->data);
                temp = temp->next;
            }
            
            return rev;
        }
    }
    
    //returns the value at a specific spot in the linked list
    int getAt(unsigned index) const
    {
        int i = 0;
        
        if(empty())
        {
            throw logic_error("List is empty.");
        }
        else if(index >= length)
        {
            throw logic_error("Index does not exist");
        }
        else
        {
            node_t* temp = head;
            
            do
            {
                if(i == index)
                {
                    return temp->data;
                }
                
                if(temp->next == NULL)
                {
                    break;
                }
                
                i++;
                temp = temp->next;
            }while(temp != NULL);
        }
    }

    bool operator==(const LList& other) const 
    {
        if(length != other.size())
        {
            return false;
        }
        else
        {
            node_t* temp = head;
            for(int i = 0; i < length;  i++)
            {
                if(temp->data != other.getAt(i))
                {
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }
    }
    
    LList operator+(const LList& other) const
    {
        LList added;
        
        node_t* temp = head;
        
        for(int i = 0; i < length; i++)
        {
            added.push_back(temp->data);
            temp = temp->next;
        }
        
        if(other.size() != 0)
        {
            for(int i = 0; i < other.size(); i++)
            {
                added.push_back(other.getAt(i));
            }
        }
        
        return added;
    }

    bool operator!=(const LList& other) const 
    {
        return !operator==(other);
    }

    void clear()
    {
        node_t* last = head;
        while(head)
        {
            head = head->next;
            delete last;
            last = head;
        }
        // Normaly you never want to change head or you'll orphan part
        // of the list, but in this case we are wiping the list,
        // so it is ok to so and saves us a variable.
        head = NULL;
    }

    private:
    node_t* head;
    unsigned int length = 0;

};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.

/*ostream& operator<<(ostream& out, const LList other)
{
    out << "[";
    for(unsigned int i = 1; i < other.size(); i++)
    {
        out << other.getAt(i-1) << ", ";
    }
    if(other.size() > 0)
    {
        out << other.getAt(other.size() - 1);
    }
    out << "]";
    return out;
}*/

#endif

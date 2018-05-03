// Programmer:   Sydni-Dee Venter
// Description:  Lab 6 that works with circuits

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//basic node
struct node 
{
	string name;
	double resistance;
	double voltage_across;
	double power_across;
};

//user is able to name a node
void enter_name(node& n)
{
  cout << "Enter name: ";
  cin >> n.name;
}

//user is able to enter the voltage of a node
void enter_totalVoltage(node& n)
{
    cout << "Enter Voltage: ";
    cin >> n.voltage_across;
    
}

//user is able to enter the resistance of a node
void enter_resistance(node& n)
{
    cout << "Enter Resistance (0 to exit): ";
    cin >> n.resistance;
}

//user is able to change the resistance of a node
double change_resistance(node& n)
{
    double oR = n.resistance;
    
    cout << "\tEnter new resistance: ";
    cin >> n.resistance;
    
    return oR;
}

//method calculates the current
double calculate_current(node n)
{
    double c = 0.0;
    
    c = n.voltage_across / n.resistance;
    
    return c;
}

//method calculates the power
void calculate_power(node& n, double current)
{
    n.power_across = n.voltage_across * current;
}

//method calculates the voltage
void calculate_voltage(node& n, double current)
{
    n.voltage_across = n.resistance * current;
}

//method updates the total resistance when a resistance is changed or a node is removed
void update_tResistance(node& n, double oldResistance, double newResistance)
{
    n.resistance -= oldResistance;
    n.resistance += newResistance;
}

//removes node and returns its resistance
double remove_node(vector<node>& nodes, int index)
{
    double r = nodes[index].resistance;
    
    nodes.erase(nodes.begin() + index);
    
    return r;
}

//user is able to edit a node
void edit_node(vector<node>& nodes, node& tN)
{
    int index;
    cout << "What is the index of the node you want to edit? (0-based) ";
    cin >> index;
    
    int num;
    double oR;
    
    cout << endl << "What do you want to do to Node " << index << "?" << endl;
    cout << "\t(0)Change the resistance" << endl;
    cout << "\t(1)Remove" << endl;
    cout << endl << "Enter function: ";
    cin >> num;
    cout << endl;
    
    switch (num)
    {
        case 0:
            oR = change_resistance(nodes[index]);
            update_tResistance(tN, oR, nodes[index].resistance);
            break;
            
        case 1:
            oR = remove_node(nodes, index);
            update_tResistance(tN, oR, 0);
            break;
    }
    
}

//this displays the network and information of the total node
void display_network(node& n)
{
    double cur = calculate_current(n);
    
    cout << "Circuit Parameters: " << endl;
    cout << "\tTotal Resistance: " << n.resistance << " ohms" << endl;
    cout << "\tInput Voltage: " << n.voltage_across << " volts" << endl;
    cout << "\tSeries Current: " << cur << " Amps" << endl;
    calculate_power(n, cur);
    cout << "\tTotal Power: " << n.power_across << " Watts" << endl << endl;
}

//this displays the information of each node
void display_nodes(vector<node>& nodes, node totNode)
{
    for (int i = 0; i < nodes.size(); i++)
    {
      calculate_voltage(nodes[i], calculate_current(totNode));
      calculate_power(nodes[i], calculate_current(totNode));
      
      cout << "Node " << i << " Parameters: " << endl;
      cout << "\tResistance: " << nodes[i].resistance << " ohms" << endl;
      cout << "\tVoltage: " << nodes[i].voltage_across << " volts" << endl;
      cout << "\tPower: " << nodes[i].power_across << " Watts" << endl;
      cout << endl;
    }
}

//this displays the menu
void display_menu()
{
    cout << "Menu:" << endl;
    cout << "\t(0) Display Network" << endl;
    cout << "\t(1) Display Nodes" << endl;
    cout << "\t(2) Edit Nodes" << endl;
    cout << "\t(3) Exit" << endl;
}

//main
int main() 
{
    int r = 1;
    vector<node> nodes;
    node TotalN;
    
    enter_totalVoltage(TotalN);
    TotalN.resistance = 0;
    
    //puts each resistance inside of a node
    while(r != 0)
    {
      node newNode;
      
      enter_resistance(newNode);
      
      r = newNode.resistance;
      
      if(r != 0)
      {
          TotalN.resistance += r;
          nodes.push_back(newNode);
      }
    }
    
    cout << endl;
    
    int num = 0;
    
    //goes through the menu as long as the user doesnt want to exit
    while(num != 3)
    {
        display_menu();
        cout << endl << "Enter task you want to execute: ";
        cin >> num;
        cout << endl;
        
        switch (num)
        {
            case 0:
                display_network(TotalN);
                break;
                
            case 1:
                display_nodes(nodes, TotalN);
                break;
                
            case 2:
                edit_node(nodes, TotalN);
                break;
                
            case 3:
                break;
        }
        
    }
    
    return 0;
}

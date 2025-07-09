#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FamilyTree 
{
private:
    string name;
    string dob;
    vector<FamilyTree*> children;

public:
    FamilyTree(string n, string b)
    {
        name =n;
        dob = b;
    } 

    void addChild(FamilyTree* child) 
    {
        children.push_back(child);
    }

    string getName() const 
    {
        return name;
    }

    string getDob() const
    {
        return dob;
    }

    void visualizeTree(int depth = 0) const 
    {
        for (int i = 0; i < depth; i++) 
        {
            cout << "  ";
        }
        cout << name << " (" << dob << ")" << endl;

        for (const FamilyTree* child : children) 
        {
            child->visualizeTree(depth + 1);
        }
    }
};

int main() 
{
    FamilyTree family("Main", "01/01/1990");
    vector<FamilyTree*> familyMembers = { &family };

    while (true) 
    {
        cout << "\nFamily Tree Menu:\n";
        cout << "1. Add Family Member\n";
        cout << "2. Visualize Family Tree\n";
        cout << "3. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            string parentName, childName, childDob;

            cout << "Enter parent's name: ";
            cin.ignore();
            getline(cin, parentName);
            cout << "Enter child's name: ";
            getline(cin, childName);
            cout << "Enter child's DOB: ";
            getline(cin, childDob);

            bool parentFound = false;
            for (FamilyTree* parent : familyMembers) 
            {
                if (parent->getName() == parentName) 
                {
                    FamilyTree* child = new FamilyTree(childName, childDob);
                    parent->addChild(child);
                    familyMembers.push_back(child);
                    cout << "Family member added successfully.\n";
                    parentFound = true;
                    break;
                }
            }

            if (!parentFound) 
            {
                cout << "Parent not found in the family tree.\n";
            }

        } else if (choice == 2) 
        {
            cout << "\nFamily Tree Visualization:\n";
            family.visualizeTree();

        } else if (choice == 3) 
        {
            cout << "Exiting the program. Goodbye!\n";
            break;

        } else 
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

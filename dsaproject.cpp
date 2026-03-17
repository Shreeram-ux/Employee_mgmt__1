#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id, salary;
    string name;
    Node *next, *left, *right;
};

Node *head = NULL, *root = NULL;

Node* createNode(int empId, int empSalary, string empName)
{
    Node* newNode = new Node;
    newNode->id = empId;
    newNode->salary = empSalary;
    newNode->name = empName;
    newNode->next = newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* node, Node* newNode)
{
    if (node == NULL) return newNode;

    if (newNode->id < node->id)
        node->left = insertBST(node->left, newNode);
    else if (newNode->id > node->id)
        node->right = insertBST(node->right, newNode);
    else
        cout << "Duplicate ID not allowed.\n";

    return node;
}

void insert(int empId, int empSalary, string empName)
{
    Node* newNode = createNode(empId, empSalary, empName);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    root = insertBST(root, newNode);
    cout << "Inserted Employee: " << empId << " in Linked List & BST\n";
}

void modify(int empId, int newSalary, string newName)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->id == empId)
        {
            temp->salary = newSalary;
            temp->name = newName;
            cout << "Employee ID " << empId << " modified successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Employee ID " << empId << " not found!\n";
}

Node* findMin(Node* node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* deleteBST(Node* root, int empId)
{
    if (root == NULL) return root;

    if (empId < root->id)
        root->left = deleteBST(root->left, empId);
    else if (empId > root->id)
        root->right = deleteBST(root->right, empId);
    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->id = temp->id;
        root->name = temp->name;
        root->salary = temp->salary;
        root->right = deleteBST(root->right, temp->id);
    }
    return root;
}

void deleteNode(int empId)
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    if (head->id == empId)
    {
        Node* temp = head;
        head = head->next;
        root = deleteBST(root, empId);
        delete temp;
        cout << "Employee ID " << empId << " deleted from Linked List & BST.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->id != empId)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Employee ID " << empId << " not found!\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    root = deleteBST(root, empId);
    delete delNode;
    cout << "Employee ID " << empId << " deleted from Linked List & BST.\n";
}

void displayLinkedList()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << "ID: " << temp->id << ", Salary: " << temp->salary
             << ", Name: " << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void inOrder(Node* node)
{
    if (node == NULL) return;
    inOrder(node->left);
    cout << "ID: " << node->id << ", Name: "
         << node->name << ", Salary: " << node->salary << endl;
    inOrder(node->right);
}

void preOrder(Node* node)
{
    if (node == NULL) return;
    cout << "ID: " << node->id << ", Name: "
         << node->name << ", Salary: " << node->salary << endl;
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node* node)
{
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << "ID: " << node->id << ", Name: "
         << node->name << ", Salary: " << node->salary << endl;
}

void displayTree()
{
    if (root == NULL)
    {
        cout << "Tree is empty.\n";
        return;
    }

    cout << "\n1. In-order Traversal\n2. Pre-order Traversal\n3. Post-order Traversal\nEnter choice: ";
    int choice;
    cin >> choice;

    if (choice == 1)
        inOrder(root);
    else if (choice == 2)
        preOrder(root);
    else if (choice == 3)
        postOrder(root);
    else
        cout << "Invalid choice\n";
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1. Insert Employee in Database (Linked List & BST)"
             << "\n2. Display Employees as Linked List"
             << "\n3. Display Employees as Tree (In-order, Pre-order, Post-order)"
             << "\n4. Modify Employee Details"
             << "\n5. Delete Employee"
             << "\n6. Exit"
             << "\nEnter your choice: ";

        cin >> choice;

        if (choice == 1)
        {
            int empId, empSalary;
            string empName;
            cout << "Enter Employee ID: ";
            cin >> empId;
            cout << "Enter Employee Salary: ";
            cin >> empSalary;
            cout << "Enter Employee Name: ";
            cin >> empName;
            insert(empId, empSalary, empName);
        }
        else if (choice == 2)
        {
            displayLinkedList();
        }
        else if (choice == 3)
        {
            displayTree();
        }
        else if (choice == 4)
        {
            int empId, newSalary;
            string newName;
            cout << "Enter Employee ID to modify: ";
            cin >> empId;
            cout << "Enter New Salary: ";
            cin >> newSalary;
            cout << "Enter New Name: ";
            cin >> newName;
            modify(empId, newSalary, newName);
        }
        else if (choice == 5)
        {
            int empId;
            cout << "Enter Employee ID to delete: ";
            cin >> empId;
            deleteNode(empId);
        }
        else if (choice == 6)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }
}
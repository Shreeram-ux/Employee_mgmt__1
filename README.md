# Employee Database using Linked List and Binary Search Tree (BST)

## 📌 Project Description

This project is a **Data Structures mini-project** implemented in **C++** that manages an employee database using two data structures:

* **Singly Linked List** → for sequential storage and display
* **Binary Search Tree (BST)** → for hierarchical storage and sorted traversal

Both data structures store the **same employee records** (Employee ID, Name, Salary).
This allows performing operations efficiently in different scenarios.

---

## 🎯 Objectives

* To understand the implementation of **Linked List and Binary Search Tree**
* To perform **CRUD operations (Create, Read, Update, Delete)** on employee data
* To demonstrate **Tree Traversals** (In-order, Pre-order, Post-order)
* To practice **dynamic memory allocation in C++**

---

## ⚙️ Features

✅ Insert Employee in both Linked List and BST
✅ Display Employees as Linked List
✅ Display Employees as Tree using:

* In-order Traversal
* Pre-order Traversal
* Post-order Traversal

✅ Modify Employee Details
✅ Delete Employee Record
✅ Menu Driven Program

---

## 🧠 Data Structures Used

### 🔹 Singly Linked List

* Stores employees in **insertion order**
* Used for sequential traversal and display

### 🔹 Binary Search Tree (BST)

* Stores employees based on **Employee ID (Key)**
* Enables **sorted traversal**
* Helps demonstrate recursive operations

---

## 🏗️ Project Structure

```
dsaproject.cpp    → Main source file containing full implementation
README.md         → Project documentation
```

---

## ▶️ How to Compile and Run

### ✅ Using g++

```bash
g++ dsaproject.cpp -o dsaproject
./dsaproject
```

### ✅ Using VS Code (Windows PowerShell)

```bash
g++ dsaproject.cpp -o dsaproject
.\dsaproject
```

---

## 📋 Menu Options

```
1. Insert Employee in Database
2. Display Employees as Linked List
3. Display Employees as Tree
4. Modify Employee Details
5. Delete Employee
6. Exit
```

---

## 🧩 Employee Record Structure

Each employee node contains:

* Employee ID (int)
* Employee Name (string)
* Employee Salary (int)
* Pointer for Linked List (next)
* Pointers for BST (left, right)

---

## 🔄 Tree Traversal Methods

### ✔ In-order Traversal

Displays employees in **ascending order of Employee ID**

### ✔ Pre-order Traversal

Displays **root → left → right**

### ✔ Post-order Traversal

Displays **left → right → root**

---

## 📚 Concepts Used

* Structures in C++
* Pointers and Dynamic Memory Allocation
* Recursion
* Linked List Operations
* Binary Search Tree Operations
* Menu Driven Programming

---

## 🚀 Future Enhancements

* Search Employee Function
* Count Total Employees
* Find Height of BST
* File Handling for Permanent Storage
* Separate Nodes for Linked List and BST (Memory Optimization)
* GUI Version

---

## 👨‍💻 Author

**Shreeram**

---

## 📄 License

This project is created for **educational and academic purposes**.

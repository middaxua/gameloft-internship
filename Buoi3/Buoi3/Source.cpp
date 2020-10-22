#include <iostream>
#include <string>
#include <list>

using namespace std;

class BaseObject
{
public:
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	virtual void move() = 0;
	virtual void printPosition() = 0;

	int id;
	string name;
	double position;
};

class StaticObject : public BaseObject
{
	void move() {}
};

class Tree : public StaticObject {
public:
	Tree(int id, string name, double position) {
		this->id = id;
		this->name = name;
		this->position = position;
	}
	void printPosition() {
		cout << "Tree position: " << position << endl;
	}
};

class House : public StaticObject {
public:
	House(int id, string name, double position) {
		this->id = id;
		this->name = name;
		this->position = position;
	}
	void printPosition() {
		cout << "House position: " << position << endl;
	}
};

class DynamicObject : public BaseObject
{
	virtual void move() {
		position += 5.0;
	}
};

class Motorbike : public DynamicObject {
public:
	Motorbike(int id, string name, double position) {
		this->id = id;
		this->name = name;
		this->position = position;
	}
	void printPosition() {
		cout << "Motorbike position: " << position << endl;
	}
};

class Car : public DynamicObject {
public:
	Car(int id, string name, double position) {
		this->id = id;
		this->name = name;
		this->position = position;
	}
	void move() {
		position += 10.0;
	}
	void printPosition() {
		cout << "House position: " << position << endl;
	}
};

int main() {

	// Create a list contains some base objects
	list<BaseObject*> listBaseObject;
	listBaseObject.push_back(new Tree(1, "Tree", 5.0));
	listBaseObject.push_back(new House(2, "House", 7.0));
	listBaseObject.push_back(new Motorbike(3, "Motorbike", 9.0));
	listBaseObject.push_back(new Car(4, "Car", 11.0));

	// Get name of all items in the list
	cout << "Get name of all items in the list\n";
	for (BaseObject *obj : listBaseObject) {
		cout << obj->getName() << endl;
	}

	// Print position of all items in the list
	cout << "\nPrint position of all items in the list before moving\n";
	for (auto obj : listBaseObject) {
		obj->printPosition();
	}

	// Move all items in the list
	cout << "\nMove all items in the list\n";
	for (BaseObject *obj : listBaseObject) {
		obj->move();
	}

	// Print position of all items in the list
	cout << "\nPrint position of all items in the list after moving\n";
	for (auto obj : listBaseObject) {
		obj->printPosition();
	}
	
	// Release memory
	cout << "\nRelese memory\n";
	for (auto obj : listBaseObject) {
		delete obj;
	}
	listBaseObject.clear();

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


//do a search from root to bottom to print everithing on the screen



struct node {
	node* parentPtr = NULL;
	vector<node*>  childrenPtrList;
	string name;
	bool admin;
	string password;


	node(node* headPtr, string name, bool admin) {
		this->name = name;

		this->parentPtr = headPtr;
		if (parentPtr != NULL)
		{
			connectObjects();
		}

		this->admin = admin;
		if (this->admin)
		{
			//cout << "password should be inserted here! " << endl;
		}
	}

	void connectObjects()
	{
		parentPtr->childrenPtrList.push_back(this);
	}

	string getName()
	{
		return name;
	}

	vector<node*> getChildren()
	{
		return  childrenPtrList;
	}

	node* getParent()
	{
		return parentPtr;
	}

	string getPassword()
	{
		if (admin)
		{
			return password;
		}
		else
		{
			cout << "There is no password on this unit" << endl;
			return NULL;
		}
	}

	void printName()
	{
		cout << name << endl;
	}

	void moveObjectToNewParent(node* newParent)
	{
		//this->parentPtr->childrenPtrList.erase(remove(childrenPtrList.begin(), childrenPtrList.end, this ), childrenPtrList.end()); -> if there are more the on occurences of the instance this will only get rid of one of them, the one below will get rid of all the instances in the vector
		vector<node*>::iterator position = find(this->parentPtr->childrenPtrList.begin(), this->parentPtr->childrenPtrList.end(), this);
		if (position != this->parentPtr->childrenPtrList.end())
			this->parentPtr->childrenPtrList.erase(position);
		this->parentPtr = newParent;
	}

	//DFS
	void printEntireTreeOnScreenDFS(node* selectedPointer)
	{
		if (selectedPointer->childrenPtrList.size() != 0)
		{
			for (int i = 0; i < selectedPointer->childrenPtrList.size(); i++)
			{
				cout << selectedPointer->childrenPtrList[i]->name << endl;
				printEntireTreeOnScreenDFS(selectedPointer->childrenPtrList[i]);
			}
		}
	}

	//BFS
	void printEntireTreeOnScreenBFS(node* selectedPointer)
	{
		//cout << selectedPointer->name << endl;

		if (selectedPointer->childrenPtrList.size() != 0)
		{
			for (int i = 0; i < selectedPointer->childrenPtrList.size(); i++)
			{
				cout << selectedPointer->childrenPtrList[i]->name << "; ";

			}
			cout << endl;
			for (int i = 0; i < selectedPointer->childrenPtrList.size(); i++)
			{
				printEntireTreeOnScreenBFS(selectedPointer->childrenPtrList[i]);
			}
		}
	}
};



int main()
{
	node root(NULL, "Root", false);
	node obj1(&root, "HeadFolder", true);
	node obj2(&obj1, "A", false);
	node obj3(&obj1, "B", false);
	node obj4(&obj1, "C", false);
	node obj5(&obj1, "D", true);
	node obj0(&root, "HeadFolder2", true);

	obj5.moveObjectToNewParent(&obj0);

	vector<node*> newObj = obj1.getChildren();

	/*
	for (int i = 0; i < newObj.size(); i++)
	{
		string nameString = newObj[i]->getName();
		cout << nameString << endl;
	}
	*/


	root.printEntireTreeOnScreenDFS(&root);
	cout << endl;
	root.printEntireTreeOnScreenBFS(&root);




}

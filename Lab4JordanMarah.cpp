#include <iostream>
/*
	Jordan Marah
	C00218412
	A class structure for a linked list,made up of item objects
	November 2019
*/

class Item
{
public:
	int data;
	Item* nextItemPointer;

};

class List
{
public:
	Item* frontPointer;
	List() :frontPointer(NULL) {};
	~List()
	{

	}
	void pushFront(int data)
	{
		Item* newItemPointer = new Item();
		newItemPointer->data = data;
		newItemPointer->nextItemPointer = frontPointer;
		frontPointer = newItemPointer;
	}

	void display()
	{
		for (Item* curItemPointer = frontPointer; curItemPointer != NULL; curItemPointer = curItemPointer->nextItemPointer)
		{
			std::cout << curItemPointer->data << std::endl;
		}
	}

	// search for the first item with the value d as data, return a pointer to the item found
	Item* search(int data)
	{
		if (frontPointer != NULL)
		{
			for (Item* curItemPointer = frontPointer; curItemPointer != NULL; curItemPointer = curItemPointer->nextItemPointer)
			{
				if (curItemPointer->data == data)
				{
					std::cout << "Found : " << data << std::endl;
					return curItemPointer;
				}
			}
			std::cout << "Number not found" << std::endl;
			return NULL;
		}
		else if (frontPointer == NULL)
		{
			std::cout << "List is empty" << std::endl;
			return NULL;
		}
		else
		{
			return NULL;
		}

	}

	// erase the item pointed to by loc
	void erase(Item* loc)
	{
		if (frontPointer != NULL && frontPointer != loc)
		{
			if (loc != NULL)
			{
				Item* curItemPointer = frontPointer;

				while (curItemPointer->nextItemPointer != NULL)
				{
					if (curItemPointer->nextItemPointer == loc)
					{
						curItemPointer->nextItemPointer = curItemPointer->nextItemPointer->nextItemPointer;
						free(loc);
						return;
					}
					else if (curItemPointer->nextItemPointer == NULL)
					{
						std::cout << "This location doesnt exist" << std::endl;
						return;
					}
					curItemPointer = curItemPointer->nextItemPointer;
				}
			}
			else if (loc == NULL)
			{
				std::cout << "Null pointer sent" << std::endl;
				return;
			}
		}
		else if (frontPointer == loc && loc != NULL)
		{
			frontPointer = frontPointer->nextItemPointer;
			free(loc);
		}
		else if (frontPointer == NULL)
		{
			std::cout << "Empty List" << std::endl;
			return;
		}
		
	}

	// insert a copy of data before or after loc
	void insertBefore(Item* loc, int data)
	{
		if (loc != NULL)
		{
			Item* newItemPointer = new Item();
			newItemPointer->data = data;

			Item* curItemPointer = frontPointer;

			if (loc == frontPointer)
			{
				newItemPointer->nextItemPointer = frontPointer;
				frontPointer = newItemPointer;
				return;
			}
			while (curItemPointer->nextItemPointer != loc && curItemPointer->nextItemPointer != NULL)
			{
				curItemPointer = curItemPointer->nextItemPointer;
			}
			if (curItemPointer->nextItemPointer == loc)
			{
				newItemPointer->nextItemPointer = loc;
				curItemPointer->nextItemPointer = newItemPointer;
				return;
			}
		}
		else if (loc == NULL)
		{
			std::cout << "Null Pointer sent" << std::endl;
			return;
		}
	}

	void insertAfter(Item* loc, int data)
	{
		if (loc != NULL)
		{
			Item* newItemPointer = new Item();
			newItemPointer->data = data;

			newItemPointer->nextItemPointer = loc->nextItemPointer;
			loc->nextItemPointer = newItemPointer;
		}
		else if (loc == NULL)
		{
			std::cout << "Null pointer sent" << std::endl;
		}
	}

	//push a copy of data on to the back(end ) of the list. PushBack adds an item to the end of the list.
	void PushBack(int data)
	{
		Item* newItemPointer = new Item();
		newItemPointer->data = data;
		newItemPointer->nextItemPointer = NULL;
		if (frontPointer != NULL)
		{
			Item* curItemPointer = frontPointer;
			while (curItemPointer->nextItemPointer != NULL)
			{
				curItemPointer = curItemPointer->nextItemPointer;
			}
			if (curItemPointer->nextItemPointer == NULL)
			{
				curItemPointer->nextItemPointer = newItemPointer;
				return;
			}
		}
		else if (frontPointer == NULL)
		{
			frontPointer = newItemPointer;
			return;
		}
	}

	//returns true if  PopBack is successful. Popback removes the last item in the list.Fill data with a copy the data in the node
	bool PopBack(int& data)
	{
		if (frontPointer != NULL)
		{
			Item* curItemPointer = frontPointer;

			if (curItemPointer->nextItemPointer == NULL)
			{
				data = curItemPointer->data;
				free(curItemPointer);
				frontPointer = NULL;
				return true;
			}
			while (curItemPointer->nextItemPointer->nextItemPointer != NULL)
			{
				curItemPointer = curItemPointer->nextItemPointer;
			}
			if (curItemPointer->nextItemPointer->nextItemPointer == NULL)
			{
				data = curItemPointer->nextItemPointer->data;
				free(curItemPointer->nextItemPointer);
				curItemPointer->nextItemPointer = NULL;
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (frontPointer == NULL)
		{
			std::cout << "Empty List" << std::endl;
			return false;
		}
		else
		{
			return false;
		}
	}

	//returns true if  PopFront is successful. Pop an item from the front of the list. Fill data with a copy of the data in the node.
	bool PopFront(int& data) 
	{
		if (frontPointer != NULL)
		{
			Item* curItemPointer = frontPointer;

			data = curItemPointer->data;
			frontPointer = frontPointer->nextItemPointer;
			free(curItemPointer);
			return true;
		}
		else
		{
			std::cout << "Empty List" << std::endl;
			return false;
		}
	}

	void DeleteFront()
	{
		if (frontPointer != NULL)
		{
			Item* curItemPointer = frontPointer;
			frontPointer = frontPointer->nextItemPointer;
			free(curItemPointer);
			return;
		}
		else if (frontPointer == NULL)
		{
			std::cout << "List is empty" << std::endl;
			return;
		}
	}

	void DeleteAll()
	{
		Item* curItemPointer = frontPointer;
		Item* temp;
		while (curItemPointer != NULL)
		{
			temp = curItemPointer->nextItemPointer;
			free(curItemPointer);
			curItemPointer = temp;
		}
		frontPointer = NULL;
	}

};
int main()
{
	List emptyList;
	List emptyList2;
	List myList;
	bool test = false;
	myList.pushFront(1);
	myList.pushFront(2);
	myList.pushFront(3);
	myList.display();
	std::cout << "3,2,1" << std::endl;
	std::cout << "-------Display---------" << std::endl;
	std::cout << std::endl;

	emptyList.display();
	std::cout << "<nothing>" << std::endl;
	std::cout << "-------Empty List Display---------" << std::endl;
	std::cout << std::endl;

	myList.search(2);
	std::cout << "Found 2" << std::endl;
	std::cout << "-------Search--------" << std::endl;
	std::cout << std::endl;

	myList.search(5);
	std::cout << "Number not found" << std::endl;
	std::cout << "-------Search number not there--------" << std::endl;
	std::cout << std::endl;

	emptyList.search(5);
	std::cout << "List is empty" << std::endl;
	std::cout << "-------Search empty list--------" << std::endl;
	std::cout << std::endl;

	myList.erase(NULL);
	std::cout << "Null pointer sent" << std::endl;
	std::cout << "-------Erase Null Pointer from list--------" << std::endl;
	std::cout << std::endl;

	Item* eraseTest = myList.search(2);
	myList.erase(eraseTest);
	myList.display();
	std::cout << "3,1" << std::endl;
	std::cout << "-------Erase from List--------" << std::endl;
	std::cout << std::endl;

	Item* eraseTest2 = myList.search(3);
	emptyList.erase(eraseTest);
	emptyList.display();
	std::cout << "Empty List" << std::endl;
	std::cout << "-------Erase from Empty List--------" << std::endl;
	std::cout << std::endl;

	Item* insertBeforeTest = myList.search(1);
	myList.insertBefore(insertBeforeTest, 5);
	myList.display();
	std::cout << "3,5,1" << std::endl;
	std::cout << "-------Insert Before--------" << std::endl;
	std::cout << std::endl;

	Item* insertBeforeTest2 = NULL;
	myList.insertBefore(insertBeforeTest2, 5);
	myList.display();
	std::cout << "NULL pointer sent" << std::endl;
	std::cout << "-------Insert Before NULL sent--------" << std::endl;
	std::cout << std::endl;

	Item* insertAfterTest = NULL;
	myList.insertAfter(insertAfterTest, 5);
	myList.display();
	std::cout << "NULL pointer sent" << std::endl;
	std::cout << "-------Insert after NULL sent--------" << std::endl;
	std::cout << std::endl;

	Item* insertAfterTest2 = myList.search(1);
	myList.insertAfter(insertAfterTest2, 5);
	myList.display();
	std::cout << "3,5,1,5" << std::endl;
	std::cout << "-------Insert after--------" << std::endl;
	std::cout << std::endl;

	myList.PushBack(7);
	myList.display();
	std::cout << "3,5,1,5,7" << std::endl;
	std::cout << "-------Push Back--------" << std::endl;
	std::cout << std::endl;

	emptyList.PushBack(9);
	emptyList.display();
	std::cout << "9" << std::endl;
	std::cout << "-------Push Back empty list--------" << std::endl;
	std::cout << std::endl;

	int x = 100;
	test = myList.PopBack(x);
	std::cout << "True" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	myList.display();
	std::cout << "3,5,1,5" << std::endl;
	std::cout << "7" << std::endl;
	std::cout << x << std::endl;
	std::cout << "-------Pop back--------" << std::endl;
	std::cout << std::endl;

	int y = 200;
	test = emptyList2.PopBack(y);
	std::cout << "False" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	emptyList2.display();
	std::cout << "List is empty" << std::endl;
	std::cout << "200" << std::endl;
	std::cout << y << std::endl;
	std::cout << "-------Pop back empty list--------" << std::endl;
	std::cout << std::endl;

	int p = 300;
	test = emptyList2.PopFront(p);
	std::cout << "False" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	emptyList2.display();
	std::cout << "List is empty" << std::endl;
	std::cout << "300" << std::endl;
	std::cout << p << std::endl;
	std::cout << "-------Pop front empty list--------" << std::endl;
	std::cout << std::endl;
	
	int q = 400;
	test = myList.PopFront(q);
	std::cout << "True" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	myList.display();
	std::cout << "5,1,5" << std::endl;
	std::cout << "3" << std::endl;
	std::cout << q << std::endl;
	std::cout << "-------Pop front --------------" << std::endl;
	std::cout << std::endl;

	emptyList2.DeleteFront();
	emptyList2.display();
	std::cout << "Empty List" << std::endl;
	std::cout << "-------Delete Front empty list--------" << std::endl;
	std::cout << std::endl;

	myList.DeleteFront();
	myList.display();
	std::cout << "1,5" << std::endl;
	std::cout << "-------Delete Front--------" << std::endl;
	std::cout << std::endl;

	myList.DeleteAll();
	myList.display();
	std::cout << "" << std::endl;
	std::cout << "-------Delete All--------" << std::endl;
	std::cout << std::endl;

	emptyList2.DeleteAll();
	emptyList2.display();
	std::cout << "" << std::endl;
	std::cout << "-------Delete All empty list--------" << std::endl;
	std::cout << std::endl;
	return 0;
}
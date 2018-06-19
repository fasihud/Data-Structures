#include <iostream>
#include <string>

// define character size
#define CHAR_SIZE 128

class RadTree
{
public:
	bool isLeaf;
	RadTree* character[CHAR_SIZE];


	RadTree()
	{
		this->isLeaf = false;

		for (int i = 0; i < CHAR_SIZE; i++)
			this->character[i] = nullptr;
	}

	//Function to insert a key in the RadixTree
	void insert(std::string key)
	{
		// start from root node
		RadTree* curr = this;
		for (int i = 0; i < key.length(); i++)
		{
			// create a new node if path doesn't exists
			if (curr->character[key[i]] == nullptr)
				curr->character[key[i]] = new RadTree();

			// go to next node
			curr = curr->character[key[i]];
		}

		// mark current node as leaf
		curr->isLeaf = true;
	}

	// Function to search a key in RadixTree
	bool search(std::string key)
	{
		// return false if RadixTree is empty
		if (this == nullptr)
			return false;

		RadTree* curr = this;
		for (int i = 0; i < key.length(); i++)
		{
			// go to next node
			curr = curr->character[key[i]];

			// if string is invalid reached end of path in RadixTree
			if (curr == nullptr)
				return false;
		}

		// if current node is a leaf and we have reached the end of the string return true
		return curr->isLeaf;
	}

	// returns true if given node has any children
	bool haveChildren(RadTree const* curr)
	{
		for (int i = 0; i < CHAR_SIZE; i++)
		if (curr->character[i])
			return true;    // child found

		return false;
	}

	// Function to delete a key in the RadTree
	bool deletion(RadTree*& curr, std::string key)
	{
		// return if RadixTree is empty
		if (curr == nullptr)
			return false;

		// if we have not reached the end of the key
		if (key.length())
		{
			// recurse for the node corresponding to next character in the key
			// and if it returns true, delete current node (if it is non-leaf)

			if (curr != nullptr && curr->character[key[0]] != nullptr && deletion(curr->character[key[0]], key.substr(1)) && curr->isLeaf == false)
			{
				if (!haveChildren(curr))
				{
					delete curr;
					curr = nullptr;
					return true;
				}
				else {
					return false;
				}
			}
		}

		// if we have reached the end of the key
		if (key.length() == 0 && curr->isLeaf)
		{
			// if current node is a leaf node and don't have any children
			if (!haveChildren(curr))
			{
				// delete current node
				delete curr;
				curr = nullptr;

				// delete non-leaf parent nodes
				return true;
			}

			// if current node is a leaf node and have children
			else
			{
				// mark current node as non-leaf node (DON'T DELETE IT)
				curr->isLeaf = false;

				// don't delete its parent nodes
				return false;
			}
		}

		return false;
	}
};
int main()
{
	RadTree* rad = new RadTree();
	/////////////////////////////////Insertion//////////////////////////////////////////
	std::cout << "/////////////////Insertion///////////////";
	std::cout << std::endl;
	rad->insert("bow");
	std::cout << rad->search("bow") << " ";      // print 1 (found)

	std::cout << std::endl;

	rad->insert("bowler");
	std::cout << rad->search("bowler") << " "; // print 1 (found)

	std::cout << std::endl;

	std::cout << rad->search("ball") << " ";        // print 0 (Not found)

	std::cout << std::endl;

	rad->insert("bat");
	std::cout << rad->search("bat") << " ";        // print 1 (found)

	std::cout << std::endl;

	////////////////////////Deletion//////////////////////////////////////////////////////////////////
	std::cout << "/////////////////Deletion///////////////";
	std::cout << std::endl;
	rad->deletion(rad, "bow");
	std::cout << rad->search("bow") << " ";       // print 0 ("bow" deleted)

	std::cout << std::endl;

	std::cout << rad->search("bowler") << " ";  // print 1 (found)

	std::cout << std::endl;

	rad->deletion(rad, "bowler");
	std::cout << rad->search("bowler") << " ";         // print 0 ("bolwer" deleted)

	std::cout << std::endl;

	std::cout << rad->search("bat") << " ";        // print 1 (found)

	std::cout << std::endl;

	rad->deletion(rad, "bat");
	std::cout << rad->search("bat") << " ";  // print 0 ("bat" deleted)

	std::cout << std::endl;

	if (rad == nullptr)
		std::cout << "Radix Tree is empty!!\n";               // RadixTree is empty now

	std::cout << rad->search("bow");               // print 0
	int a;
	std::cin >> a;
	return 0;
}
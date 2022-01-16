#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	//Part 1
	string direction;
	int amount, position = 0, depth = 0, product = 0;
	//open stream
	ifstream inStream("input2.txt");
	if (inStream.fail())
		exit(1);
	//find final position and depth
	while (!(inStream.eof()))
	{
		inStream >> direction >> amount;
		switch (direction[0])
		{
		case 'f':
			position += amount;
			break;
		case 'd':
			depth += amount;
			break;
		case 'u':
			depth -= amount;
			break;
		default:
			cout << "Error reading.\n";
			exit(1);
			break;
		}
	}
	inStream.close();
	product = position * depth;
	cout << "Part 1: The final product is " << product << endl;
	//Part 2
	//initialize variables
	int aim = 0;
	amount = 0; position = 0; depth = 0; product = 0;
	//open stream
	inStream.open("input2.txt");
	if (inStream.fail())
		exit(1);
	//find final position and depth
	while (!(inStream.eof()))
	{
		inStream >> direction >> amount;
		switch (direction[0])
		{
		case 'f':
			position += amount;
			depth += aim * amount;
			break;
		case 'd':
			aim += amount;
			break;
		case 'u':
			aim -= amount;
			break;
		default:
			cout << "Error reading.\n";
			exit(1);
			break;
		}
	}
	product = position * depth;
	cout << "Part 2: The final product is " << product << endl;
	return 0;
}
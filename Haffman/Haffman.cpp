#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string text = GetText();

	std::map<char, int> frequencies = create_character_tree(text);
	std::vector<Node> nodes = createArrFrequencies(frequencies);
	Node root = huffman(nodes);
	map<char, string> codes = codesMap(frequencies, root);

	string encodedString = getCodedString(codes, text);
	cout << encodedString << endl; 
	string decodedString = getUncodedString(codes, encodedString);
	cout << decodedString << endl;
    return 0;
}
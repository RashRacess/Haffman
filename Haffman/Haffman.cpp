#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string line;
	std::string text;

	while (getline(std::cin, line)) {
		if (line == "")
			break;
		text += '\n';
		text += line;
	}
	text.erase(0, 1);

	std::map<char, int> frequencies = create_character_tree(text);
	std::vector<Node> nodes = createArrFrequencies(frequencies);

	Node root = huffman(nodes);

	map<char, string> codes = codesMap(frequencies, root);

	string encodedString = getCodedString(codes, text);
	cout << encodedString << endl; 
	string decodedString = decodeHuffman(encodedString, codes);
	cout << decodedString << endl;
    return 0;
}
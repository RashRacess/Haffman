#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h>
#include "Node.h"
using namespace std;


std::ostream& operator<<(std::ostream& os, const Node& node) {
	os << node._c << " | " << node._weight;
	return os;
}

std::map<char, int> create_character_tree(const std::string& text) {
	std::map<char, int> frequencies;
	for (char ch : text) {
		frequencies[ch]++;
	}
	return frequencies;
}

Node huffman(vector<Node>& nodes) {
	while (nodes.size() > 1) {
		sort(nodes.begin(), nodes.end(), greater<Node>());
		Node* left = new Node(nodes.back());  // Создаем копию узла
		nodes.pop_back();
		Node* right = new Node(nodes.back());  // Создаем копию узла
		nodes.pop_back();
		Node parent = Node('\0', right->_weight + left->_weight, left, right);  // Создаем родительский узел
		nodes.push_back(parent);
	}
	return nodes[0];
}

vector<Node> createArrFrequencies(map<char, int>frequencies) {
	vector<Node> nodes;
	for (const auto& pair : frequencies) {
		nodes.push_back(Node(pair.first, pair.second));
	}
	return nodes;
}

map<char, string> codesMap(map<char, int> frequencies, Node root) {
	map<char, string> codes;
	for (auto c : frequencies) {
		codes.insert(make_pair(c.first, root.GetCodeFromCharacter(c.first, "")));
	}
	return codes;
}

string getCodedString(map<char, string> codes, string text) {
	string res;
	for (auto& c : text) {
		res += codes[c];
	}
	return res;
}

string decodeHuffman(string codedString, map<char, string> codes) {
	string res;
	string substr = "";
	for (int i = 0; i < codedString.size(); i++) {
		substr += codedString[i];
		for (const auto& pair : codes) {
			if (pair.second == substr) {
				res += pair.first;
				substr = "";
				break;
			}
		}
	}
	return res;
}

void work() {
	std::string text = "Haffman pidor";
	std::vector<Node> nodes;
	std::map<char, int> frequencies = create_character_tree(text);
	for (const auto& pair : frequencies) {
		nodes.push_back(Node(pair.first, pair.second));
	}

	Node root = huffman(nodes);

	map<char, string> codes = codesMap(frequencies, root);

	string res = getCodedString(codes, text);
	cout << res << endl;
}
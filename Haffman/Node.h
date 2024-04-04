#pragma once
#include <string>
using namespace std;

class Node {
public:
	char _c;
	int _weight;
	Node* _left;
	Node* _right;

	Node() : _c('\0'), _weight(0), _left(nullptr), _right(nullptr) {}
	Node(char c, int weight) : _c(c), _weight(weight), _left(nullptr), _right(nullptr) {}
	Node(char c, int weight, Node* left, Node* right) : _c(c), _weight(weight), _left(left), _right(right) {}

	Node(const Node& other) {
		_c = other._c;
		_weight = other._weight;
		_left = other._left;
		_right = other._right;
	}

	// Оператор присваивания
	Node& operator=(const Node& other) {
		if (this != &other) {
			_c = other._c;
			_weight = other._weight;
			_left = other._left;
			_right = other._right;
		}
		return *this;
	}
	bool operator>(const Node& other) const {
		return this->_weight > other._weight;
	}

	std::string GetCodeFromCharacter(char c, std::string parentPath) {
		if (this->_c == c) {
			return parentPath;
		}
		else {
			if (this->_left != nullptr) {
				std::string path = this->_left->GetCodeFromCharacter(c, parentPath + "0");
				if (!path.empty()) return path;
			}
			if (this->_right != nullptr) {
				std::string path = this->_right->GetCodeFromCharacter(c, parentPath + "1");
				if (!path.empty()) return path;
			}
		}
		return "";
	}

	//~Node() {
	//	if (_left != nullptr)
	//		delete _left;
	//	if (_right != nullptr)
	//		delete _right;
	//}

};

#include <iostream>
#include <stdexcept>

struct Node {
		Node* next;
		int data;
};


class List {

	
public:
	List();
	~List();
	void insert(int n, int index);
	void erase(int n);
	List marge(const List& list);
	void swap(List& list);
	void print();
	List& operator=(const List& rhs);
	bool operator==(const List& rhs);
	bool operator!=(const List& rhs);
	bool operator<(const List& rhs);
	bool operator>(const List& rhs);

private:
	Node* head;
	int size;

};

List::List(): head {nullptr}, size {0} {}

List::~List() {
	if (this->head) {
		Node* tmp = this->head;
		Node* next;
		while (tmp != nullptr) {
			next = tmp->next;
			delete tmp;
			tmp = next;
		}
	}
}

void List::insert(int n, int index) {
	if (index > this->size) {
		throw std::invalid_argument("Invalid index");
	} else {
		Node* tmp1 = this->head;
		Node* tmp2;
		if (index == 0) {
			tmp2 = new Node{tmp1, n};
			this->head = tmp2;
			
		} else {
		while (index > 1) {
			tmp1 = tmp1->next;
			--index;
		}
			tmp2 = tmp1->next;
			tmp1->next = new Node{tmp2, n};
		}
	}
	++size;
}

void List::erase(int n) {
	if (this->head) {
		Node* tmp = this->head;
		Node* tmp2;
		if (tmp->data == n) {
			tmp2 = tmp->next;
			delete tmp;
			this->head = tmp2;
			return;
		}
		while (tmp->next != nullptr) {
			if (tmp->next->data == n) {
				tmp2 = tmp->next->next;
				delete tmp->next;
				tmp = tmp2;
				--size;
				return;
			}
		}
		std::cout << "Given number doesn't exist in list";
	} else {
		std::cout << "List is empty";
	}
}

List List::marge(const List& list) {
	List res;

	Node* tmp1 = this->head;
	Node* tmp2 = list.head;
	int index = 0;
	while (tmp1 != nullptr && tmp2 != nullptr) {
		if (tmp1->data < tmp2->data) {
			res.insert(tmp1->data, index);
			tmp1 = tmp1->next;
		} else {
			res.insert(tmp2->data, index);
			tmp2 = tmp2->next;
		}
		++index;
	}
	Node* current;
	current = (tmp1)? tmp1 : tmp2;
	while (current != nullptr) {
		res.insert(current->data, index);
		current = current->next;
		++index;
	}
	return res;
}

List& List::operator=(const List& rhs) {
			if (this == &rhs) {
				return *this;
			}
			if (this->head) {
				Node* current = this->head;
				Node* next;
				while (current->next != nullptr) {
					next = current->next;
					delete current;
					current = next;
				}
			}
		this->head = nullptr;
		Node* current = rhs.head;
		Node** tmp = &head;
		while (current != nullptr) {
			*tmp = new Node{nullptr, current->data};
			tmp = &((*tmp)->next);
			current = current->next;
		}
		this->size = rhs.size;
		return *this;
	}
void List::swap(List& list) {
	Node* tmp = this->head;
	this->head = list.head;
	list.head = tmp;
	int s = this->size;
	this->size = list.size;
	list.size = s;
}
void List::print() {
	Node* tmp = this->head;
	while (tmp != nullptr) {
		std::cout << tmp->data << "\n";
		tmp = tmp->next;
	}
}

bool List::operator==(const List& list) {
	if (this->size == list.size) {
		Node* tmp1 = this->head;
		Node* tmp2 = list.head;
		while (tmp1 != nullptr) {
			if (tmp1->data != tmp2->data) {
				return false;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	} else {
		return false;
	}
	return true;
}

bool List::operator<(const List& list) {
	if (this->size < list.size) {
		Node* tmp1 = this->head;
		Node* tmp2 = list.head;
		while (tmp1 != nullptr) {
			if (tmp1->data >= tmp2->data) {
				return false;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	} else {
		return false;
	}
	return true;
}

bool List::operator>(const List& list) {
		if (this->size > list.size) {
		Node* tmp1 = this->head;
		Node* tmp2 = list.head;
		while (tmp2 != nullptr) {
			if (tmp1->data <= tmp2->data) {
				return false;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	} else {
		return false;
	}
	return true;
}

bool List::operator!=(const List& list) {
	return !(*this == list);
}
	

int main() {
	
	List list;
	List list2;
	List list3;
	List list4;
	list4.insert(1,0);
	list4.insert(2,1);

	list.insert(1,0);
	list.insert(2,1);
	list2.insert(4,0);
	list3 = list.marge(list2);
	list2.swap(list3);
	list2.print();
	std::cout <<"==" << (list4 == list);
	list.erase(5);
	list.print();
}

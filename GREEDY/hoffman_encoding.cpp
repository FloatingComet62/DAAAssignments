#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Node {
public:
  int data;
  Node* left;
  Node* right;
  Node(int data): data(data), left(nullptr), right(nullptr) {}
  Node(Node* l, Node* r): data(l->data + r->data), left(l), right(r) {}
};
class Compare {
public:
	bool operator() (Node* a, Node* b) {
		return a->data > b->data;
	}
};

std::vector<std::string> hoffmanEncoding(std::vector<int> frequencies) {
  std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
  for (auto item : frequencies) {
    pq.push(new Node(item));
  }

  while (pq.size() >= 2) {
    Node* l = pq.top(); pq.pop();
    Node* r = pq.top(); pq.pop();

    Node* newInternalNode = new Node(l, r);
    pq.push(newInternalNode);
  }

  std::vector<std::string> output;
  std::stack<std::pair<Node*, std::string>> stack;
  stack.push({pq.top(), ""});

  while (stack.size() > 0) {
    auto item = stack.top(); stack.pop();
    Node* node = item.first;
    if (node == nullptr) continue;

    std::string current = item.second;
    if (node->left == nullptr && node->right == nullptr) {
      output.push_back(current);
      continue;
    }

    stack.push({node->right, current + "1"});
    stack.push({node->left, current + "0"});
  }

  return output;
}

int main() {
  char chars[] = {'a', 'e', 'i', 'o', 'u', 's', 't'};
  auto output = hoffmanEncoding({ 10, 15, 12, 3, 4, 13, 1 });
  for (int i = 0; i < output.size(); i++) {
    std::cout << chars[i] << " => " << output[i] << "\n";
  }
}

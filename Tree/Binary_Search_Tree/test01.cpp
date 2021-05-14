#include <iostream>
#include <memory>

template <typename T> class Node;
template <typename T> class BTree;


template <typename T>
class Node{
public:
	Node():val(), left(), right() {};
	Node(T x): val(x), left(), right() {}; 

	friend class BTree<T>;
private:
	T val;
	std::unique_ptr<Node<T>> left, right;
};


template <typename T>
class BTree{
public:	
	BTree() : root() {}
	~BTree(){}

	/*
	BTree(const BTree&);
	BTree& operator=(const BTree&);
	BTree(BTree&&) = default;
	BTree& operator=(BTree&&) = default;
	*/
	
	void insert(const T &val){
		std::unique_ptr<Node<T>> node(new Node<T>(val));
		if(root ==nullptr){
			root = std::move(node);
		}else{
			Node<T>* temp = root.get();
			Node<T>* prev = root.get();
			while(temp != nullptr){
				prev = temp;
				if(temp->val < val){
					temp = temp->right.get();
				}else{
					temp = temp->left.get();
				}
			}
			if(prev->val < val){
				prev->right = std::move(node);
			}else{
				prev->left = std::move(node);
			}
		}
	}
	/*
	std::unique_ptr<Node<T>> find(const T val);
	remove(T)
	size_t height()
	void breadth_first()
	*/
	void traversal(const std::string mode){
		if(mode == "preorder"){
			preorder(root.get());
		}else if(mode == "inorder"){
			inorder(root.get());

		}else if(mode == "postorder"){
			postorder(root.get());

		}else{
			std::cerr << "Wrong mode\n";
			exit(0);
		}
		std::cout << "\n";
	}
	

private:
	void preorder(const Node<T> *n) const{
		if(n==nullptr)
			return;
		std::cout << n->val << " ";
		preorder(n->right.get());
		preorder(n->left.get());
	}

	void inorder(const Node<T> *n) const{
		if(n==nullptr)
			return;
		preorder(n->right.get());
		std::cout << n->val << " ";
		preorder(n->left.get());

	}
	void postorder(const Node<T> *n) const{
		if(n==nullptr)
			return;
		preorder(n->right.get());
		preorder(n->left.get());
		std::cout << n->val << " ";
	}


private:
	std::unique_ptr<Node<T>> root;	
};

int main(int argc, char *argv[]){
	int n, val;
	BTree<int> t;

	std::cin >> n;
	for(int i=0; i < n; ++i){
		std::cin >> val;
		t.insert(val);
	}

	t.traversal("preorder");

	
	return 0;
}

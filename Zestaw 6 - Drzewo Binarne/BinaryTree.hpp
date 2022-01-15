using namespace std;

class BinaryTree {
	
	private:
	
	struct BinaryTreeNode {
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		int value;
	};
	
	BinaryTreeNode* root = nullptr;
	int _size = 0;
	int _depth = 0;
	
	public:
	
	void insert (int x) {
		
		BinaryTreeNode* temp = root;
		
		if (root == nullptr) {
			root = new BinaryTreeNode ();
			root->value = x;
			_size++;
			
			_depth = 1;
			
			return;
		}
		
		int _curDepth = 1;
		
		while (true) {
			
			_curDepth++;
			
			if (x >= temp->value) {
				if (temp->right == nullptr) {
					temp->right = new BinaryTreeNode ();
					temp->right->value = x;
					_size++;
					
					if (_curDepth > _depth)
						_depth = _curDepth;
					
					break;
				}
				temp = temp->right;
			} else {
				if (temp->left == nullptr) {
					temp->left = new BinaryTreeNode ();
					temp->left->value = x;
					_size++;
					
					if (_curDepth > _depth)
						_depth = _curDepth;
					
					break;
				}
				temp = temp->left;
			}
		}
	}
	
	BinaryTreeNode* search (int x) {
		
		BinaryTreeNode* temp = root;
		
		while (temp != nullptr) {
			if (temp->value == x) {
				return temp;
			} else {
				if (x > temp->value) {
					temp = temp->right;
				} else {
					temp = temp->left;
				}
			}
		}
		
		return nullptr;
	}
	
	private:
	BinaryTreeNode* sR (BinaryTreeNode* node, int x) {
		
		if (node == nullptr)
			return nullptr;
		
		if (node->value == x) {
			return node;
		} else if (x > node->value) {
			return sR (node->right, x);
		} else {
			return sR (node->left, x);
		}
	}
	
	public:
	BinaryTreeNode* searchRecursive (int x) {
		return sR (root, x);
	}
	
	int size () {
		return _size;
	}
	
	int minimum () {
		
		BinaryTreeNode* temp = root;
		
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		
		return temp->value;
	}
	
	int maximum () {
		
		BinaryTreeNode* temp = root;
		
		while (temp->right != nullptr) {
			temp = temp->right;
		}
		
		return temp->value;
	}
	
	int depth () {
		return _depth;
	}
	
	private:
	void _inorder (BinaryTreeNode* node) {
		if (node != nullptr) {
			_inorder (node->left);
			cout << node->value << endl;
			_inorder (node->right);
		}
	}
	
	public:
	void inorder () {
		_inorder (root);
	}
	
	private:
	void _preorder (BinaryTreeNode* node) {
		if (node != nullptr) {
			cout << node->value << endl;
			_preorder (node->left);
			_preorder (node->right);
		}
	}
	
	public:
	void preorder () {
		_preorder (root);
	}
	
	private:
	void _postorder (BinaryTreeNode* node) {
		if (node != nullptr) {
			_postorder (node->left);
			_postorder (node->right);
			cout << node->value << endl;
		}
	}
	
	public:
	void postorder () {
		_postorder (root);
	}
	
	private:
	void BinaryTreeDestructor (BinaryTreeNode* node) {
		if (node != nullptr) {
			BinaryTreeDestructor (node->left);
			BinaryTreeDestructor (node->right);
			delete node;
		}
	}
	
	public:
	~BinaryTree () {
		BinaryTreeDestructor (root);
	}
	
};
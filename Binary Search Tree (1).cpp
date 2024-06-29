#include <iostream>
using namespace std;

// Struktur Node BST
struct Node {
	int data;
	Node *left;
	Node *right;
};

// Fungsi untuk membuat node baru
Node *createNode(int value) {
	Node *newNode = new Node();
	
	newNode->data = value;
	newNode->left = nullptr;
	newNode->right = nullptr;
	
	return newNode;
}

// Fungsi untuk memasukkan elemen / node ke dalam BST
Node *insert(Node *root, int value) {
	if (root == nullptr)
		return createNode(value);
	
	if (value < root->data) 
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	
	return root;
	
}

// Fungsi untuk melakukan pencarian pada BST
Node *search(Node *root, int value) {
	if (root == nullptr || root->data == value) 
		return root;
	
	if (value < root->data) 
		return search(root->left, value);
	else 
		return search(root->right, value);
	
}

// Fungsi untuk melakukan inorder traversal pada BST
/* Inorder traversal adalah teknik penjelajahan pohon yang 
mengikuti pola Kiri-Akar-Kanan / subtree kiri - rootnya - subtree kanan */
void inorderTraversal(Node *root) {
	if (root == nullptr) 
		return;
	
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

int main() {
	Node *root = nullptr; // root awal kosong untuk membentuk parent pertama
	root = insert(root, 50); // root 50
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	
	cout << "============== Program Binary Search Tree ============== \n\n";
	
	cout << "-> Hasil pengurutan dengan teknik Inorder Traversal <- \n\n";
	cout << "\t\t" ; 
	inorderTraversal(root);
	cout << endl<<endl;
	
	Cari_Lagi:
	int searchValue;
	cout << "Masukkan data yang ingin di cari : ";
	cin >> searchValue;
	
	cout << endl;
	Node *searchResult = search(root, searchValue);
	
	if (searchResult){
		cout << "Data " << searchValue << " ditemukan dalam Binary Search Tree " << endl;
	}
	else{
		cout << "Data " << searchValue << " tidak ditemukan dalam Binary Search Tree \n" << endl;
		goto Cari_Lagi;
	}

	return 0;
}

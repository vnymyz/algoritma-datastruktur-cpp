#include <iostream>
using namespace std;

// membuat struktur node
struct Node {
    int data; // ini root
    Node* left; // temen sebelah kiri root
    Node* right; // temen sebelah kanan root

    Node(int val) {
        data = val;
        left = right = nullptr; // pohon ini masih kosong
    }
};

// Insert node dan termasuk fungsi rekursif
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val); // Basis: pohon kosong, buat node baru

    if (val < root->data) // Jika lebih kecil, ke subtree kiri
        root->left = insert(root->left, val);
    else if (val > root->data) // Jika lebih besar, ke subtree kanan
        root->right = insert(root->right, val);

    return root; // Kembalikan node agar bisa tersambung
}

// Search Node
bool search(Node* root, int key) {

     // root == nullptr: artinya sudah sampai leaf dan nilai tidak ditemukan.
     // Jika node kosong (tidak ditemukan), kembalikan false
    if (root == nullptr) return false; 

     // Jika nilai node saat ini sama dengan nilai yang dicari, return true
     //  root->data == key: ketemu nilai yang dicari.
    if (root->data == key) return true;

     // Jika nilai yang dicari lebih kecil dari data saat ini, cari ke subtree kiri
    if (key < root->data)
        return search(root->left, key);
    else
       // Jika nilai yang dicari lebih besar dari data saat ini, cari ke subtree kanan
        return search(root->right, key);
}

// Delete Node
// findmind ini untuk mencari nilai minimum di bst
Node* findMin(Node* root) {

    // Selama masih ada anak kiri, terus bergerak ke kiri
    while (root->left != nullptr)
        root = root->left;

    // Node paling kiri adalah nilai minimum
    return root;
}

Node* deleteNode(Node* root, int key) {
     // Basis: jika pohon kosong
    if (root == nullptr) return root;

    // Jika key lebih kecil dari data saat ini → telusuri subtree kiri
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    
    // Jika key lebih besar dari data saat ini → telusuri subtree kanan
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Kalau key == root->data → node ditemukan, lanjut proses hapus
    else {

        // Kasus 1 & 2: Node hanya punya 1 anak atau tidak punya anak (leaf)
        // 1 atau 0 child
        // Jika tidak punya anak kiri → ganti dengan anak kanan (bisa null)
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root; // Hapus node sekarang
            return temp; // Kembalikan pengganti ke parent
        }

        // Jika tidak punya anak kanan → ganti dengan anak kiri
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Kasus 3: Node punya 2 anak
        // 2 child
        // Ambil nilai terkecil dari subtree kanan (in-order successor)
        Node* temp = findMin(root->right);

        // Ganti nilai root dengan nilai minimum tadi
        root->data = temp->data;

        // Hapus node duplikat dari subtree kanan
        root->right = deleteNode(root->right, temp->data);
    }

    // Kembalikan pointer root setelah perubahan
    return root;
}

// inorder traversal
// left -> root -> right
void inorder(Node* root) {
    if (root == nullptr) return;  // Basis rekursi: jika kosong, berhenti
    inorder(root->left);  // Kunjungi subtree kiri terlebih dahulu
    cout << root->data << " ";   // Cetak data node saat ini
    inorder(root->right);   // Kunjungi subtree kanan setelahnya
}

// Root → Left → Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";       // Cetak root terlebih dahulu
    preorder(root->left);            // Lanjut ke subtree kiri
    preorder(root->right);           // Lanjut ke subtree kanan
}

// Left → Right → Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);           // Kunjungi subtree kiri
    postorder(root->right);          // Kunjungi subtree kanan
    cout << root->data << " ";       // Cetak root setelah anak-anaknya
}


// Aplikasinya
int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Tampilkan Inorder\n5. Tampilkan Preorder\n6. Tampilkan Postorder\n0. Keluar\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Masukkan nilai yang dicari: ";
                cin >> value;
                if (search(root, value))
                    cout << "Data ditemukan\n";
                else
                    cout << "Data tidak ditemukan\n";
                break;
            case 3:
                cout << "Masukkan nilai yang dihapus: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 4:
                cout << "Inorder Traversal (dari kecil ke besar): ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder Traversal (urutan simpul dikunjungi sebelum anak-anaknya): ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Traversal (urutan simpul dikunjungi setelah anak-anaknya): ";
                postorder(root);
                cout << endl;
                break;
            case 0:
                cout << "Terima kasih\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);

    return 0;
}


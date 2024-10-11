// C++ to implement linked matrix 
// from a 2D matrix recursively 
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = down = nullptr;
    }
};

// Function to recursively construct the linked matrix 
// from a given 2D vector
Node* constructUtil(vector<vector<int>>& mat, 
                                      int i, int j) {
  
    // Base case: if we are out of bounds, return NULL
    if (i >= mat.size() || j >= mat[0].size()) {
        return nullptr;
    }

    // Create a new Node with the current matrix value
    Node* curr = new Node(mat[i][j]);

    // Recursively construct the right and down pointers
    curr->right = constructUtil(mat, i, j + 1);
    curr->down = constructUtil(mat, i + 1, j);

    // Return the constructed Node
    return curr;
}

// Function to construct the linked matrix given a 2D vector
Node* constructLinkedMatrix(vector<vector<int>>& mat) {
  
    // Call the utility function starting 
    // from the top-left corner of the matrix
    return constructUtil(mat, 0, 0);
}

void printList(Node *head) {
    Node *currRow = head;
    while (currRow != nullptr) {
        Node *currCol = currRow;
        while (currCol != nullptr) {
            cout << currCol->data << " ";
            currCol = currCol->right;
        }
        cout << endl;
        currRow = currRow->down;
    }
}

int main() {
  

    vector<vector<int>> mat = { { 1, 2, 3 },
                                { 4, 5, 6 },
                                { 7, 8, 9 } };

    Node* head = constructLinkedMatrix(mat);
    printList(head);

    return 0;
}

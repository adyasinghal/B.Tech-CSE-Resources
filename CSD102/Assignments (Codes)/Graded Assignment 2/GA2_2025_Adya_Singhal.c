// Name: ADYA SINGHAL
// Roll No.: 2410110027

// The program is completely my own and no part of it has been copied from anybody or downloaded from the net

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 26  // For A-Z uppercase letters

// Defining the node structure
typedef struct Tnode {
    char data;
    struct Tnode *left;
    struct Tnode *right;
} Tnode;

Tnode* nodes[MAX_EMPLOYEES] = {NULL}; // to store pointers to nodes by alphabet
int isChild[MAX_EMPLOYEES] = {0};     // marks if a node is a child (not the root)


// Function to create a new node or return an existing one
Tnode* createNode(char data) {
    if (data == 'X') return NULL;
    if (!nodes[data - 'A']) {
        nodes[data - 'A'] = (Tnode*)malloc(sizeof(Tnode));
        nodes[data - 'A']->data = data;
        nodes[data - 'A']->left = NULL;
        nodes[data - 'A']->right = NULL;
    }
    return nodes[data - 'A'];
}

// Inorder traversal function
void inorder(Tnode *root) {
    if (!root) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

// Calculate height of the tree
int height(Tnode *root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

// Count number of bosses 
int countBosses(Tnode *root) {
    if (!root) return 0;
    if (root->left || root->right)
        return 1 + countBosses(root->left) + countBosses(root->right);
    return 0;
}

// Helper function to check BST property
int isBSTUtil(Tnode *root, char min, char max, char *failNode) { // Binary Search Tree Utility
    if (!root) return 1;
    if ((root->data <= min || root->data >= max)) {
        *failNode = root->data;
        return 0;
    }
    return isBSTUtil(root->left, min, root->data, failNode) &&
           isBSTUtil(root->right, root->data, max, failNode);
}

// Wrapper to call the utility function
int isBST(Tnode *root, char *failNode) {
    return isBSTUtil(root, 'A' - 1, 'Z' + 1, failNode);
}

// Preorder traversal to print the new tree structure 
void preorder(Tnode *root) {
    if (!root) return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Tree modification function
Tnode* specialFunction(Tnode *root) {
    Tnode *alpha = root;
    Tnode *omicron = alpha->right;
    if (!omicron) return alpha;
    alpha->right = omicron->left;
    omicron->left = alpha;
    return omicron;
}

// To find team mate of a given employee
void findTeammate(Tnode *root, char emp, int *found, char *teammate) {
    if (!root) return;
    if (root->left && root->left->data == emp) {
        *found = 1;
        *teammate = (root->right ? root->right->data : 'X');
        return;
    } else if (root->right && root->right->data == emp) {
        *found = 1;
        *teammate = (root->left ? root->left->data : 'X');
        return;
    }
    findTeammate(root->left, emp, found, teammate);
    findTeammate(root->right, emp, found, teammate);
}

int main() {
    FILE *fp = fopen("employee.txt", "r");
    if (!fp) {
        printf("Could not open file\n");
        return 1;
    }

    // Task 7: Read nnn and ppp values from file
    char data[100];
    fscanf(fp, "%s", data);
    char nnn = data[0], ppp = data[1];

    // Task 1: Read the remaining tuples and build the tree
    while (fscanf(fp, "%s", data) != EOF) {
        char parent = data[0], left = data[1], right = data[2];
        Tnode *p = createNode(parent);
        p->left = createNode(left);
        p->right = createNode(right);
        if (left != 'X') isChild[left - 'A'] = 1;
        if (right != 'X') isChild[right - 'A'] = 1;
    }
    fclose(fp);

    // Task 1: Identify the root (CEO)
    Tnode *root = NULL;
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (nodes[i] && !isChild[i]) {
            root = nodes[i];
            break;
        }
    }

    // Task 2: Print inorder traversal
    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    // Task 3: Print tree height
    printf("Tree Height: %d\n", height(root));

    // Task 4: Print number of bosses
    printf("Number of Bosses: %d\n", countBosses(root));

    // Task 5: Check BST property
    char failNode;
    if (isBST(root, &failNode)) {
        printf("It is a BST tree with CEO: %c\n", root->data);
    } else {
        printf("It failed the BST property at node: %c\n", failNode);
    }

    // Task 6: Perform special tree transformation and print preorder traversal
    Tnode *newRoot = specialFunction(root);
    printf("Preorder after shuffling:\n");
    preorder(newRoot);
    printf("\n");

    // Task 7: Check for employee nnn and find their teammate
    int found = 0;
    char teammate = 'X';
    findTeammate(newRoot, nnn, &found, &teammate);
    if (found) {
        printf("Confirmed that %c is an employee.\n", nnn);
        if (teammate != 'X')
            printf("Team mate of %c: %c\n", nnn, teammate);
        else
            printf("%c is sole team member.\n", nnn);
    } else {
        printf("%c is not an employee.\n", nnn);
    }

    // Repeat for ppp
    found = 0;
    teammate = 'X';
    findTeammate(newRoot, ppp, &found, &teammate);
    if (found) {
        printf("Confirmed that %c is an employee.\n", ppp);
        if (teammate != 'X')
            printf("Team mate of %c: %c\n", ppp, teammate);
        else
            printf("%c is sole team member.\n", ppp);
    } else {
        printf("%c is not an employee.\n", ppp);
    }

    return 0;
}
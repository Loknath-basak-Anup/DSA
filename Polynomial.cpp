#include <bits/stdc++.h>
using namespace std;


struct Node {
    int coeff;
    int exp;
    Node* next;
    Node(int u, int t) {
        coeff = u;
        exp = t;
        next = nullptr;
    }
};


void add(Node*& head, int coeff, int exp) {
    if (coeff == 0)
        return;
    Node* newNode = new Node(coeff, exp);
    if (!head || exp > head->exp) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->exp == exp) {
            temp->coeff += coeff;
        } else if (temp->next && temp->next->exp == exp) {
            temp->next->coeff += coeff;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}


Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            add(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            add(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            add(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        add(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        add(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}


void printPolynomial(Node* head) {
    if (!head) {
        cout << "0" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->coeff;
        if (temp->exp != 0)
            cout << "x^" << temp->exp;
        if (temp->next && temp->next->coeff > 0)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

void readPolynomial(Node*& poly, int numTerms) {
    for (int i = 0; i < numTerms; ++i) {
        int coeff, exp;
        cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
        cin >> coeff >> exp;
        add(poly, coeff, exp);
    }
}


int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    int n1, n2;
    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n1;
    readPolynomial(poly1, n1);

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n2;
    readPolynomial(poly2, n2);

    cout << "\nPolynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);
    cout << " Resultant polynomial : ";
    printPolynomial(result);

    return 0;
}


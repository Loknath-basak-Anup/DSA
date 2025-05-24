#include <bits/stdc++.h>
using namespace std;

struct Node {
    char letter;
    int count;
    Node* next;

    Node(char g) {
        letter = g;
        count = 0;
        next = nullptr;
    }
};


Node* createFrequencyList() {
    Node* head = new Node('a');
    Node* current = head;

    for (char ch = 'b'; ch <= 'z'; ch++) {
        current->next = new Node(ch);
        current = current->next;
    }

    return head;
}


void updateFrequencies(Node* head, string input) {
    for (char ch : input) {
        Node* current = head;
        while (current != nullptr) {
            if (current->letter == ch) {
                current->count++;
                break;
            }
            current = current->next;
        }
    }
}


void printFrequencies(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->letter << " : " << current->count << endl;
        current = current->next;
    }
}

int main() {
    string input;

    cout << "Enter a string : ";
    cin >> input;


    Node* freqList = createFrequencyList();


    updateFrequencies(freqList, input);


    printFrequencies(freqList);
    Node* current = freqList;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}


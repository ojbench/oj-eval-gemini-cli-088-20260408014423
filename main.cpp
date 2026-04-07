#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Simulates the magic trick using a circular linked list
void solve_subtask1(int n) {
    if (n == 1) {
        return;
    }
    
    // Initialize the circular linked list with values 1 to n
    Node* head = new Node(1);
    Node* tail = head;
    for (int i = 2; i <= n; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    tail->next = head;

    // Perform n - 1 rounds of the trick
    for (int i = 0; i < n - 1; ++i) {
        // Step 1: "Good luck stays" - move the first card to the end
        head = head->next;
        tail = tail->next;

        // Step 2: "Troubles thrown away" - discard the new first card
        Node* to_delete = head;
        head = head->next;
        tail->next = head;
        delete to_delete;

        // Output the top card after the round
        cout << head->val << "\n";
    }
    
    // Free the last remaining node to prevent memory leaks
    delete head;
}

// Predicts the result of the magic trick directly
void solve_subtask2(long long n) {
    // The problem is equivalent to the Josephus problem with k = 2.
    // The survivor for n cards is given by the formula: 2 * (n - 2^{\lfloor \log_2 n \rfloor}) + 1
    long long p = 1;
    while (p * 2 <= n) {
        p *= 2;
    }
    cout << 2 * (n - p) + 1 << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int id;
    long long n;
    if (cin >> id >> n) {
        if (id == 1) {
            solve_subtask1(n);
        } else if (id == 2) {
            solve_subtask2(n);
        }
    }
    
    return 0;
}
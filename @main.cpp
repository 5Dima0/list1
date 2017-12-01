#include <iostream>
#include <string>

using namespace std;

int counter = 0;
struct node_t {
    int value;
    node_t * next;};
    
    void back(node_t * list) {
    node_t * begin = list;
    node_t * last = begin;
    for (int j = 0; j < counter / 2 ; j++) {
        for (int i = j; i < counter - 1 - j; i++) {
            last = last->next;
        }
        int saved = begin->value;
        begin->value = last->value;
        last->value = saved;
        begin = begin->next;
        last = begin;
    }
}

void add(node_t * & head, int value) {
    node_t * node = new node_t;
    node->value = value;
    node->next = 0;
    if( head == 0) {
        head = node;
    }
    else {
        node_t * last = head;
        while(last->next) {
            last = last->next;
        }
        last->next = node;
    }
    counter++;
}

void write(node_t * one, int counter) {
    node_t *write = one;
    for (int i = 0; i < counter; i++) {
        cout << "+---+    ";
    }
    cout << endl;
    for (int i = 0; i < counter; i++) {
        if (i != 0) {
            cout << "--->";
        }
        cout << "| " << write->value << " |";
        write = write->next;
    }
    cout << endl;
    for (int i = 0; i < counter; i++) {
        cout << "+---+    ";
    }
    cout << endl;
}

void away(node_t * & list) {
    node_t * one = list;
    list = list->next;
    delete one;
    counter--;
}

int main()
{
    int value;char op;
    node_t * head = nullptr;
    while(cin >> op) {
        switch (op) {
            case '+' : {
                cin >> value;
                add(head, value);
                write(head, counter);
                break;
            };
            case '-' : {
                away(head);
                write(head, counter);
                break;
            };
            case 'q' : {
                exit(0);
            };
            case '=' : {
                write(head, counter);
                break;
            };
            case '/' : {
                back(head);
                write(head, counter);
                break;
            };
        }
    }
 }

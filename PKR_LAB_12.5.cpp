#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include "Windows.h"

using namespace std;


stack<int> generateStack(int n) {
    stack<int> stack;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        stack.push(rand() % 100);
    }
    return stack;
}


void printStack(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}


stack<int> sortStack(stack<int> stack) {
    std::stack<int> tempStack;
    while (!stack.empty()) {
        int temp = stack.top();
        stack.pop();
        while (!tempStack.empty() && tempStack.top() < temp) {
            stack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    return tempStack;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    stack<int> stack = generateStack(10);
    cout << "Оригінальний стек: ";
    printStack(stack);
    std::stack<int> sortedStack = sortStack(stack);
    cout << "Відсортований стек: ";
    printStack(sortedStack);
    return 0;
}

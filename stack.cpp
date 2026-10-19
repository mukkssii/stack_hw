#include <iostream>
#include <stdexcept> 
using namespace std;

class Stack {
private:
    char* _arr;
    int _size;
    int _count;

public:
    Stack(int size) {
        if (size <= 0) {
            throw invalid_argument("Incorrect stack size");
        }

        _size = size;
        _count = 0;
        _arr = new char[size];
    }

    ~Stack() {
        delete[] _arr;
    }

    void Push(char symbol) {
        if (_count == _size) {
            throw overflow_error("Stack is full");
        }

        _arr[_count] = symbol;
        _count++;
    }

    void Pop() {
        if (_count == 0) {
            throw underflow_error("Stack is empty");
        }

        _count--;
    }

    int GetCount() {
        return _count;
    }

    bool IsEmpty() {
        return _count == 0;
    }

    bool IsFull() {
        return _count == _size;
    }

    void Clear() {
        _count = 0;
    }

    char Peek() {
        if (_count == 0) {
            throw underflow_error("Stack is empty");
        }

        return _arr[_count - 1];
    }

    void Resize() {
        int newSize = _size * 2;

        if (newSize == 0) {
            newSize = 1;
        }

        char* newArr = new char[newSize];

        for (int i = 0; i < _count; i++) {
            newArr[i] = _arr[i];
        }

        delete[] _arr;
        _arr = newArr;
        _size = newSize;
    }

    void PushDynamic(char symbol) {
        if (_count == _size) {
            Resize();
        }

        _arr[_count] = symbol;
        _count++;
    }
};

int main() {
    try {
        Stack s(3);

        s.Push('a');
        s.Push('b');
        s.Push('C');
        cout << "last element: " << s.Peek() << endl;
        s.PushDynamic('D');
        cout << "Count: " << s.GetCount() << endl;
        s.Pop();
        cout << "Top element: " << s.Peek() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }



    return 0;
}
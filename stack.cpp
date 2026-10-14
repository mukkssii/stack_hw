#include <iostream>
using namespace std;

class Stack {
private:
    char* _arr;
    int _size;
    int _count;

public:
    Stack(int size) {
        _size = size;
        _count = 0;
        _arr = new char[size];
    }

    ~Stack() {
        delete[] _arr;
    }

    void Push(char symbol) {
        if (_count == _size) {
            cout << "full" << endl;
            return;
        }

        _arr[_count] = symbol;
        _count++;
    }

    void Pop() {
        if (_count == 0) {
            cout << "empty" << endl;
            return;
        }

        _count--;
    }

    int GetCount() {
        return _count;
    }

    bool IsEmpty() {
        if (_count == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool IsFull() {
        if (_count == _size) {
            return true;
        }
        else {
            return false;
        }
    }

    void Clear() {
        _count = 0;
    }

    char Peek() {
        if (_count == 0) {
            cout << "empty" << endl;
            return '\0';
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
    Stack s(3);



    return 0;
}
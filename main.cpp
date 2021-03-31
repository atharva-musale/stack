#include <iostream>
#include <exception>
using namespace std;

#define CAPACITY 10

// Custom exceptions for empty stack and full stack
class EmptyStack : public exception
{
public:
    const char* what(){
        return "Stack is empty. \n";
    }
};

class FullStack : public exception
{
public:
    const char* what(){
        return "Stack is full. \n";
    }
};

//
class Stack{
private:
    int stack[CAPACITY];
    int top;
    int size;
public:
    Stack(){
        top = -1;
        size = 0;
    }

    void push(int val){
        if(size == CAPACITY){
            FullStack f;
            throw f;
        }
        top++;
        size++;
        stack[top] = val;
    }
    int pop(){
        int temp;
        if(size == 0){
            EmptyStack e;
            throw e;
        }
        temp = stack[top];
        top--;
        size--;
        return temp;
    }

    void display() {
        for(int i=0; i<size; i++){
            cout<<stack[i] <<" ";
        }
        cout<<endl;
    }
};


int main()
{
    cout << "------------- STACK --------------" << endl;
    int choice, value;
    Stack stack1;
    while(1){
        cout<< "Enter: "<< endl;
        cout<< "1. to push. "<< endl;
        cout<< "2. to pop. "<< endl;
        cout<< "3. to view. "<< endl;
        cout<< "4. to exit. "<< endl;
        cout<< "Choice: "<< endl;
        cin >> choice;
        switch(choice){
        case 1: cout<< "Enter value: ";
                cin >> value;
                try{
                    stack1.push(value);
                }
                catch(FullStack f){
                    cout << f.what();
                }
                break;
        case 2: try{
                    value = stack1.pop();
                    cout<< "Value: "<< value;
                }
                catch(EmptyStack e){
                    cout << e.what();
                }
                break;
        case 3: stack1.display();
                break;
        case 4: exit(1);
                break;

        }
        cout<< "--------------------\n";
    }
    return 0;
}

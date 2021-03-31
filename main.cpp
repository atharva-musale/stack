#include <iostream>
#include <exception>
using namespace std;

class EmptyStack : public exception
{
public:
    const char* what()
    {
        return "Stack is empty.";
    }
};

class FullStack : public exception
{
public:
    const char* what()
    {
        return "Stack is full.";
    }
};

class Stack
{
private:
    int s[5];
    int top;
    int size;
public:
    Stack(){
        top = -1;
        size = 0;
    }

    void push(int val)
    {
        if(size == 5)
        {
            FullStack f;
            throw f;
        }
        top++;
        size++;
        s[top] = val;
    }
    int pop()
    {
        int temp;
        if(size == 0)
        {
            EmptyStack e;
            throw e;
        }
        temp = s[top];
        top--;
        size--;
        return temp;
    }

    void display()
    {
        for(int i=0; i<size; i++)
            cout<<s[i] <<" ";

        cout<<endl;
    }
};


int main()
{
    cout << "------------- STACK --------------" << endl;
    int ch, i =1;
    Stack st;
    while(i == 1){
    cout<< "Enter: "<< endl;
    cout<< "1. to push. "<< endl;
    cout<< "2. to pop. "<< endl;
    cout<< "3. to view. "<< endl;
    cout<< "4. to exit. "<< endl;
    cout<< "Choice: "<< endl;
    cin >> ch;
    switch(ch){
    case 1: {int n;
            cout<< "Enter value: ";
            cin >> n;
            try{
                st.push(n);
            }
            catch(FullStack f){
                cout << f.what()<< endl;
            }
            cout<< "\n--------------------\n";
            break;}
    case 2: {int n;
            try{
                n = st.pop();
                cout<< "Value: "<< n;
            }
            catch(EmptyStack e){
                cout << e.what()<< endl;
            }
            cout<< "\n--------------------\n";
            break;}
    case 3:{st.display();
            cout<< "\n--------------------\n";
            break;}
    case 4: i = 2;
            cout<< "\n--------------------\n";
            break;

    }
    }
    return 0;
}

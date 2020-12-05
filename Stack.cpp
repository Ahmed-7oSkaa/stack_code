#include <iostream>
#include <vector>
#define Max_Size 100000

using namespace std;
template <typename T>

class Stack{
    T* stack;
    int top;
public:
    Stack(){
        stack = new T[Max_Size];
        top = -1;
    }
    ~Stack(){
        delete_list();
    }
    bool is_empty(){
        return top == -1;
    }
    bool is_Full(){
        return top == Max_Size;
    }
    void push_back(T item){
        if(!is_Full())top++, stack[top] = item;
        else cout << "Not Valid Stack is Full\n";
    }
    void push_back(vector <T> vec){
        if(!is_Full()){
            top++;
            for(int i = 0; i < vec.size(); i++, top++){
                stack[top] = vec[i];
            }
        }
        else cout << "Not Valid Stack is Full\n";
    }
    void print(){
        if(!is_empty()){
            cout << "The Stack is: ";
            for(int i = top - 1; i >= 0; i--){
                cout << stack[i] << " ";
            }
            cout << "\n";
        }else cout << "The Stack is Empty\n";
    }
    T Max_element(){
        if(!is_Full()){
            T Max = stack[0];
            for(int i = 0 ; i < top; i++) Max = max(Max, stack[i]);
            return Max;
        }else cout << "The Stack is Empty\n";
    }
    T Min_element(){
        if(!is_Full()){
            T Min = stack[0];
            for(int i = 0 ; i < top; i++) Min = min(Min, stack[i]);
            return Min;
        }else cout << "The Stack is Empty\n";
    }
    void delete_list(){
        if(!is_empty()) delete[] stack;
        else cout << "The Stack is Empty\n";
    }
    void pop_back(){
        if(!is_empty()) stack[top] = 0, top--;
        else cout << "The Stack is Empty\n";
    }
    int size(){
        if(is_empty())cout << "The Stack is Empty\n";
        else return top;
    }
    bool find(T item){
        for(int i = 0 ; i < top; i++) if(stack[i] == item) return true;
        return false;
    }
    void interface(){
        cout << "*****************************************************\n";
        cout << "1 -> check if the Stack is Empty\n";
        cout << "2 -> check if the Stack is Full\n";
        cout << "3 -> Add Element to the Stack\n";
        cout << "4 -> Add N Elements to the Stack\n";
        cout << "5 -> Print The Stack\n";
        cout << "6 -> Max Element in the Stack\n";
        cout << "7 -> Min Element is the Stack\n";
        cout << "8 -> Search an Element in the Stack\n";
        cout << "9 -> Delete Element from the Stack\n";
        cout << "10 -> Size of the Stack\n";
        cout << "11 -> Exit\n";
        cout << "*****************************************************\n";
        cout << "Your Choice: "; int button;        cin >> button;
        cout << "*****************************************************\n";
        if(button == 1) cout << (is_empty()? "The Stack is Empty" : "The Stack Contains Elements") << "\n";
        else if(button == 2) cout << (is_Full()? "The Stack is Full" : "The Stack still can contains Elements") << "\n";
        else if(button == 3){
            cout << "Enter the Element: ";
            T item;     cin >> item;    push_back(item);
        }else if(button == 4){
            cout << "Enter  Number of Elements: ";
            int n;      cin >> n;
            cout << "Enter The N Elements:\n";
            vector <T> items(n);
            for(int i = 0; i < n && cin >> items[i]; i++);
            push_back(items);
        }else if(button == 5) print();
        else if(button == 6) cout << "The Maximum Element is: " << Max_element() << "\n";
        else if(button == 7)    cout << "The Minimum Element is: " << Min_element() << "\n";
        else if(button == 8){
            cout << "Enter The Element that you want to search: ";
            T item;             cin >> item;
            cout << "*****************************************************\n" << (find(item)? "Found it\n" : "Not Found\n");
        }else if(button == 9) pop_back();
        else if(button == 10){
            if(!is_empty()) cout << "The Stack's Size is " << size() << "\n";
            else cout << "The Stack is Empty\n";
        }
        else if(button == 11) return;
        else cout << "Not Valid Choice\n";
        //system("cls");
        interface();
    }
};
int main(){
    cout << "********************************************************************************\n";
    cout << "Choose The Datatype of The Stack (char, int, long long, float, double): ";
    string choice;      cin >> choice;  
    cout << "********************************************************************************\n";
    if(choice == "int") {Stack <int> s; s.interface();}
    else if(choice == "double") {Stack <double> s; s.interface();}
    else if(choice == "float") {Stack <float> s; s.interface();}
    else if(choice == "long long") {Stack <long long> s; s.interface();}
    else if(choice == "char") {Stack <char> s; s.interface();}
    else cout << "Error\n";
}
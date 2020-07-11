#include <iostream>
#include <string>
#include <stack>

using namespace std; 
  
void showstack(stack <string> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

void popStack() {
    stack <string> s;
    cout << "\ns.pop() : "; 
    s.pop(); 
    s.pop();

    cout << "The stack is : "; 
    showstack(s); 
}
  
void sStack() {
    stack <string> s; 
    string h;
    int jml;
    cout << "Berapa data: ";
    cin >> jml;
        for(int i = 0; i < jml; i++) {
            cout << "Masukan data ke-" << i + 1 << endl;
            cout << "Data string: ";
            cin >> h;
            s.push(h);
        }
     
    // s.push("s"); 
    // s.push("g"); 
    // s.push("h"); 
    // s.push("h"); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 

    popStack();
  
  
}

int main () { 
    
    sStack();
    return 0; 
} 
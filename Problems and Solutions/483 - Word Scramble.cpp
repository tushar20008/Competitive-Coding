#include<cstdio>
#include<stack>
 
using namespace std;
 
stack<char> s;
 
int main(){
    char c;
    while((c=getchar())!=EOF){
        if(c==' '||c=='\n'){
            while(s.size()!=0){
                putchar(s.top());
                s.pop();
            }
            putchar(c);
        } else{
            s.push(c);
        }
    }   
    return 0;
}

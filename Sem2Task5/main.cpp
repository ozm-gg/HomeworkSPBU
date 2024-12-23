#include <iostream>
#include "Stack.h"

int GetPriorityOfOperation(const char *const pointer) {
    switch (*pointer) {
        case '=':
            return 1;
        case '(':
            return 2;
        case '+':
        case '-':
            return 3;
        case '*':
        case '/':
            return 4;
        default:
            return 0;
    }
}

bool IsNumChar(const char *const pointer) {
    const char *numChar = "0123456789e.";
    for (char *c = (char *) numChar; *c != '\0'; ++c) {
        if (*c == *pointer) return true;
    }
    if (*(pointer - 1) == 'e') {
        if (*pointer == '-' or *pointer == '+') return true;
    }
    if (*(pointer - 1) == '(' and isdigit(*(pointer+1))) {
        if (*pointer == '-') return true;
    }
    return false;
}

char *GetNumString(char *&pointer) {
    char *retStr = new char[20];
    char *c;
    for (c = retStr; IsNumChar(pointer); pointer++, c++) {
        *c = *pointer;
    }
    pointer--;
    *c = '\0';
    return retStr;
}

int main() {
    setlocale(LC_ALL, "ru");
    //const char *input = "7+((6+2)/(1+1)-3)*(9+(2+5)*2)=";
    //const char *input = "(5+1)*(4/2)-(7+3)/2=";
    //const char *input = "2-2-2-1=";
    //const char *input = "5/(10-2*2-2*3)=";
    const char *input = "-(-(-(-(-10-4))))=";
    //const char *input = "5/5/5/5=";
    //const char *input = "8e-02+0.2=";
    //const char *input = "-2*(-5+3)=";
    Lessons::Stack<char *> poland{};
    Lessons::Stack<char *> subStack{};
    for (char *pointer = (char *) input; *pointer != '\0'; ++pointer) {
        if (IsNumChar(pointer)) {
            poland.Push(GetNumString(pointer));
        }
        else if (*pointer == '(') {
            char *tmp = new char[2];
            *tmp = *pointer;
            tmp[1] = '\0';
            subStack.Push(tmp);
        } else if (*pointer == ')') {
            while (true) {
                char *c = subStack.Pop();
                if (*c == '(') break;
                poland.Push(c);
            }
        } else {
            int priority = GetPriorityOfOperation(pointer);
            char *tmp = new char[2];
            *tmp = *pointer;
            tmp[1] = '\0';
            while (true) {
                char *c = subStack.Pop();
                if (!c){
                    subStack.Push(tmp);
                    break;
                }else if(GetPriorityOfOperation(c) >= priority){
                    poland.Push(c);
                }else{
                    subStack.Push(c);
                    subStack.Push(tmp);
                    break;
                }
            }
        }
    }

    Lessons::Stack<char *> truePoland{};
    while(char *c = poland.Pop()) truePoland.Push(c);
    while(char *c = truePoland.Pop()){
        std::cout<<c<<" ";
        poland.Push(c);
    };
    while(char *c = poland.Pop()) truePoland.Push(c);

    std::cout<<std::endl;
    Lessons::Stack<double> nums{};
    while(char *c = truePoland.Pop()){
        if(isdigit(*c) or (*c == '-' and isdigit(*(c+1)))){
            nums.Push(atof(c));
        }else{
            double operand1 = nums.Pop(), operand2 = nums.Pop();
            switch (*c) {
                case '+':
                    nums.Push(operand1 + operand2);
                    break;
                case '-':
                    nums.Push(-(operand1 - operand2));
                    break;
                case '*':
                    nums.Push(operand1 * operand2);
                    break;
                case '/':
                    if (operand1 == 0){
                        std::cout<<"Деление на ноль"<<std::endl;
                        return 0;
                    }
                    nums.Push(1/operand1 * operand2);
                    break;
            }
        }
    }
    std::cout<<"Ответ:"<<nums.Pop();
    return 0;
}

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {
        
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            if(top == -1)
                return false;

            char temp = stack[top--];

            if((s[i] == ')' && temp != '(') ||
               (s[i] == '}' && temp != '{') ||
               (s[i] == ']' && temp != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}
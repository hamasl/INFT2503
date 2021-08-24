
int main(){
    //Task is to find errors in this code and replace it with functioning code
    /*
    int a = 5;
    int &b;
    int *c;
    c = &b;
    *a = *b + *c;
    &b = 2;
     */

    int a = 5;
    int &b = a; //A reference needs to initialized
    int *c;
    c = &b;
    a = b + *c; //A is a variable and not a pointer, b is a reference and therefore cannot be de-referenced
    b = 2; //Cannot set the address of a reference to something else
    return 0;
}


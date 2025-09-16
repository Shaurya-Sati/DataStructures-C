#include <stdio.h>
#include <stdlib.h>
struct stack {
    int size;
    int top;
    int *s;
};

void create (struct stack *st,int size) {
    st->size=size;
    st->top=-1;
    st->s=(int*)malloc(sizeof(int) * st->size);
}

int isempty(struct stack *st) {
    return st->top==-1;
}

int isfull(struct stack *st) {
    return st->top==st->size-1;
}

void push(struct stack *st,int x) {
    if (isfull(st)) {
        printf("Stack overflow\n");
    } else {
        st->top++;
        st->s[st->top]=x;;
    }
}

int pop(struct stack *st) {
    int x=-1;
    if (isempty(st)) {
        printf("Stack underflow\n");
    } else {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}


void display(struct stack *st) {
    if (isempty(st)) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements (Top to Bottom)\n");
    for(int i=st->top;i>=0;i--) {
        printf("%d " , st->s[i]);
    }
}

int main() {
    struct stack st;
    int size,val,choice;
    printf("Enter the size of the stack: ");
    scanf("%d" , &size);
    create(&st,size);
    do {
        printf("\n1. Push\n2. Pop\n3. Check if stack is empty\n4. check if stack is full\n5. display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d" , &val);
                push(&st,val);
                break;
            case 2: {
                int x;
                x=pop(&st);
                printf("%d element popped\n", x);
                break;
            }
            case 3: {
                int y;
                y=isempty(&st);
                if (y==1)   printf("Stack is empty\n");
                else    printf("Stack is not empty\n");
                break;
            }
            case 4: {
                int z;
                z=isfull(&st);
                if (z==1)   printf("Stack is full\n");
                else    printf("Stack is not full\n");
                break;
            }
            case 5:
                display(&st);  
                break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!=6);
    free(st.s);
    return 0;
}
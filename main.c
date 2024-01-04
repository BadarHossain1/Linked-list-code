#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head = NULL;
Node* tail;

typedef struct doubnode {
    int data;
    struct doubnode* prev;
    struct doubnode* next;
} doubnode;
doubnode *dhead = NULL, *dtail;

typedef struct circularnode {
    int data;
    struct circularnode* next;
} cirnode;

cirnode *chead, *ctail;

void singly();
void Create();
void Display();
void Search();
void Update();
void Insert();
void Count();
void AtBeginning();
void AtEnd();
void AtPosition();
void Delete();
void DeleteFromBeginning();
void DeleteFromEnd();
void DeleteFromPosition();
void doubly();
void doublycreate();
void doubledisplay();
void doublySearch();
void doublyUpdate();
void doublyInsert();
void doublyDelete();
void doublyCount();
void doublyatbeginning();
void doublyatend();
void doublyatpos();
void doublydelfrombeg();
void doublydelfromend();
void doublydelfrompos();
void circular();
void circularcreate();
void circulardisplay();
void circularSearch();
void circularUpdate();
void circularCount();
void circularInsert();
void circularatbeginning();
void circularatend();
void circularatpos();
void circularDelete();
void circulardelfrombeg();
void circulardelfromend();
void circulardelfrompos();
void linearSearch();
void BinarySearch();
int searchBinary(const int A[], int n, int data);
void SortBubble(int A[],int n);
void BubbleSort();
void Array();
int main() {
    int choice;

    do {
        printf("Welcome to the Lab Task 1\n"
               "Topic: Revision of Previous Lectures\n"
               "Course Title: Data Structures: Sessional\n"
               "Submission Date: 20/10/2023\n"
               "Submitted To: SRK sir\n"
               "Submitted by: Badar Hossain\n"
               "ID: 0182220012101125\n"
               "\n"
               "-----------------------------------------\n"
               "\n");
        printf("Home Menu:\n"
               "1: Singly \n"
               "2: Doubly \n"
               "3: Circular \n"
               "4: Array\n"
               "0: Exit\n"
               "\n"
               "Choose your option: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                singly();
                break;
            case 2:
                doubly();
                break;
            case 3:
                circular();
                break;

            case 4:
                Array();

                break;

            case 0:
                printf("Thank you for tuning up. Have a great day!!");
                exit(0);
        }
    } while (1);
}

void singly() {
    int choice;

    do {
        printf("Welcome to Explore the Singly Linked List....\n"
               "\n"
               "1: Create singly linked list\n"
               "2: Display singly linked list\n"
               "3: Insert in a singly linked list\n"
               "4: Delete from a singly linked list\n"
               "5: Update singly linked list\n"
               "6: Search in a singly linked list\n"
               "7: Count the nodes in a singly list\n"
               "0: Home Page\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Insert();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Update();
                break;
            case 6:
                Search();
                break;
            case 7:
                Count();
                break;
            case 0:
                printf("Thank you for tuning in.\n");
        }
    } while (choice != 0);
}

void Create() {
    int data, choice;
    Node *newNode, *temp;

    do {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(0);
        }

        printf("Enter Data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
            tail = newNode;
        }

        printf("Do you want to continue (0/1): ");
        scanf("%d", &choice);
    } while (choice != 0);
}

void Display() {
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Count() {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("The number of nodes is: %d\n", count);
}

void Search() {
    int searchItem, flag = 0;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the item you want to search: ");
    scanf("%d", &searchItem);
    Node *temp = head;

    while (temp != NULL) {
        if (temp->data == searchItem) {
            printf("FOUND!!!\n");
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if (flag == 0) {
        printf("NOT FOUND...\n");
    }
}

void Update() {
    int searchItem, flag = 0, newData;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the item you want to update: ");
    scanf("%d", &searchItem);
    Node *temp = head;

    while (temp != NULL) {
        if (temp->data == searchItem) {
            printf("Enter the new data: ");
            scanf("%d", &newData);
            temp->data = newData;
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if (flag == 0) {
        printf("NOT FOUND...\n");
    }
    else{
        temp = head;
        while(temp!=0){
            printf("Updated Linked List is %d",temp->data);
            temp = temp->next;
        }
    }
}

void Delete() {
    int choice;
    do {
        printf("Where from you want to delete?\n"
               "Press 1: Delete from beginning\n"
               "Press 2: Delete from end\n"
               "Press 3: Delete from a given position\n"
               "Press 0: Return to home page\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                DeleteFromBeginning();
                break;
            case 2:
                DeleteFromEnd();
                break;
            case 3:
                DeleteFromPosition();
                break;
            case 0:
                printf("Taking you back to home page\n");
                break;
        }
    } while (choice != 0);
}

void DeleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}

void DeleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
}

void DeleteFromPosition() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position. Position should be bigger or equal to 1.\n");
        return;
    }

    if (position == 1) {
        DeleteFromBeginning();
        return;
    }

    int currentPos = 1;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && currentPos < position) {
        prev = temp;
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL || currentPos < position) {
        printf("Position %d exceeds the length of the list.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void Insert() {
    int choice;
    do {
        printf("Where you want to insert?\n"
               "Press 1: At beginning\n"
               "Press 2: At end\n"
               "Press 3: At given position\n"
               "Press 0: Return to home page\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                AtBeginning();
                break;
            case 2:
                AtEnd();
                break;
            case 3:
                AtPosition();
                break;
            case 0:
                printf("Taking you back home.\n");
                break;
        }
    } while (choice != 0);
}

void AtBeginning() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    printf("Enter data you want to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void AtEnd() {
    Node *newnode = NULL;
    int x;
    newnode = (Node*)malloc(sizeof(Node));
    printf("Enter data\n");
    scanf("%d",&x);

    newnode->data = x;
    newnode->next = 0;
    if(head == NULL){
        head = tail = newnode;

    }
    else{
        tail->next = newnode;
        tail = newnode;
    }

}

void AtPosition() {
    int position;
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    if (position == 1) {
        AtBeginning();
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    int currentPos = 1;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && currentPos < position) {
        prev = temp;
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL || currentPos < position) {
        printf("Position %d exceeds the length of the list.\n", position);
        return;
    }

    prev->next = newNode;
    newNode->next = temp;

}
void doubly(){

    int choice;
    do{
        printf("1: Create Doubly linked list\n"
               "2: Display Doubly linked list\n"
               "3: Insert Doubly linked list\n"
               "4: Delete Doubly Linked list\n"
               "5: Update Doubly linked list\n"
               "6: Search Doubly linked list\n"
               "7: Count the nodes in Doubly linked list\n"
               "0: Home Page\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                doublycreate();
                break;

            case 2:
                doubledisplay();
                break;
            case 3:
                doublyInsert();
                break;
            case 4:
                doublyDelete();
                break;

            case 5:
                doublyUpdate();
                break;

            case 6:
                doublySearch();
                break;

            case 7:
                doublyCount();
                break;
            case 0:
                printf("Thanks for tuning in\n");
                break;
        }
    }while(choice!=0);
}
void doublycreate(){
    dhead = NULL;
    doubnode *newNodeD, *dtemp;
    int choice;
    do {
        newNodeD = (doubnode *)malloc(sizeof(doubnode));
        printf("Enter Data\n");
        scanf("%d",&newNodeD->data);
        newNodeD->prev = 0;
        newNodeD->next = 0;

        if (dhead == 0) {
            dtemp = dhead = newNodeD;

        } else {
            dtemp->next = newNodeD;
            newNodeD->prev = dtemp;
            dtemp = newNodeD;
            dtail = newNodeD;

        }
        printf("Do you want to continue (0,1)\n");
        scanf("%d",&choice);
    }while(choice!=0);
}
void doubledisplay(){
    doubnode *dtemp;
    if (dhead == NULL) {
        printf("List is empty.\n");
        return;
    }

    dtemp = dhead;
    while (dtemp != NULL) {
        printf("%d ", dtemp->data);
        dtemp = dtemp->next;
    }
    printf("\n");
}

void doublyInsert(){
    int choice;
    do {
        printf("Where do you want to insert?\n"
               "Press 1: At the beginning\n"
               "Press 2: At the end\n"
               "Press 3: At a given position\n"
               "Press 0: Return to the home page\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                doublyatbeginning();
                break;
            case 2:
                doublyatend();
                break;
            case 3:
                doublyatpos();
                break;
            case 0:
                printf("Taking you back home.\n");
                break;
        }
    } while (choice != 0);
}
void doublyatbeginning(){
    doubnode *newNodeD;
    newNodeD  = (doubnode*)malloc(sizeof(doubnode));
    printf("Enter Data\n");
    scanf("%d",&newNodeD->data);
    newNodeD->prev = 0;
    newNodeD->next  = 0;
    dhead->prev = newNodeD;
    newNodeD->next = dhead;
    dhead = newNodeD;

}
void doublyatend(){
    doubnode *newNodeD;
    doubnode *dtemp;
    newNodeD = (doubnode*)malloc(sizeof(doubnode));
    printf("Enter Data\n");
    scanf("%d",&newNodeD->data);
    newNodeD->prev = 0;
    newNodeD->next = 0;
    dtemp = dhead;
    while (dtemp->next != NULL) {
        dtemp = dtemp->next;
    }
    dtemp->next = newNodeD;
    newNodeD->prev = dtemp;
    dtemp = newNodeD;
    dtail = newNodeD;
}
void doublyatpos(){
    doubnode *newNodeD, *dtemp;
    int pos;
    printf("Enter position = ");
    scanf("%d",&pos);
    if(pos==1){
        doublyatbeginning();
    }
    else{
        dtemp = dhead;
        int i = 0;
        newNodeD = (doubnode*)malloc(sizeof(doubnode));
        printf("Enter Data = ");
        scanf("%d",&newNodeD->data);
        while(i<pos-1){
            dtemp = dtemp->next;
            i++;

        }
        newNodeD->prev  = dtemp;
        newNodeD->next = dtemp->next;
        dtemp->next = newNodeD;
        newNodeD->next->prev = newNodeD;



    }
}
void doublyDelete(){
    int choice;

    do {
        printf("Where do you want to delete?\n"
               "Press 1: Delete from the beginning\n"
               "Press 2: Delete from the end\n"
               "Press 3: Delete from a given position\n"
               "Press 0: Return to the home page\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                doublydelfrombeg();
                break;
            case 2:
                doublydelfromend();
                break;
            case 3:
                doublydelfrompos();
                break;
            case 0:
                printf("Taking you back to the home page.\n");
                break;
        }
    } while (choice != 0);
}
void doublydelfrombeg(){
    doubnode *dtemp;
    if(dhead == 0){
        printf("List is empty\n");

    }
    else{
        dtemp = dhead;
        dhead = dhead->next;
        dhead->prev = 0;
        free(dtemp);

    }
}
void doublydelfromend(){
    doubnode *dtemp;
    if(dtail==0){
        printf("EMPTY");

    }
    else{
        dtemp = dtail;
        dtail->prev->next = 0;
        dtail = dtail->prev;
        free(dtemp);

    }
}
void  doublydelfrompos() {
    doubnode *dtemp;
    int pos, i = 1;
    dtemp = dhead;
    printf("Enter Position  = ");
    scanf("%d", &pos);
    while (i < pos) {
        dtemp = dtemp->next;
        i++;

    }
    dtemp->prev->next = dtemp->next;
    dtemp->next->prev = dtemp->prev;
    free(dtemp);

}
void doublyCount(){
    doubnode *dtemp;
    dtemp = dhead;
    int count = 0;
    while(dtemp!=0){
        dtemp = dtemp->next;
        count++;

    }
    printf("%d",count);
}
void doublySearch() {
    doubnode *dtemp;
    int searchItem, flag = 0;
    if (dhead == NULL) {
        printf("List is empty.\n");

    }

    printf("What are you searching for?\n");
    scanf("%d", &searchItem);

    dtemp = dhead;
    while (dtemp != NULL) {
        if (dtemp->data == searchItem) {
            printf("Got it!\n");
            flag = 1;
            break;
        }
        dtemp = dtemp->next;
    }

    if (flag == 0) {
        printf("Not found\n");
    }
}
void doublyUpdate() {
    doubnode *dtemp;
    int searchItem, flag = 0, n;
    if (dhead == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Who You want to update?\n");
    scanf("%d", &searchItem);

    dtemp = dhead;
    while (dtemp != NULL) {
        if (dtemp->data == searchItem) {
            printf("New number?");
            scanf("%d", &n);
            dtemp->data = n;
            flag = 1;
            break;
        }
        dtemp = dtemp->next;
    }

    if (flag == 0) {
        printf("Not Found\n");
    }
    else{
        dtemp = dhead;
        while(dtemp!=0){
            printf("Updated Linked List is %d",dtemp->data);
            dtemp = dtemp->next;
        }
    }

}
void circular(){

    int choice;
    do{
        printf("1: Create Circular linked list\n"
               "2: Display circular linked list\n"
               "3: Insert circular linked list\n"
               "4: Delete circular Linked list\n"
               "5: Update circular linked list\n"
               "6: Search circular linked list\n"
               "7: Count the nodes in circular linked list\n"
               "0: Home Page\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                circularcreate();
                break;

            case 2:
                circulardisplay();
                break;
            case 3:
                circularInsert();
                break;
            case 4:
                circularDelete();
                break;

            case 5:
                circularUpdate();
                break;

            case 6:
                circularSearch();
                break;

            case 7:
                circularCount();
                break;
            case 0:
                printf("Thanks for tuning in\n");
                break;
        }
    }while(choice!=0);
}

void circularcreate(){
    int i;
    int choice = 1;
    cirnode *newNodec, *ctemp;
    do{
        newNodec = (cirnode *)malloc(sizeof(cirnode));
        if (newNodec == NULL) {
            printf("Memory allocation failed.\n");
            exit(0);
        }
        printf("Enter Data = ");

        scanf("%d", &newNodec->data);
        newNodec->next = NULL;

        if (chead == NULL) {
            chead = newNodec;
            ctemp = newNodec;
        } else {
            ctemp->next = newNodec;
            ctemp = newNodec;
            ctail = newNodec;
        }
        ctemp->next = chead;
        printf("Do you want to continue (0,1)\n");
        scanf("%d",&choice);
    }while(choice!=0);
}
void circulardisplay(){


    cirnode *ctemp;
    if (chead == NULL) {
        printf("List is empty.\n");
        return;
    }

    ctemp = chead;
    do {
        printf("%d ", ctemp->data);
        ctemp = ctemp->next;
    }while (ctemp != chead);
    printf("\n");
}
void circularCount(){
    cirnode *ctemp;
    ctemp = chead;
    int count = 0;
    while(ctemp->next!=chead){
        ctemp = ctemp->next;
        count++;

    }
    printf("%d",count);
}
void circularInsert(){
    int choice;

    do {
        printf("Where do you want to insert?\n"
               "Press 1: At the beginning\n"
               "Press 2: At the end\n"
               "Press 3: After a given value\n"
               "Press 0: Return to the home page\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                circularatbeginning();
                break;
            case 2:
                circularatend();
                break;
            case 3:
                circularatpos();
                break;
            case 0:
                printf("Taking you back home.\n");
                break;
        }
    } while (choice != 0);
}
void circularatbeginning(){
    cirnode *newNodec;
    newNodec = (cirnode*)malloc(sizeof(cirnode));
    printf("Enter data you want to insert");
    scanf("%d",&newNodec->data);
    newNodec->next = chead;
    chead = newNodec;

}
void circularatpos(){
    int pos, i =1;
    cirnode *newNodec, *ctemp;
    newNodec = (cirnode *) malloc(sizeof(cirnode));
    printf("Enter the position = ");
    scanf("%d",&pos);


    ctemp = chead;
    while(i<pos){
        ctemp = ctemp->next;
        i++;


    }printf("Enter data");
    scanf("%d",&newNodec->data);
    newNodec->next = ctemp->next;
    ctemp->next = newNodec;
}
void circularatend(){

}
void circularDelete(){
    int choice;

    do {
        printf("Where do you want to delete?\n"
               "Press 1: Delete the first occurrence\n"
               "Press 2: Delete all occurrences of a value\n"
               "3: Delete from position\n"
               "Press 0: Return to the home page\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                circulardelfrombeg();
                break;
            case 2:
                circulardelfromend();
                break;
            case 3:
                circulardelfrompos();
                break;
            case 0:
                printf("Taking you back to the home page.\n");
                break;
        }
    } while (choice != 0);
}
void circulardelfrombeg(){
    cirnode *ctemp;
    ctemp = chead;
    if(chead->next==0){
        chead=0;
        free(ctemp);

    }else{

        chead = chead->next;
        free(ctemp);
    }

}
void circulardelfrompos() {
    cirnode *nextnode, *ctemp;
    int pos, i = 1;
    ctemp = chead;
    printf("Enter Position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        circulardelfrombeg();
    } else {
        while (i < pos - 1) {
            ctemp = ctemp->next;
            i++;
        }
        nextnode = ctemp->next;
        ctemp->next = nextnode->next;
        free(nextnode);
    }
}
void circulardelfromend(){
    if (chead == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    cirnode *temp = chead;
    cirnode *prev = NULL;

    while (temp->next != chead) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        chead = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
}
void circularSearch(){
    cirnode *ctemp;
    int searchItem, flag = 0;
    if (chead == NULL) {
        printf("List is empty.\n");

    }

    printf("What are you searching for?\n");
    scanf("%d", &searchItem);

    ctemp = chead;
    while (ctemp != NULL) {
        if (ctemp->data == searchItem) {
            printf("Got it\n");
            flag = 1;
            break;
        }
        ctemp = ctemp->next;
    }

    if (flag == 0) {
        printf("Not found!!!!\n");
    }
}
void circularUpdate(){
    cirnode *ctemp;
    int searchItem, flag = 0, n;
    if (chead == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("What you want to update?\n");
    scanf("%d", &searchItem);

    ctemp = chead;
    while (ctemp != NULL){
        if (ctemp->data == searchItem) {
            printf("New number?");
            scanf("%d", &n);
            ctemp->data = n;
            flag = 1;
            break;
        }
        ctemp = ctemp->next;
    }

    if (flag == 0) {
        printf("Not found\n");
    }
    else{
        ctemp = chead;
        while(ctemp->next !=chead){
            printf("Updated Linked List is %d",ctemp->data);
            ctemp = ctemp->next;
        }
    }
    
}
void linearSearch(){
    int n;
    printf("The number of elements??\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter The element = ");
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int data;
    printf("Enter The data you want to search = ");
    scanf("%d",&data);
    for(int i=0;i<n;i++){
        if(data==arr[i]){
            printf("DATA FOUND!......\n");
            break;
        }
    }
}

void BinarySearch(){
    int n, i,findingvalue;
    int result;
    printf("Enter array size\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array values:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    printf("Enter searching value:\n");
    scanf("%d",&findingvalue);
    result  = searchBinary(arr, n, findingvalue);
    if(result==0){
        printf("Found\n");

    }
    else{
        printf("Not found\n");
    }


}
int searchBinary(const int A[], int n, int data){
    int start, end, mid;
    start = 0;
    end = n-1;
    while(start <= end){
        mid = (start + end)/2;
        if(A[mid]==data){
            return 0;
        }
        else if(A[mid]<data){
            start = mid + 1;

        }
        else{
            end = mid - 1;
        }
       return -1;

    }
}
void BubbleSort(){
     int i, j, n, temp;
     printf("Enter Array Size\n");
     scanf("%d",&n);
     int A[n];

    for(i=0;i<n;i++){
         printf("Enter array values\n");
         scanf("%d",&A[i]);
     }
     for(i=0;i<n;i++){
         printf("Array is: %d\n",A[i]);

     }
     printf("\n");
     SortBubble(A,n);

}
void SortBubble(int A[],int n){
    int i;
    int j;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;

            }
        }
    }
    printf("Sorted Array is: ");
    for(i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

}
void Array(){
    int choice;

    do {
        printf("What Array operation you want to do?\n"
               "Press 1: Bubble sort\n"
               "Press 2: Binary Search\n"
               "Press 3: Linear Search\n"
               "Press 0: Return to the home page\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                BubbleSort();
                break;
            case 2:
                BinarySearch();
                break;

            case 3:
                linearSearch();
                break;

            case 0:
                printf("Taking you back to the home page.\n");
                break;
        }
    } while (choice != 0);
}
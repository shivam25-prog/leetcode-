typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} MyLinkedList;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* temp = obj->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    if (obj->head == NULL) {
        obj->head = obj->tail = newNode;
        obj->size++;
        return;
    }
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj->head == NULL) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* newNode = createNode(val);
    obj->tail->next = newNode;
    obj->tail = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node* toDelete;
    if (index == 0) {
        toDelete = obj->head;
        obj->head = obj->head->next;
        if (obj->head == NULL) obj->tail = NULL;
        free(toDelete);
        obj->size--;
        return;
    }
    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == obj->tail) obj->tail = temp;
    free(toDelete);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* temp = obj->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
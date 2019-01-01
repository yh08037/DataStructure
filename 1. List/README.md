# 리스트

## 배열로 충분하지 않은가?

소프트웨어는 종종 프로그래머에게 배열 이상의 무언가를 요구할 때가 있습니다.
프로그래밍 문제에서는 보통, 어떤 텍스트 파일 속의 정수 데이터를 필요로 한다고 할 때,
데이터의 최대 갯수를 정해주고 우리는 그 갯수에 맞추어 데이터를 저장할 정수형 배열을 만들어 사용하곤 했습니다.
하지만 임의의 파일에 대한 정보를 소프트웨어가 필요로 한다면 어떻게 될까요?
"데이터가 많아봐야 10000개는 넘지 않겠지"라고 생각해 길이가 10000인 배열을 선언하고 사용할까요?
만약 데이터가 열몇개에 불과하다면 메모리를 불필요하게 많이 사용하는 것이고, 반대로 10000개보다 하나라도 더 많아도 문제가 생깁니다.
이를 해결하기 위해서, 배열과는 달리 크기를 유연하게 바꿀 수 있는 자료형으로 리스트가 필요합니다.

## 링크드 리스트 (Singly Linked List)

```c
typedef struct tagNode{
    int Data;
    struct tagNode* NextNode;
}Node;
```

```c
Node* SLL_CreateNode(int NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}
```

```c
void SLL_DestroyNode(Node* Node){
    free(Node);
}
```

## 더블 링크드 리스트 (Doubly Linked List)

## 환형 링크드 리스트 (Circular Linked List)


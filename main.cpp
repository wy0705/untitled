#include <stdio.h>
#include "stdlib.h"
#include "string.h"
struct Node
{
    int a;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* end=NULL;

//增
void AddListTill(int a){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->a=a;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    } else{
        end->next=temp;
    }
    end=temp;
}

//遍历--查
void ScanList(){
    struct Node* temp=head;
    while (temp!=NULL){
        printf("%d\n",temp->a);
        temp=temp->next;
    }
}


//指定查询
struct Node* FindNode(int a){
    struct Node* temp=head;
    if (temp==NULL){
        printf("该链表为空");
    } else{
        while (temp!=NULL){
            if(temp->a==a){
                printf("找到该节点");
                return temp;
            }
            temp=temp->next;
        }
    }
    printf("未找到该节点");
    return NULL;
}

//链表清空
void FreeList(){
    struct Node* temp=head;
    while (temp!=NULL){
        struct Node* pt=temp;
        temp=temp->next;
        free(pt);
    }
    head=NULL;
    end=NULL;
}

//在指定位置插入节点                        （重写）
void AddListRand(int index,int a){
    if (head==NULL){
        printf("链表为空\n");
        return;
    }
   struct Node* pt=FindNode(index);
    if (pt==NULL){
        printf("没有该节点");
        return;
    }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->a=a;
    temp->next=NULL;
    if (pt==end){
        end->next=temp;
        end=temp;
    } else{
        temp->next=pt->next;
        pt->next=temp;
    }
}

//尾删除
void DeleteListTail(){
    if (end==NULL){
        printf("该链表为空");
        return;
    }
    if (head==end){
        free(head);
        head==NULL;
        end==NULL;
    }
    else{
        struct Node* temp=head;
        while (temp->next==end){
            temp=temp->next;
        }
        free(end);
        end=temp;
        end->next=NULL;
    }

}


//头删除
void DeleteListHead(){
    struct Node* temp=head;
    if (NULL==head){
        printf("链表为空");
        return;
    }
    head=head->next;
    free(temp);
}

//删除指定节点
void DeleteListRand(int a){
    if (head==NULL){
        printf("链表为空");
        return;
    }
    struct Node* temp=FindNode(a);
    if (temp==NULL){
        printf("没有这个节点");
        return;
    }
    if (head==end){
        free(head);
        head=NULL;
        end=NULL;
    }
    else if(head->next==end){
        if (end==temp){
            DeleteListTail();
        } else if (head==temp){
            DeleteListHead();
        }
    } else{
        if (end==temp){
            DeleteListTail();
        } else if (head==temp){
            DeleteListHead();
        } else{
            struct Node* pt=head;
            while (pt->next!=temp){
                pt=pt->next;
            }
            pt->next=temp->next;
            free(temp);
        }
    }
}

/*int main() {
    struct Node* pFind;
    for (int i = 0; i < 7; ++i) {
        AddListTill(i);
    }
    printf("当前链表");
    ScanList();
    printf("在第四个位置上插入14");
    AddListRand(4,14);
    printf("当前链表");
    ScanList();
    printf("删除一个尾节点");
    DeleteListTail();
    printf("当前链表");
    ScanList();
    printf("删除第四个节点");
    DeleteListRand(4);
    printf("当前链表");
    ScanList();
    printf("查找第二个节点");
    pFind=FindNode(2);
    if (pFind!=NULL){
        printf("%d",pFind->a);
    } else{
        printf("没有找到");
    }
    printf("删除链表");
    printf("当前链表");
    ScanList();

    return 0;
}*/

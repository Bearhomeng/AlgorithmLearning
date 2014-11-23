#include<iostream>
using namespace std;
struct Node{
	int value;
	struct Node *next;
}; 
typedef struct Node Node; 
void printLinkList(Node *linkList);
Node *LinkListReverseLocally(Node *linkList,int N);
void reverseCycleLinkList(Node *linkList);
bool validateCircleLinkList(Node *cycleList); 

//��ں��� 
int main(){
 	int nodeNum,shift,N;
 	Node *head=NULL;
 	Node *cur=NULL;
	cout<<"INPUT number of node:";
	cin>>nodeNum;
	for(int i=nodeNum;i>0;i--)
	{
		Node *newNode = (Node*)malloc(sizeof(Node));
		cout<<"IUPUT value of node("<<"LEFT "<<i-1<<"):";
		cin>>newNode->value;
		if(head==NULL){
			head = newNode;
			cur = head;
		}else{
			cur->next=newNode;
			cur=newNode;
		}
		newNode->next=NULL;
	}
	//��ӡԭ���� 
	printLinkList(head);
	//�Ե�N���ڵ�Ϊ���ޣ�������ֶΣ��ֲ���ת 
	cout<<"INPUT N:";
	cin>>N;
	head = LinkListReverseLocally(head,N); 
	//��ӡ������ 
	 printLinkList(head); 
 }
 
 
 
 //����ֶξֲ���ת
 Node *LinkListReverseLocally(Node *linkList,int N){
 	if(linkList==NULL){
 		return linkList;
 	}
	//�γɻ������� 
 	Node *p=linkList;
 	while(p->next!=NULL){
 		p=p->next;
	}
 	p->next=linkList;
 	//��ȡ������ͷָ��
 	Node *newHead=linkList;
 	for(int i=1;i<N;i++){
	 	newHead=newHead->next;
 	}
 	//�����µ�β�ڵ�
 	Node *newEnd=newHead->next; 
 	//������������
	reverseCycleLinkList(newHead); 
	//�ϻ�
	newEnd->next=NULL;
 	return newHead; 
 }
 void reverseCycleLinkList(Node *linkList){
 	if(linkList==NULL){
	 	return;
 	}
 	if(!validateCircleLinkList(linkList)){
		return;
 	}
 	cout<<"�ǻ�������!"<<endl;;
	Node *first=linkList;
	Node *second=first->next;
	Node *temp=NULL; 
	while(second->next!=first){
		temp=second->next;
		second->next=first;
		first=second;
		second=temp;
	}
 }
 
 //����Ƿ��ǻ������� 
 bool validateCircleLinkList(Node *cycleList){
 	if(cycleList == NULL || cycleList->next == NULL){
	 	return false;
 	}
 	Node *turtle = cycleList;
 	Node *rabbit = cycleList->next;
 	while(turtle!=rabbit){
 		for(int i=0;i<1;i++){
	 		turtle=turtle->next;
			if(turtle==NULL){
				return false;
			}
	 	}
	 	for(int j=0;j<2;j++){
	 		rabbit=rabbit->next;
			if(rabbit==NULL){
				return false;
			}	
	 	}
 	}
 	return true;
 }
 
 //��ӡ���� 
 void printLinkList(Node *linkList){
	Node *p=linkList;
	for(int i=0;p!=NULL;i++){
		cout<<"Node"<<i<<":"<<p->value<<endl; 
		p=p->next;
	}
 }
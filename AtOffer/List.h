/**
* ������
*/

#ifndef _LIST_H_

#define _LIST_H_

// ����ڵ�
struct ListNode {
	int val;
	ListNode *pNext;

	ListNode(int n)
	{
		val = n;
		pNext = nullptr;
	}
};

// ����Ĳ���
ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestoryList(ListNode* pHead);
void AddToTail(ListNode **pHead, int value);
void RemoveNode(ListNode **pHead, int value);

#endif

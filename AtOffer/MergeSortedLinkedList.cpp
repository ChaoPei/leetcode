/**
* �ϲ��������������
*/

#include "List.h"

#include <iostream>
#include <string>

using namespace std;



ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	// ��ָ�봦��
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	if (pHead2 == nullptr)
	{
		return pHead1;
	}

	ListNode* pMergeResult = nullptr;

	// �ݹ�ϲ�
	if (pHead1->val < pHead2->val)
	{
		pMergeResult = pHead1;
		pMergeResult->pNext = MergeList(pHead1->pNext, pHead2);
	}
	else
	{
		pMergeResult = pHead2;
		pMergeResult->pNext = MergeList(pHead1, pHead2->pNext);
	}

	return pMergeResult;

}

/*----------------��Ԫ����-------------------*/

ListNode* Test(string testName, ListNode* pHead1, ListNode* pHead2)
{
	if (!testName.empty())
	{
		cout << testName << " begins: \n";
	}

	cout << "The first list is : \n";
	PrintList(pHead1);

	cout << "The second list is : \n";
	PrintList(pHead2);


	cout << "The merge list is : \n";
	ListNode* mergeResult = MergeList(pHead1, pHead2);
	PrintList(mergeResult);

	cout << "\n" << endl;
	return mergeResult;
}

// ��ͨ�������
void Test1()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node3 = new ListNode(3);
	ListNode* node5 = new ListNode(5);
	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);

	ListNode* node2 = new ListNode(2);
	ListNode* node4 = new ListNode(4);
	ListNode* node6 = new ListNode(6);
	ConnectListNodes(node2, node4);
	ConnectListNodes(node4, node6);

	ListNode* pMergeHead = Test("Test1", node1, node2);
	DestoryList(pMergeHead);
}

// ����Ԫ���ظ�
void Test2()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node3 = new ListNode(3);
	ListNode* node5 = new ListNode(5);
	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);

	ListNode* node2 = new ListNode(2);
	ListNode* node4 = new ListNode(3);
	ListNode* node6 = new ListNode(5);
	ConnectListNodes(node2, node4);
	ConnectListNodes(node4, node6);

	ListNode* pMergeHead = Test("Test2", node1, node2);
	DestoryList(pMergeHead);
}

// ������
void Test3()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node3 = new ListNode(3);
	ListNode* node5 = new ListNode(5);
	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);

	ListNode* node2 = nullptr;

	ListNode* pMergeHead = Test("Test3", node1, node2);
	DestoryList(pMergeHead);
}

// ������
void Test4()
{
	ListNode* node1 = nullptr;

	ListNode* node2 = nullptr;

	ListNode* pMergeHead = Test("Test4", node1, node2);
	DestoryList(pMergeHead);
}



int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	getchar();

	return 0;

}
/*----------------------------------------------------------------------|
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。			|
																		|
示例：																	|
																		|
给定一个链表: 1->2->3->4->5, 和 n = 2.									|
																		|
当删除了倒数第二个节点后，链表变为 1->2->3->5.							|
说明																	|
																		|
给定的 n 保证是有效的。													|
																		|
进阶：																	|
																		|
你能尝试使用一趟扫描实现吗？											|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list |
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了51.88%的用户
*	内存消耗：6.5 MB, 在所有 C++ 提交中击败了52.25%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 


ListNode* removeNthFromEnd(ListNode* head, int n)									/*	注意链表节点用法	*/
{
	if (!head)
	{
		return head;
	}
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *scan = dummy;
	ListNode *nth = dummy;

	for (int count = 0; count < n; count++)
	{
		scan = scan->next;
	}
	while (scan->next)
	{
		scan = scan->next;
		nth = nth->next;
	}

	nth->next = nth->next->next;

	ListNode *result = dummy->next;

	delete dummy;

	return result;
}


int main()
{
	ListNode head(0);
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	ListNode l5(5);

	head.next = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;

	ListNode p = head;

	while (p.next)
	{
		cout << p.next->val << endl;
		p = *p.next;
	}
	int n = 2;

	
	//
	//ListNode result = *head;
	//ListNode scan(0);
	//scan = *head.next;
	//ListNode n_th(0);
	//n_th = scan;
	//ListNode n_1_th(0);
	//n_1_th = head;

	//int count = 1;
	//while (scan.next)
	//{
	//	scan = *scan.next;
	//	count++;
	//	if (count < n)
	//	{
	//		continue;
	//	}
	//	else
	//	{
	//		n_th = *n_th.next;
	//		n_1_th = *n_1_th.next;
	//	}
	//}
	//n_1_th.next = &scan;

	//delete& n_th;
	//

	ListNode q(0);
	q = *removeNthFromEnd(&head, n);
	while (q.next)
	{
		cout << q.next->val << endl;
		q = *q.next;
	}
}
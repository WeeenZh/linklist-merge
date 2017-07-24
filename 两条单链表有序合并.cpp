//输入两列有序整数，组成两个链表，而后合并为一个有序链表
//文件名：链表操作.cp1p1

#include<iostream>
using namespace std;

struct link {
	int num;
	link *next;
};

int main()
{
	int x, i;
	link *head, *p, *rear, *head1, *p1, *rear1,*tmp;

	{cout << "请输入第1列整数：";
	head = rear = new link;
	while (true) {
		cin >> x;
		if (x == -1) break;
		p = new link;
		p->num = x;
		rear->next = p;
		rear = p;
	}
	rear->next = NULL;

	//读链表
	cout << "第一链表的内容是：\n";
	p = head->next;
	while (p != NULL) {
		cout << p->num << '\t';
		p = p->next;
	}
	cout << endl;


	cout << "请输入第2列整数：";
	head1 = rear1 = new link;
	while (true) {
		cin >> x;
		if (x == -1) break;
		p1 = new link;
		p1->num = x;
		rear1->next = p1;
		rear1 = p1;
	}
	rear1->next = NULL;

	cout << "第二链表的内容是：\n";
	p1 = head1->next;
	while (p1 != NULL) {
		cout << p1->num << '\t';
		p1 = p1->next;
	}
	cout << endl;


	//合并链表
	rear = head->next;
	rear1 = head1->next;
	p = head;
	while (true) {
		if (rear->num > rear1->num) {
			p1 = rear1->next;
			rear1->next = rear;
			p->next = rear1;           //rear1 插入 p 与 rear 之间
			p = rear1;
			rear1 = p1;
		}
		else {
			if (rear->next != NULL) {
				p = rear;
				rear = rear->next;
				if (rear->next == NULL) {
					if (rear->num < rear1->num) { rear->next = rear1; }
					else { rear->next = rear1->next; 
					p->next = rear1;
					rear1->next = rear;
					}

			break;
			}
			}                                   //数列0向前移动
		}
		if (rear1->next == NULL) break;        //如果数列1空，终止
	}


	cout << "链表的内容是：\n";
	p = head->next;
	while (p != NULL) {
		cout << p->num << '\t';
		p = p->next;
	     }
	}
	cout << endl;


	return 0;
}
//���������������������������������ϲ�Ϊһ����������
//�ļ������������.cp1p1

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

	{cout << "�������1��������";
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

	//������
	cout << "��һ����������ǣ�\n";
	p = head->next;
	while (p != NULL) {
		cout << p->num << '\t';
		p = p->next;
	}
	cout << endl;


	cout << "�������2��������";
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

	cout << "�ڶ�����������ǣ�\n";
	p1 = head1->next;
	while (p1 != NULL) {
		cout << p1->num << '\t';
		p1 = p1->next;
	}
	cout << endl;


	//�ϲ�����
	rear = head->next;
	rear1 = head1->next;
	p = head;
	while (true) {
		if (rear->num > rear1->num) {
			p1 = rear1->next;
			rear1->next = rear;
			p->next = rear1;           //rear1 ���� p �� rear ֮��
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
			}                                   //����0��ǰ�ƶ�
		}
		if (rear1->next == NULL) break;        //�������1�գ���ֹ
	}


	cout << "����������ǣ�\n";
	p = head->next;
	while (p != NULL) {
		cout << p->num << '\t';
		p = p->next;
	     }
	}
	cout << endl;


	return 0;
}
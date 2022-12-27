#include <bits/stdc++.h>
#include "cs_class.h"
#include <windows.h>
using namespace std;
int begin_time;
int end_time;
int people;
int total_time = 0;
queue<int> q;
map<int, char *> m; // 保存业务
map<int, int> Te;
void second_to_hour(int second, int *hour, int *mintue, int *sec)
{
	*hour = second / 3600;
	*mintue = second % 3600 / 60;
	*sec = second % 60;
}
int hour_to_second(int hour, int mintue, int second)
{
	return hour * 3600 + mintue * 60 + second;
}
void Print_time(int second)
{
	int hour, mintue, sec;
	second_to_hour(second, &hour, &mintue, &sec);
	printf("[%02d:%02d:%02d]:", hour, mintue, sec);
}
void Print_work(int i)
{
	int num;
	for (int j = 1; j <= 4; j++)
	{
		num = s[i].getwork(j);
		printf("%s 业务 : %d人\n", m[j], num);
	}
}
bool cmp(Customer a, Customer b)
{
	return a.getTime() < b.getTime();
}
void Random_people()
{
	for (int i = 1; i <= people; i++)
	{
		srand(customer[i - 1].getTime() + time(0));
		customer[i].charge_work_time(rand() % 4 + 1, (rand() % (end_time - begin_time) + begin_time));
	}
	sort(customer + 1, customer + people + 1, cmp);
}
void Continue_time(int sec1, int sec2)
{
	int h1, h2, m1, m2, s1, s2;
	second_to_hour(sec1, &h1, &m1, &s1);
	second_to_hour(sec2, &h2, &m2, &s2);
	printf("from[%02d:%02d:%02d] --- to  [%02d:%02d:%02d]", h1, m1, s1, h2, m2, s2);
	total_time += (sec2 - sec1);
}

int Enter_queue(int currentcustomer)
{
	int flag = 1;
	int cnt = 0;
	queue<int> tmp;
	if (q.empty())
	{
		q.push(currentcustomer);
		return 0;
	}
	else
	{
		while (!q.empty())
		{
			if (customer[currentcustomer].getWorkId() < customer[q.front()].getWorkId() ||
				((customer[currentcustomer].getWorkId() == customer[q.front()].getWorkId()) && (customer[currentcustomer].getTime() < customer[q.front()].getTime())))
			{
				flag = 0;
				tmp.push(currentcustomer);
				break;
			}
			else
			{
				cnt++;
				tmp.push(q.front());
				q.pop();
			}
		}
		if (flag == 1)
		{
			tmp.push(currentcustomer);
		}
		else
		{
			while (!q.empty())
			{
				tmp.push(q.front());
				q.pop();
			}
		}

		q = tmp;
		return cnt;
	}
}

void Print_Fastesrttime(int sec, int p)
{
	int server_time = s[1].getRemainTime();
	int queue_time = 0;
	for (int i = 2; i <= 4; i++)
	{
		if (server_time > s[i].getRemainTime())
		{
			server_time = s[i].getRemainTime();
		}
	}

	set<int> s;
	queue<int> tmp = q;
	while (!tmp.empty())
	{
		s.insert(tmp.front());
		tmp.pop();
	}
	int cnt = 0;
	for (auto it = s.begin(); cnt < p / 4; it++)
	{
		queue_time += Te[customer[*it].getWorkId()];
		cnt++;
	}
	printf("最快还要:");
	Print_time(queue_time + server_time);
	printf(" ");
	printf("时间即可办理业务\n");
	printf("预计办理时间:");
	Print_time(sec + queue_time + server_time);
	printf("\n");
}

int Total_Time()
{
	for(int i=1;i<=4;i++)
	{   if(s[i].getRemainTime()>0)
	    {
		total_time+=end_time-customer[s[i].getnum()].getTime();
		}
	}
    
	while(!q.empty())
	{
		total_time+=end_time-customer[q.front()].getTime();
		q.pop();
	}
	return total_time;
}

void Simulate()
{
	int currentcustomer = 1;

	//  	 for(int i=1;i<=4;i++)
	//  {
	// 	 printf("%d %d %d\n",customer[i].getId(),customer[i].getTime(),customer[i].getWorkId());
	//  }
	for (int i = begin_time; i <= end_time && currentcustomer <= people + 1; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (s[j].getRemainTime() == 0) // 有窗口为空闲状态
			{
				Print_time(i);
				
				printf("【办理完成】%02d 号客户在%d号创口办理完成[%s]业务", customer[s[j].getnum()].getId(), j, m[customer[s[j].getnum()].getWorkId()]);
				Continue_time(customer[s[j].getnum()].getTime(), i);
				printf("\n\n");
				//Sleep(500);
				// pop出队
				if (!q.empty())
				{
					Print_time(i);
					s[j].cntadd(); // 完成人数加一
					printf("【办理中】%02d 号客户在 %d 号口开始办理[%s]业务\n\n", q.front(), j, m[customer[q.front()].getWorkId()]);
					s[j].charge_stuff(q.front());
					q.pop();
					//Sleep(200);
				}
				else
				{
					if (s[j].getRemainTime() != -1)
						s[j].charge_remaintime(-1);
				}
			}
		}

		while (i == customer[currentcustomer].getTime()) // 当前客户进来   //用while而不是if是因为有多个顾客同时进入的情况
		{

			customer[currentcustomer].charge_id(currentcustomer);
			int flag = 0;

			for (int k = 1; k <= 4; k++)
			{
				if (s[k].getRemainTime() == -1) // 刚开始
				{
					flag = 1;
					s[k].charge_stuff(currentcustomer);
					Print_time(i);
					s[k].cntadd(); // 完成人数加一
					printf("【办理中】%02d 号客户在 %d 号口开始办理[%s]业务\n\n", customer[currentcustomer].getId(), k, m[customer[currentcustomer].getWorkId()]);
					//Sleep(200);
					break;
				}
			}
			if (flag == 0)
			{ // 打印编号 队伍长度
				int p = Enter_queue(currentcustomer);
				Print_time(i);
				printf("【打号】您已成功打号：%d号  业务为[%s]   \n", customer[currentcustomer].getId(), m[customer[currentcustomer].getWorkId()]);
				printf("队伍前面还有:");
				cout << p << endl;
				Print_Fastesrttime(i, p);
				printf("******************************************\n");
				//Sleep(500);
				// q.push(currentcustomer);
				//  入队列
			}
			currentcustomer++;
		}
		for (int m = 1; m <= 4; m++)
		{
			if (s[m].getRemainTime() > 0)
				s[m].time();
		}
	}
	int k = 1;
	printf("\n");
	printf("********************今日统计**********************\n");
	printf("共接待：%d\n", s[1].getcnt() + s[2].getcnt() + s[3].getcnt() + s[4].getcnt());
	printf("一号柜台共接待： %d人\n", s[1].getcnt());
	Print_work(1);
	printf("二号柜台共接待： %d人\n", s[2].getcnt());
	Print_work(2);
	printf("三号柜台共接待： %d人\n", s[3].getcnt());
	Print_work(3);
	printf("四号柜台共接待： %d人\n", s[4].getcnt());
	Print_work(4);
	for (int i = 2; i <= 4; i++)
	{
		if (s[k].getcnt() < s[i].getcnt())
		{
			k = i;
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(s[k].getcnt()==s[i].getcnt())
			printf("今日勤劳之星为%d号\n", i);
	}

	printf("顾客总逗留时间：");
	total_time=Total_Time();
	Print_time(total_time);
	printf("\n");
	printf("顾客平均逗留时间: ");
	Print_time(total_time / people);
	printf("\n");
}
void Clear()
{
	 for(int i=1;i<=4;i++)
	 {
		s[i]=Staff();
	 }
	 for(int j=0;j<=people;j++)
	 {
		customer[j]=Customer();
	 }
	 begin_time=end_time=people=0;
	 while(!q.empty())
	 {
		q.pop();
	 }
}
void Bank()
{
	int h, m, s;
	int hour,time;
	printf("请输入银行开始营业时间:(格式9:30)");
	scanf("%d:%d", &hour, &time);
	if (hour < 0 || hour > 23 || time < 0 || time > 59)
	{
		printf("输入非法!");
		return;
	}
	begin_time = hour_to_second(hour, time, 0);
	printf("请输入银行开始打烊时间:(格式18:30)");
	scanf("%d:%d", &hour, &time);
	if (hour < 0 || hour > 23 || time < 0 || time > 59)
	{
		cout<<"输入非法!"<<endl;
	}
	end_time = hour_to_second(hour, time, 0);
	if (begin_time > end_time)
	{
		cout<<"开店时间比关门时间迟!"<<endl;
		return;
	}
	printf("请输入模拟人数!\n");
	cin >> people;
	if(people<0)
	{
		cout<<"人数为负数非法!"<<endl;
		return ;
	}
	Random_people();
	second_to_hour(begin_time, &h, &m, &s);
	printf("[%02d:%02d:%02d]:", h, m, s);
	printf("*******************开始营业!******************\n");
	Simulate();
}
void bankMenu()
{
	int select = 0;
	cout << "                    ===========================================================================" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                          ------ czx-Bank ------                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                         Enter 1 to begin to simulate                    |" << endl;
	cout << "                    |                         Enter 2 to quit system                          |" << endl;
	cout << "                    ===========================================================================" << endl;
	cin >> select;
	if (select == 1)
	{
		Bank();
		Clear();
	}
	else if (select == 2)
	{
		return;
	}
	else
	{
		cout << "输入非法" << endl;
	}
	while(1)
	{
	cout << "                    ===========================================================================" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                          ------ czx-Bank ------                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                         Enter 1 to again to simulate                    |" << endl;
	cout << "                    |                         Enter 2 to quit system                          |" << endl;
	cout << "                    ===========================================================================" << endl;
	cin >> select;
	if (select == 1)
	{   //system("cls");
		Bank();
		Clear();
	}
	else if (select == 2)
	{
		return;
	}
	else
	{
		cout << "输入非法" << endl;
	}
	}
}
void Welcome()
{
	int select;
	int hour, time;
	printf("                                   /************************************************/\n");
	printf("                                   /*   ____ _______  __  ____    _    _   _ _  __ */\n");
	printf("                                   /*  / ___|__  /\\ \\/ / | __ )  / \\  | \\ | | |/ / */\n");
	printf("                                   /* | |     / /  \\  /  |  _ \\ / _ \\ |  \\| | ' /  */\n");
	printf("                                   /* | |___ / /_  /  \\  | |_) / ___ \\| |\\  | . \\  */\n");
	printf("                                   /*  \\____/____|/_/\\_\\ |____/_/   \\_\\_| \\_|_|\\_\\ */\n");
	printf("                                   /*                                              */\n");
	printf("                                   /************************************************/\n");
	bankMenu();
}

int main()
{
	m[1] = "存款";
	Te[1] = 600;
	m[2] = "取款";
	Te[2] = 1200;
	m[3] = "挂失";
	Te[3] = 1800;
	m[4] = "还贷";
	Te[4] = 3600;
	Welcome();
}

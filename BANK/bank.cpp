#include <bits/stdc++.h>
#include "cs_class.h"
using namespace std;
int begin_time;
int end_time;
int people;
int total_time=0;
int id = 1;
queue<int> q;
map<int,char *> m;//保存业务
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
{   int num;
	for(int j=1;j<=4;j++)
	{
		num=s[i].getwork(j);
		printf("%s 业务 : %d人\n",m[j],num);
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
void Continue_time(int sec1,int sec2)
{
	int h1,h2,m1,m2,s1,s2;
	second_to_hour(sec1,&h1,&m1,&s1);
	second_to_hour(sec2,&h2,&m2,&s2);
	printf("from[%02d:%02d:%02d] --- to  [%02d:%02d:%02d]", h1,m1,s1,h2,m2,s2);
	total_time+=(sec2-sec1);
}
void Simulate()
{
	int currentcustomer = 1;

	//  	 for(int i=1;i<=4;i++)
	//  {
	// 	 printf("%d %d %d\n",customer[i].getId(),customer[i].getTime(),customer[i].getWorkId());
	//  }
	for (int i = begin_time; i <= end_time&&currentcustomer <= people+1; i++)
	{    
		for (int j = 1; j <= 4; j++)
		{
			if (s[j].getRemainTime() == 0) // 有窗口为空闲状态
			{
				Print_time(i);
				printf("%02d 号客户在%d号创口办理完成[%s]业务", customer[s[j].getnum()].getId(), j,m[customer[s[j].getnum()].getWorkId()]);
				Continue_time(customer[s[j].getnum()].getTime(),i);
				printf("\n\n");
				s[j].cntadd(); // 完成人数加一

				// pop出队
				if (!q.empty())
				{  Print_time(i);
					printf("%02d 号客户在 %d 号口开始办理[%s]业务\n\n", q.front(), j,m[customer[q.front()].getWorkId()]);
					s[j].charge_stuff(q.front());
					q.pop();
				}
				else{
					if(s[j].getRemainTime()!=-1)
					s[j].charge_remaintime(-1);
				}
			}
		}

		while (i == customer[currentcustomer].getTime()) // 当前客户进来
		{
			id++;
			customer[currentcustomer].charge_id(id);
			int flag = 0;

			for (int k = 1; k <= 4; k++)
			{
				if (s[k].getRemainTime() == -1) // 刚开始
				{
					flag = 1;
					s[k].charge_stuff(currentcustomer);
					Print_time(i);
					printf("%02d 号客户在 %d 号口开始办理[%s]业务\n\n", customer[currentcustomer].getId(), k,m[customer[currentcustomer].getWorkId()]);
					break;
				}
			}
			if (flag == 0)
			{ // 打印编号 队伍长度
				q.push(currentcustomer);
				// 入队列
			}
			currentcustomer++;
		}
		for (int m = 1; m <= 4; m++)
		{
			if (s[m].getRemainTime() > 0)
				s[m].time();
		}
	}
	int k=1;
	printf("\n");
	printf("********************今日统计**********************\n");
	printf("共接待：%d\n",s[1].getcnt()+s[2].getcnt()+s[3].getcnt()+s[4].getcnt());
	printf("一号柜台共接待： %d人\n",s[1].getcnt());
	Print_work(1);
	printf("二号柜台共接待： %d人\n",s[2].getcnt());
	Print_work(2);
	printf("三号柜台共接待： %d人\n",s[3].getcnt());
	Print_work(3);
	printf("四号柜台共接待： %d人\n",s[4].getcnt());
	Print_work(4);
	for(int i=2;i<=4;i++)
	{
		if(s[k].getcnt()<s[i].getcnt())
		{
			k=i;
		}
	}
	printf("今日勤劳之星为%d号\n",k);

	printf("顾客总逗留时间：");
	Print_time(total_time);
	printf("\n");
	printf("顾客平均逗留时间: ");
	Print_time(total_time/people);
	printf("\n");


	
}

void Bank()
{
	int h, m, s;
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
	cout << "                    |                          ------ czx-Bank ------                       |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                         Enter 1 to begin to simulate                    |" << endl;
	cout << "                    |                         Enter 2 to quit system                          |" << endl;
	cout << "                    ===========================================================================" << endl;
	cin >> select;
	if (select == 1)
	{
		Bank();
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
void Welcome()
{
	int select;
	int hour, time;
	printf("/************************************************/\n");
	printf("/*   ____ _______  __  ____    _    _   _ _  __ */\n");
	printf("/*  / ___|__  /\\ \\/ / | __ )  / \\  | \\ | | |/ / */\n");
	printf("/* | |     / /  \\  /  |  _ \\ / _ \\ |  \\| | ' /  */\n");
	printf("/* | |___ / /_  /  \\  | |_) / ___ \\| |\\  | . \\  */\n");
	printf("/*  \\____/____|/_/\\_\\ |____/_/   \\_\\_| \\_|_|\\_\\ */\n");
	printf("/*                                              */\n");
	printf("/************************************************/\n");
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
		printf("输入非法!");
	}
	end_time = hour_to_second(hour, time, 0);
	if (begin_time > end_time)
	{
		printf("开店时间比关门时间迟!");
		return;
	}
	printf("请输入模拟人数!\n");
	cin >> people;
	Random_people();
	// system("cls");
	bankMenu();
}

int main()
{       m[1]="存款";
        m[2]="取款";
		m[3]="挂失";
		m[4]="还贷";
		Welcome();
}
#include <iostream>
#include<bits/stdc++.h>
#include <queue>
using namespace std;
class Customer
{
private:
  int id;
  int entertime;
  int workid;
  friend class Staff;

public:
  Customer()
  {
  }
  void charge_id(int id)
  {
    this->id = id;
  }
  void charge_work_time(int workid, int time)
  {
    this->workid = workid;
    this->entertime = time;
  }
  int getId()
  {
    return this->id;
  }
  int getWorkId()
  {
    return this->workid;
  }
  int getTime()
  {
    return this->entertime;
  }
} customer[10000];

class Staff
{
private:
  int remainTime=-1; // 每个员工对于当前业务的处理时间
  int people_id=0;
  int count=0;// 经手多少人
  int works[5];
  // queue<Customer> q;//员工面前的队伍
public:
 
  int getRemainTime()
  {
    return this->remainTime;
  }
  int getnum()
  {
    return this->people_id;
  }
  int getcnt()
  {
    return this->count;
  }
  int getwork(int i)
  {
    return this->works[i];
  }
  void cntadd()
  {
    this->count++;
  }
  void time()
  {
    this->remainTime--;
  }
  int charge_remaintime(int time)
  {
    this->remainTime=-1;
  }
   void charge_stuff(int num)
  {
    this->people_id = num;
    srand(customer[num].getTime() + customer[num].getWorkId());
    switch (customer[num].getWorkId())
    {
     case 1:
      this->works[1]++;
      this->remainTime = rand() % 1200 + 300;
      break;
    case 2:
      this->works[2]++;
      this->remainTime = rand() %2400  + 300;
      break;
    case 3:
      this->works[3]++;
      this->remainTime = rand() % 1200 + 300;
      break;
    case 4:
      this->works[4]++;
      this->remainTime = rand() % 1560 + 300;
      break;
    default:
      break;
    }
  }

} s[5];
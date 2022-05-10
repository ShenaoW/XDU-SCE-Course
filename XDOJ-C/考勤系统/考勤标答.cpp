#include<stdio.h>
typedef struct{						//建立结构体，储存学生的学号及工作时间
    int biaohao;
    int time ;
}Student;
int main()
{
    int flag = 0 ;			
    int m;
    scanf("%d",&m);
    int cnt = 0;				//cnt为当前已经出现的学生的个数
    Student stu[m];				//建立结构体数组
    int i,  j;
    for(i =0 ; i< m ;i++)		//初始化结构体数组。
    {
        stu[i].time = 0;
        stu[i].biaohao = -1;		
    }
    for(i = 0;  i< m ;i++)
    {
        int xuehao,h1,m1,m2,h2;				//为了使输入的学号与结构体中的学号便于区分，我们分别用xuehao
       										//以及 stu[i].biaohao   来进行区别
        scanf("%d %d:%d %d:%d",&xuehao,&h1,&m1,&h2,&m2);	//输入数据
        for(j = 0 ; j< m;  j++)
        {
            if(xuehao == stu[j].biaohao)			//遍历我们的结构体数组。如果该学号之前已经出现过，
           				 							//则进行时间的累加
            {
                int t = m2 -m1 ;						
                if(t<0)   {t = 60 + t ;     h2 = h2 - 1 ;  }  		
                stu[j].time +=((h2-h1)*60 + t);       //进行时间的计算并累加
                flag = 1;					//flag 为1 ，证明我们的数据已经被利用
            }
        }
        if(flag == 0)				//flag为0，说明这个学号在之前并未出现过，
        							//我们需要将该时间赋给一个新的成员
            {
                stu[cnt].biaohao = xuehao;      //将该学号赋给新的一个人
                int t = m2 -m1 ;
                if(t<0)   {t = 60+t;     h2-=1;     }
                stu[cnt++].time +=((h2-h1)*60 + t);    	//将时间赋给这个人
            }
        flag = 0 ;                      	//初始化flag.为进行下一个人的判断做准备
    }
    //----------------------------------------开始进行排序------------------------------------
    for(i = 0 ; i < m-1;  i++)
    {
        for(j = i+1 ; j< m;j ++)
        {
            if(stu[i].time!=0&&stu[j].time!=0)		//排除为 0 数据
             {
                    if(stu[i].time<stu[j].time)			//进行时间的比较
                    {
                        Student t = stu[i]; stu[i] = stu[j] ; stu[j] = t ;
                    }
                    if(stu[i].time==stu[j].time)		//时间相同，我们进行学号的比较
                    {
                        if(stu[i].biaohao>stu[j].biaohao)
                        {
                            Student t = stu[i]; stu[i] = stu[j] ; stu[j] = t ;
                        }
                    }
             }
        }
    }
    //------------------------------排序完成，接下来按照我们的顺序输出------------------------------------
    for(i = 0 ; i<  m ; i++)					
    {
            if(stu[i].time!=0)											//注意排除 为0 项
            printf("%d %d\n",stu[i].biaohao,stu[i].time);
    }
}

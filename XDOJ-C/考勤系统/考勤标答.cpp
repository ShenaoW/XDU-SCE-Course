#include<stdio.h>
typedef struct{						//�����ṹ�壬����ѧ����ѧ�ż�����ʱ��
    int biaohao;
    int time ;
}Student;
int main()
{
    int flag = 0 ;			
    int m;
    scanf("%d",&m);
    int cnt = 0;				//cntΪ��ǰ�Ѿ����ֵ�ѧ���ĸ���
    Student stu[m];				//�����ṹ������
    int i,  j;
    for(i =0 ; i< m ;i++)		//��ʼ���ṹ�����顣
    {
        stu[i].time = 0;
        stu[i].biaohao = -1;		
    }
    for(i = 0;  i< m ;i++)
    {
        int xuehao,h1,m1,m2,h2;				//Ϊ��ʹ�����ѧ����ṹ���е�ѧ�ű������֣����Ƿֱ���xuehao
       										//�Լ� stu[i].biaohao   ����������
        scanf("%d %d:%d %d:%d",&xuehao,&h1,&m1,&h2,&m2);	//��������
        for(j = 0 ; j< m;  j++)
        {
            if(xuehao == stu[j].biaohao)			//�������ǵĽṹ�����顣�����ѧ��֮ǰ�Ѿ����ֹ���
           				 							//�����ʱ����ۼ�
            {
                int t = m2 -m1 ;						
                if(t<0)   {t = 60 + t ;     h2 = h2 - 1 ;  }  		
                stu[j].time +=((h2-h1)*60 + t);       //����ʱ��ļ��㲢�ۼ�
                flag = 1;					//flag Ϊ1 ��֤�����ǵ������Ѿ�������
            }
        }
        if(flag == 0)				//flagΪ0��˵�����ѧ����֮ǰ��δ���ֹ���
        							//������Ҫ����ʱ�丳��һ���µĳ�Ա
            {
                stu[cnt].biaohao = xuehao;      //����ѧ�Ÿ����µ�һ����
                int t = m2 -m1 ;
                if(t<0)   {t = 60+t;     h2-=1;     }
                stu[cnt++].time +=((h2-h1)*60 + t);    	//��ʱ�丳�������
            }
        flag = 0 ;                      	//��ʼ��flag.Ϊ������һ���˵��ж���׼��
    }
    //----------------------------------------��ʼ��������------------------------------------
    for(i = 0 ; i < m-1;  i++)
    {
        for(j = i+1 ; j< m;j ++)
        {
            if(stu[i].time!=0&&stu[j].time!=0)		//�ų�Ϊ 0 ����
             {
                    if(stu[i].time<stu[j].time)			//����ʱ��ıȽ�
                    {
                        Student t = stu[i]; stu[i] = stu[j] ; stu[j] = t ;
                    }
                    if(stu[i].time==stu[j].time)		//ʱ����ͬ�����ǽ���ѧ�ŵıȽ�
                    {
                        if(stu[i].biaohao>stu[j].biaohao)
                        {
                            Student t = stu[i]; stu[i] = stu[j] ; stu[j] = t ;
                        }
                    }
             }
        }
    }
    //------------------------------������ɣ��������������ǵ�˳�����------------------------------------
    for(i = 0 ; i<  m ; i++)					
    {
            if(stu[i].time!=0)											//ע���ų� Ϊ0 ��
            printf("%d %d\n",stu[i].biaohao,stu[i].time);
    }
}

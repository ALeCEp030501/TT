#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include"basic1.h"
#include"admin.h"
/***********************************************************/
bool sortir(admin a1, admin a2)
{
	if(a1<a2) return true;
	else return false;
}
/***********************************************************/
int main()
{
	admin* adm;
	//adm=new admin;
	for(int I=0;;I++){
	cout<<"\n1)add\n2)read\n3)delete\n4)change\n";
	int num3;
	while(true){
		cin>>num3;
		if(num3==10) break;
		iti=testin(num3);
		if(iti==2) continue;
		else if(iti==1) break;
		
	}
	if(num3==10) break;
	switch(num3)
	{
		/********************************************/
		case 1:
		{
			cout<<"сколько добавляем ?\n";
			int kolvo1;
			while(true){
				cin>>kolvo1;
				iti=testin(kolvo1);
				if(iti==2) continue;
				else if(iti==1) break;
		
			}
			adm=new admin[kolvo1];
			for(int i=0;i<kolvo1;i++){
				adm[i].addItem(i);
			}
			delete[] adm;
			break;
		}
		/********************************************/
		case 2:
		{
			int numItem=adm->numItem();
			adm=new admin[numItem];
			for(int i=0;i<numItem;i++){
				adm[i].readItem(i);
			}
			sort(adm, adm+numItem,sortir);
			for(int i=0;i<numItem;i++){
				adm[i].outputItem();
			}
			delete[] adm;
			break;
		}
		/********************************************/
		case 3:
		{
			cout<<"как удаляем\n1)по группам(удалить расписание всей группы)\n2)по дате(удалить расписание всех групп в определённый день)\n3)отдельную группу в отдельный день\n";
			int numItem1=adm->numItem();
			adm=new admin[numItem1];
			for(int i=0;i<numItem1;i++){
				adm[i].readItem(i);
			}
			sort(adm, adm+numItem1,sortir);
			int num4;
			while(true){
			
				cin>>num4;
				iti=testin(num4);
				if(iti==2) continue;
				else if(iti==1) break;
			}
			
			if(num4==1){
				cout<<"\nвведите номер групnы\n";
				int group;
				
				cin>>group;
				for(int i=0;i<numItem1;i++){
					if(group==adm[i].getGroup()){
						for(int j=i;j<numItem1;j++){
							adm[j]=adm[j+1];	
						}
						numItem1=numItem1-1;
						i=0;
						continue;
					}
					
				}
				cout<<"\nв файле\n";
				adm[0].posZ();
				for(int i=1;i<numItem1;i++){
					adm[i].writeF(i);
				}
			}
			else if(num4==2){
				cout<<"\nвведите день\n";
				int day;
				cin>>day;
				cout<<"\nвведите месяц\n";
				int mon;
				cin>>mon;
				for(int i=0;i<numItem1;i++){
					if(day==adm[i].getDay() && mon==adm[i].getMon()){
						for(int j=i;j<numItem1;j++){
							adm[j]=adm[j+1];	
						}
						numItem1=numItem1-1;
						i=0;
						continue;
					}
				}
				cout<<"\nв файле\n";
				adm[0].posZ();
				for(int i=1;i<numItem1;i++){
					adm[i].writeF(i);
				}
			}
			else if(num4==3){
				cout<<"\nвведите день\n";
				int day;
				cin>>day;
				cout<<"\nвведите месяц\n";
				int mon;
				cin>>mon;
				cout<<"введите номер группы";
				int group;
				cin>>group;
				for(int i=0;i<numItem1;i++){
					if(day==adm[i].getDay() && mon==adm[i].getMon() && group==adm[i].getGroup()){
						for(int j=i;j<numItem1;j++){
								adm[j]=adm[j+1];	
							}
						numItem1=numItem1-1;
					}
				}

				cout<<"\nв файле\n";
				adm[0].posZ();
				for(int i=1;i<numItem1;i++){
					adm[i].writeF(i);
				}
				
			}
				else{
					cout<<"\nнекоректный ввод,Pовторите\n";
					continue;
				}
			
			break;
			delete[] adm;
		}
		/********************************************/
		case 4:
		{
			int numItem2=adm->numItem();
			adm=new admin[numItem2];
			for(int i=0;i<numItem2;i++){
				adm[i].readItem(i);
			}
			
			cout<<"\nу какой группы и в какой день меняем\n";
			int chgroup,chday,chmon;
			while(true){
				cout<<"\nвведите группу\n";
				cin>>chgroup;
				iti=testin(chgroup);
				if(iti==2) continue;
				else if(iti==1) break;
		
			}
			while(true){
				cout<<"\nвведите день\n";
				cin>>chday;
				iti=testin(chday);
				if(iti==2) continue;
				else if(iti==1) break;
		
			}
			while(true){
				cout<<"\nвведите группу\n";
				cin>>chmon;
				iti=testin(chmon);
				if(iti==2) continue;
				else if(iti==1) break;
		
			}
			for(int i=0;i<numItem2;i++)
			{
				if(chgroup==adm[i].getGroup() && chday==adm[i].getDay() && chmon==adm[i].getMon()){
					adm[i].ch();
					break;
				}
			}
			adm[0].posZ();
			for(int i=1;i<numItem2;i++){
				adm[i].writeF(i);
			}
			delete[] adm;
			break;
		}	
	}
	}
	
	
	return 0;
}
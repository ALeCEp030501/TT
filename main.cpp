#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include"basic1.h"
#include"userBas.h"
using namespace std;
/***********************************************************/
bool sortir1(userBas a1, userBas a2)
{
	if(a1<a2) return true;
	else return false;
}
/***********************************************************/

int main()
{
	userBas *user;
	int numItem=user->numItem();
	user=new userBas[numItem];
	
	for(int i=0;i<numItem;i++){
		user[i].readItem(i);
	}
	sort(user, user+numItem,sortir1);
	
	cout<<"\n0011)\n1)student\n2)teacher"<<endl;
		
	int num0;
	while(true){
			cin>>num0;
			iti=testin(num0);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
	switch(num0)
	{
		case 1:
			cout<<endl<<"input number of group"<<endl;
			int group;
			while(true){
				cin>>group;
				if(cin.good()){
					cin.ignore(6,'\n');
					break;
				}
				cin.clear();
				cout<<"некоректный ввод, повторите\n";
				cin.ignore(6,'\n');
			}
			for(int i=0;i<numItem;i++){
				if(group==user[i].getGroup()){
					user[i].outputItem();
				}
			}
			break;
		case 2: 
			cout<<endl<<"input surname of teacher"<<endl;
			char prepod[30];
			cin>>prepod;
			for(int i=0;i<numItem;i++)
					user[i].testPrepod(prepod);
			break;
		
	}
	delete[] user;
	return 0;
}
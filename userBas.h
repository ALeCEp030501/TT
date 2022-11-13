//#include"basic.h"
using namespace std;
class userBas  
{
	friend class basic;
	private: 
		basic data;
	public:
		void  readItem(int i){//считывает из файла и заносит в массив
			data._read(i);
		}
		void outputItem(){//выводит на экран
			cout<<data;
			cout<<endl;
		}
		int  numItem(){//считает количество элементов в файле
			return data._num();
		}
		bool operator <(userBas& a){//перегрузка оператора сравнения
			if(data<a.data) return true;
			else return false;
		}
		int getGroup(){//получить номер группы
			return data.getGr();
		}
		void testPrepod(char* prep){
			for(int i=0;i<3;i++)
			{
				if(strcmp(prep,data.getPrepod(i))==0) data.outputPrep(i);
			}
		}
};
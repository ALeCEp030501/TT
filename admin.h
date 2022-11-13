using namespace std;
class admin
{
	friend class basic;
	private:
		basic data;
	public:	
		void ch(){//изменение данных
			data.change();
		}	
		void addItem(int i){//заполняет массив с последующим заполнением файла
			while(true){
				cin>>data;
				iti=testin(data);
				if(iti==2) continue;
				else if(iti==1) break;
		
			}
			data.add(i);
		}
		void writeF(int i){//просто запись в файл
			data.add(i);
		}
		void  readItem(int i){//считывает из файла и заносит в массив
			data._read(i);
		}
		void outputItem(){//выводит на экран
			cout<<data;
			cout<<endl;
		}
		void posZ(){//открытие и очистка файла с последующей записью данных в него
			data.posZ();
		}
		int  numItem(){//считает количество элементов в файле
			return data._num();
		}
		int getGroup(){//получить номер группы
			return data.getGr();
		}
		int getDay(){//получить день
			return data.getD();
		}
		int getMon(){//получить месяц
			return data.getMonth();
		}
		bool operator <(admin& a){//перегрузка оператора сравнения
			if(data<a.data) return true;
			else return false;
		}
};
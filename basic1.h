using namespace std;
/********************************************/
int iti;
template <class T>
int testin(T& data){
	if(cin.good()){
		cin.ignore(6,'\n');
		return 1;
	}
	cin.clear();
	cout<<"\nнекоректный ввод, повторите\n";
	cin.ignore(6,'\n');
	return 2;
}
/**********************************************/
class basic
{
	private:
		int _class[3];
		char lesson[3][30];
		int month;
		int day;
		int group;
		char teacher[3][30];
		
	public:
		void outputPrep(int i){//вывести данные для преподавателя
			cout<<"\nдата "<<day<<"."<<month<<"\nаудитория "<<_class[i]<<" дисциплина "<<lesson[i]<<" группа "<<group<<endl;
		}
		void posZ(){///открытие и очистка файла с последующей записью данных в него
			fstream f;
			f.open("data",ios::out);
			f.write((char*)this,sizeof(*this));
		}
		void add(int i){//запись в файл
			fstream f;
			f.open("data",ios::app);
			f.write((char*)this,sizeof(*this));
		}
		void _read(int i){//чтение из файла
			 fstream f;
			 f.open("data",ios::in);
			 f.seekg(i*sizeof(basic));
			 f.read((char*)this,sizeof(*this));
		}
		int  _num(){//считает количество элементов
			fstream f;
			f.open("data",ios::in);
			f.seekg(0,ios::end);
			int a=f.tellg();
			return a/sizeof(basic);
		}
		int getGr(){//получить номер группы
			return group;
		}
		int getD(){//получить день
			return day;
		}
		int getMonth(){//получить месяц
			return month;
		}
		char* getPrepod(int i){
			return teacher[i];
		}
		void change(){//изменение элементов
			cout<<"\nчто поменяем\n";
			cout<<"\n1)дату\n2)номер группы\n3)аудиторию, пары или преподавателя\n";
			int i;
			int i1,F;
			int d, m;
			char str[30];
			cin>>i;
			switch(i)
			{
				case 1:
					cout<<"\nвведите день\n";
					cin>>d;
					day=d;
					cout<<"\nвведите месяц\n";
					cin>>m;
					month=m;
					break;
				case 2:
					cout<<"\nвведите группу"<<endl;
					cin>>group;
					break;
				case 3:
					cout<<"\nкакую пару меняем\n";
					cin>>d;
					cout<<"\nвведите пару\n";
					cin>>lesson[d];
					cout<<"\nвведите аудиторию\n";
					cin>>_class[d];
					cout<<"\nвведите преподавателя\n";
					cin>>teacher[d];
					break;
			}	
		}
		bool operator< (basic& a)//перегрузка оператора сравнения
		{
			if(month<a.month) return true;
			else if(month==a.month){
				if(day<a.day) return true;
				else return false;
			}
			else return false;
		}
		friend ostream& operator<<(ostream& o, basic& a);
		friend istream& operator>>(istream& i, basic& a);
		
};
istream& operator >> (istream& i, basic& a){
	cout<<"\nвведите дату"<<endl<<"день: ";
	while(true){
			i>>a.day;
			iti=testin(a.day);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
	//i>>a.day;
	cout<<"\nмесяц: "<<endl;
	while(true){
			i>>a.month;
			iti=testin(a.month);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
	//i>>a.month;
	cout<<"\nвведите группу: "<<endl;
	while(true){
			i>>a.group;
			iti=testin(a.group);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
	//i>>a.group;
	
	
	cout<<"\nдобавьте занятия: "<<endl;
		cout<<"1 пара: "<<endl;
		i>>a.lesson[0];
		cout<<"аудитория "<<endl;
		while(true){
			i>>a._class[0];
			iti=testin(a._class[0]);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
		//i>>a._class[0];
		cout<<"добавьте преподавателя"<<endl;
		i>>a.teacher[0];
		cout<<"2 пара: "<<endl;
		i>>a.lesson[1];
		cout<<"аудитория "<<endl;
		while(true){
			i>>a._class[1];
			iti=testin(a._class[1]);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
		//i>>a._class[1];
		cout<<"добавьте преподавателя"<<endl;
		i>>a.teacher[1];
		cout<<"3 пара: "<<endl;
		i>>a.lesson[2];
		cout<<"аудитория "<<endl;
		while(true){
			i>>a._class[2];
			iti=testin(a._class[2]);
			if(iti==2) continue;
			else if(iti==1) break;
		
		}
		//i>>a._class[2];
		cout<<"добавьте преподавателя"<<endl;
		i>>a.teacher[2];
	return i;
}
ostream& operator << (ostream& o, basic& a){
	o<<"\nдата: "<<a.day<<"."<<a.month<<endl;
	o<<"группа: "<<a.group<<endl;
	for(int i=0;i<3;i++){
	o<<i<<" пара: "<<a.lesson[i]<<" аудитория "<<a._class[i]<<" преподаватель "<<a.teacher[i]<<endl;
	}
	return o;
}
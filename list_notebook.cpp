// List_Notebook - Однонаправленный связаный список
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


struct tItem {		// Записи
    std::string name;
    std::string phone;
    tItem* next;
};


void InitListBook(tItem** List);
void LoadListBook(tItem** List, std::string fname);
void PrintListBook(tItem** List);
int listLen(tItem** List);
void ClearListBook(tItem** List);
tItem* FindPhone(tItem** List, std::string name);
void InsertAfter(tItem* phonePtr, tItem* newP);
 


int main(int argc, char *argv[]){
	
    std::cout << "List Notebook" << std::endl;
    
    tItem* List;
	InitListBook(&List);
	std::cout << "Количество записей: " << listLen(&List) << std::endl;
	LoadListBook(&List, "book.txt");
	PrintListBook(&List);
	std::cout << "Количество записей: " << listLen(&List) << std::endl;
	//ClearListBook(&List);
	//std::cout << "Количество записей: " << listLen(&List) << std::endl;
	
	std::string name;
	std::cout << "Фамилия?: ";
	std::cin >> name;
	tItem* found = FindPhone(&List, name);
	if(found != nullptr){
		std::cout << "Телефон: " << found->phone << std::endl;
		
		tItem* newP = new tItem;
		std::cout << "Добавить фамилию: ";
		std::cin >> newP->name;
		std::cout << "Добавить телефон: ";
		std::cin >> newP->phone;
		InsertAfter(found, newP);
	}
	else std::cout << "Не найдено" << std::endl;
	
	PrintListBook(&List);
	std::cout << "Количество записей: " << listLen(&List) << std::endl;
	
	
	
    return 0;
}


//Инициализаця списка
void InitListBook(tItem** List){
	*List = nullptr;
}


// Загрузка книжки из файла
void LoadListBook(tItem** List, std::string fname){
	int i = 0;
	std::ifstream in(fname); 
    if (in.is_open())
    {
		std::cout << "Reading file " << fname << " ... ";
		std::string nameF;
		std::string phoneF;
        while(in >> nameF >> phoneF){
			tItem* p = new tItem;
			p->name = nameF;
			p->phone = phoneF;
			p->next = *List;
			*List = p;
			i++;
        }
    }
    in.close();
	std::cout << i << std::endl;
}


// Распечатать список
void PrintListBook(tItem** List){
	tItem* p = *List;
	while(p != nullptr){
		std::cout << p->name << " " << p->phone << std::endl;
		p = p->next;
	}
}


// Полить длину списка
int listLen(tItem** List){
	tItem* p = *List;
	int c = 0;
	while(p != nullptr){
		c++;
		p = p->next;
	}
	return c;
}


// Очистка списка
void ClearListBook(tItem** List){
	tItem* p = *List;
	while(p != nullptr){
		tItem* next = p->next;
		delete p;
		p = next;
	}
	*List = nullptr;
}


// Поиск по имени
tItem* FindPhone(tItem** List, std::string name){
	tItem* p = *List;
	while(p != nullptr && name != p->name){
		p = p->next;
	}
	return p;
}


// Вставить новую запись в середину
void InsertAfter(tItem* phonePtr, tItem* newP){
	newP->next = phonePtr->next;
	phonePtr->next = newP;
}
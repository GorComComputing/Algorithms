// List_Notebook - ���������������� �������� ������
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


struct tItem {		// ������
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
	std::cout << "���������� �������: " << listLen(&List) << std::endl;
	LoadListBook(&List, "book.txt");
	PrintListBook(&List);
	std::cout << "���������� �������: " << listLen(&List) << std::endl;
	//ClearListBook(&List);
	//std::cout << "���������� �������: " << listLen(&List) << std::endl;
	
	std::string name;
	std::cout << "�������?: ";
	std::cin >> name;
	tItem* found = FindPhone(&List, name);
	if(found != nullptr){
		std::cout << "�������: " << found->phone << std::endl;
		
		tItem* newP = new tItem;
		std::cout << "�������� �������: ";
		std::cin >> newP->name;
		std::cout << "�������� �������: ";
		std::cin >> newP->phone;
		InsertAfter(found, newP);
	}
	else std::cout << "�� �������" << std::endl;
	
	PrintListBook(&List);
	std::cout << "���������� �������: " << listLen(&List) << std::endl;
	
	
	
    return 0;
}


//������������ ������
void InitListBook(tItem** List){
	*List = nullptr;
}


// �������� ������ �� �����
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


// ����������� ������
void PrintListBook(tItem** List){
	tItem* p = *List;
	while(p != nullptr){
		std::cout << p->name << " " << p->phone << std::endl;
		p = p->next;
	}
}


// ������ ����� ������
int listLen(tItem** List){
	tItem* p = *List;
	int c = 0;
	while(p != nullptr){
		c++;
		p = p->next;
	}
	return c;
}


// ������� ������
void ClearListBook(tItem** List){
	tItem* p = *List;
	while(p != nullptr){
		tItem* next = p->next;
		delete p;
		p = next;
	}
	*List = nullptr;
}


// ����� �� �����
tItem* FindPhone(tItem** List, std::string name){
	tItem* p = *List;
	while(p != nullptr && name != p->name){
		p = p->next;
	}
	return p;
}


// �������� ����� ������ � ��������
void InsertAfter(tItem* phonePtr, tItem* newP){
	newP->next = phonePtr->next;
	phonePtr->next = newP;
}
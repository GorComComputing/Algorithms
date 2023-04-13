// Notebook - Статический массив
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

//using namespace std;

const int nmax = 1000;

struct tItem {		// Записи
    std::string name;
    std::string phone;
    //char cname[30];
    //char cphone[30];
};

struct tBook {		// Статический массив
    int n;
    tItem* a[nmax];
};

 
void InitBook(tBook* B);
void LoadBook(tBook* B, std::string fname);
void WriteBook(tBook* B);
void SortBook(tBook* B);
void SaveBook(tBook* B, std::string fname);
void ClearBook(tBook* B);


int main(int argc, char *argv[]){
	
    std::cout << "Notebook" << std::endl;
    
    tBook Book;
    InitBook(&Book);
    LoadBook(&Book, "book.txt");
	std::cout << "============================" << std::endl;
	WriteBook(&Book);
	std::cout << "============================" << std::endl;
	SortBook(&Book);
	WriteBook(&Book);
	SaveBook(&Book, "sortbook.txt");
	std::cout << "============================" << std::endl;
	ClearBook(&Book);
	WriteBook(&Book);
	std::cout << "============================" << std::endl;
	LoadBook(&Book, "sortbook.txt");
	WriteBook(&Book);
	
    return 0;
}


// Инициализаци книжки
void InitBook(tBook* B){
    for(int i = 0; i < nmax; i++){
        B->a[i] = nullptr;
    }
    B->n = 0;
}


// Загрузка книжки из файла
void LoadBook(tBook* B, std::string fname){
	std::ifstream in(fname); 
    if (in.is_open())
    {
		std::cout << "Reading file " << fname << " ... ";
		B->n = 0;
		std::string nameF;
		std::string phoneF;
        while(in >> nameF >> phoneF){
			B->a[B->n] = new tItem;
			B->a[B->n]->name = nameF;
			B->a[B->n]->phone = phoneF;
			B->n++;
        }
    }
    in.close();
	std::cout << B->n << std::endl;
}


// Чтение книжки
void WriteBook(tBook* B){
	for(int i = 0; i < B->n; i++){
		std::cout << i+1 << " " << B->a[i]->name << " " << B->a[i]->phone << std::endl;
	}
}


// Сортировка (народная)
void SortBook(tBook* B){
	for(int i = 0; i < B->n-1; i++){
		for(int j = 1; j < B->n; j++){
			if(B->a[i]->name > B->a[j]->name){
				tItem* buf = B->a[i];
				B->a[i] = B->a[j];
				B->a[j] = buf;
			}
		}
	}
}


// Сохранить книжку в файл
void SaveBook(tBook* B, std::string fname){
	std::ofstream out;          // поток для записи
    out.open(fname);      		// открываем файл для записи
    if (out.is_open())
    {
		for(int i = 0; i < B->n; i++){
			out << B->a[i]->name << " " << B->a[i]->phone << std::endl;
		}
    }
    out.close(); 
    std::cout << "Saved to file " << fname << std::endl;
}


// Очиста книжки
void ClearBook(tBook* B){
	for(int i = 0; i < B->n; i++){
			delete B->a[i];
	}
	B->n = 0;
	std::cout << "Cleared" << std::endl;
}


#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int size_first  = 0; int size_second = 0;//размеры массивов

    ifstream in;
    in.open("in.txt");
    //проверяем открытие,завершаем  программу если нет
    if (!in.is_open()) {
        cout << "File is not opened";
        return 0;
    }
    in >> size_first;
    int* arr_first = new int [size_first];
    for(int i = 0; i< size_first; ++i) in >> arr_first[i];
    
    //меняем 1 и последний элемент
    arr_first[0] = arr_first[size_first-1] + arr_first[0];
    arr_first[size_first-1] = arr_first[0] - arr_first[size_first - 1];
    arr_first[0]= arr_first[0] - arr_first[size_first - 1];
    
    //упорядочиваем с 1го элемента
    int keeper;
    for (int i = 1; i < size_first - 1; i++)
        for (int j = size_first - 2; j >= i; j--) {
            if(arr_first[j-1] > arr_first[j]){
              keeper = arr_first[j-1]; arr_first[j-1]= arr_first[j]; arr_first[j] = keeper;
             }
         }     

    in >> size_second;
    int* arr_second = new int[size_second];
    for (int i = 0; i < size_second; ++i) in >> arr_second[i]; 
   
   //меняем 1 и последний элемент
    arr_second[0] = arr_second[size_second - 1] + arr_second[0];
    arr_second[size_second - 1] = arr_second[0] - arr_second[size_second - 1];
    arr_second[0] = arr_second[0] - arr_second[size_second - 1];
    
    //упорядочиваем со 2го элемента    
    for (int i = 2; i < size_second-1; i++)
        for (int j = size_second - 1; j >= i; j--) {
            if (arr_second[j-1] > arr_second[j]) {
                keeper = arr_second[j-1]; arr_second[j-1] = arr_second[j]; arr_second[j] = keeper;
            }
        }

    //создаем выходной файл
    ofstream  out("out.txt");

    out << size_second << "\n";
    for(int i = 0; i< size_second;i++) {out << arr_second[i];if (i < size_second -1) out << " "; }

    out << "\n" << size_first << "\n";
    for (int i = 0; i < size_first; i++) {out << arr_first[i]; if (i < size_first - 1) out << " ";}

    in.close();
    out.close();
    delete [] arr_first;
    delete [] arr_second;
}


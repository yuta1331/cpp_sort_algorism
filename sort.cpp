#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <time.h>

void RequireEnterInput(void){
  while(fgetc(stdin) != '\n'){
    ;
  }
}

void Ary_cout(int ary[], int size){
  std::cout << "array[" << size << "] = {";
  for(int i = 0; i < size; i++){
    std::cout << ary[i] << ", ";
  }
  std::cout << "}" << std::endl;
}

void Swap(int ary[], int i, int j){
  int tmp;
  tmp = ary[i];
  ary[i] = ary[j];
  ary[j] = tmp;
}

void Shuffle(int ary[], int size){ // ary[]をランダムで並べ替えする関数
  for(int i = 0; i < size; i++){
    int j = rand()%size;
    Swap(ary, i, j);
  }
}

void Bubble(int ary[], int size){
  for(int i = 0; i < size - 1; i++){
    std::cout << "i = " << i << std::endl;
    for(int j = 0; j < size - 1 - i; j++){
      RequireEnterInput(); // Require ENTER
      Ary_cout(ary, size);  // aryを標準出力
      if(ary[j] > ary[j+1]){ // ary[j] > ary[j+1] -> 昇順
        Swap(ary, j, j+1);
      }
    }
  }
}

void Selection(int ary[], int size){
  for(int i = 0; i < size - 1; i++){
    std::cout << std::endl << "i = " << i << std::endl;
    Ary_cout(ary, size);  // aryを標準出力
    int min = i;
    for(int j = i; j < size; j++){
      RequireEnterInput(); // Require ENTER
      std::cout << "min_array[" << min << "] = " << ary[min];
      if(ary[j] < ary[min]){ //ary[j] < ary[min] -> 昇順
        min = j;
      }
    }
    Swap(ary, i, min);
  }
}

void Quick(int ary[], int left, int right){ // 基準は中央値
  int i, j;
  int pivot; // 基準

  i = left;
  j = right;

  pivot = ary[(left + right) / 2];
  std::cout << "pivot = " << pivot << std::endl;

  while(1){
    while(ary[i] < pivot)
      i++;
    while(ary[j] > pivot)
      j--;
    if(i >=j)
      break;

    Swap(ary, i, j);
    i++;
    j--;
  }

  RequireEnterInput();
  Ary_cout(ary, right + 1);

  if(left < i - 1)
    Quick(ary, left, i - 1);
  if(j + 1 < right)
    Quick(ary, j + 1, right);
}

int main(void){
  int n;
  std::cout << "input the size of array" << std::endl;
  std::cin >> n;

  int i;
  int ary[n];
  std::string sort_algo;

  for(i = 0; i < n; i++){ // ary[n]を生成
    ary[i] = i + 1;
  }
  Shuffle(ary, n);   // aryをランダムで並べ替え
  Ary_cout(ary, n);  // aryを標準出力

  std::cout << "select sort algorism" << std::endl;
  std::cin >> sort_algo;

  // sorting
  if(sort_algo == "bubble"){
    clock_t time_s = clock();
    Bubble(ary, n);
    clock_t time_f = clock();
    std::cout << "time = " << time_f - time_s << std::endl;
  }else if(sort_algo == "selection"){
    clock_t time_s = clock();
    Selection(ary, n);
    clock_t time_f = clock();
    std::cout << std::endl << "time = " << time_f - time_s << std::endl;
  }else if(sort_algo == "quick"){
    clock_t time_s = clock();
    Quick(ary, 0, n - 1);
    clock_t time_f = clock();
    std::cout << "time = " << time_f - time_s << std::endl;
  }else{
    std::cout << "no match sort algorism" << std::endl;
    return 0;
  }

  // sort後のaryを標準出力
  Ary_cout(ary, n);
  return 0;
}

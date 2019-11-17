#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

namespace my_random{
  auto generate(int min_t,int max_t,int nombre){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min_t,max_t);

    auto t=std::vector<int>(nombre);
    for(auto& n : t){
      n = dis(gen);
    }
    return t;
  }
}

void echange(std::vector<int>& v,int a,int b){
  int temp = v[a];
  v[a]=v[b];
  v[b]=temp;
}

int partitionner(std::vector<int>& v,int premier,int dernier){
  int pivot = v[premier+(dernier-premier)/2];
  int i= premier-1;
  int j = dernier+1;
  while (true) {
    do{
        i++;
    }while (v[i] < pivot);

    do{
      j--;
    }while (v[j] > pivot);
    if (i>= j)  return j;
    echange(v,i,j);

  }

}

inline void tri_rapide(std::vector<int>&T,int first,int last){
  if(first<last){

    int pivot = partitionner(T, first, last);
    //std::cout << "premier "<< first <<" pivot = "<< pivot <<" dernier "<<last<< std::endl;
    tri_rapide(T,first,pivot);
    tri_rapide(T,pivot+1,last);

  }
}

void jaffiche(std::vector<int>& t){
  for(int i=0;i<t.size();i++){
    std::cout << t[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc ,char *argv[]){
  if(argc<2){
    std::cout << "Usage : %[size] " << std::endl;
    return 1;}
  
  int size = atoi(argv[1]);
  auto v = my_random::generate(0,size,size);
  //jaffiche(v);
  auto start = std::chrono::system_clock::now();
  tri_rapide(v,0,size-1);
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = end-start;
  std::cout << "L'execution du tri rapide nous prend " << diff.count() << " s\n" << std::endl;
  //jaffiche(v);

  std::cout << "Comparaison avec sort de la librairie standard "<< std::endl;
  auto debut = std::chrono::system_clock::now();
  std::sort(v.begin(),v.end());
  auto fin = std::chrono::system_clock::now();
  std::chrono::duration<double> diff2 = fin-debut;
  std::cout << "L'execution avec sort de la librairie std nous prend " << diff2.count() << " s\n" << std::endl;
  //jaffiche(v);
    
  return 0;
}

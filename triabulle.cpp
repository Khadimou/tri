#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>

namespace my_random {
  auto generate(int min_t,int max_t,int nombre)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min_t,max_t);

    auto t = std::vector<int>(nombre);
    for(auto& n : t){
      n = dis(gen);
    }
    /*for(auto i=0;i<nombre;i++){
      t[i] = dis(gen);
      }*/
    return t;
  }
}

inline void tri_a_bulle(std::vector<int>& tab){
  auto start = std::chrono::system_clock::now();
  int i=tab.size()-1;
  do{
    for(int j=0;j<=i-1;j++){
      if(tab[j+1]<tab[j]){
	int tmp = tab[j];
	tab[j] = tab[j+1];
	tab[j+1] = tmp;
      }
	}
    i--;
  }while(i>=1);
   auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = end-start;
  std::cout << "L'execution pour le tri a bulle nous prend " << diff.count() << " s\n" << std::endl;
}

inline bool tri_a_bulle_optim(std::vector<int>& T){
  auto start = std::chrono::system_clock::now();
  int i = T.size()-1;
  do{
    if(tri_a_bulle_optim)
      for(int j=0;j<=i-1;j++){
	if(T[j+1]<T[j]){
	  int tmp = T[j+1];
	  T[j+1] = T[j];
	  T[j] = tmp;
	  !tri_a_bulle_optim(T);
	}
      }
    i--;
  }while(i>=1);
   auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = end-start;
  std::cout << "L'execution pour le tri a bulle optimise nous prend " << diff.count() << " s\n" << std::endl;

  return tri_a_bulle_optim;
}

void jaffiche(std::vector<int>& t){
  for(int i=0;i<t.size();i++){
    std::cout << t[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc,char *argv[]){
  if(argc<2){
    std::cout << "usage : [size] "<< std::endl;
    return 1;
  }

  int size = atoi(argv[1]);
  auto v = my_random::generate(0,size,size);
  //jaffiche(v);
  std::cout << "Apres tri " << std::endl;
  tri_a_bulle(v);
  
  //jaffiche(v);

  std::cout << "Comparaison avec sort de la librairie standard, on a " << std::endl;
  auto debut = std::chrono::system_clock::now();
  std::sort(v.begin(), v.end());
  auto fin = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = fin-debut;
  std::cout << "L'execution du tri avec la fonction sort de std nous prend " << diff.count() << " s\n" << std::endl;
  //jaffiche(v);

  std::cout << "Apres optimisation de l'algo de tri " << std::endl;
  tri_a_bulle_optim(v);
  //jaffiche(v);

  return 0;
}

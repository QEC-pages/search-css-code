//Weilei Zeng, Nov 26 2018
/*
This code produce two random quantum codes and construct concatenated codes and reduced code. Then check their distance.
 */
#include "weilei_lib/my_lib.h"
//#include <itpp/itbase.h>
#include <ctime> //to get current time
#include <vector>
//using namespace itpp;
//using namespace std;
const int MAX_SIZE=20;

int print_array(int d[MAX_SIZE][MAX_SIZE][MAX_SIZE][2], int na_input, int na, int ka, int dax, int daz){
  //print
  cout<<"n,k,d k=1                   k=2                 k=3"<<endl;
  if (true) {
    for ( int i1 = 5 ; i1<=na_input ; i1 ++ ){
      cout<<"n="<<i1<<endl;
      for ( int i2 = 1 ; i2<=i1-2 ; i2 ++ ){
	cout<<"k"<<i2;
	for ( int i3 = 1 ; i3<=i1 ; i3 ++ ){
	  if ( i1 == na && i2 == ka && i3 == dax ) 
	    cout<<"\033[31m("<<d[i1][i2][i3][0]<<","<< d[i1][i2][i3][1]<<")\033[0m";
	  //	    cout<<"="<<d[i1][i2][i3][0]<<","<< d[i1][i2][i3][1]<<"=";
	  else
	    cout<<"("<<d[i1][i2][i3][0]<<","<< d[i1][i2][i3][1]<<")";
	}
	cout<<endl;
      }
    }
  }
  cout<<"n k d = "<<na<<","<<ka<<","<<dax<<","<<daz<<endl;
  return 0;
}

void print_dist_list( std::vector<mat> & dist_list,  int na_input, int na, int ka, int dax, int daz){
  cout<<"n,k,d k=1                   k=2                 k=3"<<endl;
  if (true) {
    for ( int i1 = 5 ; i1<=na_input ; i1 ++ ){
      cout<<"n="<<i1<<endl;
      for ( int i2 = 1 ; i2<=i1-2 ; i2 ++ ){
	cout<<"k"<<i2;
	for ( int i3 = 1 ; i3<=i1 ; i3 ++ ){
	  
	  
	    if ( i1 == na && i2 == ka && i3 == dax ) 
	      //	    cout<<"\033[31m("<<d[i1][i2][i3][0]<<","<< d[i1][i2][i3][1]<<")\033[0m";
	      cout<<"\033[31m("<<i3<<","<< dist_list[i1].get(i2,i3)<<")\033[0m";
	  //	    cout<<"="<<d[i1][i2][i3][0]<<","<< d[i1][i2][i3][1]<<"=";
	    else
	      cout<<"("<<i3<<","<< dist_list[i1].get(i2,i3)<<")";
	    //	    cout<<"("<<d[i1][i2][i3][0]<<","<< d[i1][i2][i3][1]<<")";
	  
	}
	cout<<endl;
      }
    }
  }
  cout<<"n k d = "<<na<<","<<ka<<","<<dax<<","<<daz<<endl;
  

  return;
}

void read_dist(mat & dist, int n){
  string filename="data/dist-size-"+to_string(n)+".mtx";

  if (fopen(filename.c_str(), "r") == NULL) {
    cout<<"file open fail:"<<filename<<endl;
  }else{
    dist = MM_to_mat(filename); 
  }
  return ;
}

void write_dist(mat dist, int n){
  string filename="data/dist-size-"+to_string(n)+".mtx";
  mat_to_MM(dist,filename);
  return;
}



int main(int args, char ** argv){
  itpp::Parser parser;
  parser.init(args,argv);
  parser.set_silentmode(true);
  int mode = 1; parser.get(mode,"mode");
  int num_core = 16; parser.get(num_core,"num_core");
  int num_trial = 10; parser.get(num_trial,"num_trial");
  //  int sub_mode = 1; parser.get(sub_mode,"sub_mode");
  std::string title_str;  parser.get(title_str,"title");
  const char * title = title_str.c_str();
  std::string note=""; parser.get(note,"note");
  int debug = 1; //default debug on
  parser.get(debug,"debug");
  int seed=1; parser.get(seed,"seed");
  //  std::cout<<"\t seed:"<<seed;
  if (debug) std::cout<<"input seed: "<<seed<<" --> ";
  //  seed = seed + std::time(nullptr);
  //  itpp::RNG_reset(std::time(nullptr)); 
  //  seed = seed + itpp::randi(1,1000000000);
  seed=seed+get_time(3); 
  itpp::RNG_reset(seed);
  if (debug)   std::cout<<"converted seed:"<<seed<<endl;
  //std::cout<<std::endl;

  //  int na_input;  parser.get(na_input,"na_input");
  int n_low;  parser.get(n_low,"n_low");
  int n_high;  parser.get(n_high,"n_high");



  //  RNG_randomize();  

  Real_Timer timer;  timer.tic();


  //int mode=atof(argv[1]);  
  //char * title = argv[2];
  char filename_Gax[256];char filename_Gaz[256];char filename_Gbx[256];char filename_Gbz[256];
  sprintf(filename_Gax,"%sGax.mm",title);  sprintf(filename_Gaz,"%sGaz.mm",title);      sprintf(filename_Gbx,"%sGbx.mm",title);  sprintf(filename_Gbz,"%sGbz.mm",title);

  //  mat dd;
  int dx_max=0, dz_max=0;
  int d[MAX_SIZE][MAX_SIZE][MAX_SIZE][2];
  //init: n k d (dx, dz)
  for ( int i1 = 0 ; i1<=MAX_SIZE ; i1 ++ )
    for ( int i2 = 0 ; i2<=MAX_SIZE ; i2 ++ )
      for ( int i3 = 0 ; i3<=MAX_SIZE ; i3 ++ )
	{ d[i1][i2][i3][0]=i3; d[i1][i2][i3][1]=0;}


  // convert format to imat
  std::vector<mat> dist_list;
  //  *mat address = *mat[MAX_SIZE];
  for ( int i =0; i<MAX_SIZE; i++){
    mat distance(MAX_SIZE+1,MAX_SIZE+1);
    distance.zeros();
    read_dist(distance, i);   
    std::cout<<" i = "<<i<<std::endl;
    dist_list.push_back(distance);
  }


  //  print_array(d,na_input);

  if (debug)   cout<<"mode, title ->"<<mode<<endl<<title<<endl;
  switch( mode ){
    case 1://generate random codes and save
      //      int i = 0;
      //#pragma omp parallel num_threads(10)
#pragma omp parallel for num_threads(num_core)
	//      {
	for ( int i =0; i<num_trial;i++){

	  GF2mat Gax,Gaz,Cax,Caz;
	  GF2mat Gbx,Gbz,Cbx,Cbz;
	  int na,ka, Gax_row,Gaz_row;//k is not necessary number of qubits
	  int nb,kb, Gbx_row,Gbz_row;


	  //	  na = na_input; 
	  na=randi(n_low,n_high); 
	  ka = randi(1,na-2);Gax_row=randi(1,na-ka-1); Gaz_row=na-ka-Gax_row;
	  //      getGoodQuantumCode(na,Gax_row,Gaz_row,Gax,Gaz,Cax,Caz,debug);
	  getRandomQuantumCode(na,Gax_row,Gaz_row,Gax,Gaz,Cax,Caz);
      //  cout<<"check code A"<<endl;
	  if (! is_quantum_code(Gax,Gaz,Cax,Caz)) {
	    cout<<"not a quantum code"<<endl;
	    throw "invalid code";
	  }
      int dax = quantum_dist_v2(Gax,Gaz);
      int daz = quantum_dist_v2(Gax,Gaz,1);


      /*
      if ( dax > dx_max ) {
	dx_max = dax;
	cout<<"\r"<<i<<"\t dax,daz="<<dax<<","<<daz<<", max dx, dz = "<<dx_max<<","<<dz_max<<",  time:"<<timer.toc()<<flush;
      }
      if ( daz > dz_max ) {
	dz_max = daz;
	cout<<"\r"<<i<<"\t dax,daz="<<dax<<","<<daz<<", max dx, dz = "<<dx_max<<","<<dz_max<<",  time:"<<timer.toc()<<flush;
      }
      */
      //      cout<<daz<<","<<d[na][ka][dax][1]<<endl;
      //      if ( daz > d[na][ka][dax][1] ){
      if ( daz > dist_list[na].get(ka,dax)){
	d[na][ka][dax][1] = daz;
	print_array(d,n_high, na,ka,dax, daz);
	//	cout<<"debug 2"<<endl;
	dist_list[na].set(ka,dax,daz);
	print_dist_list(  dist_list ,n_high, na,ka,dax, daz);

	write_dist(dist_list[na], na);
	//	cout<<"debug 3"<<endl;
      }

      //#pragma omp critical
      //      {
	//	i++

	//	cout<<i<<"\t dax,daz="<<dax<<","<<daz<<", max dx, dz = "<<dx_max<<","<<dz_max<<".    ."<<endl;
      //      }

      }
      break;
  }
  

  cout<<endl;
  
  if ( debug )  timer.toc_print();
  return 0;
}

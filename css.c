//Weilei Zeng, 2020
/*
search for random CSS code and give a table of parameter for [n k (d_x,d_z)]
 */
#include "weilei_lib/my_lib.h"
//#include <itpp/itbase.h>
#include <ctime> //to get current time
#include <vector>
//using namespace itpp;
//using namespace std;

const int MAX_SIZE=100; // max size of the code

//print all distances. (the new value will be red if applicable)
void print_dist_list( std::vector<mat> dist_list,  int na_input, int na, int ka, int dax, int daz, int format=0){
  switch (format){
  case 0:{//plain format, with red hightlight
    for ( int i1 = 5 ; i1<=na_input ; i1 ++ ){
      cout<<"n="<<i1<<endl;
      for ( int i2 = 1 ; i2<=i1-2 ; i2 ++ ){
	cout<<"k"<<i2;
	for ( int i3 = 1 ; i3<=i1 ; i3 ++ ){	  	  
	    if ( i1 == na && i2 == ka && i3 == dax ) 
	      cout<<"\033[31m("<<i3<<","<< dist_list[i1].get(i2,i3)<<")\033[0m";
	    else
	      cout<<"("<<i3<<","<< dist_list[i1].get(i2,i3)<<")";
	}
	cout<<endl;
      }
    }
    cout<<"input case: n k d = "<<na<<","<<ka<<","<<dax<<","<<daz<<endl;
  }
    break;
  case 1:{ //markdown table
    int temp;
    for ( int i1 = 5 ; i1<=na_input ; i1 ++ ){//i1 -> n
      cout<<endl<<"n="<<i1<<endl<<endl;
      /*      if ( i1 == 15 ) {
	      cout<<"("
		  << dist_list[i1-1].rows()<<","
		  << dist_list[i1].rows()<<","
		  <<endl;
	      cout<<"```\n"<<dist_list[i1-1]<<endl;
	      cout<<dist_list[i1]<<endl<<"```\n";
      }*/

      
      //print table header
      cout<<"| k,dx ";
      for ( int j = 1 ; j< i1+1 ; j++)
	cout<<"| "<<j;
      cout<<"|"<<endl;
      for ( int j = 0 ; j< i1+1 ; j++)
	cout<<"|-";
      cout<<"|"<<endl;
      //print entries
      for ( int i2 = 1 ; i2<=i1-2 ; i2 ++ ){ //i2 -> k
	cout<<"| "<<i2;
	for ( int i3 = 1 ; i3<=i1 ; i3 ++ ){ // i3 -> dx
	  temp = dist_list[i1].get(i2,i3) ;
	  if ( temp == 0 ){
	    cout<<"| ";
	  }else{
	    cout<<"|"<< temp <<"";
	  }
	    //check n=14,15,16
	  /*   if ( i1 == 15 ) {
	      cout<<"("
		  << dist_list[i1-1].get(i2,i3)<<","
		  << temp
		  <<")";

		  }*/
	  
	}
	cout<<"|"<<endl;
      }
    }
    cout<<endl;
    //    cout<<"input case: n k d = "<<na<<","<<ka<<","<<dax<<","<<daz<<endl;
  }    
    break;
  }
  return;
}

int print_file(string filename){
  int c;
  FILE *fp;
  fp = fopen(filename.c_str(), "r");
  if (fp)
    {
      while ((c = getc(fp)) != EOF)
	putchar(c);
      fclose(fp);
    }
  return 0;
}


//read distance saved in file
void read_dist(mat & dist, int n){
  string filename="data/dist-size-"+to_string(n)+".mtx";
  cout<<"read file: "<<filename.c_str()<<endl;
  FILE *f;
  if ( (f=fopen(filename.c_str(), "r") ) == NULL) {
    cout<<"No such file:"<<filename<<endl;
  }else{
    fclose(f);
    //file exists; read and update
    dist = MM_to_mat(filename);
    /*    if ( n == 14 || n == 15 ) {
      print_file(filename);
      // cout<<"```\n n = "<<n<<"\n"<<dist<<endl<<"```\n";
      }*/
  }
  return ;
}

//write distance for a particular size into file
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
  //  std::string title_str;  parser.get(title_str,"title");
  //  const char * title = title_str.c_str();
  //  std::string note=""; parser.get(note,"note");
  int debug = 1; //default debug on
  parser.get(debug,"debug");
  int seed=1; parser.get(seed,"seed");
  //  std::cout<<"\t seed:"<<seed;
  if (debug) std::cout<<"input seed: "<<seed<<" --> ";
  seed=seed+get_time(3); 
  itpp::RNG_reset(seed);
  if (debug)   std::cout<<"converted seed:"<<seed<<endl;

  //  int na_input;  parser.get(na_input,"na_input");
  int n_low;  parser.get(n_low,"n_low");
  int n_high;  parser.get(n_high,"n_high");

  Real_Timer timer;  timer.tic();


  //  int dx_max=0, dz_max=0;

  cout<<"<details>\n <summary>Click to expand the log!</summary> \n\n ```log";
  
  
  std::vector<mat> dist_list;
  for ( int i =0; i<MAX_SIZE; i++){
    mat distance(MAX_SIZE+1,MAX_SIZE+1);
    distance.zeros();
    read_dist(distance, i);   

    /*
    //fix 0, I keep getting wired value for 0, may because of openmp
    for ( int i1 =0; i1 < distance.rows();i1++) {
      for ( int i2 =0; i2 < distance.cols();i2++) {
	distance.set(i1,i2, (distance.get(i1,i2) > MAX_SIZE)? 0 : distance.get(i1,i2) );
    	distance.set(i1,i2, (distance.get(i1,i2) < 0.1 )? 0 : distance.get(i1,i2) );
      }
    }
    write_dist(distance, i);   //write the file after fix zero
    */
    dist_list.push_back(distance);      
  }

  cout<<"```\n\n</details>\n";

  //just print current result
  if ( debug ){
    if ( debug ==2 ){
      print_dist_list(  dist_list , n_high , 0,0,0, 0,1);
      return 0;
    }else{
      print_dist_list(  dist_list , n_high , 0,0,0, 0);
    }
  }
  

  //  if (debug)   cout<<"mode, title ->"<<mode<<endl<<title<<endl;
  switch( mode ){
    case 1://generate random CSS code and estimate distance
#pragma omp parallel for num_threads(num_core)
	//      {
	for ( int i =0; i<num_trial;i++){
	  cout<<"*";
	  GF2mat Gax,Gaz,Cax,Caz;
	  int na,ka, Gax_row,Gaz_row;//k is not necessary number of qubits
	  //	  na = na_input; 
	  na=randi(n_low,n_high); 
	  ka = randi(1,na-2);Gax_row=randi(1,na-ka-1); Gaz_row=na-ka-Gax_row;
#pragma omp critical
	  {
	    getRandomQuantumCode(na,Gax_row,Gaz_row,Gax,Gaz,Cax,Caz);
	  }
	  if (! is_quantum_code(Gax,Gaz,Cax,Caz)) {
	    cout<<"not a quantum code"<<endl;
	    throw "invalid code";
	  }
	  int dax = quantum_dist_v2(Gax,Gaz);
	  int daz = quantum_dist_v2(Gax,Gaz,1);
	  
	  //found larger distance ( either d_x or d_z )
#pragma omp critical
	  {
	    if ( daz > dist_list[na].get(ka,dax)){
	      dist_list[na].set(ka,dax,daz);
	      if (debug) print_dist_list(  dist_list ,n_high, na,ka,dax, daz);
	      cout<<"n k d = "<<na<<","<<ka<<","<<dax<<","<<daz<<", time: "<<timer.toc()<<endl;
	      write_dist(dist_list[na], na);
	    }
	  }
	}
	break;//for switch statement
  }
  
  if ( debug )  timer.toc_print();
  cout<<"css.out:program ended"<<endl;
  return 0;
}

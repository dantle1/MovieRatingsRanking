#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <chrono>
#include "movies.h"

using namespace std;
using namespace std::chrono;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file

  MovieList allMovies;  // BST to contain all movie objects

  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    Movie newMovie = Movie(movieName, movieRating);
    allMovies.insert(newMovie);  // inserting movies into BST
  }
  if(flag){
      allMovies.printPreOrder();  // print preorder of movie BST
      std::cout << std::endl;
      allMovies.getBestMovie(argv[3]); // get best movie with given prefix
  }
  else{
    // obtaining runtimes for searching for a movie after inserting
      movieFile.clear();
      movieFile.seekg(0, ios::beg);
      auto total_time = 0;
      ofstream pa02search;
      pa02search.open("pa02search.csv");  // csv for search times
      for(int i = 0; i < stoi(argv[3]); i++){  // W = stoi(argv[3])
          auto start = steady_clock::now();
          while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
              allMovies.search(movieName);  // call search()

          }
          auto stop = steady_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          movieFile.clear();
          movieFile.seekg(0, ios::beg);
          pa02search << allMovies.getSearchNodes() << ", " << duration.count() << "Microseconds" << std::endl;
      }
      pa02search.close();


//      // obtaining n and n_visited for insert
//      ofstream pa02insert;
//      pa02insert.open("pa02insert.csv");  // csv for insert nodes
//      for(int i = 0; i < allMovies.getTotalNodes(); i++){
//          pa02insert << allMovies.node[i] << ","  << allMovies.nodes_visited[i] << std::endl;  // N, N_Visited
//      }
//      pa02insert.close();
  }
  movieFile.close();

  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}


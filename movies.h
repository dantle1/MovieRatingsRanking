#include <string>
#include <iostream>
#include <vector>

class Movie{
private:
    std::string movieTitle;
    double movieRating;
public:
    Movie *left, *right, *parent;
    std::string getTitle() const {return movieTitle;}
    void setTitle(const std::string newTitle) {movieTitle = newTitle;}
    double getRating() const {return movieRating;}
    void setRating(const double newRating) {movieRating = newRating;}
    Movie() : movieTitle(""), movieRating(0.0), left(nullptr), right(nullptr), parent(nullptr) { }
    Movie(std::string newTitle,double newRating): movieTitle(newTitle), movieRating(newRating), left(nullptr), right(nullptr), parent(nullptr) { }
};

class MovieList{
private:
    Movie *root;  // root node
    Movie *bestMovie; // contains highest rated movie

    int total_nodes;  // keeps track of total nodes in BST
    int search_nodes;

    bool insert(Movie& newMovie, Movie *n);  // recursive helper for insert function
    void clear(Movie *n);  // recursive helper for constructor
    int getDepth(std::string movieName, Movie *n) const;  // recursive helper for getDepth()
    void printPreOrder(Movie *n) const; // recursive helper for printPreOrder()
    void getBestMovie(std::string prefix, Movie *n);  // recursive helper for getBestMovie()
    bool search(std::string title, Movie *n);  // recursive helper for search()

public:

    MovieList();  // constructor for empty BST
    ~MovieList();  // destructor, deletes all movies in BST
    std::vector<int> node, nodes_visited;  // node: amount of nodes in BST before insertion of new node
                                           // nodes_visited: amount of nodes visited before BST
    int getTotalNodes() const { return total_nodes; }
    int getSearchNodes() const { return search_nodes; }
    Movie* getRoot() const {return root;}  // obtains root from BST
    bool insert(Movie& newMovie);  // function to insert movie into BST
    int getDepth(std::string movieName) const;  // function to obtain depth/level a movie is at
    void getBestMovie(std::string prefix);  // function to obtain best movie with given prefix
    void printPreOrder() const;  // prints preorder of BST
    bool search(std::string title); // searches for title in BST
};

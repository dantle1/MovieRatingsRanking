#include <string>
#include <iostream>
#include "movies.h"
#include "utility.h"

// constructor to set up empty tree
MovieList::MovieList() : root(nullptr), bestMovie(new Movie("", -1.0)), total_nodes(0), search_nodes(0){ }

// destructor to delete the whole tree
MovieList::~MovieList() {
    clear(root);
}

// recursive helper for destructor
void MovieList::clear(Movie *n){
    if(n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}
// inserts newMovie into BST
bool MovieList::insert(Movie& newMovie){
    if(!(root)) {  // inserting into empty BST
        root = new Movie;
        root->setTitle(newMovie.getTitle());
        root->setRating(newMovie.getRating());
        node.push_back(0);
        nodes_visited.push_back(0);
        total_nodes++;  // 1 node in BST now
        return true;
    }
    else {
        insert(newMovie, root);
    }
}

// recursive helper for insert (always call root as n outside of this function)
bool MovieList::insert(Movie& newMovie, Movie* n){
    if(newMovie.getTitle() == n->getTitle()) {
        return false; // return false if movie with same title is already in BST
    }
    else if (newMovie.getTitle() < n->getTitle()){
        if(n->left) {
            return insert(newMovie, n->left);  // go to n's left subtree
        }
        else {
            n->left = new Movie(newMovie.getTitle(), newMovie.getRating());
            n->left->parent = n;
            node.push_back(total_nodes);
            total_nodes++;
            nodes_visited.push_back(getDepth(newMovie.getTitle()));
            return true;
        }
    }
    else {

        if(n->right) {
            return insert(newMovie, n->right);  // go to n's right subtree
        }
        else {
            n->right = new Movie(newMovie.getTitle(), newMovie.getRating());
            n->right->parent = n;
            node.push_back(total_nodes);
            total_nodes++;
            nodes_visited.push_back(getDepth(newMovie.getTitle()));
            return true;
        }
    }
}

// prints pre order list of movies
void MovieList::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for pre order
void MovieList::printPreOrder(Movie *n) const {
    if (n) {
        std::cout << n->getTitle() << ", " << n->getRating() << ", " << getDepth(n->getTitle()) << std::endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// gets best movie with prefix
void MovieList::getBestMovie(std::string prefix){
    getBestMovie(prefix, root);
    if(bestMovie->getRating() == -1.0) {return;}  // no best movie with prefix
    std::cout << "Best movie is " << bestMovie->getTitle() << " with rating " << bestMovie->getRating() << std::endl;
}

void MovieList::getBestMovie(std::string prefix, Movie *n) {
    if(n){
        if(containsPrefix(prefix, n->getTitle())){ // n's title must contain prefix
            if(n->getRating() > bestMovie->getRating()){bestMovie = n;}  // best movie changed to n if n's rating is higher
            getBestMovie(prefix, n->left);  // traverse left subtree
            getBestMovie(prefix, n->right);  // traverse right subtree

        }
        else if(lessPrefix(prefix, n->getTitle())){  // go to left subtree if prefix is less than n's title
            getBestMovie(prefix, n->left);
        }
        else {
            getBestMovie(prefix, n->right);  // go to right subtree if prefix is greater than n's title
        }
    }
}

// returns depth of a movie (its level in a tree, starting from 0 at the root)
int MovieList::getDepth(std::string movieName) const {
    return getDepth(movieName, root);
}

// recursive helper for getDepth
int MovieList::getDepth(std::string movieName, Movie *n) const {
    if(n){
        if(movieName == n->getTitle()) { return 0; }  // return 0 once title is found
        else if(movieName < n->getTitle()) { return 1 + getDepth(movieName, n->left);}  // go to n's left subtree and add 1
        else { return 1 + getDepth(movieName, n->right); } // go to n's right subtree and add 1
    }
}

// search returns true if title is in BST, false otherwise
bool MovieList::search(std::string title){
    return search(title, root);
}

// recursive helper for search
bool MovieList::search(std::string title, Movie* n){
    if(n){
        if(title == n->getTitle()){
            search_nodes++;
            return true;
        }  // return true if n's title is the same as target title
        else if(title.compare(n->getTitle()) < 0){  // go to n's left subtree if title is less than n's title
            search_nodes++;
            return search(title, n->left);
        }
        else{
            search_nodes++;
            return search(title, n->right);  // go to n's right subtree otherwise
        }
    }
    return false;
}

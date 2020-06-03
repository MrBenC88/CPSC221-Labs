/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"
#include <algorithm>
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    ifstream words(filename);
    string word;
    if (words.is_open()) {
        while (getline(words, word)) {
            add_word_to_dict(word);
        }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    for (const string& word : words) {
        add_word_to_dict(word);
    }
}

/**
 * @param word The word to add to the dictionary
 * Adds the word as a (key, value) pair to the dictionary.
 * NOTE: word is the value. You will need to decide an appropriate key
 * for the word.
 */
void AnagramDict::add_word_to_dict(const std::string& word)
{
    /* Your code goes here! */
    string wordCopy = word;
    std::sort(wordCopy.begin(), wordCopy.end());
    
    auto lookup= dict.find(wordCopy);
    if (lookup == dict.end()) {
    // if lookup is not in the dictionary XDDDDDDD

        vector<string> newVector;
        newVector.push_back(word);

        dict.insert ( std::pair<string,vector<string>>(wordCopy,newVector) );


    } else { // if key exists, then dict[wordCopy] = add the word into vector
        dict[wordCopy].push_back(word); 
       
    }


    // string wordCopy = word;
    // std::sort(wordCopy.begin(), wordCopy.end());
    // dict[wordCopy].push_back(word);
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */

    string wordCopy = word;
    std::sort(wordCopy.begin(), wordCopy.end());
    auto lookup = dict.find(wordCopy);

    if (dict.find(wordCopy) != dict.end()){
        return dict.find(wordCopy)->second;
    } else {
        return vector<string>();
    }
    
    
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */

    vector<vector<string>> res;
    auto beginIter = dict.begin();
    auto endIter = dict.end();
    for (auto iter = beginIter; iter  != endIter; iter++ ) {
        if (iter->second.size() > 1) {
            res.push_back(iter->second);
        }
    }
    return res;

    /**
    vector<vector<string>> res;

    for (auto & key_val : dict) {
        res.push_back(key_val.second);
    }

    if (res.size() >= 2) {
        return res;
    } else {
        return vector<vector<string>>();
    }
    
    */
}

